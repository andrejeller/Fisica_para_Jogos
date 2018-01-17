#pragma once

#include "ofMain.h"

class Player {
public:
	ofImage mySprite;
	ofVec2f pos, vel;

	Player(int posX, int posY, string spriteName);

	void draw();
	void update(float gravity);

	void LockOnScreen();
	void OnMouseDown(int mouseX, int mouseY);
};
