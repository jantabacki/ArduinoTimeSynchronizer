#ifndef TimeSynchronizer_h
#define TimeSynchronizer_h

#include "Arduino.h"

class TimeSynchronizer {
  private:
    long previousMillis = 0;
    long currentMillis = 0;
    long totalSeconds = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;
    void internalSynchronization();
	  void updateTimeVariables();
  public:
    void ExternalSynchronization(long, long, long);
    int GetHour();
    int GetMinute();
    int GetSecond();
    String TimeToString();
};

#endif
