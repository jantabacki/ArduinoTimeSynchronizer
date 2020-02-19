#include "TimeSynchronizer.h"

void TimeSynchronizer::internalSynchronization() {
  currentMillis = millis();
  long timeSpan = currentMillis - previousMillis;
  previousMillis = currentMillis;
  long secondToAdd = timeSpan / 1000;
  long millisToSubstract = timeSpan % 1000;
  previousMillis -= millisToSubstract;
  totalSeconds += secondToAdd;
  totalSeconds %= 86400;
  updateTimeVariables();
}

void TimeSynchronizer::updateTimeVariables(){
  long restOfSeconds = totalSeconds % 3600;
  long fullHoursInSeconds = totalSeconds - restOfSeconds;
  hour = fullHoursInSeconds / 3600;
  long restOfSecondsToDisplay = restOfSeconds % 60;
  long fullMinutesInSeconds = restOfSeconds - restOfSecondsToDisplay;
  minute = fullMinutesInSeconds / 60;
  second = restOfSecondsToDisplay;
}

void TimeSynchronizer::ExternalSynchronization(long externalHour, long externalMinute, long externalSecond) {
  totalSeconds = externalSecond + externalMinute * 60 + externalHour * 60 * 60;
  previousMillis = millis();
}

int TimeSynchronizer::GetHour() {
  internalSynchronization();
  return hour;
}

int TimeSynchronizer::GetMinute() {
  internalSynchronization();
  return minute;
}

int TimeSynchronizer::GetSecond() {
  internalSynchronization();
  return second;
}

String TimeSynchronizer::TimeToString() {
  internalSynchronization();
  String valueToReturn = "";
  if (hour >= 10){
    valueToReturn += String(hour);
  }
  else{
    valueToReturn += "0";
    valueToReturn += String(hour);
  }
  valueToReturn += ":";
  if (minute >= 10){
    valueToReturn += String(minute);
  }
  else{
    valueToReturn += "0";
    valueToReturn += String(minute);
  }
  valueToReturn += ":";
  if (second >= 10){
    valueToReturn += String(second);
  }
  else{
    valueToReturn += "0";
    valueToReturn += String(second);
  }
  return valueToReturn;
}
