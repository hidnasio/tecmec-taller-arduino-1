#define SWITCH_PIN 4
#define LED_PIN 12


 bool led_on;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT);

  led_on = false;
}


void loop() {

  if (led_on == true) {
    digitalWrite(LED_PIN, HIGH); 
  } else {
    digitalWrite(LED_PIN, LOW); 
  }

  if (digitalRead(SWITCH_PIN) == HIGH) {
    led_on = true;
  } else {
    led_on = false;
  }
  
  delay(200);
}
