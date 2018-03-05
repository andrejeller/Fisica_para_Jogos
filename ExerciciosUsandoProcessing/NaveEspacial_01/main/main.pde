Nave nave;

boolean clicked = true;
float TimeSincelastframe = 0.0f;

ArrayList <Tiro> tiro = new ArrayList<Tiro>();

void settings() {
  size(720, 640);
}

void setup() {
  nave = new Nave();
}

void draw() {
  background(0);

  float deltaTime = millis() - TimeSincelastframe;
  TimeSincelastframe = millis();


  if (mousePressed && clicked) {
    if (mouseButton == LEFT) {                
      nave.dir = new PVector (mouseX, mouseY);  
      nave.vel.x = (nave.dir.x - nave.pos.x)/0.5;
      nave.vel.y = (nave.dir.y - nave.pos.y)/0.5;      
    } 
    else if (mouseButton == RIGHT) {
      //nave.dir = new PVector (mouseX, mouseY); // Para ficar Divertido
      tiro.add(new Tiro(nave.pos.x, nave.pos.y, mouseX, mouseY));
    }
    clicked = false; //Para apenas pegar o clique do mouse, para não funcionar mais de uma ves se ele ficar pressionado
  }


  PVector mag = new PVector ((nave.dir.x - nave.pos.x), (nave.dir.y - nave.pos.y));

  if (mag.mag() <= 2) {
    nave.vel.x = 0;
    nave.vel.y = 0;
  } 
  
  for (int i = 0; i < tiro.size(); i++) {
    tiro.get(i).update();
    tiro.get(i).display(); 

    if (tiro.get(i).pos.x >= 720 || tiro.get(i).pos.x <= 0 || tiro.get(i).pos.y >= 640 || tiro.get(i).pos.y <= 0) {
      tiro.remove(i);
      //System.out.println("Removed");
    }
  }   
  nave.update(deltaTime);
  nave.display();
}

void mouseReleased() {
  clicked = true;
}