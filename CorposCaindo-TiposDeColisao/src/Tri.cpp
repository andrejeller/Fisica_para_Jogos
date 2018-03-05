#include "Tri.h"

//--------------------------------------------------------------

Tri::Tri(ofVec2f pos, ofVec2f vel, float size) {
	myPos = pos;
	myVel = vel;
	mySize = size;

	positionToCollide.push_back(ofVec2f(myPos.x, myPos.y - mySize / 2)); // Esquedo Cima
	positionToCollide.push_back(ofVec2f(myPos.x + mySize / 2, myPos.y + mySize / 2)); //Esquedo Baixo
	positionToCollide.push_back(ofVec2f(myPos.x - mySize / 2, myPos.y + mySize / 2)); //Direito Cima

}

void Tri::update(float gravity) {

	//Garante que ficara na tela
	LockOnScreen();

	//Se não estiver sendo movido ele recebe a gravidade
	if(!dragging)
		myVel += ofVec2f(0, gravity);

	//Atualiza posição com a
	myPos += myVel * ofGetLastFrameTime();

	//"Reinicia" as posicoes
	max = ofVec2f(0, ofGetHeight());
	min = ofVec2f(ofGetWidth(), 0);

	//"Reinicia" as posicoes para a origem do sist
	positionToCollide.at(0) = (ofVec2f(0, -mySize / 2)); // Esquedo Cima	
	positionToCollide.at(1) = (ofVec2f(+mySize / 2, +mySize / 2)); //Esquedo Baixo	
	positionToCollide.at(2) = (ofVec2f(-mySize / 2, +mySize / 2)); //Direito Cima

	//Rotaciona e depois adiciona a posicao do "player"
	for(int i = 0; i < positionToCollide.size(); i++) {
		positionToCollide.at(i).rotate(myAngle);
		positionToCollide.at(i) += (myPos);
	}

	//Faz comparacao para saber quel dos pontos de colisao esta mais acima, baixa, ao lado
	for(int i = 0; i < positionToCollide.size(); i++) {

		if(positionToCollide.at(i).x > max.x)
			max.x = positionToCollide.at(i).x;

		if(positionToCollide.at(i).x < min.x)
			min.x = positionToCollide.at(i).x;

		if(positionToCollide.at(i).y < max.y)
			max.y = positionToCollide.at(i).y;

		if(positionToCollide.at(i).y > min.y)
			min.y = positionToCollide.at(i).y;

	}

}

void Tri::draw() {
	ofSetColor(0, 255, 255);

	ofPushMatrix();
	ofTranslate(myPos);
	ofRotateZ(myAngle);
	ofDrawTriangle(ofVec2f(0, -mySize / 2), ofVec2f(+mySize / 2, +mySize / 2), ofVec2f(-mySize / 2, +mySize / 2));
	ofPopMatrix();


	ofSetColor(255, 0, 0);
	for(int i = 0; i < positionToCollide.size(); i++)
		ofDrawCircle(positionToCollide.at(i), 3);

	ofVec2f upLeft = ofVec2f(min.x, min.y - mySize);
	ofVec2f downRigth = ofVec2f(max.x, max.y + mySize);

	ofDrawLine(min, upLeft);
	ofDrawLine(upLeft, max);
	ofDrawLine(max, downRigth);
	ofDrawLine(downRigth, min);

}

void Tri::CheckCollision(Body body) {
	for(int i = 0; i < body.positionToCollide.size(); i++) {

		if(body.positionToCollide.at(i).x < max.x && body.positionToCollide.at(i).x > min.x &&
		   body.positionToCollide.at(i).y < min.y && body.positionToCollide.at(i).y > max.y)

			myVel *= -1;
	}
}

void Tri::MouseDragged(ofVec2f mouse, bool pressed) {

	if(mouse.x < max.x && mouse.x > min.x &&
	   mouse.y < min.y && mouse.y > max.y) {

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
