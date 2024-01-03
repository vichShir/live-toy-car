/*
  Modified version from:
	L298N Motor Demonstration
	L298N-Motor-Demo.ino
	Demonstrates functions of L298N Motor Controller
	
	DroneBot Workshop 2017
	http://dronebotworkshop.com
*/
	

// Motor A
int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup()
{
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
}

void turn_right()
{
  // digitalWrite(in1, LOW);
  // digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turn_left()
{
  // digitalWrite(in1, HIGH);
  // digitalWrite(in2, LOW);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void make_turn(int force=255)
{
  analogWrite(enB, force);
  delay(150);
  analogWrite(enB, 0);
  delay(1000);
}

void demo()
{
  // This function will run the front motor in both directions
  // Note that maximum speed is determined by the motor itself and the operating voltage

  // Turn on motors to right
  turn_right();

  // Accelerate a little bit
  make_turn();

  // Turn on motors to left
  turn_left();

  // Accelerate a little bit
  make_turn();

  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
}

void loop()
{
  demo();
  delay(5000);
}