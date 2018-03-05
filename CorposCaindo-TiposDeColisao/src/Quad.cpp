#include "Quad.h"

//--------------------------------------------------------------

Quad::Quad(ofVec2f pos, ofVec2f vel, float size) {
	myPos = pos;
	myVel = vel;
	mySize = size;
	

	positionToCollide.push_back(ofVec2f(- mySize / 2, - mySize / 2)); // Esquedo Cima
	positionToCollide.push_back(ofVec2f(- mySize / 2, + mySize / 2)); //Esquedo Baixo
	positionToCollide.push_back(ofVec2f(+ mySize / 2, - mySize / 2)); //Direito Cima
	positionToCollide.push_back(ofVec2f(+ mySize / 2, + mySize / 2)); //Direito Baixo
}

void Quad::update(float gravity) {

	LockOnScreen();

	if(!dragging)
		myVel += ofVec2f(0, gravity);



	myPos += myVel * ofGetLastFrameTime();

	

	positionToCollide.at(0) = ofVec2f(-mySize / 2, -mySize / 2);
	positionToCollide.at(1) = ofVec2f(-mySize / 2, +mySize / 2);
	positionToCollide.at(2) = ofVec2f(+mySize / 2, -mySize / 2);
	positionToCollide.at(3) = ofVec2f(+mySize / 2, +mySize / 2);


	for(int i = 0; i < positionToCollide.size(); i++) {
		//positionToCollide.at(i).rotate(myAngle);		
		positionToCollide.at(i) += (myPos);
	}


}

void Quad::draw() {
	ofSetColor(255, 255, 0);

	ofPushMatrix();
	ofTranslate(myPos);
	//ofRotateZ(myAngle);
	ofDrawRectangle(- mySize / 2, - mySize / 2, mySize, mySize);
	ofPopMatrix();


	ofSetColor(255, 0, 0);
	for(int i = 0; i < positionToCollide.size(); i++)
		ofDrawCircle(positionToCollide.at(i), 3);



}

void Quad::CheckCollision(Body body) {

	for(int i = 0; i < body.positionToCollide.size(); i++) {

		//if((mouse.x > myPos.x - mySize / 2) && (mouse.x < myPos.x + mySize / 2) &&
			//(mouse.y > myPos.y - mySize / 2) && (mouse.y < myPos.x + mySize / 2) && pressed)

		if(body.positionToCollide.at(i).x > positionToCollide.at(0).x && body.positionToCollide.at(i).y > positionToCollide.at(0).y
		   && body.positionToCollide.at(i).x > positionToCollide.at(1).x && body.positionToCollide.at(i).y < positionToCollide.at(1).y
		   && body.positionToCollide.at(i).x < positionToCollide.at(2).x && body.positionToCollide.at(i).y > positionToCollide.at(2).y
		   && body.positionToCollide.at(i).x < positionToCollide.at(3).x && body.positionToCollide.at(i).x < positionToCollide.at(3).x) {
			myVel *= -1;
		}

	}

}

void Quad::MouseDragged(ofVec2f mouse, bool pressed) {
	if((mouse.x > myPos.x - mySize / 2) && (mouse.x < myPos.x + mySize / 2) &&
		(mouse.y > myPos.y - mySize / 2) && (mouse.y < myPos.x + mySize / 2) && pressed) {
				
		dragging = true;
		ofVec2f distancia = mouse - myPos;
		myVel = (mouse - myPos).normalize() * 450;				
		myAngle = ofRadToDeg(atan2f(distancia.y, distancia.x)) + 90;

	}

	else if(pressed == false) {
		dragging = false;
		//myVel = (mouse - myPos).normalize() * 20;
	}
}

//--------------------------------------------------------------
