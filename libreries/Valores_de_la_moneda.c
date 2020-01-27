
#include <xc.h>
#include <stdint.h>
#include "MiADC.h"
#include "Usart.h"
#include "Servo.h"
#include "Valores_de_la_modeda.h"

int i;
static int a;

void Coil (void){
    
        if(bandera_leer_adc == 1){
            valor_adc = LecturaADC(0);
            if(bandera_cambio == 1){
                LATDbits.LATD0=1;
                Leer_Moneda();
                a=Detecta_Cambio();
            }else{
                bandera_cambio = Detecta_Cambio();
            }
        
        }        
        if(bandera_muestreo_completo == 1){
            UART0_Tx_String("A=[");
            for(i=0;i<N_MUESTRAS;i++){ 
                UART0_Tx_Integer(willi[i]);
                if(i<N_MUESTRAS-1)UART0_Tx_String(",");
            }
            UART0_Tx_String("]; \n\r");
            bandera_muestreo_completo = 0;
        }
}

uint8_t Detecta_Cambio(void){
        
    int16_t diferencia1;
    int16_t diferencia2;
    
    uint8_t salida;
            
    points[0]=points[1];
    points[1]=points[2];
    points[2]=valor_adc;
    
    
    diferencia1 = (int16_t)points[2] - (int16_t)points[1];
    diferencia2 = (int16_t)points[0] - (int16_t)points[1];
    
    if (((diferencia1>Umbral)||(diferencia1<-Umbral))&&((diferencia2>Umbral)||(diferencia2<-Umbral))){
        LATDbits.LATD0=1;
        salida = 1;
    }else{
        salida = 0;
    }
   
    return salida;
}

void Leer_Moneda(void){
    
    static uint8_t i = 0;
    
   willi[i]=valor_adc;
   
   i++;
   
   if(i >= N_MUESTRAS){
       i = 0;
       bandera_muestreo_completo = 1;
       bandera_cambio = 0;
       LATDbits.LATD0=0;
   }
         
   
}

/*
void __interrupt(high_priority) Timer0_ISR(void){
    
    static uint16_t conta_1ms = 0;
   
    if(Laser_Flag==1){
        TMR0H=((Offset)>>8)&0xff;           //Setear al TMR0 para que 
        TMR0L=(Offset)&0xff;
        Laser_Flag=0;
        conta_1ms++;
        if(conta_1ms == Tiempo_de_muestreo){
            conta_1ms=0;
            bandera_leer_adc = 1;
        }
        
    }
}
*/