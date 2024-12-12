/*
 ******************************************************************************
 * @file           : STM32F4xx_GPIO.c
 * @author         : Youssef Ibrahem
 * @brief          : STM32F4xx_GPIO.c
 ******************************************************************************
 */
#include "HAL_Drivers/STM32F4xx_GPIO.h"
#include "HAL_Drivers/STM32F4xx_HAL_RCC.h"


/* private macro*/
#define GPIO_NUMBER           16U

/* Private Macro functions*/
#define GPIO_MODER_CLEAR_Msk(_PIN)		((GPIO_MODE_Msk) << ((_PIN) << 1UL))

#define GPIO_OTYPER_CLEAR_Msk(_PIN)		((GPIO_TYPE_Msk << (_PIN)))

#define GPIO_PUPDR_CLEAR_Msk(_PIN)		(( GPIO_PUPDR_Msk << ((_PIN) << 1UL)))

#define GPIO_OSPEEDR_CLEAR_Msk(_PIN)	((GPIO_OSPEEDR_Msk << ((_PIN) << 1UL)))

#define GPIO_AFR_CLEAR_Msk(_PIN)		((GPIO_AFR_Msk << (((_PIN) & 7UL) << 2UL)))

/**
  * @brief  Initializes the GPIOx peripheral according to the specified parameters in the GPIO_Init.
  * @param  GPIOx where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
  *                      x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
  * @param  GPIO_Init pointer to a GPIO_InitTypeDef structure that contains
  *         the configuration information for the specified GPIO peripheral.
  * @retval None
  */
void  HAL_GPIO_Init(volatile GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init)
{
	u32_t temp = 0;
	if(NULL != GPIOx && NULL != GPIO_Init && (IS_GPIO(GPIOx)) )
	{

		/*enable GPIO CLK*/
		switch((u32_t)GPIOx)
		{
		case (u32_t)GPIOA:
			HAL_RCC_GPIOA_CLK_ENABLE();
			break;
		case (u32_t)GPIOB:
			HAL_RCC_GPIOB_CLK_ENABLE();
			break;
		case (u32_t)GPIOC:
			HAL_RCC_GPIOC_CLK_ENABLE();
			break;
		case (u32_t)GPIOD:
			HAL_RCC_GPIOD_CLK_ENABLE();
			break;
		case (u32_t)GPIOE:
			HAL_RCC_GPIOE_CLK_ENABLE();
			break;
		case (u32_t)GPIOH:
			HAL_RCC_GPIOH_CLK_ENABLE();
			break;
		default :
			return;
			break;
		}
		/*Select Gpio mode*/
		if(IS_GPIO_MODE(GPIO_Init->Mode))
		{
			temp = (READ_BIT(GPIO_Init->Mode ,GPIO_MODE_Msk) << (GPIO_Init->Pin << 1UL) ); /*Set mask for Mode reg*/
			GPIOx->MODER = MODIFY_REG(GPIOx->MODER , GPIO_MODER_CLEAR_Msk(GPIO_Init->Pin) , temp);
			/*select gpio pull*/
			temp = ( READ_BIT(GPIO_Init->Mode , 0x04UL) >> GPIO_TYPE_Pos ) << (GPIO_Init->Pin); /*Set mask for type reg*/
			GPIOx->OTYPER = MODIFY_REG(GPIOx->OTYPER , GPIO_OTYPER_CLEAR_Msk(GPIO_Init->Pin) ,  temp);
		}
		else
		{/*nothing*/}
		/*configure pull up or down */
		if( (GPIO_Init->Mode & GPIO_MODE_Msk)  != GPIO_MODE_ANALOG)
		{
			temp = (GPIO_Init->Pull << (GPIO_Init->Pin << 1UL)); /*Set mask for PUPDR reg*/
			GPIOx->PUPDR = MODIFY_REG(GPIOx->PUPDR ,  GPIO_PUPDR_CLEAR_Msk(GPIO_Init->Pin)  , temp);
		}
		else
		{/*nothing*/}

		/*configure ospeed if pin is output or AF*/
		if(IS_GPIO_MODE_OUTPUT_AF(GPIO_Init->Mode))
		{
			temp = (GPIO_Init->Speed << (GPIO_Init->Pin << 1UL)); /*Set mask for speed reg*/
			GPIOx->OSPEEDR = MODIFY_REG(GPIOx->OSPEEDR , GPIO_OSPEEDR_CLEAR_Msk(GPIO_Init->Pin) , temp);
		}
		else
		{/*nothing*/}
		/*configure AF*/
		if(IS_GPIO_MODE_AF((GPIO_Init->Mode)))
		{
			temp = (GPIO_Init->Alternate << ((GPIO_Init->Pin & 7UL) << 2UL)); /*Set mask for AF reg*/
			GPIOx->AFR[GPIO_Init->Pin >> 3UL] = MODIFY_REG(GPIOx->AFR[(GPIO_Init->Pin >> 3UL)] ,GPIO_AFR_CLEAR_Msk(GPIO_Init->Pin) ,temp);
		}
		else
		{/*nothing*/}
	}
	else
	{/*nothing*/}
}

