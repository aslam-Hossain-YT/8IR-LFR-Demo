void turnLeft() {
  set_motor(-turn_speed, turn_speed); 
}
void turnRight() {
  set_motor(turn_speed, -turn_speed); 
}
void stop() {
  set_motor(0, 0); 
}

