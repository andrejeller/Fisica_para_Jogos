#pragma once

#include "Body.h"

class Quad : public Body{

	public:
		Quad(ofVec2f pos, ofVec2f vel, float size);

		void update(float gravity);

		void draw();


		void CheckCollision(Body body);
		void MouseDragged(ofVec2f mouse, bool pressed);
};
