// Motor 1

int m1 = 11; // Pin for motor 1 clockwise
int m2 = 12; // Pin for motor 1 anti-clockwise

// Motor 2

int m3 = 9 ; // Pin for motor 2 clockwise
int m4 = 8 ; // Pin for motor 2 anti-clockwise

String voice ; // String for storing voice command 

void setup() {

    Serial.begin(38400);

    pinMode(m1, OUTPUT); // Right motor
    pinMode(m2, OUTPUT); // Right motor
    pinMode(m3, OUTPUT); // Left motor
    pinMode(m4, OUTPUT); // Left motor

}


void loop() {

    while(Serial.available()>0){
        delay(10);
        char c = Serial.read() ;
        if (c == "#")
          break ;    
        voice += c ;
    }

    if (voice == "forward"){
      digitalWrite(m1, LOW);  
      digitalWrite(m2, HIGH);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
      delay(5000); // These delays are put in place to make the bot rotate
    }

    else if (voice == "back"){
      digitalWrite(m1, HIGH);  
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
      delay(5000);  
    }

    else if (voice == "left"){
      digitalWrite(m1, LOW);  
      digitalWrite(m2, HIGH);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
      delay(5000);   
    }

    else if (voice == "right"){
      digitalWrite(m1, HIGH);  
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, HIGH);
      delay(5000);   
    }
    
  // To return the motor back to its original state of rest

    if(voice.length()>0){
      Serial.println(voice);
      voice = "" ;
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);  
    }

}