/*
 * Robot Line Follower 1.0 Updated July 13th, 2016
 * 
 * Robot Line Follower by Patrick Callahan and Adam Wang is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License. 
 * For more information, please visit https://creativecommons.org/licenses/by-sa/4.0/.
 * Github Link: https://github.com/AdamW19/robot-line-follower
 * 
 * Notes: 
 * 1. If you wish to change the analog pins the two light sensors will use, the motor pins
 * that will be used, the speeds of the motors, and the line threshold, please change the read-only variables below.
 * 2. For more information please visit the GitHub page above.
*/

/* Read-only variables for the two sensors and the two motors */
const int LEFT_SENSOR = 0; // Analog Pin
const int RIGHT_SENSOR = 1; // Analog Pin
const int LEFT_MOTOR = 1; // Motor Pin
const int RIGHT_MOTOR = 0; // Motor Pin

/* Speeds must be between -100 and 100 inclusive, must be an integer */
const int TURNING_SPEED = 75;
const int SPEED = 15;

/* Line threshold: how bright/dark the line is to follow. Number obtained via expermentation and must be
an integer between 0 and 1023, inclusive. */
const int LINE_THRESHOLD = 970;

/*
 * foward() allows the robot to move foward, given a speed.
 *
 * Variable SPEED is the speed going foward. This variable is defined above.
 * Please note that the motor() function used in foward() uses PWM to control motor speed.
*/
void forward()
{
	if (SPEED >= 0 && SPEED <= 100)
	{
		motor(LEFT_MOTOR, SPEED);
		motor(RIGHT_MOTOR, SPEED);
	}
}

/*
 * backward() allows the robot to move backward, given a speed.
 *
 * Variable SPEED is the speed going foward. This variable is defined above.
 * The method will automatically invert SPEED.
 * Please note that the motor() method used in backward() uses PWM to control motor speed.
*/
void backward() 
{
	if (SPEED >= 0 && SPEED <= 100)
	{
		motor(LEFT_MOTOR, -SPEED);
		motor(RIGHT_MOTOR, -SPEED);
	}
}

/*
 * right() allows the robot to turn right.
 *
 * Variable TURNING_SPEED is the amount of power used to turn the robot. This variable is defined above.
 * Please note that the motor() method used in right() uses PWM to control motor speed.
*/
void right() 
{
	if (TURNING_SPEED >= 0 && TURNING_SPEED <= 100)
	{
		motor(LEFT_MOTOR, TURNING_SPEED);
		motor(RIGHT_MOTOR, -TURNING_SPEED);
	}
}

/*
 * left() allows the robot to turn left.
 *
 * Variable TURNING_SPEED is the amount of power used to turn the robot. This variable is defined above.
 * Please note that the motor() method used in right() uses PWM to control motor speed.
*/
void left() 
{
	if (TURNING_SPEED >= 0 && TURNING_SPEED <= 100)
	{
		motor(LEFT_MOTOR, -TURNING_SPEED);
		motor(RIGHT_MOTOR, TURNING_SPEED);
	}
}

/*
 * left_is_dark() allows the robot to use the left light sensor to detect a line.
 * 
 * Modify LINE_THRESHOLD to adjust the sensitivity of the detection.
 *
 * left_is_dark() will return either a 1 or a 0.
 * 
 * A return value of 1 means that a line was detected.
 * A return value of 0 means that a line was not detected.
*/
int left_is_dark() 
{
	if (analog(LEFT_SENSOR) >= LINE_THRESHOLD)
	return 1;
	else
	return 0;
}

/*
 * right_is_dark() allows the robot to use the right light sensor to detect a line.
 * 
 * Modify LINE_THRESHOLD to adjust the sensitivity of the detection.
 *
 * right_is_dark() will return either a 1 or a 0.
 * 
 * A return value of 1 means that a line was detected.
 * A return value of 0 means that a line was not detected.
*/
int right_is_dark() {
	if (analog(RIGHT_SENSOR) >= LINE_THRESHOLD)
	return 1;
	else
	return 0;
}

/*
* main() is the main function for the robot.
* 
* Please note that main()'s return value is 0 and is only present to compile the program.
*/
int main() {
	// Adds a pull-up resistor to the light sensors
 	set_analog_pullup(LEFT_SENSOR,0);
 	set_analog_pullup(RIGHT_SENSOR,0);
 	// Resets the "tick" counter to zero
	clear_motor_position_counter(LEFT_MOTOR);
 	clear_motor_position_counter(RIGHT_MOTOR);
 	
	for(int i=0; i < 2; i++) // Prevents the robot from infinitely looping the track. Feel free to remove this line 
	{
		while (1) //Loops indefinitely until both sensors detect the endline 
		{
			msleep(200);
			if (left_is_dark() && right_is_dark()) // If both sensors detect the line...
			{
				ao(); // We kill the motors
				msleep(2000); // Wait two seconds
				break; //and exit the while loop
			}
			else if(left_is_dark()) // If the left sensor detects the line...
			right(); // Turn slightly right
			else if(right_is_dark()) // If the right sensor detects the line...
			left(); // Turn slightly left
			else //Otherwise...
			forward(SPEED); // Continue moving foward
		}
		/* When we break the while loop these commands make the robot turn around and go back to the beginning. 
		These numbers were obtained via expermentation. */
		backward(10);
		msleep(900);
		ao();
		msleep(1500);
		left(); // You can turn left or right; it is your choice
		msleep(2550);
		ao();
	}
	return 0; // Line required to compile program
	
}
