//
//  GameApp.cpp
//  test-game-engine
//
//  Created by Andy Mina on 7/8/21.
//

#include <Hunter/Hunter.h>
#include "GameApp.h"

GameApp::GameApp():
	player(
		new Spaceship(
			playerSprite,
			{ 100, 100 },
			50,
			GetWindowWidth(),
			GetWindowHeight()
		)
	),
	earth(earthSprite, { 100, 100 }, 0, GetWindowWidth(), GetWindowHeight()),
	gameOver(gameOverSprite),
	endGame(false),
	frameNumber(0)
{
	// properly set player coords
	player->SetCoords({ (GetWindowWidth() / 2) - (GetWindowWidth() / 2) % 50, 100 });
	// properly set earths coordinates now that it's size is known
	earth.SetCoords({(GetWindowWidth() - earth.GetWidth()) / 2, -earth.GetHeight() + 100});
}

void GameApp::OnUpdate() {
	// draw earth
	earth.Draw();
	
	if (endGame) {
		int x_pos = (GetWindowWidth() - gameOver.GetWidth()) / 2;
		int y_pos = (GetWindowHeight() - gameOver.GetHeight()) / 2;
		Hunter::Renderer::Draw(gameOver, x_pos, y_pos, gameOver.GetWidth(), gameOver.GetHeight());
		
		// handle potentially dead player
		if (player) {
			if (player->GetAction() == Action::DEAD) {
				delete player;
				player = nullptr;
			} else {
				player->Update();
				player->Draw();
			}
		}
		
		// clear dead enemies
		for (int i = enemies.size() - 1; i >= 0; i--) {
			Spaceship &enemy = enemies[i];
			if (enemy.GetAction() == Action::DEAD) {
				enemies.erase(enemies.begin() + i);
			}
			
			// if there's still enemies, continue moving down
			if (frameNumber % 30 == 0)
				enemy.SetAction(Action::MOVE_DOWN);
		}
		
		
		// process enemy collisions
		for (Spaceship &enemy: enemies) {
			// process laser collisions
			for (int i = lasers.size() - 1; i >= 0; i--) {
				Laser &laser = lasers[i];
				
				if (enemy.CollidesWith(laser)) {
					// dmg ship if a laser hits
					laser.InflictDamage(enemy);
					// delete laser after collision
					lasers.erase(lasers.begin() + i);
				}
			}
		}
		
		// update remaining enemies and lasers
		for (Spaceship &enemy: enemies) {
			// process player collision
			if (player && player->GetCoords().x == enemy.GetCoords().x && player->GetCoords().y == enemy.GetCoords().y) {
				player->SetAction(Action::EXPLODE);
			}
			
			enemy.Update();
		}			
		
		for (Laser &laser: lasers)
			laser.Update();
		
		// draw remaining enemies and lasers
		for (const Spaceship &enemy: enemies)
			enemy.Draw();
		
		for (const Laser &laser: lasers)
			laser.Draw();
		
		frameNumber++;
		return;
	}

	// clear old lasers
	while (!lasers.empty() && lasers.front().GetCoords().y >= GetWindowHeight())
		lasers.pop_front();
	
	// clear dead enemies
	for (int i = enemies.size() - 1; i >= 0; i--) {
		Spaceship &enemy = enemies[i];
		if (enemy.GetAction() == Action::DEAD) {
			enemies.erase(enemies.begin() + i);
		}
	}
	
	// process enemy collisions
	for (Spaceship &enemy: enemies) {
		// process laser collisions
		for (int i = lasers.size() - 1; i >= 0; i--) {
			Laser &laser = lasers[i];
			
			if (enemy.CollidesWith(laser)) {
				// dmg ship if a laser hits
				laser.InflictDamage(enemy);
				// delete laser after collision
				lasers.erase(lasers.begin() + i);
			}
		}
		
		// process player collision
		if (enemy.GetCoords().y <= player->GetCoords().y) {
			// if enemy and player share a space, explode player
			if (player->GetCoords().x == enemy.GetCoords().x)
				player->SetAction(Action::EXPLODE);
			endGame = true;
		} else if (earth.CollidesWith(enemy)) { // process earth collision
			endGame = true;
		}
	}
	
	// every second...
	if (frameNumber % (30 * 1) == 0){
		// gen a new enemy if there are less than 5
		if (enemies.size() < 5) {
			// x and y must be divisible by 50 to be on the grid
			// y >= 300 (top of player sprite + 2 spaces) to give player some room
			int x = (rand() % 16) * 50;
			int y = (rand() % 6) * 50 + (player->GetCoords().y + (player->GetHeight() * 4));
			
			while (populatedCoords.count(x) || populatedCoords[x].count(y)) {
				x = (rand() % 16) * 50;
				y = (rand() % 6) * 50 + (player->GetCoords().y + (player->GetHeight() * 4));
			}
			
			enemies.emplace_back(enemySprite, Coords({ x, y }), 50, GetWindowWidth(), GetWindowHeight());
			populatedCoords[x].insert(y);
		}
		
		// move all enemies down
		for (Spaceship &enemy: enemies)
			enemy.SetAction(Action::MOVE_DOWN);
	}

	// update phase
	player->Update();
	
	for (Spaceship &enemy: enemies)
		enemy.Update();
	
	for (Laser &laser: lasers)
		laser.Update();

	// Draw phase
	player->Draw();
	
	for (const Spaceship &enemy: enemies)
		enemy.Draw();

	for (const Laser &laser: lasers)
		laser.Draw();

	frameNumber++;
}

void GameApp::OnKeyPressed(Hunter::KeyPressedEvent &event) {
	// shoot code
	if (event.GetKeyCode() == HUNTER_KEY_SPACE && player && player->GetAction() != Action::DEAD) {
		int x = player->GetCoords().x + (player->GetWidth() / 2) - 5;
		int y = player->GetCoords().y + player->GetHeight();
		lasers.emplace_back(
			laserSprite,
			Coords({ x, y }),
			25,
			GetWindowWidth(), GetWindowHeight(),
			Action::MOVE_UP
		);
	}

	if (event.GetKeyCode() == HUNTER_KEY_LEFT && player && player->GetAction() != Action::DEAD)
		player->SetAction(Action::MOVE_LEFT);
	else if (event.GetKeyCode() == HUNTER_KEY_RIGHT && player && player->GetAction() != Action::DEAD)
		player->SetAction(Action::MOVE_RIGHT);
}

void GameApp::OnKeyHeld(Hunter::KeyHeldEvent &event) {
	if (event.GetKeyCode() == HUNTER_KEY_LEFT && player && player->GetAction() != Action::DEAD)
		player->SetAction(Action::BOOST_LEFT);
	else if (event.GetKeyCode() == HUNTER_KEY_RIGHT && player && player->GetAction() != Action::DEAD)
		player->SetAction(Action::BOOST_RIGHT);
}

void GameApp::OnKeyReleased(Hunter::KeyReleasedEvent &event) {
	if (player && player->GetAction() != Action::DEAD)
		player->SetAction(Action::NONE);
}
