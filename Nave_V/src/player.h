#pragma once

#include "ofMain.h"
#include "astro.h"

class Player {
public:
	ofImage mySprite;
	ofVec2f pos, vel, impulso;
	float Fa = 0; //Força de Atração
	float g = 0.1;
	float mass;

	Player(ofVec2f position, float mass, string spriteName);

	void draw();
	void update(Astro other);

	void LockOnScreen();
	void OnMouseDown(ofVec2f mouse);
};
