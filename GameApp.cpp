//
//  GameApp.cpp
//  test-game-engine
//
//  Created by Andy Mina on 7/8/21.
//

#include "GameApp.h"

GameApp::GameApp():
	player("assets/sprites/player.png", 5, Action::NONE) {
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

void GameApp::OnUpdate() {
	player.Update();
	player.Draw();
}
