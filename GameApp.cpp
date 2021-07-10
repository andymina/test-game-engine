//
//  GameApp.cpp
//  test-game-engine
//
//  Created by Andy Mina on 7/8/21.
//

#include <Hunter/Hunter.h>
#include "GameApp.h"

GameApp::GameApp():
	playerSprite("assets/sprites/player.png"),
	enemySprite("assets/sprites/enemy.png"),
	player(
		playerSprite, { 100, 100 }, 50,
		GetWindowWidth(), GetWindowHeight()
	) {
	
}

void GameApp::OnUpdate() {
	if (frameNumber % 15 == 0 && enemies.size() < 3) {
		enemies.emplace_back(enemySprite, Coords({ int(100 + (enemies.size() * 50)), 200 }), 50, GetWindowWidth(), GetWindowHeight());
	}
	
	for (Spaceship &enemy: enemies)
		enemy.Update();
	player.Update();
	
	for (Spaceship &enemy: enemies)
		enemy.Draw();
	player.Draw();
}

void GameApp::OnKeyPressed(Hunter::KeyPressedEvent &event) {
	if (event.GetKeyCode() == HUNTER_KEY_LEFT)
		player.SetAction(Action::MOVE_LEFT);
	else if (event.GetKeyCode() == HUNTER_KEY_RIGHT)
		player.SetAction(Action::MOVE_RIGHT);

	if (event.GetKeyCode() == HUNTER_KEY_SPACE)
		player.SetAction(Action::SHOOT);
}

void GameApp::OnKeyHeld(Hunter::KeyHeldEvent &event) {
	if (event.GetKeyCode() == HUNTER_KEY_LEFT)
		player.SetAction(Action::HOLD_LEFT);
	else if (event.GetKeyCode() == HUNTER_KEY_RIGHT)
		player.SetAction(Action::HOLD_RIGHT);
}

void GameApp::OnKeyReleased(Hunter::KeyReleasedEvent &event) {
	player.SetAction(Action::NONE);
}
