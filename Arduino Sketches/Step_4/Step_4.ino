const int ledPin      = 12;
const int speakerPin  = 9;
const int buttonPin   = 2;
const int photoPin    = 0;
const int tempo       = 200;
const int threshold   = 400;
const char notes[]    = "eeeeeeegcde fffffeeeeddedg";
const int beats[]     = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};

bool led_on = false;
int sensor_value;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {

  if (digitalRead(buttonPin) == HIGH) {
        
    digitalWrite(ledPin, HIGH);
      
    for (int i = 0; i < sizeof(notes); i++) {
      if (notes[i] == ' ') {
        delay(beats[i] * tempo);
      } else {
        playNote(notes[i], beats[i] * tempo);
      }
  
      delay(tempo / 2); 
    }
  }

  sensor_value = analogRead(photoPin);
 
  Serial.print("Sensor value = ");
  Serial.println(sensor_value);

  if (sensor_value < threshold ) {
    if(led_on) {
      led_on = false;
      digitalWrite(ledPin, LOW);
    }
    else {
      led_on = true;
      digitalWrite(ledPin, HIGH); 
    }
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  for (int i = 0; i < 8; i++) {
    if (names[i] == note) playTone(tones[i], duration);
  }
}
