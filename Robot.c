/*
 * Program Robot allows the robot to follow a line on the ground. The line must be a dark color and the surrounding area must be a light color.
 * 
 * Notes: 
 * 1. If you wish to change which analog pins the two light sensors will be connected to, 
 * which digital pin the switch will be connected to, the motor speeds, and line threshold
 * please change the read-only variables below. You also can change the threshold at which the program
 * will detect a line.
*/


/* Read-only variables for the two sensors, the two motors, the switch, and the motor speeds */
const int LEFT_SENSOR = 0; // Analog Pin
const int RIGHT_SENSOR = 1; // Analog Pin
const int LEFT_MOTOR = 0; // Motor Pin
const int RIGHT_MOTOR = 1; // Motor Pin
const int SWITCH = 8; // Digital Pin

/* Speeds must be between -100 and 100 inclusive, must be an integer */
const int TURNING_SPEED = 80;
const int SPEED = 50;

/* Line threshold: how bright/dark the line is to follow. Number obtained via expermentation and must be
an integer between 0 and 1023, inclusive. */
const int LINE_THRESHOLD = 950;

/*
 * turnLeft() allows the robot to turn left.
 *
 * Variable duration is the amount of time, in seconds, to turn the robot.
*/
void turnLeft(int duration)
{
	motor(RIGHT_MOTOR, TURNING_SPEED); // Makes the right motor run slower
	motor(LEFT_MOTOR, -TURNING_SPEED); // Reverses the left motor to turn the robot
	msleep(duration * 1000); // Sleeps the robot for "duration" seconds
	motor(LEFT_MOTOR, SPEED); // Restores left motor to orginal speed
	motor(RIGHT_MOTOR, SPEED); // Restores right motor to orginal speed
}

/*
 * turnRight() allows the robot to turn left.
 *
 * Variable duration is the amount of time, in seconds, to turn the robot.
*/
void turnRight(int duration)
{
	motor(LEFT_MOTOR, TURNING_SPEED); // Makes the left motor run slower
	motor(RIGHT_MOTOR, -TURNING_SPEED); // Reverses the right motor to turn the robot
	msleep(duration * 1000); // Sleeps the robot for "duration" seconds
	motor(LEFT_MOTOR, SPEED); // Restores right motor to orginal speed
	motor(RIGHT_MOTOR, SPEED); // Restores left motor to orginal speed
}

/*
 * move() allows the robot to move foward or backward. 
 * 
 * Variable direction allows the user to choose which direction to move the robot.
 *
 * If direction is 1, than the robot will move foward.
 * If direction is -1, than the robot will move foward.
 * Any other integer will not affect the movement of the robot.
*/
void move(int direction)
{
	if (direction == 1)
	{
		motor(LEFT_MOTOR, SPEED);
		motor(RIGHT_MOTOR, SPEED);
	}
	else if (direction == -1)
	{
		motor(LEFT_MOTOR, -SPEED);
		motor(RIGHT_MOTOR, -SPEED);
	}	
}

/*
 * leftLine() allows the robot to use the left light sensor to detect a line.
 * 
 * Modify LINE_THRESHOLD to adjust the sensitivity of the detection.
 *
 * leftLine() will return either a 1 or a 0.
 * 
 * A return value of 1 means that a line was detected.
 * A return value of 0 means that a line was not detected.
*/
int leftLine()
{
	return analog(LEFT_SENSOR) >= LINE_THRESHOLD ? 1 : 0; //Ternary operators!
}

/*
 * rightLine() allows the robot to use the right light sensor to detect a line.
 * 
 * Modify LINE_THRESHOLD to adjust the sensitivity of the detection.
 *
 * rightLine() will return either a 1 or a 0.
 * 
 * A return value of 1 means that a line was detected.
 * A return value of 0 means that a line was not detected.
*/
int rightLine()
{
	return analog(RIGHT_SENSOR) >= LINE_THRESHOLD ? 1 : 0; //Ternary operators!
}

/*
* main() is the main function for the robot.
* 
* Please note that main()'s return value is 0 and is only present to compile the program.
*/
int main()
{
	set_a_button_text("DEBUG"); // (TEMP ONLY)
	// Adds a pull-up resistor to the light sensors
	set_analog_pullup(LEFT_SENSOR,0);
	set_analog_pullup(RIGHT_SENSOR,0);
	// Resets the "tick" counter to zero
	clear_motor_position_counter(LEFT_MOTOR);
	clear_motor_position_counter(RIGHT_MOTOR);
	//Beep once when all setup is done!
	beep();
	// Starts to move the robot
	move(1);
	while(1)
	{		
		if (leftLine() == 1)
		{
			turnRight(0.1);
		}
		else if (rightLine() == 1)
		{
			turnLeft(0.1);
		}
	}
	
	// Below line required to compile program
	return 0;
}



