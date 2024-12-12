/*
 ******************************************************************************
 * @file           : STM32F4xx_HAL_RCC.c
 * @author         : Youssef Ibrahem
 * @brief          : static code to control rcc
 *******************************************************************************
 */
#include "HAL_Drivers/STM32F4xx_HAL_RCC.h"
#include "HAL_Drivers/STM32F4xx_Peripheral_Defs.h"






HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct)
{
	HAL_StatusTypeDef Ret_Stat = HAL_ERROR;
	if( (IS_RCC_PtrOscInitType(RCC_OscInitStruct)) )
	{

		 	 /**************** HSE Config ***************/
		if(IS_RCC_OsillatorType_HSE(RCC_OscInitStruct->OscillatorType))
		{
			if( IS_RCC_HSEState_ON(RCC_OscInitStruct->HSEState))
			{
				/*system clock select HSE*/

				MODIFY_REG(RCC.CFGR , RCC_CFGR_SW_Msk , RCC_CFGR_SW_HSE_SELECT_Msk);
				SET_BIT(RCC.CR , HAL_RCC_HSE_HSEON_Msk); /* enable HSE clock*/
			}
			else
			{

				CLEAR_BIT(RCC.CR , HAL_RCC_HSE_HSEON_Msk); /* bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock*/
			}

			Ret_Stat  = HAL_OK;
		}
		 	 /**************** HSI Config ***************/
		else if (IS_RCC_OsillatorType_HSI(RCC_OscInitStruct->OscillatorType) )
		{
			if( IS_RCC_HSIState_ON(RCC_OscInitStruct->HSIState))
			{

			}
			else
			{

			}
			Ret_Stat  = HAL_OK;
		}
		 	 /**************** LSE Config ***************/
		else if (IS_RCC_OsillatorType_LSE(RCC_OscInitStruct->OscillatorType))
		{

			if( IS_RCC_LSEState_ON(RCC_OscInitStruct->LSEState))
			{

			}
			else
			{

			}
			Ret_Stat  = HAL_OK;
		}
		 	 /**************** LSI Config ***************/
		else if (IS_RCC_OsillatorType_LSI(RCC_OscInitStruct->OscillatorType))
		{

			if( IS_RCC_LSIState_ON(RCC_OscInitStruct->LSIState))
			{

			}
			else
			{

			}
			Ret_Stat  = HAL_OK;
		}
		else
		{
			Ret_Stat  = HAL_ERROR;
		}

	}
	else
	{
		//Nothing
	}

	return Ret_Stat;
}

HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct)
{
	HAL_StatusTypeDef Ret_Stat = HAL_ERROR;
	if (NULL != RCC_ClkInitStruct)
	{
		MODIFY_REG(RCC.CFGR ,RCC_CFGR_HPRE_Msk , RCC_ClkInitStruct->AHBCLKDivider);
		MODIFY_REG(RCC.CFGR ,RCC_CFGR_PPRE1_Msk , RCC_ClkInitStruct->APB1CLKDivider);
		MODIFY_REG(RCC.CFGR ,RCC_CFGR_PPRE2_Msk , RCC_ClkInitStruct->APB2CLKDivider);
		Ret_Stat = HAL_OK;
	}
	else
	{
		/* nothing */
	}

	return Ret_Stat;
}
HAL_StatusTypeDef HAL_RCC_DeInit(void)
{

	return HAL_OK;
}
