/*
 * Custom Hardware Abstraction Layer
 * IC: L293 H-Bridge
 *
 */

#include "Arduino.h"
#include "chall293.h"

ChalL293::ChalL293(int a1, int b1, int en1, int a2, int b2, int en2){
    _pinA1=a1; // Pin A CH.1 / 1A pin 2 on IC,
    _pinB1=b1; // Pin B CH.1 / 2A pin 7 on IC,
    _pinEn1=en1; // Pin En Ch.1 /1,2EN pin 1 on IC
    _pinA2=a2; // Pin A CH.1 / 3A pin 10 on IC,
    _pinB2=b2; // Pin B CH.1 / 4A pin 15 on IC,
    _pinEn2=en2; // Pin En Ch.1 / 3,4EN pin 9 on IC,
    
    setModeCh1(l293_free);
    setModeCh2(l293_free);
    
}

void ChalL293::setMode(L293_MODE mode, int a, int b, int en){
    //digitalWrite(en, LOW); //
    switch (mode) {
        case l293_free:
            digitalWrite(a,LOW);
            digitalWrite(b,LOW);
            digitalWrite(en,LOW);
            break;
            
        case l293_stop_h:
            digitalWrite(a,HIGH);
            digitalWrite(b,HIGH);
            digitalWrite(en,HIGH);
            break;
            
        case l293_stop_l:
            digitalWrite(a,LOW);
            digitalWrite(b,LOW);
            digitalWrite(en,HIGH);
            break;
            
            
        case l293_forward:
            digitalWrite(a,HIGH);
            digitalWrite(b,LOW);
            //digitalWrite(en,LOW);
            break;
            
        case l293_backward:
            digitalWrite(a,LOW);
            digitalWrite(b,HIGH);
            //digitalWrite(en,LOW);
            break;
        default:
            break;
    }
}

void ChalL293::setModeCh1(L293_MODE mode){
    _modeCh1=mode;
    setMode(mode,_pinA1,_pinB1,_pinEn1);
}

void ChalL293::setModeCh2(L293_MODE mode){
    _modeCh2=mode;
    setMode(mode,_pinA2,_pinB2,_pinEn2);
}

void ChalL293::setSpeed(L293_MODE mode,int en, byte val){
    if(mode == l293_backward || l293_forward){
        analogWrite(en,val);
    }
}

void ChalL293::setSpeedCh2(byte val){
    setSpeed(_modeCh1,_pinEn1,val);
}
void ChalL293::setSpeedCh1(byte val){
    setSpeed(_modeCh2,_pinEn2,val);
}
/*
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
}*/