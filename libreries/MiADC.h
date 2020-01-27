/* 
 * File:   MiLCD.h
 * Author: EDUARDO
 *
 * Created on 12 de mayo de 2018, 08:11 PM
 */

#ifndef MIADC_H
#define	MIADC_H

#define ACQ_US_DELAY 5

#define VMAX 5
#define VMIN 0
#define RESOLUCION 10
#define LectorAdc TRISAbits.RA0

void ConfigADC(void);
uint16_t LecturaADC(uint8_t);

#ifdef	__cplusplus
}
#endif

#endif	/* MIADC_H */

