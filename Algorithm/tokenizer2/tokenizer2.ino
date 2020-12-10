// Pins
const int LED_PIN = 13;
const int LEFT_FORWARD = 2;
const int LEFT_BACKWARD = 3;
const int RIGHT_FORWARD = 4;
const int RIGHT_BACKWARD = 5;

// Tokenizer
const int INPUT_SIZE = 30;
const int MAX_ARGS = 10;
const char DELIMETER[] = " ";

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);
}

void loop()
{
  if(Serial.available()) {
    processSerialCommand();
  }
  
  delay(1000);
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
  else if(command[0] == "forward") {
    digitalWrite(LEFT_FORWARD, command[1].toInt());
  }
  else if(command[0] == "back") {
    digitalWrite(LEFT_BACKWARD, command[1].toInt());
  }
  else if(command[0] == "halt") {
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(LEFT_BACKWARD, LOW);
  }
}
