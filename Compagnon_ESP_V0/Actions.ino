void choix_mode(void){
  unsigned char choix_mode_act = 1; 
  while(choix_mode_act == 1){
    display.clearDisplay();
    menu_back("Change Mode",30);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    
    if (mode == 1){
      display.setCursor(36,20);
      display.println("Watch");
      }
    else if (mode == 0){
      display.setCursor(10,20);
      display.println("Compagnon");
      }
    else {
      display.setCursor(25,20);
      display.println("ERROR");
    }
    display.display(); 
     
    if (digitalRead(BP1) == HIGH){
      mode++;
      if(mode>1)mode=0;
      delay(110);
    }  
    if(digitalRead(BP2) == HIGH){
     choix_mode_act = 0;
     draw_menu = 0;
     while((digitalRead(BP1) == HIGH));
     delay(110);
     Serial.println("Set mode");
    EEPROM.write(5, mode);
    EEPROM.commit();
    }
    if (digitalRead(BP3) == HIGH){    
     choix_mode_act = 0;
     while((digitalRead(BP3) == HIGH));
     delay(110);
     Serial.println("Set mode");
     EEPROM.write(5, mode);
     EEPROM.commit();
    }
    
    }
}

void print_time(void){
  // déclaration des variables de temps
  static unsigned char jours   = rtc.getDay();
  static unsigned char mois    = rtc.getMonth()+1;
  static unsigned char heure   = rtc.getHour(true); 
  static unsigned char minut   = rtc.getMinute();
  static unsigned char seconde = rtc.getSecond();
  static unsigned int  annee   = rtc.getYear();

  do{
    display.clearDisplay();
    if(reglage != 0 )reg_back(); 
   
    display.setTextSize(2);      // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE); // Draw white text
    display.setCursor(14, 10);     // Start at top-left corner

    if(reglage == 1){
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
      if(heure<10)display.print('0');
      display.print(heure);
      display.setTextColor(SSD1306_WHITE); // Draw white text
    }
    else{
      if(rtc.getHour(true)<10)display.print('0');
      display.print(rtc.getHour(true));
      }
    display.print(':');
  
    if(reglage == 2){
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
      if(minut<10)display.print('0');
      display.print(minut);
      display.setTextColor(SSD1306_WHITE); // Draw white text
    }
    else{
      if(rtc.getMinute()<10)display.print('0');
      display.print(rtc.getMinute());
      }
    display.print(':'); 
 
    if(reglage == 3){
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
      if(seconde<10)display.print('0');
      display.print(seconde);
      display.setTextColor(SSD1306_WHITE); // Draw white text
    }
    else{
      if(rtc.getSecond()<10)display.print('0');
      display.print(rtc.getSecond());
      }
    display.setCursor(5, 30);     // Start at top-left corner
  
    if(reglage == 4){
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
      if(jours<10)display.print('0');
      display.print(jours);
      display.setTextColor(SSD1306_WHITE); // Draw white text
    }
    else{
      if(rtc.getDay()<10)display.print('0');
      display.print(rtc.getDay());
      }  
    display.print('/');
  
    if(reglage == 5){
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
      if(mois<10)display.print('0');
      display.print(mois);
      display.setTextColor(SSD1306_WHITE); // Draw white text
    }
    else{
      if(rtc.getMonth()+1<10)display.print('0');
      display.print(rtc.getMonth()+1);
      } 
    display.print('/');
  
    if(reglage == 6){
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
      display.print(annee);
      display.setTextColor(SSD1306_WHITE);
    }
    else{
      display.print(rtc.getYear());
      }  
    display.display();
  
   if (reglage != 0){
    if (digitalRead(BP1) == HIGH){
       switch(reglage){
          case(1): heure=constrain(heure-1,0,23);break;
          case(2): minut=constrain(minut-1,0,59);break;          
          case(3): seconde=constrain(seconde-1,0,59);break;
          case(4): jours=constrain(jours-1,1,59);break;
          case(5): mois=constrain(mois-1,1,60); break;
          case(6): annee=constrain(annee-1,2022,2100);break;         
      }
    delay(80);
    }  
    if(digitalRead(BP2) == HIGH){
      if (sound == true)tone(5, 500, 100);
      Serial.println(rtc.getMonth());
      Serial.println(mois);
      switch(reglage){
        case(1):
          rtc.setTime(rtc.getSecond(),rtc.getMinute(),heure,rtc.getDay(),rtc.getMonth()+1,rtc.getYear());
          reglage = 2;
        break;
        case(2):
          rtc.setTime(rtc.getSecond(),minut,rtc.getHour(true),rtc.getDay(),rtc.getMonth()+1,rtc.getYear());
          reglage = 3;
        break;          
        case(3):
          rtc.setTime(seconde,rtc.getMinute(),rtc.getHour(true),rtc.getDay(),rtc.getMonth()+1,rtc.getYear());
          reglage = 4;
        break;
        case(4):
          rtc.setTime(rtc.getSecond(),rtc.getMinute(),rtc.getHour(true),jours,rtc.getMonth()+1,rtc.getYear());
          reglage = 5;
        break;
        case(5):
          rtc.setTime(rtc.getSecond(),rtc.getMinute(),rtc.getHour(true),rtc.getDay(),mois,rtc.getYear());
          reglage = 6;
        break;
        case(6):
          rtc.setTime(rtc.getSecond(),rtc.getMinute(),rtc.getHour(true),rtc.getDay(),rtc.getMonth()+1,annee);
          reglage = 0;
        break;           
        }   
        delay(200);   
    }
    if (digitalRead(BP3) == HIGH){   
      if (sound == true)tone(5, 500, 100); 
        switch(reglage){
          case(1): heure=constrain(heure+1,0,23); break;
          case(2): minut=constrain(minut+1,1,60); break;          
          case(3): seconde=constrain(seconde+1,1,60);break;
          case(4): jours=constrain(jours+1,1,31); break;
          case(5): mois=constrain(mois+1,1,12); break;
          case(6): annee=constrain(annee+1,2021,3000); break;      
          }
        delay(80);
      }
    }
  }while(reglage != 0);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  delay(2);
}

