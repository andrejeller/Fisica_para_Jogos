#pragma once

#include "ofMain.h"

class Bird {
public:
	ofImage mySprite;
	ofVec2f pos, vel;
	float mass;
	bool isMoving, LeftPlayer;

	Bird(int posX, int posY, float birdMass, bool isLeftPlayer, string spriteName);

	void draw();
	void update();

	void applyForce(ofVec2f force);
	void LockOnScreen();
	void Reset(int x, int y);
	//void OnMouseDown(int mouseX, int mouseY);
};
