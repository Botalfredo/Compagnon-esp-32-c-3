//================================================================
//  ____  _ _                         
// |  _ \(_) |                        
// | |_) |_| |_ _ __ ___   __ _ _ __  
// |  _ <| | __| '_ ` _ \ / _` | '_ \ 
// | |_) | | |_| | | | | | (_| | |_) |
// |____/|_|\__|_| |_| |_|\__,_| .__/ 
//                             | |    
//                             |_|   
//================================================================

void draw_face_1(unsigned char pos){
  display.clearDisplay();
  display.drawBitmap(9, 6+pos, oeuil, 33,32, SSD1306_WHITE);
  display.drawBitmap(128-(33+9), 6+pos, oeuil, 33,32, SSD1306_WHITE);
  display.drawBitmap(46, 42, bouche, 37,15, SSD1306_WHITE);
  display.drawBitmap(12, 45, tache, 18,12, SSD1306_WHITE);
  display.drawBitmap(128-(18+12), 45, tache, 18,12, SSD1306_WHITE);
  display.display();
  }


void draw_face_2(unsigned char pos){
  display.clearDisplay();
  display.drawBitmap(9, 6+pos, oeuil, 33,32, SSD1306_WHITE);
  display.drawBitmap(128-(33+9), 6+pos, oeuil, 33,32, SSD1306_WHITE);
  display.drawBitmap(50, 42, bouche2, 32,19, SSD1306_WHITE);
  display.drawBitmap(12, 45, tache, 18,12, SSD1306_WHITE);
  display.drawBitmap(128-(18+12), 45, tache, 18,12, SSD1306_WHITE);
  display.display();
  }

void draw_face_3(unsigned char pos){
  display.clearDisplay();
  display.drawBitmap(9, 6+pos, oeuil, 33,32, SSD1306_WHITE);
  display.drawBitmap(128-(33+9), 6+pos, oeuil, 33,32, SSD1306_WHITE);
  display.drawBitmap(47, 41, bouche5, 30,13, SSD1306_WHITE);
  display.drawBitmap(12, 45, tache, 18,12, SSD1306_WHITE);
  display.drawBitmap(128-(18+12), 45, tache, 18,12, SSD1306_WHITE);
  display.display();
  }

void draw_face_4(unsigned char pos){
  display.clearDisplay();
  display.drawBitmap(9, 6+pos, oeuil, 33,32, SSD1306_WHITE);
  display.drawBitmap(128-(33+9), 6+pos, oeuil, 33,32, SSD1306_WHITE);
  display.drawBitmap(47, 41, bouche6, 30,13, SSD1306_WHITE);
  display.drawBitmap(12, 45, tache, 18,12, SSD1306_WHITE);
  display.drawBitmap(128-(18+12), 45, tache, 18,12, SSD1306_WHITE);
  display.display();
  }

void draw_face_5(unsigned char pos){
  display.clearDisplay();
  display.drawBitmap(9, 10+pos, oeuil2, 33,20, SSD1306_WHITE);
  display.drawBitmap(128-(34+9), 10+pos, oeuil2, 33,20, SSD1306_WHITE);
  display.drawBitmap(47, 41, bouche6, 30,13, SSD1306_WHITE);
  display.drawBitmap(12, 45, tache, 18,12, SSD1306_WHITE);
  display.drawBitmap(128-(18+12), 45, tache, 18,12, SSD1306_WHITE);
  display.display();
  }
