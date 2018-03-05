class Tiro {

  PVector pos, vel, direcao;
  PImage img;
  float angle;

  Tiro(float x, float y, float pmseX, float pmseY) {
    img = loadImage("ufoYellow.png");
    pos = new PVector(x, y);  
    direcao = new PVector(pmseX, pmseY);
    vel = new PVector(pmseX - x, pmseY - y);
  }

  void update() {
    vel.normalize();
    pos.x += vel.x * 10;
    pos.y += vel.y * 10;
  }

  void display() {
    pushMatrix();
    translate(pos.x, pos.y);
    image(img, -img.width/2, -img.height/2);
    popMatrix();
  }
}