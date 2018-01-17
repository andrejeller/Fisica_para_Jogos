#include "firework.h"

fireWork::fireWork(ofVec2f initialPosition, float velocity, ofVec2f mouseClick) {
	//Inicializa Variaveis
	pos = initialPosition;
	mouse = mouseClick;
	vel = (mouseClick - initialPosition).normalized() * velocity;

	//Definindo Cor
	color.set(ofRandom(255), ofRandom(255), ofRandom(255), 255);

	//Definindo caracteristicas do path
	path.setFilled(false);
	path.setStrokeWidth(size - 1);
	path.setStrokeColor(color);

	//Inicializado como não explodido
	exploded = false;

	//Gardando Momento em que foi inicializado
	InitialTime = ofGetElapsedTimeMillis();
}

void fireWork::update() {
	//Calcula o tempo de vida
	lifeTime = ofGetElapsedTimeMillis() - InitialTime;

	//Enquanto ele não alcançar a altura do clique do mouse
	if(pos.y > mouse.y) {
		pos += vel * ofGetLastFrameTime();
		path.curveTo(pos);
	}
	//ao passar do y do mouse ele explode
	else if(pos.y < mouse.y && exploded == false) {
		explode();
		exploded = true;
	}
	else {
		//Atualiza todas as bolinhas do vetor
		for(int i = 0; i < fire.size(); i++) {
			fire.at(i).vel += fire.at(i).vel.normalized() * -1.7f * ofGetLastFrameTime(); //Resistencia ao ar
			fire.at(i).vel.y += gravity * ofGetLastFrameTime(); //Gravidade
			fire.at(i).pos += fire.at(i).vel * 5 * ofGetLastFrameTime(); //Força
		}
	}

}

void fireWork::draw() {
	ofSetColor(255, 255, 255);

	//Desenha circulo inicial
	if(pos.y > mouse.y) {
		ofSetColor(color);
		ofDrawCircle(pos, size);
		path.draw();
	}
	//Desenha bolinhas apos explosão
	else {
		for(int i = 0; i < fire.size(); i++) {
			//Caso queira ativas a cor aleatoria das bolinhas descomentar linha abaixo
			//ofSetColor(fire.at(i).color.x, fire.at(i).color.y, fire.at(i).color.z);
			ofSetColor(color);
			ofDrawCircle(fire.at(i).pos, fire.at(i).size);
		}
	}
}

void fireWork::explode() {
	//Cria entre 100 e 200 circulos no vetor
	int randCount = ofRandom(100, 200);

	for(int i = 0; i < randCount; i++) {
		circle newCircle;
		ofVec2f circleVelocity;
		
		circleVelocity.set(ofRandom(-10, 10), ofRandom(-10, 10));

		while((ofVec2f(0, 0) + circleVelocity).length() > 10) {
			circleVelocity.set(ofRandom(-10, 10), ofRandom(-10, 10));
		}

		newCircle.pos = pos;
		newCircle.size = ofRandom(0.2f, 2.5f);
		newCircle.vel.set(circleVelocity);
		newCircle.color.set(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));

		fire.push_back(newCircle);
	}

}
