#pragma once

#include "ofMain.h"

class Astro {
public:
	ofImage mySprite;
	ofVec2f pos, vel;
	float Fa = 0; //Força de Atração
	float g = 0.1;
	float mass;

	Astro(ofVec2f aPosition, float aMass, string spriteName);

	void draw(float scale);
	void update(Astro other);
};