#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "MiADC.h"
#include "MiLCD.h"
#include "Servo.h"
#include "EEPROM.h"
#include "Confi.h"
#include "Usart.h"
#include "Laser.h"
#include "TMRs.h"
//Variables
    int u=0;      //acumulador
    float v;    //distorcion
    int n;      //diametro
    char pepe[8];    
//Valores de las monedas
    float Mon[Canti_Mon];
    int Diame[Canti_Mon];
    
//Funcion Principal
void main(void){
    Inicializacion();   //Configuracion del pic
    while(1){  
        switch(Boton_Principal){
            case 0: //Modo Guardado de datos
                while(Laser_Pin==1);
                
                while(Laser_Pin==0){
                    TMR1_Start=1;
                    if(TMR1_Flag==1){
                        TMR1_Flag=0;
                        Coin_Size++;
                        TMR1_Reset();
                    }
                }
                Diame[i]=Coin_Size;
                Coin_Size=0;
                TMR1_Start=0;
                TMR1_Reset();
                
                
                
                
                
                
                
                
                
                Led=1;
                Start_Laser=1;
                n=Laser_TMR();
                // Necesito alago aqui xd                   
                v=0+1.0*LecturaADC(0)*5/(1024);
                LcdFloat(v,pepe);
                LcdEntero(u,pepe);
                Save_entero(n,30+u);
                Guardafloat(u,v);
                __delay_ms(250);
                Led=0;
                u++;                
            break;
            case 1: //Modo activacion
                for(u=0;u<Canti_Mon;u++)Mon[u]=SacaDatos(4*u);
                for(u=0;u<Canti_Mon;u++)Diame[u]=Show_data(30+u);
                while(Boton_Principal==1){
                    while(Laser_Pin==1);
                    Start_Laser=1;
                    n=Laser_TMR();
                    v=0+1.0*LecturaADC(0)*5/(1024);
                    Giro_Servo('90',Servo1);
                    for(u=0;u<Canti_Mon;u++){
                        if((v==Mon[u])&&(n==Diame[u])){
                           Led=1;
                           Giro_Servo('0',Servo1);
                           LcdFloat(v,pepe);
                           __delay_ms(250);
                           Led=0; 
                        }
                    }
                }
                u=0;
            break;
        }
    }
}