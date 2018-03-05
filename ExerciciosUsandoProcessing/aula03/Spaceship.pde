class Spaceship{
  PVector pos, vel;
  PImage img;
  float angle = PI;
  
  Spaceship(){
    pos = new PVector(300, 300);
    img = loadImage("playerShip1_red.png");
  }
  
  void update(float deltaTime){
    angle += 0.001 * deltaTime;
  }
  
  void display(){
    pushMatrix();
    translate(pos.x, pos.y);
    rotate(angle);
    image(img, - img.width/2, -img.height/2);
    popMatrix();
  }

}