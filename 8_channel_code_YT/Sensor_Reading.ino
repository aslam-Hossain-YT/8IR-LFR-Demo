//pid sensor reading
void read_sensor() {
  sensor_wight = 0;
  sum_on_sensor = 0;

  for (int8_t i = 0; i < sensorNumber; i++) {
    sensor_value[i] = analogRead(i);
    if (sensor_value[i] > threshold[i]) sensor_value[i] = 1;
    else sensor_value[i] = 0;

    sum_on_sensor += sensor_value[i];
    sensor_wight += sensor_value[i] * position[i];
  }
}


void analog_value_check() {
  while (1) {
    for (int8_t i = 0; i < sensorNumber; i++) {
      sensor_value[i] = analogRead(i);
      Serial.print(String(sensor_value[i]) + " ");
    }
    Serial.println();
  }
}