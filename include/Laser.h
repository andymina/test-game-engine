//
//  Laser.h
//  test-game-engine
//
//  Created by Andy Mina on 7/11/21.
//

#ifndef Laser_h
#define Laser_h

#include <deque>
#include "Entity.h"
#include "Spaceship.h"

class Laser: public Entity {
public:
	using Entity::Entity;
	
	void Update();
	void InflictDamage(Spaceship &spaceship);
};

#endif /* Laser_h */