void choix_oui_non(void){
  unsigned char rando = random(0,2);
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(40,20);    
  switch(rando){
    case 0:    
    display.println("NON");
    break;
    case 1:
    display.println("OUI");  
    break;
    }
   display.display(); 
   delay(200);
}

//
//void musique(void){
//  tone(PIN_BUZZER, 2637, 200);
//  delay(400);
//  tone(PIN_BUZZER, 1975, 200);
//  delay(200);
//  tone(PIN_BUZZER, 2093, 200);
//  delay(200);
//  tone(PIN_BUZZER, 2349, 200);
//  delay(400);
//  tone(PIN_BUZZER, 2093, 200);
//  delay(200);
//  tone(PIN_BUZZER, 1975, 200);
//  delay(200);
//  tone(PIN_BUZZER, 1760, 200);
//  delay(400);
//  tone(PIN_BUZZER, 1760, 200);
//  delay(200);
//  tone(PIN_BUZZER, 2093, 200);
//  delay(200);
//  tone(PIN_BUZZER, 2637, 200);
//  delay(400);
//  tone(PIN_BUZZER, 2349, 200);
//  delay(200);
//  tone(PIN_BUZZER, 2093, 200);
//  delay(200);
//  tone(PIN_BUZZER, 1975, 200);
//  delay(400);
//  tone(PIN_BUZZER, 1975, 200);
//  delay(200);
//  tone(PIN_BUZZER, 2093, 200);
//  delay(200);
//  tone(PIN_BUZZER, 2349, 200);
//  delay(400);
//  tone(PIN_BUZZER, 2637, 200);
//  delay(400);
//  tone(PIN_BUZZER, 2093, 200);
//  delay(400);
//  tone(PIN_BUZZER, 1760, 200);
//  delay(400);
//  tone(PIN_BUZZER, 1760, 200); 
//  }

