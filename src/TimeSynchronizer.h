#ifndef TimeSynchronizer_h
#define TimeSynchronizer_h

#include "Arduino.h"

class TimeSynchronizer {
  private:
    unsigned long previousMillis = 0;
    unsigned long currentMillis = 0;
    unsigned long totalSeconds = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;
    void internalSynchronization();
	  void updateTimeVariables();
  public:
    void ExternalSynchronization(unsigned long, unsigned long, unsigned long);
    int GetHour();
    int GetMinute();
    int GetSecond();
	unsigned long GetTotalSeconds();
    String TimeToString();
};

#endif
