/*
 * Serial communications example
 * Allows the ESP built-in LED to be controlled over the serial port
 * If an 'h' is received, the LED is switched on. If anything else is received it is switched off.
 * Also echos any received serial input over the serial port
 */

char serialIn;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available()>0){
    serialIn = Serial.read();
    Serial.print(serialIn);
    if (serialIn == 'h'){
      digitalWrite(LED_BUILTIN, LOW);                   // Set LED on (ESP LED has inverted logic)
    }
    else if((serialIn == '\n')||(serialIn == '\r')){    // Ignore newline or carriage return
      
    }
    else
    {
      digitalWrite(LED_BUILTIN, HIGH);                  // Set LED off (ESP LED has inverted logic)
    }
  }
}
