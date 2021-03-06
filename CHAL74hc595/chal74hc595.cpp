/*
 * Custom Hardware Abstraction Layer
 * IC: 74HC595 Serial Shift Register
 *
 */

#include "Arduino.h"
#include "chal74hc595.h"

Chal74hc595::Chal74hc595(int channels, int icsPerChannel){
    _channels=channels;
    _icsPerChannel=icsPerChannel;
    
}

void Chal74hc595::setup(int* _ds, int _sh, int _st){
    _pinDs=_ds; // Data Serial Pin (DS) 14 in IC
    _pinStCp=_st; // Storage Clock Pin (ST_CP) 12 in IC
    _pinShCp=_sh; // Shift Register Clok (SH_CP) 11 in IC
    
    for(int j=0;j<_channels;j++){
       pinMode(_ds[j], OUTPUT);
    }
    pinMode(_st, OUTPUT);
    pinMode(_sh, OUTPUT);
}

void Chal74hc595::shift(int* data){
    digitalWrite(_pinStCp, LOW);
    for(int i=_icsPerChannel;i>0;i--){
        uint8_t bi;
        for (bi = 0; bi < 8; bi++)  {
            for(int j=0;j<_channels;j++){
                digitalWrite(_pinDs[j],
                             !!(data[j*_icsPerChannel + i-1] & (1 << (7 - bi))));
                
            }
            digitalWrite(_pinShCp, HIGH);
            digitalWrite(_pinShCp, LOW);
//        shiftOut(_pinDs[j], _pinShCp, MSBFIRST, data[j*_icsPerChannel + i-1]);
        }
    }
    digitalWrite(_pinStCp, HIGH);
}