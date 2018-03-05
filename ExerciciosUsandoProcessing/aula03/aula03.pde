Spaceship ship;

void settings(){
  size(640, 480);
}

void setup(){
  ship = new Spaceship();
}

float timeSinceLastFrame = 0;
void draw(){
  float deltaTime = millis() - timeSinceLastFrame;
  timeSinceLastFrame = millis();
  ship.pos = new PVector(mouseX, mouseY);
  if (mousePressed){
    if (mouseButton == LEFT){
      noCursor();
    }
    else if (mouseButton == RIGHT){
      cursor();
    }
  }
  
  background(0);
  ship.update(deltaTime);
  ship.display();
}