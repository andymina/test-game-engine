//
//  Entity.h
//  test-game-engine
//
//  Created by Andy Mina on 7/7/21.
//

#ifndef Entity_h
#define Entity_h

#include <Hunter/Hunter.h>

class Entity {
public:
private:
	Hunter::Sprite img;
	struct Coord {
		int x, y;
	} position;
	int speed;
}

#endif /* Entity_h */
