//
//  Entity.cpp
//  test-game-engine
//
//  Created by Andy Mina on 7/7/21.
//

#include "Entity.h"

Entity::Entity() {
	
}

Entity::Entity(
	const std::string &spritePath,
	const Coords &pos,
	const int &entitySpeed,
	const int &windowWidth,
	const int &windowHeight,
	const Action &action
):
	img(spritePath),
	position(pos),
	speed(entitySpeed),
	action(action),
	windowWidth(windowWidth),
	windowHeight(windowHeight) {
	
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

int Entity::GetSpeed() const {
	return speed;
}

void Entity::SetNewSprite(const std::string &newSprite) {
	img.Load(newSprite);
}

void Entity::HandleMove() {
	// handle moves
	if (action == Action::MOVE_LEFT || action == Action::HOLD_LEFT) {
		// check if will be in bounds
		if (position.x - speed >= 0)
			position.x -= speed;
		
		if (action == Action::MOVE_LEFT)
			action = Action::NONE;
		else if (action == Action::HOLD_LEFT)
			action = Action::MOVE_LEFT;
	} else if (action == Action::MOVE_RIGHT || action == Action::HOLD_RIGHT) {
		if (position.x + speed <= windowWidth - GetWidth())
			position.x += speed;
		
		if (action == Action::MOVE_RIGHT)
			action = Action::NONE;
		else if (action == Action::HOLD_RIGHT)
			action = Action::MOVE_RIGHT;
	} else if (action == Action::MOVE_DOWN) {
		position.y -= speed;
		action = Action::NONE;
	} else if (action == Action::MOVE_UP) {
		position.y += speed;
		action = Action::NONE;
	}
}

void Entity::Update() {
	
}

void Entity::Destroy() {
	SetAction(Action::DEAD);
}

void Entity::Draw() const {
	Hunter::Renderer::Draw(img, position.x, position.y, img.GetWidth(), img.GetHeight());
}

// checks if this entity collided with other
bool Entity::CollidesWith(const Entity &other) const {
//	const bool leftEdge = other.position.x >= this->position.x && other.position.x <= this->position.x + this->GetWidth();
//	const bool rightEdge = other.position.x + other.GetWidth() >= this->position.x && other.position.x + other.GetWidth() <= this->position.x + this->GetWidth();
//	const bool bottomEdge = other.position.y >= this->position.y && other.position.y <= this->position.y + this->GetHeight();
//	const bool topEdge = other.position.y + other.GetHeight() >= this->position.y && other.position.y + other.GetHeight() <= this->position.y + this->GetHeight();
	
//	const bool xCollide = (position.x <= other.position.x && other.position.x <= position.x + GetWidth()) ||
//	(position.x <= other.position.x + other.GetWidth() && other.position.x + other.GetWidth() <= position.x + GetWidth());
//
//	const bool yCollide = (position.y <= other.position.y && other.position.y <= position.y + GetHeight()) ||
//	(position.y <= other.position.y + other.GetHeight() && other.position.y + other.GetHeight() <= position.y + GetHeight());
//
//	return xCollide && yCollide;
	
	
		if ((position.x <= other.position.x && other.position.x <= position.x + GetWidth()) ||
			(position.x <= other.position.x + other.GetWidth() && other.position.x + other.GetWidth() <= position.x + GetWidth())) {
			if ((position.y <= other.position.y && other.position.y <= position.y + GetHeight()) ||
					(position.y <= other.position.y + other.GetHeight() && other.position.y + other.GetHeight() <= position.y + GetHeight())) {
				return true;
			}
		}
	
		
	
	return false;
}