void visage(void){
  draw_visage = 1; 
  while(draw_visage == 1){
    display.clearDisplay();
    display.setTextSize(1);
    menu_back("Change Face",55);
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(56,20);
    display.print(number_oled);
    display.display(); 
     
    if (digitalRead(BP1) == HIGH){
      number_oled = (number_oled + 1)%6;
      delay(80);
    }  
    if(digitalRead(BP2) == HIGH){
     draw_visage = 0;
     draw_menu = 0;
     while((digitalRead(BP1) == HIGH));
     delay(80);
  
    }
    if (digitalRead(BP3) == HIGH){    
     draw_visage = 0;
     draw_menu = 1;
     while((digitalRead(BP3) == HIGH));
     delay(80);
    }
    EEPROM.write(1, number_oled);
    EEPROM.commit();
    }
}  

void mute_fonc(void){
  unsigned char mute_buzzer = 1; 
  while(mute_buzzer == 1){
    display.clearDisplay();
    menu_back("Sound ON/OFF",28);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    
    if (sound == HIGH){
      display.setCursor(50,20);
      display.println("ON");
      }
    else if (sound == LOW){
      display.setCursor(45,20);
      display.println("OFF");
      }
    else {
      display.setCursor(25,20);
      display.println("ERROR");
    }
    display.display(); 
     
    if (digitalRead(BP1) == HIGH){
      sound = !sound;
      delay(110);
    }  
    if(digitalRead(BP2) == HIGH){
     mute_buzzer = 0;
     draw_menu = 0;
     while((digitalRead(BP1) == HIGH));
     delay(110);
  
    }
    if (digitalRead(BP3) == HIGH){    
     mute_buzzer = 0;
     draw_menu = 1;
     while((digitalRead(BP3) == HIGH));
     delay(110);
    }
    //EEPROM.write(4, sound);
    }
}

void random_face_fonc(void){
  unsigned char rando_face = 1; 
  while(rando_face == 1){
    display.clearDisplay();
    menu_back("Random face",20);
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    
    if (Random_face == HIGH){
      display.setCursor(42,20);
      display.println("TRUE");
      }
    else if (Random_face == LOW){
      display.setCursor(37,20);
      display.println("FALSE");
      }
    else {
      display.setCursor(25,20);
      display.println("ERROR");
    }
    display.display(); 
     
    if (digitalRead(BP1) == HIGH){
      Random_face = !Random_face;
      delay(110);
    }  
    if(digitalRead(BP2) == HIGH){
     rando_face = 0; draw_menu = 0;
     while((digitalRead(BP1) == HIGH));
     delay(110);
  
    }
    if (digitalRead(BP3) == HIGH){    
     rando_face = 0; draw_menu = 1;
     while((digitalRead(BP3) == HIGH));
     delay(110);
    }
    //EEPROM.write(0, Random_face);
    }
}

void crono(void){
  bool crono_fonct = true;
  bool crono_act = false;
  bool run_crono = false;
  bool Bouton2_RE = false;
  unsigned long start_crono = 0;
  unsigned long crono_ms = 0;
  unsigned int crono_s = 0;
  unsigned int crono_m = 0;
  
  while(crono_fonct == true){
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(20,10);
    display.print(crono_m);
    display.print(":");
    if(crono_s<10)display.print("0");
    display.print(crono_s);
    display.print(".");
    if(crono_ms<10)display.print("0");
    display.println(crono_ms);

    display.setTextSize(1);      // Normal 1:1 pixel scale
    display.setCursor(60,55);
    if(crono_act == false)display.write(16);
    else display.write(19);
    display.setCursor(110,54);
  display.write(27);
    delay(2);
    display.display(); 
  
    if(crono_act == false){
        if(run_crono == true){
          crono_act = true;
          start_crono = millis();
       }
    }
    else{
      if(run_crono == false)crono_act = false;
      else{
        crono_m = (millis() - start_crono)/60000;
        crono_s = ((millis() - start_crono)%60000)/1000;
        crono_ms =(((millis() - start_crono)%60000)%1000)/10;
        }
      }
    
    
    if (digitalRead(BP1) == HIGH){
      
      delay(80);
    }  
    if(digitalRead(BP2) == HIGH && Bouton2_RE == false){
      Bouton2_RE = true;
      run_crono = !run_crono;
    }
    if(digitalRead(BP2) == LOW) Bouton2_RE = false;
    
    if (digitalRead(BP3) == HIGH){    
     while((digitalRead(BP3) == HIGH)); 
     crono_fonct = false;
     draw_menu = 1;
     delay(80);
    } 
  }
}

