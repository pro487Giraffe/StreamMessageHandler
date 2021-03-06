/*************************************************************************
    File        : 3_OverrideNumberStates.ino (opens in arduino IDE www.arduino.cc)
    Description : Example sketch using SerialEventParser Library
    Usage       : Using the Arduino serial monitor you can call the state
                  functions below by sending the state name ending in
                  "new line". In order to get a proper greeting, provide
                  your name as the first parameter.
    Example     : getTime\n
                  getGreeting::Larry\n
*************************************************************************/

#include <Arduino.h>

#define SMH_MAX_STATES 2                                                  // Overrides the maximum number of states that can be registered (default 10)
#define SMH_MAX_PARAMETERS 1                                              // Overrides the maximum number of parameters per state (default 10)

#include <StreamMessageHandler.h>

StreamMessageHandler handler;                                             // Defaults to using Serial "type" stream communication

state getTime() {
  handler.println(millis());
}

state getGreeting() {
  handler.println("Hello " + handler.parameter(0) + ", have a nice day!");
}

void setup() {
  Serial.begin(9600);                                                     // Begin Serial communication at 9600 baud
  handler.registerState(getTime, "getTime");                              // Register the "getTime" state for callback
  handler.registerState(getGreeting, "getGreeting");                      // Register the "getGreeting" state for callback
}

void loop() {
  handler.run();                                                          // Run and monitor stream for messages, instantiate callbacks when received
}

/*************************************************************************
    End of File : 3_OverrideNumberStates.ino
*************************************************************************/
