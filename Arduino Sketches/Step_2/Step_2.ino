const int ledPin      = 12;

bool led_on = true;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  if(led_on) {
    led_on = false;
    digitalWrite(ledPin, LOW);  
  }
  else {
    led_on = true;
    digitalWrite(ledPin, HIGH); 
  }

  delay(1000);
}
