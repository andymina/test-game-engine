//
//  Coords.cpp
//  test-game-engine
//
//  Created by Andy Mina on 7/8/21.
//

#include "Coords.h"

Coords::Coords(int x, int y): x(x), y(y) {
	
}

const Coords Coords::operator+(const Coords &rhs) {
	return Coords(*this) += rhs;
}

const Coords Coords::operator-(const Coords &rhs){
	return Coords(*this) -= rhs;
}

Coords& Coords::operator=(const Coords &rhs) {
	if (this != &rhs) {
		x = rhs.x;
		y = rhs.y;
	}
	
	return *this;
}

Coords& Coords::operator+=(const Coords &rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Coords& Coords::operator-=(const Coords &rhs) {
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

bool Coords::operator==(const Coords &rhs) const {
	return x == rhs.x && y == rhs.y;
}

bool Coords::operator!=(const Coords &rhs) const {
	return !(*this == rhs);
}
