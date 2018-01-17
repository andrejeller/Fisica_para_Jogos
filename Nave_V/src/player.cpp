#include "player.h"

Player::Player(ofVec2f position, float mass, string spriteName) {
	pos = position;
	this->mass = mass;
	mySprite.load(spriteName);
	vel.set(2, 0);
}

void Player::draw() {
	ofSetColor(255, 255, 255);

	ofPushMatrix();
	ofTranslate(pos.x, pos.y);
	mySprite.setAnchorPercent(0.5f, 0.5f);
	mySprite.draw(0, 0, mySprite.getWidth() / 2, mySprite.getHeight() / 2);
	ofPopMatrix();
}

void Player::update(Astro other) {

	LockOnScreen();
	
	ofVec2f direction = other.pos - pos;
	float d = sqrt((pow(direction.x, 2) + pow(direction.y, 2)));

	if(d < 20.0f) d = 20.0f;
	if(d > 40.0f) d = 40.0f;


	Fa = (mass * other.mass * g) / pow(d, 2);


	ofVec2f force = direction.normalized() * Fa;
	ofVec2f acceleration = force / mass;
	
	vel += acceleration;
	pos += vel * 35 * ofGetLastFrameTime();	
	pos += impulso * ofGetLastFrameTime();
}


void Player::LockOnScreen() {
	if(pos.x <= 30)
		pos.x = 30;

	if(pos.x > ofGetWidth() - 30)
		pos.x = ofGetWidth() - 30;

	if(pos.y <= 30)
		pos.y = 30;

	if(pos.y > ofGetHeight() - 30)
		pos.y = ofGetHeight() - 30;
}

void Player::OnMouseDown(ofVec2f mouse) {
	ofVec2f direction = mouse - pos;
	impulso = direction.normalize() * 300;
}