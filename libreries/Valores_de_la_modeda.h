/* 
 * File:   Valores_de_la_modeda.h
 * Author: EDWIN
 *
 * Created on 10 de julio de 2019, 05:52 PM
 */

#ifndef VALORES_DE_LA_MODEDA_H
#define	VALORES_DE_LA_MODEDA_H

// Constantes de lectura
#define Umbral     3
#define N_MUESTRAS 40
#define Tiempo_de_muestreo 100

// Banderas de cambio
volatile uint8_t bandera_cambio = 0;
volatile uint8_t bandera_leer_adc = 0;
volatile uint8_t bandera_muestreo_completo = 0;

//Valores del Pic
uint16_t willi[N_MUESTRAS];
uint16_t points[3];
volatile uint16_t valor_adc;

// Funciones
uint8_t Detecta_Cambio(void);
void Leer_Moneda(void);
void Coil (void);

#endif	/* VALORES_DE_LA_MODEDA_H */

