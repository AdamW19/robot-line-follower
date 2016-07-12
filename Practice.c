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
	int dark = 970;
	if (analog(left_light) >= dark) {
		return 1;
		}else{
		return 0;
	}
	
}

int right_is_dark() {
	
	int right_light = 1;
	int dark = 970;
	if (analog(right_light) >= dark) {
		return 1;
		}else{
		return 0;
	}
	
}



int main() {
	//int over_line;
	//int over_line_2;
	int button_pressed() {
		int push_button = 8;
		return digital(push_button);
	}
	int i;
	for(i=0; i < 2; i++) {
		while (1) {
			int over_line = left_is_dark();
			//printf("over_line_left = %d\n", over_line);
			msleep(100);
			int over_line_2 = right_is_dark();
			//printf("over_line_right = %d\n", over_line_2);
			msleep(100);
			
			/*if (forward()){
				printf("It is going forward");
			}else if(right()){
				printf("It is going right");
			}else if(left()){
				printf("It is going right");
			}else {
				printf("It is about to do a 180");
			}*/
			
			/*if (button_pressed()==0){
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
			}*/
			if (left_is_dark() && right_is_dark() ) {
					ao();
					msleep(2000);
				break;
				/*forward(10);
				msleep(100);
				right(10000);
				msleep(500);*/
			}else if(left_is_dark()){
			
			right(75);
			}else if(right_is_dark()){
			
			left(75);
			}else {
			forward(20);
		}
		
		
		
		 /*Insert loop code here */ 
		
		
		
		
		
		
	}
	backward(10);
	msleep(900);
	ao();
	msleep(1500);
	left(100);
	msleep(2550);
	//right(100);
	//msleep(2000);
	ao();
	
}
	return 0;
}




