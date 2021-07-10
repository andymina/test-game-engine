//
//  Spaceship.cpp
//  test-game-engine
//
//  Created by Andy Mina on 7/8/21.
//

#include "Spaceship.h"

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
	explodeSprite("assets/sprites/explode.png"),
	health(health) {
	
}

void Spaceship::Update() {
	if (action == Action::EXPLODE) {
		SetNewSprite(explodeSprite);
		action = Action::NONE;
	}
	
	if (action == Action::SHOOT) {
		InflictDamage(1);
		action = Action::NONE;
	}
	
	HandleMove();
}

void Spaceship::InflictDamage(const int &dmg) {
	if (health > 0)
		health -= dmg;
	else if (health <= 0)
		action = Action::EXPLODE;
}

void Spaceship::Explode() {
	img.Load(explodeSprite);
}
