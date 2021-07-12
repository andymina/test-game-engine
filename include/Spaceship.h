//
//  Spaceship.h
//  test-game-engine
//
//  Created by Andy Mina on 7/8/21.
//

#ifndef Spaceship_h
#define Spaceship_h

#include <deque>
#include "Entity.h"

class Spaceship: public Entity {
public:
	Spaceship();
	Spaceship(
		const std::string &spritePath,
		const Coords &pos,
		const int &entitySpeed,
		const int &windowWidth,
		const int &windowHeight,
		const int &health = 3
	);
	
	virtual void Update() override;
	void InflictDamage(const int &dmg);
	void Explode();
	
private:
	std::string explodeSprite = "assets/sprites/explode.png";
	int health;
	
};

#endif /* Spaceship_h */
