// Motor Pins
const int LEFT_FORWARD = 2;
const int LEFT_BACKWARD = 3;
const int RIGHT_FORWARD = 4;
const int RIGHT_BACKWARD = 5;

// Tokenizer Pins
const int INPUT_SIZE = 30;
const int MAX_ARGS = 10;
const char DELIMETER[] = " ";

// Functions
// Individual motors
void LeftForward() {
  LeftStop();
  digitalWrite(LEFT_FORWARD, HIGH);
}

void LeftBackward() {
  LeftStop();
  digitalWrite(LEFT_BACKWARD, HIGH);
}

void LeftStop() {
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, LOW);
}

void RightForward() {
  RightStop();
  digitalWrite(RIGHT_FORWARD, HIGH);
}

void RightBackward() {
  RightStop();
  digitalWrite(RIGHT_BACKWARD, HIGH);
}

void RightStop() {
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, LOW);
}

// Both motors
void Forward() {
  Halt();
  LeftForward();
  RightForward();
}

void Backward() {
  Halt();
  LeftBackward();
  RightBackward();
}

void ForwardLeft() {
  Halt();
  RightForward();
}

void ForwardRight() {
  Halt();
  LeftForward();
}

void BackwardLeft() {
  Halt();
  RightBackward();
}

void BackwardRight() {
  Halt();
  LeftBackward();
}

void SpinLeft() {
  Halt();
  LeftBackward();
  RightForward();
}

void SpinRight() {
  Halt();
  LeftForward();
  RightBackward();
}

void Halt() {
  LeftStop();
  RightStop();
}

// Init
void setup() {
  Serial.begin(9600);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);
}

// Main
void loop() {
  Forward();
}
