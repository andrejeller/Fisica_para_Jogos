#pragma once

#include "ofMain.h"


class fireWork {

	struct circle {
		ofVec3f color;
		ofVec2f pos, vel;
		float size;
	};

public:

	bool exploded;

	float size = 4.0f;
	float gravity = 10.0f;
	float InitialTime, lifeTime;

	ofPath path;
	ofColor color;
	ofVec2f pos, vel, mouse;	
	
	vector <circle> fire;


	fireWork(ofVec2f initialPosition, float velocity, ofVec2f mouseClick);

	void update();
	void draw();

	void explode();

};
