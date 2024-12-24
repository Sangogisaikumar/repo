/* On-chip Includes */
#include <syscon.h>
#include <iocon.h>
#include <gpio.h>
#include <adc.h>

/* On Board Includes */
#include <analog.h>
#include <rgb.h>
#include <lcd.h>
#include <stdio.h>


void Init(void)
{
	// Hardware Inits
	SystemConfigAll();
	IOConfigAll();
	GPIOConfigAll();
	ADCConfig();	
	LCDInit();
}	

void Delay(unsigned long cycles)
{
	do
	{
		cycles--;
	}while(cycles>0);
}

float POT;

int main(void)
{

	Init(); 
	
	while(1) // Real Time Loop
	{
		POT = DtrmVoltage();
		
		LCDRowSelect(LCD_ROW1);
		printf("%.1f", POT);
	
		  if((POT/3.3) * 100 >= 50)
		  {
			  RGBSetColor(RGB_GREEN);	
		  }	
			
      else if((POT/3.3) * 100 >= 30 && (POT/3.3) * 100 <= 49)
			{
				RGBSetColor(RGB_YELLOW);
			}		
		
			else if((POT/3.3) * 100 >= 20 && (POT/3.3) * 100 <= 29)
			{
				RGBSetColor(RGB_RED);
			}
			
			else if((POT/3.3) * 100 < 20)
			{
				RGBSetColor(RGB_NONE);
				Delay(10000000);
				RGBSetColor(RGB_RED);
			}		
	}	
}






