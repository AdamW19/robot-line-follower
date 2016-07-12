void forward(int speed){
	int left_motor = 1, right_motor = 0;
	motor(left_motor, speed);
	motor(right_motor, speed);
}

void backward(int speed) {
	int left_motor = 1, right_motor = 0;
	motor(left_motor, -speed);
	motor(right_motor, -speed);
}

void right(int speed) {
	
	int left_motor = 1, right_motor = 0;
	motor(left_motor, speed);
	motor(right_motor, -speed);
}

void left(int speed) {
	int left_motor = 1, right_motor = 0;
	motor(left_motor, -speed);
	motor(right_motor, speed);
}

int left_is_dark() {
	
	int left_light = 0;
	int dark = 950
	if (analog(left_light) >= dark) {
		return 1;
	}else{
		return 0;
	}
	
}

int right_is_dark() {
	
	int right_light = 1;
	int dark = 950
	if (analog(right_light) >= dark) {
		return 1;
	}else{
		return 0;
	}
	
}

	

int main() {
	int over_line_left;
	int over_line_right;
	int button_pressed() {
		int push_button = 8;
		return digital(push_button);
	}
	
	while (1) {
		over_line = left_is_dark();
		printf("over_line_left = %d", over_line_left);
		msleep(500);
		over_line_2 = right_is_dark();
		printf("over_line_right = %d", over_line_right);
		msleep(500);
		
	if (button_pressed()==0){
		forward(50);
	}else{
		backward(50);
		msleep(1000);
		ao();
		msleep(2000);
		right(100);
		msleep(2100);
		ao();
		msleep(500);
	}
}
	return 0;
}


	
