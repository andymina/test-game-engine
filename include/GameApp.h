//
//  GameApp.h
//  test-game-engine
//
//  Created by Andy Mina on 7/8/21.
//

#ifndef GameApp_h
#define GameApp_h

#include <deque>
#include <Hunter/Hunter.h>
#include "Spaceship.h"
#include "Player.h"

class GameApp: public Hunter::HunterApp {
public:
	GameApp();
	
	virtual void OnUpdate() override;
	virtual void OnKeyPressed(Hunter::KeyPressedEvent &event) override;
	
private:
	Player player;
	std::deque<Spaceship> enemies;
};


#endif /* GameApp_h */
