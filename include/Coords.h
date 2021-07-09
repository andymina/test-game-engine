//
//  Coords.h
//  test-game-engine
//
//  Created by Andy Mina on 7/8/21.
//

#ifndef Coords_h
#define Coords_h

class Coords {
public:
	int x, y;
	
	Coords() = default;
	Coords(int x, int y);
		
	const Coords operator+(const Coords &rhs);
	const Coords operator-(const Coords &rhs);
	Coords& operator=(const Coords &rhs);
	Coords& operator+=(const Coords &rhs);
	Coords& operator-=(const Coords &rhs);
	bool operator==(const Coords &rhs) const;
	bool operator!=(const Coords &rhs) const;
};

#endif /* Coords_h */
