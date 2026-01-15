int baud_rate = 115200;
int baseline = 0;
int cal_max = 0;

// Oversampled ADC read
int getAnalog(int pin) {
  long sum = 0;
  for (int i = 0; i < 32; i++)
    sum += analogRead(pin);

  return sum >> 5; // divide by 32
}

void setup() {
  Serial.begin(baud_rate);

  // ----------------------
  // 1. Baseline calibration (silence)
  // ----------------------
  long sum = 0;
  for (int i = 0; i < 5000; i++) {
    sum += getAnalog(A0);
    delay(1);
  }
  baseline = sum / 5000;

  Serial.print("CAL_BASELINE ");
  Serial.println(baseline);

  // ----------------------
  // 2. Max calibration (talk now)
  // ----------------------
  cal_max = 0;
  for (int i = 0; i < 10000; i++) // ~2 seconds of talking
  {
    int v = abs(getAnalog(A0) - baseline);
    if (v > cal_max)
      cal_max = v;

    delay(1);
  }

  Serial.print("CAL_MAX ");
  Serial.println(cal_max);
}

void loop() {
  // Stream live amplitude
  int amplitude = abs(getAnalog(A0) - baseline);

  Serial.print("DATA ");
  Serial.println(amplitude);

  delay(5); // ~200 Hz stream (plenty for Python trigger)
}
