#ifndef Reaktionstest_h
#define Reaktionstest_h
#include "Arduino.h"
class RT {
  public:
    RT();
    void animation();
    void start_test();
  private:
    void oneLed();
    void twoLed();
    void threeLed();
    void fourLed();
    void fiveLed();
    void sixLed();
    void sevenLed();
    void reset();
    void testAnimation();
    void wait_until_release();
    void test_loop();
    int led1;
    int led2;
    int led3;
    int led4;
    int led5;
    int led6;
    int led7;
    int buttonPin;
};
#endif
