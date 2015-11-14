/*
 * Custom Hardware Abstraction Layer
 * IC: L293 H-Bridge
 *
 */

#include "Arduino.h"

#ifndef chal_l293_h
#define chal_l293_h

typedef enum  tL293_MODE {
    l293_free=0,
    l293_stop_h=1,
    l293_stop_l=2,
    l293_forward=3,
    l293_backward=4
} L293_MODE;

class ChalL293 {
private:
    int _pinA1; // Pin A CH.1 / 1A pin 2 on IC,
    int _pinB1; // Pin B CH.1 / 2A pin 7 on IC,
    int _pinEn1; // Pin En Ch.1 /1,2EN pin 1 on IC
    int _pinA2; // Pin A CH.1 / 3A pin 10 on IC,
    int _pinB2; // Pin B CH.1 / 4A pin 15 on IC,
    int _pinEn2; // Pin En Ch.1 / 3,4EN pin 9 on IC,
    L293_MODE _modeCh1;
    L293_MODE _modeCh2;
    void setMode(L293_MODE mode, int a, int b, int en);
    void setSpeed(L293_MODE mode,int en, byte val);

    
public:
    ChalL293(int a1, int b1, int en1, int a2, int b2, int en2);
    void setModeCh1(L293_MODE mode);
    void setModeCh2(L293_MODE mode);
    void setSpeedCh1(byte val);
    void setSpeedCh2(byte val);
    
    //void shift(int* data);
};



#endif
