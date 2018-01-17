#include "player.h"

Player::Player(int posX, int posY, string spriteName) {
	pos.set(posX, posY);
	mySprite.load(spriteName);
}

void Player::draw() {
	ofSetColor(255, 255, 255);

	ofPushMatrix();
	ofTranslate(pos.x, pos.y);
	mySprite.setAnchorPercent(0.5f, 0.5f);
	mySprite.draw(0, 0, mySprite.getWidth(), mySprite.getHeight());
	ofPopMatrix();
}

void Player::update(float gravity) {
	//Faz com que o alien permaneça na tela
	//Incluindo comando para "quicar" no chão
	LockOnScreen();

	//Aplica a gravidade a velocidade atual do alien
	vel.set(vel.x, vel.y - gravity);

	//Adiciona a posição a velocidade multiplicada pelo deltaTime
	pos += vel * ofGetLastFrameTime();		
}


void Player::LockOnScreen() {
	if(pos.x <= 50) {
		pos.x = 50;
		vel.x = -vel.x; //* 0.7f; // Para Diminuir a vel constantemente em 70%
	}
	if(pos.x > ofGetWidth() - 50) {
		pos.x = ofGetWidth() - 50;
		vel.x = -vel.x; //* 0.7f; // Para Diminuir a vel constantemente em 70%
	}
	if(pos.y <= 50)
		pos.y = 50;
	if(pos.y > ofGetHeight() - 100) {
		pos.y = ofGetHeight() - 100;
		vel.y = -vel.y;// * 0.7f; // Para Diminuir a vel constantemente em 70%
	}
}

void Player::OnMouseDown(int mouseX, int mouseY) {
	if(mouseY < pos.y) {

		//Compara se Clicou para esquerda ou direit
		//e faz seu impulso relativo 
		float impulsoX;
		if(mouseX > pos.x)
			impulsoX = 100;
		else
			impulsoX = -100;

		//Aplica o impulso a velocidade (sempre para cima);
		vel.set(impulsoX, -150);
	}
}