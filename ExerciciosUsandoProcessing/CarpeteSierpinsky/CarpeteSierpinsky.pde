int w = 720;
int h = 640;
int border = 20;
int depth = 6;

void settings(){  
  size(w, h);
}

void setup() {
  smooth();
  noLoop();
}

void draw(){  
  background(255);
  fill(0);
  noStroke();
  fill(250,190,0);
  rect(border, border, w - border - border, h - border - border);
  
  drawQuadSierpinsky(0, depth, new PVector(border, border), new PVector(width - border, border), new PVector(border, h-border), new PVector(width - border, h-border));
}

void drawQuadSierpinsky(int level, int maxLevels, PVector l_t, PVector r_t, PVector l_b, PVector r_b){

  level++;

  if (level > maxLevels) {
    return;
  }
  
  fill(255);
        
  PVector a = PVector.add(l_b, PVector.div(PVector.sub(l_t, l_b), 3));
  PVector b = PVector.add(l_t, PVector.div(PVector.sub(r_t, l_t), 3));
  PVector c = PVector.add(r_t, PVector.div(PVector.sub(r_b, r_t), 3));
  PVector d = PVector.add(r_b, PVector.div(PVector.sub(l_b, r_b), 3));
  
  quad( b.x, c.y, 
        d.x, c.y, 
        d.x, a.y, 
        b.x, a.y);

  //left top
  drawQuadSierpinsky(level, depth, l_t, 
                                  b, 
                                  new PVector(a.x, c.y), 
                                  new PVector(b.x, c.y));
                                  
  //mid top
  drawQuadSierpinsky(level, depth, b, 
                                  new PVector(d.x, b.y), 
                                  new PVector(b.x, c.y), 
                                  new PVector(d.x, c.y));
                                  
  // top right
  drawQuadSierpinsky(level, depth, new PVector(d.x, b.y), 
                                  r_t, 
                                  new PVector(d.x, c.y), 
                                  c);               
                                  
  // mid right
  drawQuadSierpinsky(level, depth, new PVector(d.x, c.y), 
                                  c, 
                                  new PVector(d.x, a.y), 
                                  new PVector(c.x, a.y));
                                  
  // bottom right
  drawQuadSierpinsky(level, depth, new PVector(d.x, a.y), 
                                  new PVector(c.x, a.y), 
                                  d, 
                                  r_b);  
  
  // bottom mid
  drawQuadSierpinsky(level, depth, new PVector(b.x, a.y), 
                                  new PVector(d.x, a.y), 
                                  new PVector(b.x, d.y), 
                                  d);
                                  
  // bottom left
  drawQuadSierpinsky(level, depth, a, 
                                  new PVector(b.x, a.y), 
                                  l_b, 
                                  new PVector(b.x, d.y));
  
  // mid left
  drawQuadSierpinsky(level, depth, new PVector(a.x, c.y), 
                                  new PVector(b.x, c.y), 
                                  a, 
                                  new PVector(b.x, a.y));

}