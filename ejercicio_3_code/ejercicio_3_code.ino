#define SENSOR_PIN 3
#define LED_PIN 12

bool led_on;
unsigned long last_event = 0;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), trigger, CHANGE);

  led_on = false;
  last_event = millis();
}

void trigger() {
  last_event = millis();
  led_on = true;
}

void loop() {
  if (led_on) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  if ((millis() - last_event) > 1000) {
    led_on = false; 
  }
}
