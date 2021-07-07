//
//  main.cpp
//  test-game-engine
//
//  Created by Andy Mina on 6/23/21.
//

#include <Hunter/Hunter.h>
#include "Entity.h"

class GameApp: public Hunter::HunterApp {
public:
private:
	Entity spaceship;
};

START_GAME(GameApp);
