// Tokenizer
const int INPUT_SIZE = 30;
const int MAX_ARGS = 10;
const char DELIMETER[] = " ";

// Motor Pins
const int LEFT_FORWARD = 2;
const int LEFT_BACKWARD = 3;
const int RIGHT_FORWARD = 4;
const int RIGHT_BACKWARD = 5;

// Led Pins
const int LED_PIN = 13;

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

// Util Functions
/** Turn n miliseconds
 * Input: number of miliseconds to turn, (char) direction to turn 
 * 
 * Processing: if 'L' in direction to turn, spin left, wait n milliseconds, halt. 
 *  elif 'R' in direction to turn, spin right, wait n milliseconds, halt.
 * 
 * Output: void
 */

void Spin(char dirToTurn, int milisec) {
  if ('l' == dirToTurn) {
      Serial.println("Spin Left");
      SpinLeft();
      delay(milisec);
      Halt();
   }
   else if ('r' == dirToTurn) {
      Serial.println("Spin Right");
      SpinRight();
      delay(milisec);
      Halt();
   }
   Serial.println("Finished");
}

bool isOnBlack() {
  // TODO
  return true;
}

void processSerialCommand() {
  char input[INPUT_SIZE + 1];
  char *strings[MAX_ARGS + 1];
  char *ptr = NULL;
  byte size = Serial.readBytes(input, INPUT_SIZE);
  // Add the final 0 to end the C string
  input[size] = 0;

  byte index = 0;
  ptr = strtok(input, DELIMETER);  // takes a list of delimiters
  while(ptr != NULL)
  {
    strings[index] = ptr;
    index++;
    ptr = strtok(NULL, DELIMETER);  // takes a list of delimiters
  }
  
  // store the tokens in a string array
  String command[index];
  for(int n = 0; n < index; n++)
  {
    command[n] = strings[n];
  }
  
  // decode command
  // LED control
  if(command[0] == "led") {
    digitalWrite(LED_PIN, command[1].toInt());
  }
  if(command[0] == "spin") {
    char charBuf[50];
    command[1].toCharArray(charBuf, 50);
    Spin(charBuf[0], command[2].toInt());
  }
}

// Init
void setup() {
  Serial.begin(9600);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

// Main
void loop() {
  if(Serial.available()) {
    processSerialCommand();
  }

  // If on white, forward, else turn 90 (alt. elevation/depression) then forward, if doesn't hit white, repeat turn.
  
}
