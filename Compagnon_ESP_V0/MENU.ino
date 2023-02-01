void menu(void){
  Serial.println("void menu(void)");
  unsigned char index_action = 0;
  unsigned char item_inverted = 0;
  const String liste_action_menu1[] PROGMEM ={"-Change Mode","-visage","-Sound ON/OFF","-LED ON/OFF"};
  const String liste_action_menu2[] PROGMEM ={"-temperature","-Change Time","-Crono","-Info"};
  
  while(draw_menu == 1){//variable affichage du menu
    display.clearDisplay();
    menu_back("MENU",55);

    //Mesure de la battrie
    
    display.setCursor(100,10);
    display.print(pourcent_bat());
    display.print("%");
    
    for(int i = 0 ; i<4 ; i++){
      display.setTextColor(SSD1306_WHITE);
      if(item_inverted == i)display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
      display.setCursor(1,i*9+10);
      if(index_action < 4){
        display.println(liste_action_menu1[i]); 
      }
      else if(index_action < 8){
        display.println(liste_action_menu2[i]); 
      }          
    }
    display.display();
      
    if (digitalRead(BP2) == HIGH){
        if(sound == true)tone(5,2000,100);
        Serial.println("BP2 MENU");
        while((digitalRead(BP2) == HIGH));
        action_menu(index_action);
    }  
    
    if(digitalRead(BP1) == HIGH){
      Serial.println("BP1 MENU");
      item_inverted++;
      index_action++;
      if (index_action > nbr_item_menu){
        index_action=0; 
        item_inverted = 0;
     }
     if (item_inverted >= 4){
      item_inverted = 0;
     }
     
    //if(sound == true)tone(5,1000,100);
      delay(110);
    }
    
    if (digitalRead(BP3) == HIGH){ 
      Serial.println("BP3 MENU");
      //if(sound == true)tone(PIN_BUZZER, NOTE_C4, 500, 0);   
      draw_menu = 0;
      while((digitalRead(BP3) == HIGH));
      index_action=0; 
      item_inverted = 0;
      delay(110);
    } 
  }
}

unsigned char action_menu(unsigned char action){
  Serial.println("unsigned char action_menu(unsigned char action)");
   switch(action){
    case 0:
      choix_mode();
    break;
    case 1:
      visage();
    break;
    case 2:
       mute_fonc();
    break;
    case 3:
       led_state = !led_state;
       digitalWrite(LED,led_state);
    break; 
    case 4:   
       Print_temp();
    break; 
    case 5:   
       reglage = 1;
        print_time(); 
    break; 
    case 6:
        crono();
    break;
    case 7:
      Print_info();
     break;
    }
    return 0;
}

void menu_back(String nom,int correcteur){
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.drawLine(0, 8, 128,8, SSD1306_WHITE);
  display.setCursor(correcteur,0);
  display.println(nom);
  display.setCursor(10,55);
  display.write(25);
  display.setCursor(60,55);
  display.write("ok");
  display.setCursor(100,54);
  display.write(27);
}

void reg_back(void){
 
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10,55);
  display.println("-");
  display.setCursor(60,55);
  display.println("ok");
  display.setCursor(115,55);
  display.println("+");  
}
