/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Youssef Ibrahem
 * @brief          : Main program body
 ******************************************************************************
 */
#include "common/Std_types.h"
#include "CortexM4/CortexM4_Core_Interface.h"
#include "HAL_Drivers/STM32F4xx_HAL_RCC.h"
#include "CortexM4/CortexM4_Core_SysTick.h"
#include "HAL_Drivers/STM32F4xx_GPIO.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


void USART2_IRQHandler(void);
void EXTI15_10_IRQHandler(void);
void systemClockConfig(void);

u8_t retval;
u32_t counter;
volatile u32_t systickHandler;
void systick_1(void);
int main(void)
{

	systemClockConfig();
//	SysTick_PeriodicInterval(1000000UL,systick_1);
	HAL_GPIO_Write(GPIOC, 0x00UL);
    /* Loop forever */
	for(;;)
	{
		HAL_GPIO_Write(GPIOC, 0xFFFFUL);
	}
}

void systemClockConfig(void)
{
	HAL_StatusTypeDef ret = HAL_ERROR;
	RCC_OscInitTypeDef OSC = {
			.OscillatorType = RCC_OSCILLATORTYPE_HSE,
			.HSEState = RCC_HSE_ON,
			.HSIState = RCC_HSI_OFF,
			.LSIState = RCC_LSI_OFF,
			.LSEState = RCC_LSE_OFF,
	};
	RCC_ClkInitTypeDef clk = {
			.APB1CLKDivider = RCC_HCLK1_DIV1,
			.APB2CLKDivider = RCC_HCLK2_DIV1,
			.AHBCLKDivider = RCC_SYSCLK_DIV1

	};
	ret = HAL_RCC_OscConfig(&OSC);
	ret |= HAL_RCC_ClockConfig(&clk);

	GPIO_InitTypeDef c13 = {
			.Mode = GPIO_MODE_OUTPUT_PP,
			.Pin =  GPIO_PIN_13,
			.Pull = GPIO_NOPULL,
			.Speed =GPIO_SPEED_FREQ_LOW,
//			.Alternate = GPIO_AF12_SDIO

	};
	HAL_GPIO_Init(GPIOC,&c13);
}
void systick_1(void)
{
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	systickHandler++;
}
