#include "Body.h"


Body::Body() {

	myAngle = 0;
	mySize = 20;
	myVel = myPos;
	dragging = false;
	myPos.set(ofGetWidth() / 2, ofGetHeight() / 2);
}

//--------------------------------------------------------------

Body::Body(ofVec2f pos, ofVec2f vel, float size) {
	mySize = size;
	myPos = pos;
	myVel = vel;
	dragging = false;
}

//--------------------------------------------------------------

void Body::update(float gravity) {
	LockOnScreen();

	if(!dragging)
		myVel += ofVec2f(0, gravity);


	myPos += myVel * ofGetLastFrameTime();


	if(positionToCollide.size() > 0) {
		for(int i = 0; i < positionToCollide.size(); i++)
			positionToCollide.at(i) += myPos;
	}


}

//--------------------------------------------------------------

void Body::LockOnScreen() {
	/*
	if(positionToCollide.size() > 0) {
		for(int i = 0; i < positionToCollide.size(); i++) {
			/*
			if(positionToCollide.at(i).x <= 50) {
				myPos.x = 50;
				myVel.x = -myVel.x * 0.7f;
			}

			
			if(positionToCollide.at(i).x > ofGetWidth() - mySize / 2) {
				myPos.x = ofGetWidth() - mySize / 2;
				myVel.x = -myVel.x * 0.7f;
			}
			
			
			//if(positionToCollide.at(i).y <= 30)
				//.y = 30;

			if(positionToCollide.at(i).y > ofGetHeight() - 50) {
				myPos.y = ofGetHeight() - (50 + mySize / 2);
				myVel.y = -myVel.y * 0.7f;

				if(myVel.x > 0) myVel.x -= 0.05f; // Atrito
				if(myVel.x < 0) myVel.x += 0.05f; // Atrito

			}
			
		}

	}
	*/
	if(myPos.x <= 50) {
		myPos.x = 50;
		myVel.x = -myVel.x * 0.7f;
	}

	if(myPos.x > ofGetWidth() - mySize / 2) {
		myPos.x = ofGetWidth() - mySize / 2;
		myVel.x = -myVel.x * 0.7f;
	}

	if(myPos.y <= 30)
		myPos.y = 30;

	if(myPos.y + mySize / 2 > ofGetHeight() - 50) {
		myPos.y = ofGetHeight() - 50 - mySize / 2;
		myVel.y = -myVel.y * 0.7f;

		if(myVel.x > 0) myVel.x -= 0.05f; // Atrito
		if(myVel.x < 0) myVel.x += 0.05f; // Atrito

	}
	
}
