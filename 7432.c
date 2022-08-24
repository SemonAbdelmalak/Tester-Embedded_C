#define F_CPU 11000000UL
#include <mega16a.h>
#include <io.h>
#include <stdint.h>
#include <delay.h>
#include <stdio.h>
#define A0  PORTA.0
#define A1  PORTA.1
#define A5  PORTA.5
#define A6  PORTA.6
#define A7  PORTA.7
#define D2  PORTD.2
#define D4  PORTD.4
#define D5  PORTD.5
#define D6  PORTD.6
#define C6  PORTC.6
#define C7  PORTC.7
#define B0  PORTB.0
#define B1  PORTB.1
#define B2  PORTB.2
#define B3  PORTB.3
void main(){
    
    int i;
    int flag = 0;

    DDRA = 0b01100011 ;
    DDRB = 0b00000110 ; 
    DDRD = 0b00110000 ;
    DDRC = 0b11000000 ;    
    
    D2=1;   
    
    for (;PIND.2 == 1;); 
    delay_ms(100);
    
    for(i=0;i<=3;i++){ 
        A5=(int)i%2;
        A6=(int)i/2;  
        D4=(int)i%2;
        D5=(int)i/2; 
        C6=(int)i%2;
        C7=(int)i/2;
        B1=(int)i%2;
        B2=(int)i/2;  
        
        delay_ms(100);    
        
        if( PINA.7!=(PINA.5|PINA.6)){ 
           flag=1;  
           break; 
        }   
        if(PIND.6 != (PIND.4||PIND.5)){  
          flag = 1 ;
          break; 
       }
        if(PINB.0 != (PINC.6|PINC.7)){  
          flag = 1 ;
          break;
        }
        if(PINB.3 != (PINB.2|PINB.1)){  
          flag = 1 ; 
          break;
        }        
    }  
        

    if (!flag){       
      A1=1;
      A0=0;   

    } 
    while(1);
    
            
}