void  HAL_GPIO_DeInit(volatile GPIO_TypeDef  *GPIOx, u16_t GPIO_Pin)
{
	if(NULL != GPIOx && ((GPIO_Pin & ~GPIO_Pin) == 0UL) && (IS_GPIO(GPIOx)) )
	{
		/*Reset mode */
		CLEAR_BIT(GPIOx->MODER , GPIO_MODER_CLEAR_Msk((u32_t)GPIO_Pin) );
		/*Reset Type */
		CLEAR_BIT(GPIOx->OTYPER , GPIO_OTYPER_CLEAR_Msk((u32_t)GPIO_Pin) );
		/*reset pull */
		CLEAR_BIT( GPIOx->PUPDR , GPIO_PUPDR_CLEAR_Msk((u32_t)GPIO_Pin) );
		/*Reset OSpeed*/
		CLEAR_BIT( GPIOx->OSPEEDR , GPIO_OSPEEDR_CLEAR_Msk((u32_t)GPIO_Pin) );
		/*Reset AF*/
		CLEAR_BIT( GPIOx->AFR[GPIO_Pin >> 3UL] , GPIO_AFR_CLEAR_Msk((u32_t)GPIO_Pin) );
		/*Reset  Logic */
		CLEAR_BIT(GPIOx->BSRR , (1UL<<GPIO_Pin));
		SET_BIT(GPIOx->BSRR , (1UL<< (GPIO_Pin+16UL)) );
	}
	else
	{/*nothing*/}
}

/**
  * @brief  Reads the specified input port pin.
  * @param  GPIOx where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
  *                      x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
  * @param  GPIO_Pin specifies the port bit to read.
  *         This parameter can be GPIO_PIN_x where x can be (0..15).
  * @retval The input port pin value.
  */
GPIO_PinState HAL_GPIO_ReadPin(volatile GPIO_TypeDef* GPIOx, u16_t GPIO_Pin)
{
	GPIO_PinState retVal = GPIO_PIN_RESET;
	if(NULL != GPIOx && ((GPIO_Pin & ~GPIO_Pin) == 0UL) && (IS_GPIO(GPIOx)) )
	{
		retVal = (GPIO_PinState)((GPIOx->IDR >> GPIO_Pin) & 0x01UL);
	}
	else
	{/*nothing*/}
	return retVal;
}

/**
  * @brief  Sets or clears the selected data port bit.
  *
  * @note   This function uses GPIOx_BSRR register to allow atomic read/modify
  *         accesses. In this way, there is no risk of an IRQ occurring between
  *         the read and the modify access.
  *
  * @param  GPIOx where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
  *                      x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
  * @param  GPIO_Pin specifies the port bit to be written.
  *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
  * @param  PinState specifies the value to be written to the selected bit.
  *          This parameter can be one of the GPIO_PinState enum values:
  *            @arg GPIO_PIN_RESET: to clear the port pin
  *            @arg GPIO_PIN_SET: to set the port pin
  * @retval None
  */
