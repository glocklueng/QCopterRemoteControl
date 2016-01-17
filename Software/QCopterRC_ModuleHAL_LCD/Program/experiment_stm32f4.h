/* #include "experiment_stm32f4.h" */

#ifndef __EXPERIMENT_STM32F4_H
#define __EXPERIMENT_STM32F4_H

#include "stm32f4xx_hal.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define LED_R_PIN                 GPIO_PIN_5
#define LED_R_GPIO_PORT           GPIOD
#define LED_R_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOD_CLK_ENABLE()
#define LED_R_Set()               __GPIO_SET(LED_R_GPIO_PORT, LED_R_PIN)
#define LED_R_Reset()             __GPIO_RST(LED_R_GPIO_PORT, LED_R_PIN)
#define LED_R_Toggle()            __GPIO_TOG(LED_R_GPIO_PORT, LED_R_PIN)

#define LED_G_PIN                 GPIO_PIN_6
#define LED_G_GPIO_PORT           GPIOG
#define LED_G_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOG_CLK_ENABLE()
#define LED_G_Set()               __GPIO_SET(LED_G_GPIO_PORT, LED_G_PIN)
#define LED_G_Reset()             __GPIO_RST(LED_G_GPIO_PORT, LED_G_PIN)
#define LED_G_Toggle()            __GPIO_TOG(LED_G_GPIO_PORT, LED_G_PIN)

#define LED_B_PIN                 GPIO_PIN_3
#define LED_B_GPIO_PORT           GPIOK
#define LED_B_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOK_CLK_ENABLE()
#define LED_B_Set()               __GPIO_SET(LED_B_GPIO_PORT, LED_B_PIN)
#define LED_B_Reset()             __GPIO_RST(LED_B_GPIO_PORT, LED_B_PIN)
#define LED_B_Toggle()            __GPIO_TOG(LED_B_GPIO_PORT, LED_B_PIN)

#define LED_Y_PIN                 GPIO_PIN_4
#define LED_Y_GPIO_PORT           GPIOD
#define LED_Y_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOD_CLK_ENABLE()
#define LED_Y_Set()               __GPIO_SET(LED_Y_GPIO_PORT, LED_Y_PIN)
#define LED_Y_Reset()             __GPIO_RST(LED_Y_GPIO_PORT, LED_Y_PIN)
#define LED_Y_Toggle()            __GPIO_TOG(LED_Y_GPIO_PORT, LED_Y_PIN)

#define KEY_PIN                   GPIO_PIN_0
#define KEY_GPIO_PORT             GPIOA
#define KEY_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define KEY_Read()                (__GPIO_READ(KEY_GPIO_PORT, KEY_PIN) == KEY_PIN)
/*====================================================================================================*/
/*====================================================================================================*/
void GPIO_Config( void );
/*====================================================================================================*/
/*====================================================================================================*/
#endif
