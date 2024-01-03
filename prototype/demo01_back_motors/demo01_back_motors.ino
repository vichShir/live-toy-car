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

void forwards()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  // digitalWrite(in3, LOW);
  // digitalWrite(in4, HIGH);
}

void backwards()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  // digitalWrite(in3, HIGH);
  // digitalWrite(in4, LOW);
}

void accelerate()
{
  for (int i = 0; i < 256; i++)
  {
    analogWrite(enA, i);
    // analogWrite(enB, i);

    delay(20);
  } 
}

void decelerate()
{
  for (int i = 255; i >= 0; --i)
  {
    analogWrite(enA, i);
    // analogWrite(enB, i);

    delay(20);
  } 
}

void demo()
{
  // This function will run the back motor in both directions across the range of possible speeds
  // Note that maximum speed is determined by the motor itself and the operating voltage

  // Turn on motors forwards
  forwards();

  // Accelerate from zero to maximum speed
  accelerate();

  // Decelerate from maximum speed to zero
  decelerate();

  // Turn on motors backwards
  backwards();

  // Accelerate from zero to maximum speed
  accelerate();

  // Decelerate from maximum speed to zero
  decelerate();

  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
}

void loop()
{
  demo();
  delay(1000);
}