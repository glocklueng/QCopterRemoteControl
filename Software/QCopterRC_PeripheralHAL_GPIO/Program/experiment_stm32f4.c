/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f4_system.h"

#include "experiment_stm32f4.h"
/*====================================================================================================*/
/*====================================================================================================*/
void System_Init( void )
{
  HAL_Init();
  GPIO_Config();
}

int main( void )
{
  System_Init();

  while(1) {
    LED_R_Toggle();
    LED_G_Toggle();
    LED_B_Toggle();
    LED_Y_Toggle();
    delay_ms(100);
 
    while(KEY_Read()) {
      LED_B_Set();
      LED_G_Reset();
      delay_ms(100);
      LED_G_Set();
      LED_Y_Reset();
      delay_ms(100);
      LED_Y_Set();
      LED_R_Reset();
      delay_ms(100);
      LED_R_Set();
      LED_B_Reset();
      delay_ms(100);

      LED_R_Set();
      LED_G_Set();
      LED_B_Set();
      LED_Y_Set();
    }
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
