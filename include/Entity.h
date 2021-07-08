//
//  Entity.h
//  test-game-engine
//
//  Created by Andy Mina on 7/7/21.
//

#ifndef Entity_h
#define Entity_h

#include <Hunter/Hunter.h>

struct Coords {
	int x, y;
	
	Coords() = default; // default constructor
	Coords(const Coords &other) = default; // copy constructor
	Coords(Coords &&other) = default; // move constructor
	Coords& operator=(const Coords &rhs) = default; // copy assignment
	Coords& operator=(Coords &&rhs) = default; // move assignment
	~Coords() = default;
};

class Entity {
public:
	Entity();
	Entity(const std::string &spritePath, int speed);
	
	Coords GetCoords() const;
	void SetCoords(Coords coords);
	int GetWidth() const;
	int GetHeight() const;
	
	void Draw() const;
	bool CollidesWith(const Entity &other) const;
	
private:
	Hunter::Sprite img { "assets/sprites/mario.gif" };
	Coords position;
	int speed;
};

#endif /* Entity_h */
