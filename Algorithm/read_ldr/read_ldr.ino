const int ledPin = LED_BUILTIN;
const int ldrPin = A0;
const int interpolationDegree = 10;
int ldrValueHistory[interpolationDegree];
int normalisedLdrValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {
  normalisedLdrValue = readInterpolatedLdrVal();

  // LED Control
  if (normalisedLdrValue > 25) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  // Output
  Serial.println(normalisedLdrValue);

  // Delay For Stability
  delay(1);
}

int readInterpolatedLdrVal() {
  int ldrValue;
  int ldrHistorySum;

  // Read LDR Voltage
  ldrValue = analogRead(ldrPin);

  // Shift History Values By 1 To Make Space For New Value
  for (int i = interpolationDegree - 1; i > 0; i--) {
    ldrValueHistory[i] = ldrValueHistory[i-1];
  }

  // Write In New Value To The History
  ldrValueHistory[0] = ldrValue;

  // Smoothen The Wavy Line
  if (ldrValueHistory[interpolationDegree - 1] != 0) {
    ldrHistorySum = 0;
    for (int i = 0; i < interpolationDegree; i++) {
      ldrHistorySum += ldrValueHistory[i];
    }
    normalisedLdrValue = ldrHistorySum / interpolationDegree;
  } else {
    // If There's Not Enough Data To Average The Value, Just Return The Read Value
    normalisedLdrValue = ldrValue;
  }

  return normalisedLdrValue;
}
