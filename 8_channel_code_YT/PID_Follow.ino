//PID_FOLLOW function
void PID_FOLLOW() {
  while (1) {
    read_sensor();
    pid_algorithm(base_speed, kp, kd, ki);

    //TURN DETECTION
    if (sensor_value[7] == 1 && sensor_value[0] == 0) turn_value = 1;  //left turn detect
    if (sensor_value[7] == 0 && sensor_value[0] == 1) turn_value = 2;  //right turn detect

    if (sum_on_sensor == 0) {
      if (turn_value == 1 || turn_value == 2) {
        if (turn_value == 1) {
          turnLeft();  //set_motor(-turn_speed, turn_speed);  //left turn execute
        } else {
          turnRight();  //set_motor(turn_speed, -turn_speed);  //right turn execute
        }
        while (sensor_value[3] + sensor_value[4] < 2) read_sensor();  //duration of turn
        turn_value = 0;                                            //set to default
      }
    } else if (sum_on_sensor == 8) {
      delay(stop_time);
      read_sensor();
      if (sum_on_sensor == 8) {
        while (1) stop();  //set_motor(0, 0);
        //while (sum_on_sensor == 8) read_sensor();
      } else if (sum_on_sensor == 0) turn_value = 2;  //T section turn
    }
  }
}


void pid_algorithm(int base_speed, int p, int d, int i) {
  if (sum_on_sensor > 0) line_position = sensor_wight / sum_on_sensor;

  error = center_position - line_position;
  integral = integral + error;
  derivative = error - previous_error;

  int correction = (error * p) + (i * integral) + (d * derivative);
  previous_error = error;

  int right_motor_speed = base_speed - correction;
  int left_motor_speed = base_speed + correction;

  set_motor(left_motor_speed, right_motor_speed);
}
