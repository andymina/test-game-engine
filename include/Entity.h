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
	MOVE_UP,
	SHOOT,
	NONE
};

class Entity {
public:
	Entity();
	Entity(
		const std::string &spritePath,
		const Coords &pos,
		const int &entitySpeed,
		const Action &action,
		const int &windowWidth,
		const int &windowHeight
	);
	
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
	Hunter::Sprite img;
	Coords position;
	int speed;
	Action action;
	int windowWidth;
	int windowHeight;
};

#endif /* Entity_h */
