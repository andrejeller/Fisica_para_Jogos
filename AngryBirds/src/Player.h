#pragma once

#include "ofMain.h"

class Player {
public:
	ofImage mySprite;
	ofVec2f pos, vel;
	float mass;
	bool isMoving, LeftPlayer;

	Player(int posX, int posY, float birdMass, bool isLeftPlayer, string spriteName);

};
