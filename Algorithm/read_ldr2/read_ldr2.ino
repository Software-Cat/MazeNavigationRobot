const int LDR = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LDR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(LDR));
}
