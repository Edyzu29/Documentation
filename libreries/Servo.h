/* 
 * File:   Servo.h
 * Author: EDWIN
 *
 * Created on 7 de junio de 2019, 09:29 AM
 */

#ifndef SERVO_H
#define	SERVO_H

//Seteo de Pines
#define Servo1_Tris TRISDbits.RD1

//Control de Servos
#define Servo1      LATDbits.LATD1

//Grados del Servo    
#define g0    0.5
#define g90   1.5
#define g180  2.5

//Funciones
void Giro_Servo (char,int);
void Confi_Servo (void);

#endif	/* SERVO_H */

