/* 
 * File:   Confi.h
 * Author: EDWIN
 *
 * Created on 12 de junio de 2019, 01:55 PM
 */

#ifndef CONFI_H
#define	CONFI_H

/* Constantes y macros */
#define Tris_Principal TRISDbits.RD7
#define Tris_Save      TRISDbits.RD6
#define Tris_Led       TRISDbits.RD0

#define Boton_Principal PORTDbits.RD7
#define Boton_Save      PORTDbits.RD6
#define Led             LATDbits.LATD0

#define Canti_Mon         6

#define _XTAL_FREQ 8000000

//Declarar Variables
    
//Declarar funciones
void Inicializacion (void);
void LcdFloat (float,char);
void LcdEntero (int,char);

#ifdef	__cplusplus
}
#endif

#endif	/* CONFI_H */

