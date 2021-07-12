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
	earth(earthSprite),
	gameOver(gameOverSprite),
	endGame(false),
	frameNumber(0) {
	
}

void GameApp::OnUpdate() {
	// draw earth
	Hunter::Renderer::Draw(earth, (GetWindowWidth() - earth.GetWidth()) / 2, -earth.GetHeight() + 100, earth.GetWidth(), earth.GetHeight());

	// end game if player is dead
	if (player->GetAction() == Action::DEAD)
		endGame = true;

	// game over code
	if (endGame) {
		int x_pos = (GetWindowWidth() - gameOver.GetWidth()) / 2;
		int y_pos = (GetWindowHeight() - gameOver.GetHeight()) / 2;
		Hunter::Renderer::Draw(gameOver, x_pos, y_pos, gameOver.GetWidth(), gameOver.GetHeight());
	}

	// clear old lasers
	while (!lasers.empty() && lasers.front().GetCoords().y >= GetWindowHeight())
		lasers.pop_front();

	// update phase
	player->Update();

	for (Laser &laser: lasers)
		laser.Update();

	// Draw phase
	player->Draw();

	for (const Laser &laser: lasers)
		laser.Draw();

	frameNumber++;
}

void GameApp::OnKeyPressed(Hunter::KeyPressedEvent &event) {
	// shoot code
	if (event.GetKeyCode() == HUNTER_KEY_SPACE) {
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


	if (event.GetKeyCode() == HUNTER_KEY_LEFT)
		player->SetAction(Action::MOVE_LEFT);
	else if (event.GetKeyCode() == HUNTER_KEY_RIGHT)
		player->SetAction(Action::MOVE_RIGHT);
}

void GameApp::OnKeyHeld(Hunter::KeyHeldEvent &event) {
	if (event.GetKeyCode() == HUNTER_KEY_LEFT)
		player->SetAction(Action::HOLD_LEFT);
	else if (event.GetKeyCode() == HUNTER_KEY_RIGHT)
		player->SetAction(Action::HOLD_RIGHT);
}

void GameApp::OnKeyReleased(Hunter::KeyReleasedEvent &event) {
	player->SetAction(Action::NONE);
}
