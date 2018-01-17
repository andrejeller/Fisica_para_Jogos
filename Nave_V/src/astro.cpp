#include "astro.h"

Astro::Astro(ofVec2f aPosition, float aMass, string spriteName) {
	pos = aPosition;
	mass = aMass;
	mySprite.load(spriteName);
	vel.set(0.6, 0);
}

void Astro::draw(float scale) {
	ofSetColor(255, 255, 255);

	ofPushMatrix();
	ofTranslate(pos.x, pos.y);
	mySprite.setAnchorPercent(0.5f, 0.5f);
	mySprite.draw(0, 0, mySprite.getWidth() * scale, mySprite.getHeight() * scale);
	ofPopMatrix();
}

void Astro::update(Astro other) {
	ofVec2f direction = other.pos - pos;
	float d = sqrt((pow(direction.x, 2) + pow(direction.y, 2)));

	if(d < 20.0f) d = 20.0f;
	if(d > 40.0f) d = 40.0f;


	Fa = (mass * other.mass * g) / pow(d, 2);


	ofVec2f force = direction.normalized() * Fa;
	ofVec2f acceleration = force / mass;

	pos += (vel + acceleration / 2.0f) * 5;
	vel += acceleration;
}



/*
Formula Quadro
F = P1 - P2;
d = mag(F); -- Tamanho do vetor
F1 = Normalize(F)

(G * M1 * M2) / d^2 = C;

Ft = (F1 * C);
.

ofVec2f F1 = f.normalize();
float c = 0;

if(d > 60.0f)
c = ((10) * mass * other.mass) / pow(d, 2);

ofVec2f Ft = F1 * c;

pos += Ft * vel * ofGetLastFrameTime();


/*
_path.curveTo(pos);
if(_pathTimer > 100) {
_path.clear();
_pathTimer = 0;
}
_pathTimer++;
*/