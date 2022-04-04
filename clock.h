#include <stm32f0xx.h> 




volatile uint32_t msTicks;                /* counts 1ms timeTicks       */
/*----------------------------------------------------------------------------
  SysTick_Handler
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void)
{
  msTicks++;
}



/*----------------------------------------------------------------------------
  delays number of tick Systicks (happens every 1 ms)
 *----------------------------------------------------------------------------*/
void Delay (uint32_t dlyTicks)
{                                              
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks);
	
}





/*----------------------------------------------------------------------------
  set HSI as SystemCoreClock (HSE is not populated on STM32L-Discovery board)
 *----------------------------------------------------------------------------*/
void set_clock(char clock)

{

  RCC->CR |= ((uint32_t)RCC_CR_HSION);                      /* Enable HSI                        */ 
  while ((RCC->CR & RCC_CR_HSIRDY) == 0);                   /* Wait for HSI Ready                */

  RCC->CFGR = RCC_CFGR_SW_HSI;                              /* HSI is system clock               */
  while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);   /* Wait for HSI used as system clock */

  FLASH->ACR  = FLASH_ACR_PRFTBE;                           /* Enable Prefetch Buffer            */
  FLASH->ACR |= FLASH_ACR_LATENCY;                          /* Flash 1 wait state                */
 
  RCC->CFGR |= RCC_CFGR_HPRE_DIV1;                          /* HCLK = SYSCLK                     */
  RCC->CFGR |= RCC_CFGR_PPRE_DIV1;                          /* PCLK = HCLK                       */

  RCC->CR &= ~RCC_CR_PLLON;                                 /* Disable PLL */

  /*  PLL configuration:  = HSI * 12 = 48 MHz */
  RCC->CFGR &= ~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL);
	
	
	
	
	if(clock==48)
	 RCC->CFGR |=  (RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PLLMULL12);
	
	
	else if(clock==44)
	 RCC->CFGR |=  (RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PLLMULL11);	
	
	
	else if(clock==40)
	 RCC->CFGR |=  (RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PLLMULL10);	


	else if(clock==36)
	 RCC->CFGR |=  (RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PLLMULL9);	

	else if(clock==32)
	 RCC->CFGR |=  (RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PLLMULL8);	

	else if(clock==28)
	 RCC->CFGR |=  (RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PLLMULL7);	

	else if(clock==24)
	 RCC->CFGR |=  (RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PLLMULL6);	

	else if(clock==20)
	 RCC->CFGR |=  (RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PLLMULL5);	

	else if(clock==16)
	 RCC->CFGR |=  (RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PLLMULL4);	

	else if(clock==12)
	 RCC->CFGR |=  (RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PLLMULL3);		
	
		else if(clock==8)
	 RCC->CFGR |=  (RCC_CFGR_PLLSRC_HSI_Div2 | RCC_CFGR_PLLMULL2);	
		
		

	
	
	
	
	
            
  RCC->CR |= RCC_CR_PLLON;                                  /* Enable PLL                        */
  while((RCC->CR & RCC_CR_PLLRDY) == 0) __NOP();            /* Wait till PLL is ready            */

  RCC->CFGR &= ~RCC_CFGR_SW;                                /* Select PLL as system clock source */
  RCC->CFGR |=  RCC_CFGR_SW_PLL;    

  while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);   /* Wait till PLL is system clock src */
		
		
		
		
	SystemCoreClockUpdate(); 





  if (SysTick_Config(SystemCoreClock / 1000))     /* SysTick 1 msec interrupts  */
	{ 
    while (1);                         
  }

		
		
		
		
}












