//
//  Laser.cpp
//  test-game-engine
//
//  Created by Andy Mina on 7/11/21.
//

#include "Laser.h"

void Laser::Update() {
	if (action == Action::MOVE_UP)
		position.y += speed;
}

void Laser::InflictDamage(Spaceship &spaceship) {
	spaceship.InflictDamage(1);
}
