//
//  GameApp.cpp
//  test-game-engine
//
//  Created by Andy Mina on 7/8/21.
//

#include <Hunter/Hunter.h>
#include "GameApp.h"

GameApp::GameApp():
	player("assets/sprites/player.png", { 100, 100 }, 5, Action::NONE, GetWindowWidth(), GetWindowHeight()) {
}

void GameApp::OnUpdate() {
	player.Update();
}

void GameApp::OnKeyPressed(Hunter::KeyPressedEvent &event) {
	if (event.GetKeyCode() == HUNTER_KEY_LEFT) {
		player.SetAction(Action::MOVE_LEFT);
	} else if (event.GetKeyCode() == HUNTER_KEY_RIGHT) {
		player.SetAction(Action::MOVE_RIGHT);
	}

	if (event.GetKeyCode() == HUNTER_KEY_SPACE) {
		player.SetAction(Action::SHOOT);
	}
}
