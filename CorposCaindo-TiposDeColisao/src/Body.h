#pragma once

#include "ofMain.h"

class Body{

	public:

		float mySize, myAngle;
		ofVec2f myPos, myVel;
		bool dragging;
		vector <ofVec2f> positionToCollide;

		Body();
		Body(ofVec2f pos, ofVec2f vel, float size);


		void update(float gravity);	
		void LockOnScreen();

		
};
