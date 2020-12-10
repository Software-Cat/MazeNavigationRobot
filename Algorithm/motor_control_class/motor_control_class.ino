// Motor Pins
// const int LEFT_FORWARD = 2;
// const int LEFT_BACKWARD = 3;
// const int RIGHT_FORWARD = 4;
// const int RIGHT_BACKWARD = 5;

// Robot Class Definition
class Robot {
  private:
    int LEFT_FORWARD;
    int LEFT_BACKWARD;
    int RIGHT_FORWARD;
    int RIGHT_BACKWARD;

  public:
    Robot(int leftForward, int leftBackward, int rightForward, int rightBackward) {
      this->LEFT_FORWARD = leftForward;
      this->LEFT_BACKWARD = leftBackward;
      this->RIGHT_FORWARD = rightForward;
      this->RIGHT_BACKWARD = rightBackward;

      pinMode(LEFT_FORWARD, OUTPUT);
      pinMode(LEFT_BACKWARD, OUTPUT);
      pinMode(RIGHT_FORWARD, OUTPUT);
      pinMode(RIGHT_BACKWARD, OUTPUT);
    }

    void halt() {
      digitalWrite(LEFT_FORWARD, LOW);
      digitalWrite(RIGHT_FORWARD, LOW);
      digitalWrite(LEFT_BACKWARD, LOW);
      digitalWrite(RIGHT_BACKWARD, LOW);
    }

    void forward(int milliseconds) {
      halt();
      digitalWrite(LEFT_FORWARD, HIGH);
      digitalWrite(RIGHT_FORWARD, HIGH);
      delay(milliseconds);
      halt();
    }

    void backward(int milliseconds) {
      halt();
      digitalWrite(LEFT_BACKWARD, HIGH);
      digitalWrite(RIGHT_BACKWARD, HIGH);
      delay(milliseconds);
      halt();
    }

    void forwardLeft(int milliseconds) {
      halt();
      digitalWrite(LEFT_FORWARD, HIGH);
      delay(milliseconds);
      halt();
    }

    void forwardRight(int milliseconds) {
      halt();
      digitalWrite(RIGHT_FORWARD, HIGH);
      delay(milliseconds);
      halt();
    }

    void backwardLeft(int milliseconds) {
      halt();
      digitalWrite(LEFT_BACKWARD, HIGH);
      delay(milliseconds);
      halt();
    }

    void backwardRight(int milliseconds) {
      halt();
      digitalWrite(RIGHT_BACKWARD, HIGH);
      delay(milliseconds);
      halt();
    }

    void spinLeft(int milliseconds) {
      halt();
      digitalWrite(LEFT_BACKWARD, HIGH);
      digitalWrite(RIGHT_FORWARD, HIGH);
      delay(milliseconds);
      halt();
    }

    void spinRight(int milliseconds) {
      halt();
      digitalWrite(LEFT_FORWARD, HIGH);
      digitalWrite(RIGHT_BACKWARD, HIGH);
      delay(milliseconds);
      halt();
    }
};

Robot robot = Robot(2, 3, 5, 4);

// Init
void setup() {
  Serial.begin(9600);
}

// Mainloop
void loop() {
  robot.spinLeft(1000);
  robot.spinRight(1000);
}
