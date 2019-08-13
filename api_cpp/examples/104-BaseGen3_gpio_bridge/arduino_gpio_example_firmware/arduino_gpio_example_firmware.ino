#include <Wire.h>

// Change those pins to your own pin numbers
const int ROBOT_PIN_1 = 23;
const int ROBOT_PIN_2 = 24;
const int ROBOT_PIN_3 = 29;
const int ROBOT_PIN_4 = 30;

unsigned long previous_time;

// Runs once
void setup() 
{
  // Prints
  Serial.begin(9600);
   
  // GPIO setup
  pinMode(ROBOT_PIN_1, INPUT_PULLUP);
  pinMode(ROBOT_PIN_2, INPUT_PULLUP);
  pinMode(ROBOT_PIN_3, OUTPUT);
  pinMode(ROBOT_PIN_4, OUTPUT);
  previous_time = millis();
}

// Runs after the setup as an infinite loop
void loop() 
{
  unsigned long current_time = millis();

  if (current_time - previous_time > 200)
  {
    previous_time = current_time;
    
    // Pin 1 to Pin 3    
    int p1_value = digitalRead(ROBOT_PIN_1);
    if (p1_value)
    {
      digitalWrite(ROBOT_PIN_3, HIGH);
    }
    else
    {
      digitalWrite(ROBOT_PIN_3, LOW);
    }
    
    // Pin 2 to pin 4
    int p2_value = digitalRead(ROBOT_PIN_2);
    if (p2_value)
    {
      digitalWrite(ROBOT_PIN_4, HIGH);
    }
    else
    {
      digitalWrite(ROBOT_PIN_4, LOW);
    }
  }
}
