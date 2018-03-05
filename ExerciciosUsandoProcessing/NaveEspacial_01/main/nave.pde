class Nave {

  PVector pos, vel, dir;
  PImage img;
  float ang;

  Nave() {
    img = loadImage("playerShip1_red.png");    
    pos = new PVector(360, 320);  
    dir = new PVector(0, 0);
    vel = new PVector(0, 0);
  }  

  void update(float deltaTime) {          
    deltaTime *= 0.001;
    
    //pos.x = lerp(pos.x, moveTo.x, 0.5f); 
    //pos.y = lerp(pos.y, moveTo.y, 0.5f);
        
    pos.x += vel.x * deltaTime;
    pos.y += vel.y * deltaTime;
    
    //float newAng = (atan2(dir.y - pos.y, dir.x - pos.x) + (PI/2)) / deltaTime * 0.1;  
    
    ang = (atan2(dir.y - pos.y, dir.x - pos.x) + (PI/2));
    System.out.println(ang);
    
  }
  float gTime = 0;
  void girar(float deltaTime){
    /* (Novo Ang - Meu ang) / 0.1 * deltaTime 
    
    */
    
    float newAng = (atan2(dir.y - pos.y, dir.x - pos.x) + (PI/2)); // deltaTime * 0.1
    float goTo = newAng - ang / deltaTime * 0.1;
    if (newAng != ang) gTime = 0.1;
    if (gTime > 0){
       
    }
    
    
  }

  void display() {
    pushMatrix();
    translate(pos.x, pos.y);
    rotate(ang);
    image(img, -img.width/2, -img.height/2);
    popMatrix();
  }
}