//
//  Entity.cpp
//  test-game-engine
//
//  Created by Andy Mina on 7/7/21.
//

#include "Entity.h"

Entity::Entity() {
	
}

Entity::Entity(const std::string &spritePath, int entitySpeed, Action action):
	img(spritePath), speed(entitySpeed), action(Action::NONE) {
	
}

Coords Entity::GetCoords() const {
	return position;
}

void Entity::SetCoords(Coords coords) {
	position = coords;
}

Action Entity::GetAction() const {
	return action;
}

void Entity::SetAction(Action newAction) {
	action = newAction;
}

int Entity::GetWidth() const {
	return img.GetWidth();
}

int Entity::GetHeight() const {
	return img.GetHeight();
}

void Entity::Update() {
	if (action == Action::MOVE_LEFT)
		position.x -= speed;
	else if (action == Action::MOVE_RIGHT)
		position.x += speed;
	else if (action == Action::MOVE_DOWN)
		position.y -= speed;
	else if (action == Action::SHOOT)
		std::cout << "SHOOT ACTION\n";
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
