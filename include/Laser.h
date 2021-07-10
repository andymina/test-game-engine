//
//  Laser.h
//  test-game-engine
//
//  Created by Andy Mina on 7/8/21.
//

#ifndef Laser_h
#define Laser_h

#include "Spaceship.h"
#include "Entity.h"

class Laser: public Entity {
public:
	Laser();
	Laser(
		const std::string &spritePath,
		const Coords &pos,
		const int &entitySpeed,
		const int &windowWidth,
		const int &windowHeight
	);
	~Laser();
	
	void InflictDamage(Spaceship &spaceship);
};

#endif /* Laser_h */
