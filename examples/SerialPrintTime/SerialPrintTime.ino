#include<TimeSynchronizer.h>

TimeSynchronizer timeSynchronizer;

void setup() {
  Serial.begin(9600);
  timeSynchronizer.ExternalSynchronization(19, 30, 28);
}

void loop() {
  Serial.println(timeSynchronizer.TimeToString());
}