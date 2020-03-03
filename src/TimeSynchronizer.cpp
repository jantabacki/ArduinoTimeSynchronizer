#include "TimeSynchronizer.h"

void TimeSynchronizer::internalSynchronization() {
  currentMillis = millis();
  unsigned long timeSpan = currentMillis - previousMillis;
  previousMillis = currentMillis;
  unsigned long secondToAdd = timeSpan / 1000;
  unsigned long millisToSubstract = timeSpan % 1000;
  previousMillis -= millisToSubstract;
  totalSeconds += secondToAdd;
  updateTimeVariables();
}

void TimeSynchronizer::updateTimeVariables(){
  unsigned long restOfSeconds = totalSeconds % 3600;
  unsigned long fullHoursInSeconds = totalSeconds - restOfSeconds;
  hour = (fullHoursInSeconds % 86400) / 3600;
  unsigned long restOfSecondsToDisplay = restOfSeconds % 60;
  unsigned long fullMinutesInSeconds = restOfSeconds - restOfSecondsToDisplay;
  minute = fullMinutesInSeconds / 60;
  second = restOfSecondsToDisplay % 60;
}

unsigned long TimeSynchronizer::GetTotalSeconds(){
	internalSynchronization();
	return totalSeconds;	
}

void TimeSynchronizer::ExternalSynchronization(unsigned long externalHour, unsigned long externalMinute, unsigned long externalSecond) {
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
