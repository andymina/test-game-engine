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
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_DOWN,
	SHOOT,
	NONE
};

class Entity {
public:
	Entity();
	Entity(const std::string &spritePath, int entitySpeed, Action action);
	
	Coords GetCoords() const;
	void SetCoords(Coords coords);
	int GetWidth() const;
	int GetHeight() const;
	Action GetAction() const;
	void SetAction(Action newAction);
	int GetSpeed() const;
	void SetSpeed() const;
	
	void Update();
	void Draw() const;
	bool CollidesWith(const Entity &other) const;
	
private:
	Action action;
	Hunter::Sprite img;
	Coords position;
	int speed;
};

#endif /* Entity_h */
