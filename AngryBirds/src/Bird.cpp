#include "Bird.h"


Bird::Bird(int posX, int posY, float birdMass, bool isLeftPlayer, string spriteName) {
	mass = birdMass;
	isMoving = false;
	pos.set(posX, posY);
	mySprite.load(spriteName);
	LeftPlayer = isLeftPlayer;
}

void Bird::draw() {
	ofSetColor(255, 255, 255);

	ofPushMatrix();
	ofTranslate(pos.x, pos.y);
	mySprite.setAnchorPercent(0.5f, 0.5f);
	if(LeftPlayer) mySprite.draw(0, 0, mySprite.getWidth(), mySprite.getHeight());
	else if(!LeftPlayer) mySprite.draw(0, 0, mySprite.getWidth() * -1.0f, mySprite.getHeight());
	ofPopMatrix();
}

void Bird::update() {
	if(isMoving) {
		//Faz o player permanecer na tela //Incluindo comando para "quicar" no chão		
		LockOnScreen();

		//Aplica a gravidade a velocidade atual do alien
		//float acceleration = gravity / mass;
		//vel.set(vel.x, vel.y - acceleration * ofGetLastFrameTime());

		//Adiciona a posição a velocidade multiplicada pelo deltaTime
		pos += vel * ofGetLastFrameTime();
	}
}

void Bird::applyForce(ofVec2f force) {
	//isMoving = true;
	float accelerationX = force.x / mass;
	float accelerationY = force.y / mass;

	//Multiplicar Pelo Tempo aqui tambem ?
	vel.x += accelerationX; // * ofGetLastFrameTime();
	vel.y += accelerationY; // * ofGetLastFrameTime();
}

void Bird::LockOnScreen() {
	if(pos.x <= 50) {
		pos.x = 50;
		vel.x = -vel.x * 0.7f; // Para Diminuir a vel constantemente em 70%
	}
	if(pos.x > ofGetWidth() - mySprite.getWidth()) {
		pos.x = ofGetWidth() - 50;
		vel.x = -vel.x * 0.7f; // Para Diminuir a vel constantemente em 70%
	}
	if(pos.y <= 30)
		pos.y = 30;

	if(pos.y > ofGetHeight() - mySprite.getHeight() + 10) {
		//pos.y = ofGetHeight() - 100;
		vel.y = -vel.y * 0.7f; // Para Diminuir a vel constantemente em 70%
		if(vel.x > 0) vel.x -= 0.05 * mass; // Atrito
		if(vel.x < 0) vel.x += 0.05 * mass; // Atrito
	}
}

void Bird::Reset(int x, int y) {
	pos.set(x, y);
	vel.set(0, 0);
	isMoving = false;
}
