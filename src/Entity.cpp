//
//  Entity.cpp
//  test-game-engine
//
//  Created by Andy Mina on 7/7/21.
//

#include <Hunter/Hunter.h>
#include "Entity.h"

Entity::Entity() {
	
}

Entity::Entity(const std::string &spritePath, int entitySpeed): img(spritePath), speed(entitySpeed) {
	
}

Coords Entity::GetCoords() const {
	return position;
}

void Entity::SetCoords(Coords coords) {
	position = coords;
}

int Entity::GetWidth() const {
	return img.GetWidth();
}

int Entity::GetHeight() const {
	return img.GetHeight();
}

void Entity::Draw() const {
	Hunter::Renderer::Draw(img, position.x, position.y, img.GetWidth(), img.GetWidth());
}

bool Entity::CollidesWith(const Entity &other) const {
	const bool leftEdge = other.position.x >= this->position.x && other.position.x <= this->position.x + this->GetWidth();
	const bool rightEdge = other.position.x + other.GetWidth() >= this->position.x && other.position.x + other.GetWidth() <= this->position.x + this->GetWidth();
	const bool bottomEdge = other.position.y >= this->position.y && other.position.y <= this->position.y + this->GetHeight();
	const bool topEdge = other.position.y + other.GetHeight() >= this->position.y && other.position.y + other.GetHeight() <= this->position.y + this->GetHeight();
	
	return leftEdge || rightEdge || bottomEdge || topEdge;
}