void HAL_GPIO_WritePin(volatile GPIO_TypeDef* GPIOx, u16_t GPIO_Pin, GPIO_PinState PinState)
{
	if(NULL != GPIOx && ((GPIO_Pin & ~GPIO_Pin) == 0UL) && (IS_GPIO(GPIOx)) )
	{
		switch(PinState)
		{
		case GPIO_PIN_RESET :
			GPIOx->BSRR = (u32_t)(1UL << (u32_t)(GPIO_Pin+16UL));
			break;

		case GPIO_PIN_SET:
			GPIOx->BSRR = (u32_t)(1UL << GPIO_Pin);
			break;
		}
	}
	else
	{/*nothing*/}
}

/**
  * @brief  Reads the specified input port.
  * @param  GPIOx where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
  *                      x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
  * @retval The input port  value.
  */
u16_t HAL_GPIO_Read(volatile GPIO_TypeDef* GPIOx)
{
	u16_t retVal = 0;
	if(NULL != GPIOx && (IS_GPIO(GPIOx)) )
	{
		retVal = ((u16_t)(GPIOx->IDR));
	}
	else
	{/*nothing*/}

	return retVal;
}

void HAL_GPIO_Write(volatile GPIO_TypeDef* GPIOx,u16_t PortLogic)
{
	if(NULL != GPIOx && (IS_GPIO(GPIOx)))
	{
		GPIOx->ODR = PortLogic;
	}
	else
	{/*nothing*/}

}

/**
  * @brief  Toggles the specified GPIO pins.
  * @param  GPIOx Where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
  *                      x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
  * @param  GPIO_Pin Specifies the pins to be toggled.
  * @retval None
  */
void HAL_GPIO_TogglePin(volatile GPIO_TypeDef* GPIOx, u16_t GPIO_Pin)
{
	if(NULL != GPIOx && ((GPIO_Pin & ~GPIO_Pin) == 0UL) && (IS_GPIO(GPIOx)) )
	{
		u32_t odr_temp = GPIOx->ODR & (1UL << (u32_t)GPIO_Pin);
		GPIOx->BSRR = ((odr_temp << 16UL) | (~odr_temp & (1UL << (u32_t)GPIO_Pin)));
	}
	else
	{/*nothing*/}
}

/**
  * @brief  Locks GPIO Pins configuration registers.
  * @note   The locked registers are GPIOx_MODER, GPIOx_OTYPER, GPIOx_OSPEEDR,
  *         GPIOx_PUPDR, GPIOx_AFRL and GPIOx_AFRH.
  * @note   The configuration of the locked GPIO pins can no longer be modified
  *         until the next reset.
  * @param  GPIOx where x can be (A..F) to select the GPIO peripheral for STM32F4 family
  * @param  GPIO_Pin specifies the port bit to be locked.
  *         This parameter can be any combination of GPIO_PIN_x where x can be (0..15).
  * @retval None
  */
HAL_StatusTypeDef HAL_GPIO_LockPin(volatile GPIO_TypeDef* GPIOx, u16_t GPIO_Pin)
{
	u32_t temp = GPIO_LCKR_LCKK_Msk;
	if(NULL != GPIOx && ((GPIO_Pin & ~GPIO_Pin) == 0UL) && (IS_GPIO(GPIOx)) )
	{
		/**/
		temp |= (u32_t)(1UL << GPIO_Pin);
		GPIOx->LCKR = temp; /*WR LCKR[16] = ‘1’ + LCKR[15:0]*/
		GPIOx->LCKR = (u32_t)((1UL << GPIO_Pin)); /*WR LCKR[16] = ‘0’ + LCKR[15:0]*/
		GPIOx->LCKR = temp;	/*WR LCKR[16] = ‘1’ + LCKR[15:0]*/
		/*Must read LCKR to complete lock key write sequence*/
		temp = GPIOx->LCKR;
		/*confirms that the lock is active*/
		if(GPIO_LCKR_LCKK_Msk == (GPIOx->LCKR & GPIO_LCKR_LCKK_Msk))
		{
			temp = GPIOx->LCKR;
			return HAL_OK;
		}
		else
		{
			temp = GPIOx->LCKR;
			return HAL_ERROR;
		}

	}
	else
	{/*nothing*/}

	return HAL_ERROR;
}





