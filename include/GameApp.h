//
//  GameApp.h
//  test-game-engine
//
//  Created by Andy Mina on 7/8/21.
//

#ifndef GameApp_h
#define GameApp_h

#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <Hunter/Hunter.h>
#include "Entity.h"
#include "Spaceship.h"
#include "Laser.h"

class GameApp: public Hunter::HunterApp {
public:
	GameApp();
	
	virtual void OnUpdate() override;
	virtual void OnKeyPressed(Hunter::KeyPressedEvent &event) override;
	virtual void OnKeyHeld(Hunter::KeyHeldEvent &event) override;
	virtual void OnKeyReleased(Hunter::KeyReleasedEvent &event) override;
	
	void GameOver();
	
private:
	std::string playerSprite = "assets/sprites/player.png";
	std::string enemySprite = "assets/sprites/enemy.png";
	std::string laserSprite = "assets/sprites/laser.png";
	std::string earthSprite = "assets/sprites/earth.png";
	std::string gameOverSprite = "assets/sprites/game-over.png";
	
	Spaceship *player;
	std::deque<Spaceship> enemies;
	std::deque<Laser> lasers;
	Entity earth;
	Hunter::Sprite gameOver;
	std::unordered_map<int, std::unordered_set<int>> populatedCoords;
	
	bool endGame;
	long long frameNumber;
};


#endif /* GameApp_h */
