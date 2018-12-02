/*
 * Generador de frecuencia 20khz.c
 *
 * Created: 17/05/2018 07:06:13 p. m.
 * Author : dx_ch
 */ 
#define  F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned int Pulsos=0;
unsigned int PulsosXSeg=0;
unsigned int MiliSeg=0;

int main(void)
{
	DDRB|=0x04;	//(1<<PORTB2);	
	TCCR1A= 0x10;	//Cambia estado en el pin OC1B----->PB2.
	TCCR1B= 0x0A;	//Prescalador de 8, modo CTC con registro a OCR1A.
	OCR1A= 5000;//5000;		//50000;	//Aqui manda 50 mS de tiempo	//50;	//Aqui manda 50uS de tiempo;		//Comparación de 20 khz con un prescalador de 8
	TIMSK1|=1<<TOIE1;
	//Habilita interrupcion externa 0 por flanco de subida
	EICRA|=(1<<ISC01)|(1<<ISC00);
	EIMSK|=1<<INT0;
	
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB|=0x04;
		_delay_ms(10);
		PORTB&=~0x04;
		_delay_ms(2);
    }
	
}
