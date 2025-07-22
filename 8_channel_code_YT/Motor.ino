//motor function
void set_motor(int left, int right) {
  if (left > 0) {
    digitalWrite(lmf, 1);
    digitalWrite(lmb, 0);
  } else {
    left = -(left);
    digitalWrite(lmf, 0);
    digitalWrite(lmb, 1);
  }
  if (right > 0) {
    digitalWrite(rmf, 1);
    digitalWrite(rmb, 0);
  } else {
    right = -(right);
    digitalWrite(rmf, 0);
    digitalWrite(rmb, 1);
  }

  if (left > 255) left = 255;
  if (right > 255) right = 255;

  analogWrite(lms, left);
  analogWrite(rms, right);
}