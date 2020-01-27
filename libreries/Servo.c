#include <xc.h>
#include "Servo.h"
#include <stdint.h>

#define _XTAL_FREQ 4000000UL
//Declarion de variables
  int i;

//Funciones
void Confi_Servo(void){
    Servo1_Tris=0;      //Programa al pin del Servo como salida
};
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Giro_Servo(char selec,int SelecDeServo){
    switch(selec){
        case '0':
            for(int i=0;i<16;i++){
            SelecDeServo=0;
            SelecDeServo=1;
            __delay_ms(g0);
            SelecDeServo=0;
            __delay_ms(20-g0);}
            break;
        case '90':
            for(int i=0;i<16;i++){
            SelecDeServo=0;
            SelecDeServo=1;
            __delay_ms(g90);
            SelecDeServo=0;
            __delay_ms(20-g90);}
            break;
        case '180':
            for(int i=0;i<16;i++){
            SelecDeServo=0;
            SelecDeServo=1;
            __delay_ms(g180);
            SelecDeServo=0;
            __delay_ms(20-g180);}
            break;            
    }
}