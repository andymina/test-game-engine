//
//  Spaceship.cpp
//  test-game-engine
//
//  Created by Andy Mina on 7/8/21.
//

#include "Spaceship.h"

Spaceship::Spaceship(): Entity() {
	
}

Spaceship::Spaceship(
	const std::string &spritePath,
	const Coords &pos,
	const int &entitySpeed,
	const int &windowWidth,
	const int &windowHeight,
	const int &health
):
	Entity(
		spritePath,
		pos,
		entitySpeed,
		windowWidth,
		windowHeight
	),
	health(health) {
	
		
}

void Spaceship::Update() {
	if (action == Action::EXPLODE) {
		Explode();
	} else if (health >= 1)
		HandleMove();
}

void Spaceship::InflictDamage(const int &dmg) {
	if (health >= 1)
		health -= dmg;
	
	if (health <= 0)
		SetAction(Action::EXPLODE);
}

void Spaceship::Explode() {
	SetNewSprite(explodeSprite);
	SetAction(Action::DEAD);
}
