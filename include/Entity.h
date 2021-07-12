//
//  Entity.h
//  test-game-engine
//
//  Created by Andy Mina on 7/7/21.
//

#ifndef Entity_h
#define Entity_h

#include <Hunter/Hunter.h>
#include "Coords.h"

enum class Action {
	MOVE_LEFT, HOLD_LEFT,
	MOVE_RIGHT, HOLD_RIGHT,
	MOVE_DOWN, HOLD_DOWN,
	MOVE_UP, HOLD_UP,
	SHOOT, EXPLODE,
	NONE, DEAD
};

class Entity {
public:
	Entity();
	Entity(
		const std::string &spritePath,
		const Coords &pos,
		const int &entitySpeed,
		const int &windowWidth,
		const int &windowHeight,
		const Action &action = Action::NONE
	);
	
	Entity(const Entity & other);
	Entity(Entity &&other);
	Entity& operator=(const Entity &rhs) = delete;
	Entity& operator=(Entity &&rhs) = delete;	
	
	
	Coords GetCoords() const;
	void SetCoords(Coords coords);
	int GetWidth() const;
	int GetHeight() const;
	Action GetAction() const;
	int GetSpeed() const;
	void SetAction(Action newAction);
	void SetNewSprite(const std::string &spritePath);
	
	virtual void Update();
	void HandleMove();
	void Destroy();
	void Draw() const;
	bool CollidesWith(const Entity &other) const;
	
protected:
	Hunter::Sprite img;
	Coords position;
	int speed;
	Action action;
	int windowWidth;
	int windowHeight;
};

#endif /* Entity_h */
