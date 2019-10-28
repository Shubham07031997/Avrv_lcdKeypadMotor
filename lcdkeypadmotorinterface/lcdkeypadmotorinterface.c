#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>
#include<lcdavr.h>

unsigned char keyscan();
int main()
{	
    
	DDRA = 0X00;
	DDRD = 0XFF;
	DDRC=0XFF;
	PORTA= 0XFF;
	DDRB = 0XFF;
	lcd_init();
	
	lcd_command(0x80);
	lcd_string("data");
	lcd_command(0xc0);
	


	while(1)
	{
	lcd_data(keyscan());
	_delay_ms(10);
	}
	return 0;
}
//*****************************************SUBROTINE************************************************


unsigned char keyscan()
{
		while(1)
	{
	PORTD = 0X0e;// switch no. is taken as reference or ground
	_delay_ms(5);  /////must for response at porta when key press
	if((PINA&0b00000001)==0){ return '7';}
	if((PINA&0b00000010)==0){while(!(PINA&0b00000010));PORTC=0b10100000;
	  _delay_ms(100);
	   return'4';}
	if((PINA&0b00000100)==0){while(!(PINA&0b00000100)); return '1';}
	if((PINA&0b00001000)==0){while(!(PINA&0b00001000)); return '3';}

	PORTD = 0X0d;//switch no. two is taken as ground/reference
	_delay_ms(5);
	if((PINA&0b00000001)==0){while(!(PINA&0b00000001)); PORTC=0b01010000;
	_delay_ms(100);
	return '8';}
	if((PINA&0b00000010)==0){while(!(PINA&0b00000010)); return '5';}
	if((PINA&0b00000100)==0){while(!(PINA&0b00000100));PORTC=0b00010000;
	_delay_ms(100);
	  return '2';}
	if((PINA&0b00001000)==0){while(!(PINA&0b00001000)); return '0';}

	PORTD = 0X0b;//switch no. three is taken as reference
	_delay_ms(5);
	if((PINA&0b00000001)==0){while(!(PINA&0b00000001)); return '9';}
	if((PINA&0b00000010)==0){while(!(PINA&0b00000010)); PORTC=0b01000000;
	_delay_ms(100);
	  return '6';}
	if((PINA&0b00000100)==0){while(!(PINA&0b00000100)); return '3';}
	if((PINA&0b00001000)==0){while(!(PINA&0b00001000)); return '=';}											

	PORTD = 0X07;//switch no.four is taken as reference
	_delay_ms(5);
	if((PINA&0b00000001)==0){while(!(PINA&0b00000001)); return '/';}
	if((PINA&0b00000010)==0){while(!(PINA&0b00000010)); return 'x';}
	if((PINA&0b00000100)==0){while(!(PINA&0b00000100)); return '-';}
    if((PINA&0b00001000)==0){while(!(PINA&0b00001000)); return '+';}

	}	  
}
//************************************END**************************************************

