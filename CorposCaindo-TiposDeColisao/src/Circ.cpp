#include "Circ.h"

//--------------------------------------------------------------

Circ::Circ(ofVec2f pos, ofVec2f vel, float size) {
	myPos = pos;
	myVel = vel;
	mySize = size;

	positionToCollide.push_back(ofVec2f(myPos)); // Esquedo Cima
	positionToCollide.push_back(ofVec2f(myPos)); //Esquedo Baixo
	positionToCollide.push_back(ofVec2f(myPos)); //Direito Cima
	positionToCollide.push_back(ofVec2f(myPos)); //Direito Baixo
}

void Circ::update(float gravity) {

	LockOnScreen();

	if(!dragging)
		myVel += ofVec2f(0, gravity);


	myPos += myVel * ofGetLastFrameTime();

	positionToCollide.at(0) = ofVec2f(0, -mySize / 2); //Cima
	positionToCollide.at(1) = ofVec2f(0, +mySize / 2); //Baixo
	positionToCollide.at(2) = ofVec2f(-mySize / 2, 0); //Esquerda
	positionToCollide.at(3) = ofVec2f(+mySize / 2, 0); //Direita


	for(int i = 0; i < positionToCollide.size(); i++) {
		positionToCollide.at(i).rotate(myAngle);
		positionToCollide.at(i) += (myPos);
	}

}

void Circ::draw() {

	ofSetColor(0, 0, 255);

	ofPushMatrix();
	ofTranslate(myPos);
	ofRotateZ(myAngle);
	ofDrawCircle(0, 0, mySize / 2);
	ofPopMatrix();

	ofSetColor(255, 0, 0);
	for(int i = 0; i < positionToCollide.size(); i++)
		ofDrawCircle(positionToCollide.at(i), 3);

}

void Circ::CheckCollision(Body body) {

	//for(int i = 0; i < bodies.size(); i++) {
		//if(bodies.at(i) != this) {
	for(int i = 0; i < body.positionToCollide.size(); i++) {

		if((body.positionToCollide.at(i) - myPos).length() < mySize / 2) {
			myVel *= -1;
		}

	}
	//if((body.myPos - myPos).length() < (mySize / 2) + (body.mySize / 2)) {
		//myVel *= -1;
	//}
		//}
	//}
}

void Circ::MouseDragged(ofVec2f mouse, bool pressed) {

	if((mouse - myPos).length() < mySize && pressed) {

		dragging = true;
		ofVec2f distancia = mouse - myPos;
		myVel = (mouse - myPos).normalize() * 450;
		myAngle = ofRadToDeg(atan2f(distancia.y, distancia.x)) + 90;

	}

	else if(pressed == false) {
		dragging = false;

	}
}

//--------------------------------------------------------------
