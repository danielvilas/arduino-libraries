/*
 * Custom Hardware Abstraction Layer
 * IC: 74HC595 Serial Shift Register
 *
 */

#include "Arduino.h"

#ifndef chal74hc595_h
#define chal74hc595_h

class Chal74hc595 {
private:
    int _pinDs; // Data Serial Pin (DS) 14 in IC
    int _pinStCp; // Storage Clock Pin (ST_CP) 12 in IC
    int _pinShCp; // Shift Register Clok (SH_CP) 11 in IC
    int _channels;
    int _icsPerChannel;
    
public:
    Chal74hc595(int channels, int icsPerChannel);
    void setup(int _ds, int _sh, int _st);
    void shift(int* data);
};

#endif