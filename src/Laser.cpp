//
//  Laser.cpp
//  test-game-engine
//
//  Created by Andy Mina on 7/8/21.
//

#include "Laser.h"

Laser::Laser() {
	
}

Laser::Laser(
	const std::string &spritePath,
	const Coords &pos,
	const int &entitySpeed,
	const int &windowWidth,
	const int &windowHeight
):
	Entity(
		spritePath,
		pos,
		entitySpeed,
		windowWidth,
		windowHeight
	) {
	
}

void Laser::InflictDamage(Spaceship &spaceship) {
	
}
