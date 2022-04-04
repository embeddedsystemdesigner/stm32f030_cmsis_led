#include <stm32f0xx.h> 
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_rcc.h"
#include "clock.h"

// telegram id --->    @eneeir
// github --->  https://github.com/embeddedsystemdesigner
// website  ---> www.enee.ir





int main (void)
{
	
	int count;
	uint16_t leds[8]={GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2,GPIO_Pin_3,GPIO_Pin_4,GPIO_Pin_5,GPIO_Pin_6,GPIO_Pin_7};
	
	GPIO_InitTypeDef GPIO_InitStructure;

	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;						  
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);


  set_clock(8);
	
	
	while(1)
	{
		
		
		
		for(count=0; count<=7; count++)
		{
	   	GPIO_SetBits(GPIOA,leds[count]);
      Delay(500);			
		}
		
		
		
	  for(count=0; count<=7; count++)
		{
	   GPIO_ResetBits(GPIOA,leds[count]);
			Delay(500);	
		}
	
		
		



		
	}//end of while
	
	
}//end of main



