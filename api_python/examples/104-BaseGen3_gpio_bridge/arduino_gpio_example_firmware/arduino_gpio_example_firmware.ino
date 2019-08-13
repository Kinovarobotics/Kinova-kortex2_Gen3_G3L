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

  // I2C setup
  int slave_address = 0x20; // this address has to match the one in the Kortex example
  Wire.begin(slave_address);
  Wire.onReceive(i2c_on_receive_callback); // Function called when a I2CWrite comes in
  Wire.onRequest(i2c_on_request_callback); // Function called when a I2CRead comes in
   
  // GPIO setup
  pinMode(ROBOT_PIN_1, INPUT_PULLUP);
  pinMode(ROBOT_PIN_2, INPUT_PULLUP);
  pinMode(ROBOT_PIN_3, OUTPUT);
  pinMode(ROBOT_PIN_4, OUTPUT);
  previous_time = millis();

  // LED setup
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
}

void blink_led()
{
  digitalWrite(LED1, HIGH);
  delay(10);
  digitalWrite(LED1, LOW);
  delay(10);
}

void i2c_on_receive_callback(int bytes_to_read)
{
  while (Wire.available() > 0)
  {
    char c = Wire.read();
    Serial.print(c);
    blink_led();
  }
  Serial.println();
}

void i2c_on_request_callback()
{
    Wire.write("This is the child's answer!"); 
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
