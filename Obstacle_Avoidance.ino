int trigPin = 9;      // trig pin of HC-SR04

int echoPin = 10;     // Echo pin of HC-SR04


int revleft4 = 4;       //REVerse motion of Left motor

int fwdleft5 = 5;       //ForWarD motion of Left motor

int revright6 = 6;      //REVerse motion of Right motor

int fwdright7 = 7;      //ForWarD motion of Right motor

int ENA= 3;
int ENB=11;
//int speed=100:
long duration, distance;


void setup() {

  

  //delay(random(500,2000));   // delay for random time

  Serial.begin(9600);

  pinMode(revleft4, OUTPUT);      // set Motor pins as output

  pinMode(fwdleft5, OUTPUT);

  pinMode(revright6, OUTPUT);

  pinMode(fwdright7, OUTPUT);

  

  pinMode(trigPin, OUTPUT);         // set trig pin as output

  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves

}


void loop() {


  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);   

  digitalWrite(trigPin, HIGH);     // send waves for 10 us

  delayMicroseconds(10);

  duration = pulseIn(echoPin, HIGH); // receive reflected waves

  distance = duration / 58.2;   // convert to distance
  Serial.println(distance);

  delay(10);

    // If you dont get proper movements of your robot then alter the pin numbers

  if (distance > 18)            

  {

    digitalWrite(fwdright7, HIGH);                    // move forward

    digitalWrite(revright6, LOW);

    digitalWrite(fwdleft5, HIGH);                                

    digitalWrite(revleft4, LOW);    
    analogWrite(ENA, 130);
    analogWrite(ENB, 130);                                                   

  }


  if (distance < 18)

  {

    digitalWrite(fwdright7, LOW);  //Stop                

    digitalWrite(revright6, LOW);

    digitalWrite(fwdleft5, LOW);                                

    digitalWrite(revleft4, LOW);

    delay(500);

    digitalWrite(fwdright7, LOW);      //movebackword         

    digitalWrite(revright6, HIGH);

    digitalWrite(fwdleft5, LOW);                                

    digitalWrite(revleft4, HIGH);
     analogWrite(ENA, 130);
    analogWrite(ENB, 130); 

    delay(600);

    digitalWrite(fwdright7, LOW);  //Stop                

    digitalWrite(revright6, LOW);

    digitalWrite(fwdleft5, LOW);                                

    digitalWrite(revleft4, LOW);  

    delay(400);  

    digitalWrite(fwdright7, HIGH);       

    digitalWrite(revright6, LOW);   

    digitalWrite(revleft4, LOW);                                 

    digitalWrite(fwdleft5, HIGH);  
     analogWrite(ENA, 120);
    analogWrite(ENB, 120); 

    delay400);

  }


}