void Print_info(void){
  while(digitalRead(BP3) == LOW){
    Serial.println("void Print_info(void)");
    display.setCursor(0,0);
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.println("COMPAGNON");
    display.println("-Soft ESP v0");
    display.print  ("-LastMAJ "); display.println(F(__DATE__));
    display.println("-Hard ESP32-c3 V0.1");
    display.println("by Alfred");
    display.print  ("V_bat "); display.print(tension_bat());   display.println("mV");
    display.print  ("P_bat "); display.print(pourcent_bat());  display.println("%");
    display.print  ("E_c ");   display.println(digitalRead(charge));
    display.setCursor(110,50);
    display.write(27);
    display.display();
    delay(10);
  }
}

void Print_temp(void){
  Serial.println("Print_temp(void)");
  start = millis();
  bool B_Print_temp = 0;
  while(digitalRead(BP3) == LOW){
    
    if ( millis() - start > 1000 || B_Print_temp == 0){
      B_Print_temp = 1;
      start = millis();
      STH30.UpdateData();

      Serial.println("Inforation");
      display.setCursor(0,0);
      display.clearDisplay();
      display.setTextColor(SSD1306_WHITE);
      
      display.print("BMP TEMP ");
      display.print(bmp.readTemperature());
      display.println(" *C");
      
      display.print("STH30 TEMP ");
      display.print(STH30.GetTemperature()); //Celsius
      display.println(" *C");
      
      display.print("Humidity ");
      display.print(STH30.GetRelHumidity());
      display.println("%");
      
      display.setCursor(110,50);
      display.write(27);
      display.display();
          
      Serial.println(" - BMP280 - ");
      Serial.print("Temperature = ");
      Serial.print(bmp.readTemperature());
      Serial.println(" *C");
      Serial.print("Pressure = ");
      Serial.print(bmp.readPressure());
      Serial.println(" Pa");
      Serial.print("Approx altitude = ");
      Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
      Serial.println(" m");
      Serial.println(" - STH30 - ");
      Serial.print("Temperature = ");
      Serial.print(STH30.GetTemperature()); //Celsius
      Serial.println("*C");
      Serial.print("Humidity = ");
      Serial.print(STH30.GetRelHumidity());
      Serial.println("%");
    }
  }
}

void setup_ADC(){
  pinMode(MesBatEn, OUTPUT);
  pinMode(charge, INPUT);
  digitalWrite(MesBatEn,HIGH);
  
  esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_2_5, ADC_WIDTH_BIT_12, 0, &adc1_chars);
  adc1_config_width(ADC_WIDTH_BIT_12);
  adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_2_5);
}

int pourcent_bat(){
  int pourcentage = map(tension_bat(),3500,4100,0,100);
  
  if(pourcentage > 100){
    pourcentage=100;
  }
  else if(pourcentage<0){
    pourcentage=0;
  }
  
  return pourcentage;
}


int tension_bat(){
  unsigned int moyenne_bat = 0;
  delay(10);
  if(!init_cal_bat){
    init_cal_bat = 1;
    for(int i = 0 ; i < 16 ; i++){
      tension_moyenne[i] = esp_adc_cal_raw_to_voltage(adc1_get_raw((adc1_channel_t)4), &adc1_chars);
      delay(1);
    }
  }
  else{
    for(int i = 15 ; i >= 0 ; i--){
      tension_moyenne[i+1] = tension_moyenne[i];
    }
  tension_moyenne[0] = esp_adc_cal_raw_to_voltage(adc1_get_raw((adc1_channel_t)4), &adc1_chars) + 3;
  }

  for(int i = 0 ; i < 16 ; i++){
      moyenne_bat = moyenne_bat + tension_moyenne[i];
    }


  return((moyenne_bat/16)*(32000+10000)/10000); // * ((32000+10000)/10000)
}
