#pragma once

#include "Body.h"

class Circ : public Body{

	public:
		Circ(ofVec2f pos, ofVec2f vel, float size);

		void update(float gravity);

		void draw();


		//void CheckCollision(vector <Body> bodies);
		void CheckCollision(Body body);
		void MouseDragged(ofVec2f mouse, bool pressed);
};
