//Board: Arduino UNO/NANO
//Language: C++
//Software: Arduino IDE
//by Dana&Alua

int Sensor = 2;     // KY-033 Input Pin
int LED = 13; // Use the onboard Uno LED
int isObstaclePin = 7; // This is our input pin
int isObstacle = HIGH; // HIGH MEANS NO OBSTACLE
byte led=0; //Состояние светодиода
byte oldled=1; //Последнее состояние //светодиода, для исключения ложных //переключений

void setup() {

pinMode (Sensor, INPUT);  // RCWL-0516 as input
pinMode(isObstaclePin, INPUT);
 pinMode (LED, OUTPUT);    // LED as OUTPUT
  digitalWrite(LED, LOW);   // Turn LED Off
Serial.begin(9600);
}

void loop() {
isObstacle = digitalRead(isObstaclePin);
  
  if (isObstacle == LOW) //sensor is activated
  { Serial.println("OBSTACLE!!, OBSTACLE!!");
     if (led==oldled) { //Проверка, что //состояние кнопки изменилось
       led=!led;
        Serial.println("LED was changed");
     }
    } else { //Когда не нажата
       oldled=led;
    } 
    digitalWrite(LED,led);
}