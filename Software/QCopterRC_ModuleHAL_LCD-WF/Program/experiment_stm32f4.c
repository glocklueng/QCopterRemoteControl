/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f4_system.h"
#include "modules\module_otm8009.h"
#include "algorithms\algorithm_mathUnit.h"
#include "api\api_waveForm.h"

#include "experiment_stm32f4.h"
/*====================================================================================================*/
/*====================================================================================================*/
void WaveForm_Init( void );
void WaveForm_demo( void );

WaveForm_Struct WaveForm;
/*====================================================================================================*/
/*====================================================================================================*/
#define LCD_FB_START_ADDRESS       ((uint32_t)0xC0000000)
void System_Init( void )
{
  HAL_Init();
  GPIO_Config();

  LCD_Init();
  WaveForm_Init();
}

int main( void )
{
  System_Init();

  while(1) {
    LED_G_Toggle();
     WaveForm_demo();

    while(KEY_Read()) {
      LCD_TestColorClear();
      LCD_Clear(LCD_BLACK);
    }
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void WaveForm_Init( void )
{
	WaveForm.Channel     = 4;
	WaveForm.WindowColor = LCD_WHITE;
	WaveForm.BackColor   = LCD_BLACK;
  for(uint8_t i = 0; i < WaveForm.Channel; i++) {
    WaveForm.Data[i] = 0;
    WaveForm.Scale[i] = 100;
  }
	WaveForm.PointColor[0] = LCD_RED;
  WaveForm.PointColor[1] = LCD_BLUE;
  WaveForm.PointColor[2] = LCD_YELLOW;
  WaveForm.PointColor[3] = LCD_GREEN;

  LCD_Clear(LCD_BLACK);
}
void WaveForm_demo( void )
{
  float data = 0.0f;
  static float rad = 0.0f;
//  static float theta = 0.0f;

  rad += 0.01f;
  for(uint8_t i = 1; i < 10; i = i + 2)
    data += (1.0f / i) * arm_sin_f32(i * rad);

  WaveForm.Data[0] = arm_sin_f32(rad) * 20000;
  WaveForm.Data[1] = (1.0f/3) * arm_sin_f32(3 * rad) * 20000;
  WaveForm.Data[2] = (1.0f/5) * arm_sin_f32(5 * rad) * 20000;
  WaveForm.Data[3] = data * 20000;
  WaveFormPrint(&WaveForm, ENABLE);
}
/*====================================================================================================*/
/*====================================================================================================*/
