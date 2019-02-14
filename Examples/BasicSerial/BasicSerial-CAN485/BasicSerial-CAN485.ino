/*
 * Serial communications example
 * Allows the CAN485 built-in LED to be controlled over the serial port
 * If an 'h' is received, the LED is switched on. If anything else is received it is switched off.
 * 
 * Sends alternating x and h over the serial port.
 */

#define BLINK_DELAY 100

char serialIn;
bool blinkState = false;
unsigned long prevTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  prevTime = millis();
}

void loop() {
  // Read any serial input and set the LED accordingly
  if (Serial.available()>0){
    serialIn = Serial.read();
    if (serialIn == 'h'){
      digitalWrite(LED_BUILTIN, HIGH);                  // Set LED on
    }
    else if((serialIn == '\n')||(serialIn == '\r')){    // Ignore newline or carriage return
      
    }
    else
    {
      digitalWrite(LED_BUILTIN, LOW);                   // Set LED off
    }
  }

  // non blocking timed serial send
  // Every BLINK_DELAY, a character is sent over the serial port
  if ((millis() - prevTime) > BLINK_DELAY){
    prevTime = millis();
    if (blinkState){
      Serial.print('h');
      blinkState = false;
    }
    else{
      Serial.print('x');
      blinkState = true;
    }
  }
}
