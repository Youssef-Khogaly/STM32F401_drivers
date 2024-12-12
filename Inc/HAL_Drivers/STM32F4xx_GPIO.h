/*
 ******************************************************************************
 * @file           : STM32F4xx_GPIO.h
 * @author         : Youssef Ibrahem
 * @brief          : STM32F4xx_GPIO.h
 ******************************************************************************
 */
#ifndef HAL_DRIVERS_STM32F4XX_GPIO_H_
#define HAL_DRIVERS_STM32F4XX_GPIO_H_

/*----------------------- Include Start ---------------------- */
#include "Common/Common_Macros.h"
#include "Common/Std_types.h"
#include "HAL_Common.h"
#include "STM32F4xx_Peripheral_Defs.h"

/* ----------------------- Include END ----------------------- */

/* ----------------------- MACROS Start ---------------------- */

/** @defgroup GPIO_pins_define GPIO pins define
  * @{
  */
#define GPIO_PIN_0                 ((u16_t)0x0000)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((u16_t)0x0001)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((u16_t)0x0002)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((u16_t)0x0003)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((u16_t)0x0004)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((u16_t)0x0005)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((u16_t)0x0006)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((u16_t)0x0007)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((u16_t)0x0008)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((u16_t)0x0009)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((u16_t)0x000A)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((u16_t)0x000B)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((u16_t)0x000C)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((u16_t)0x000D)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((u16_t)0x000E)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((u16_t)0x000F)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((u16_t)0xFFFF)  /* All pins selected */


/** @defgroup GPIO_speed_define  GPIO speed define
  * @brief GPIO Output Maximum frequency
  * @{
  */
#define  GPIO_SPEED_FREQ_LOW         0x00000000U  /*!< IO works at 2 MHz, please refer to the product datasheet */
#define  GPIO_SPEED_FREQ_MEDIUM      0x00000001U  /*!< range 12,5 MHz to 50 MHz, please refer to the product datasheet */
#define  GPIO_SPEED_FREQ_HIGH        0x00000002U  /*!< range 25 MHz to 100 MHz, please refer to the product datasheet  */
#define  GPIO_SPEED_FREQ_VERY_HIGH   0x00000003U  /*!< range 50 MHz to 200 MHz, please refer to the product datasheet  */


 /** @defgroup GPIO_pull_define GPIO pull define
   * @brief GPIO Pull-Up or Pull-Down Activation
   * @{
   */
#define  GPIO_NOPULL        0x00000000U   /*!< No Pull-up or Pull-down activation  */
#define  GPIO_PULLUP        0x00000001U   /*!< Pull-up activation                  */
#define  GPIO_PULLDOWN      0x00000002U   /*!< Pull-down activation                */
/**
  * @}
  */

/** @defgroup GPIO_Alternate_function_selection GPIO Alternate Function Selection
  * @{
  */
/**
  * @brief   AF 0 selection
  */
#define GPIO_AF0_RTC_50Hz      ((u8_t)0x00)  /* RTC_50Hz Alternate Function mapping                       */
#define GPIO_AF0_MCO           ((u8_t)0x00)  /* MCO (MCO1 and MCO2) Alternate Function mapping            */
#define GPIO_AF0_TAMPER        ((u8_t)0x00)  /* TAMPER (TAMPER_1 and TAMPER_2) Alternate Function mapping */
#define GPIO_AF0_SWJ           ((u8_t)0x00)  /* SWJ (SWD and JTAG) Alternate Function mapping             */
#define GPIO_AF0_TRACE         ((u8_t)0x00)  /* TRACE Alternate Function mapping                          */

/**
  * @brief   AF 1 selection
  */
#define GPIO_AF1_TIM1          ((u8_t)0x01)  /* TIM1 Alternate Function mapping */
#define GPIO_AF1_TIM2          ((u8_t)0x01)  /* TIM2 Alternate Function mapping */

/**
  * @brief   AF 2 selection
  */
#define GPIO_AF2_TIM3          ((u8_t)0x02)  /* TIM3 Alternate Function mapping */
#define GPIO_AF2_TIM4          ((u8_t)0x02)  /* TIM4 Alternate Function mapping */
#define GPIO_AF2_TIM5          ((u8_t)0x02)  /* TIM5 Alternate Function mapping */

/**
  * @brief   AF 3 selection
  */
#define GPIO_AF3_TIM9          ((u8_t)0x03)  /* TIM9 Alternate Function mapping  */
#define GPIO_AF3_TIM10         ((u8_t)0x03)  /* TIM10 Alternate Function mapping */
#define GPIO_AF3_TIM11         ((u8_t)0x03)  /* TIM11 Alternate Function mapping */

/**
  * @brief   AF 4 selection
  */
#define GPIO_AF4_I2C1          ((u8_t)0x04)  /* I2C1 Alternate Function mapping */
#define GPIO_AF4_I2C2          ((u8_t)0x04)  /* I2C2 Alternate Function mapping */
#define GPIO_AF4_I2C3          ((u8_t)0x04)  /* I2C3 Alternate Function mapping */

/**
  * @brief   AF 5 selection
  */
#define GPIO_AF5_SPI1          ((u8_t)0x05)  /* SPI1 Alternate Function mapping        */
#define GPIO_AF5_SPI2          ((u8_t)0x05)  /* SPI2/I2S2 Alternate Function mapping   */
#define GPIO_AF5_SPI3          ((u8_t)0x05)  /* SPI3 Alternate Function mapping        */
#define GPIO_AF5_SPI4          ((u8_t)0x05)  /* SPI4 Alternate Function mapping        */
#define GPIO_AF5_I2S3ext       ((u8_t)0x05)  /* I2S3ext_SD Alternate Function mapping  */

/**
  * @brief   AF 6 selection
  */
#define GPIO_AF6_SPI3          ((u8_t)0x06)  /* SPI3/I2S3 Alternate Function mapping  */
#define GPIO_AF6_I2S2ext       ((u8_t)0x06)  /* I2S2ext_SD Alternate Function mapping */

/**
  * @brief   AF 7 selection
  */
#define GPIO_AF7_USART1        ((u8_t)0x07)  /* USART1 Alternate Function mapping     */
#define GPIO_AF7_USART2        ((u8_t)0x07)  /* USART2 Alternate Function mapping     */
#define GPIO_AF7_I2S3ext       ((u8_t)0x07)  /* I2S3ext_SD Alternate Function mapping */

/**
  * @brief   AF 8 selection
  */
#define GPIO_AF8_USART6        ((u8_t)0x08)  /* USART6 Alternate Function mapping */

/**
  * @brief   AF 9 selection
  */
#define GPIO_AF9_I2C2          ((u8_t)0x09)  /* I2C2 Alternate Function mapping  */
#define GPIO_AF9_I2C3          ((u8_t)0x09)  /* I2C3 Alternate Function mapping  */


/**
  * @brief   AF 10 selection
  */
#define GPIO_AF10_OTG_FS        ((u8_t)0x0A)  /* OTG_FS Alternate Function mapping */

/**
  * @brief   AF 12 selection
  */
#define GPIO_AF12_SDIO          ((u8_t)0x0C)  /* SDIO Alternate Function mapping  */

/**
  * @brief   AF 15 selection
  */
#define GPIO_AF15_EVENTOUT      ((u8_t)0x0F)  /* EVENTOUT Alternate Function mapping */


/** @defgroup GPIO_mode_define GPIO mode define
  * @brief GPIO Configuration Mode

  * @{
  */
#define  GPIO_MODE_INPUT                         	 (0UL)                                           	      	 /*!< Input Floating Mode                   */
#define  GPIO_MODE_OUTPUT_PP                    	 (1UL)                                  					 /*!< Output Push Pull Mode                 */
#define  GPIO_MODE_OUTPUT_OD                   		 (5UL)                                   					/*!< Output Open Drain Mode                */
#define  GPIO_MODE_AF_PP                       		 (2UL)                                       				/*!< Alternate Function Push Pull Mode     */
#define  GPIO_MODE_AF_OD                             (6UL)                                       				/*!< Alternate Function Open Drain Mode    */

#define  GPIO_MODE_ANALOG                       	 (3UL)                                                 		/*!< Analog Mode  */


#define GPIO_MODE_Pos								  (0UL)
#define GPIO_MODE_Msk								  (3UL)

#define GPIO_TYPE_Pos								  (0UL)
#define GPIO_TYPE_Msk								  (1UL)

#define GPIO_PUPDR_Pos								  (0UL)
#define GPIO_PUPDR_Msk								  (3UL)

#define GPIO_OSPEEDR_Pos							  (0UL)
#define GPIO_OSPEEDR_Msk							  (3UL)

#define GPIO_AFR_Pos								  (0UL)
#define GPIO_AFR_Msk								  (15UL)
/* ----------------------- MACROS END ------------------------ */

/* ----------------------- Macro Functions Start -------------- */

#define IS_GPIO_MODE_OUTPUT_AF(_MODE)				(	(_MODE == GPIO_MODE_OUTPUT_PP ) ||	(_MODE == GPIO_MODE_OUTPUT_OD ) || (_MODE == GPIO_MODE_AF_PP ) ||	(_MODE == GPIO_MODE_AF_OD ) )

#define IS_GPIO_MODE(_MODE)							(	(_MODE == GPIO_MODE_OUTPUT_PP ) ||	(_MODE == GPIO_MODE_OUTPUT_OD ) || (_MODE == GPIO_MODE_AF_PP ) ||	(_MODE == GPIO_MODE_AF_OD ) \
															|| (_MODE == GPIO_MODE_ANALOG ) || ( _MODE == GPIO_MODE_INPUT)		)

#define IS_GPIO_MODE_AF(_MODE)						((_MODE == GPIO_MODE_AF_PP ) ||	(_MODE == GPIO_MODE_AF_OD ))

#define IS_GPIO(GPIOX)								((((u32_t)GPIOA) == ((u32_t)GPIOX)) || (((u32_t)GPIOB) == ((u32_t)GPIOX)) || (((u32_t)GPIOC) == ((u32_t)GPIOX)) \
													 || (((u32_t)GPIOD) == ((u32_t)GPIOX)) || (((u32_t)GPIOE) == ((u32_t)GPIOX)) || (((u32_t)GPIOH) == ((u32_t)GPIOX)))

/* ----------------------- Macro Function End ----------------- */

/* ----------------------- User Data Types Start -------------- */

/**
  * @brief GPIO Init structure definition
  */
typedef struct
{
  u32_t Pin;       /*!< Specifies the GPIO pins to be configured.
                           This parameter can be any value of @ref GPIO_pins_define */

  u32_t Mode;      /*!< Specifies the operating mode for the selected pins.
                           This parameter can be a value of @ref GPIO_mode_define */

  u32_t Pull;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
                           This parameter can be a value of @ref GPIO_pull_define */

  u32_t Speed;     /*!< Specifies the speed for the selected pins.
                           This parameter can be a value of @ref GPIO_speed_define */

  u32_t Alternate;  /*!< Peripheral to be connected to the selected pins.
                            This parameter can be a value of @ref GPIO_Alternate_function_selection */
}GPIO_InitTypeDef;

/**
  * @brief  GPIO Bit SET and Bit RESET enumeration
  */
typedef enum
{
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET
}GPIO_PinState;
/**
  * @}
  */



/* ----------------------- User Data Types End ---------------- */

/* ----------------------- Software Interfaces Start ---------- */

/* Initialization and de-initialization functions *****************************/

/**
  * @brief  Initializes the GPIOx peripheral according to the specified parameters in the GPIO_Init.
  * @param  GPIOx where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
  *                      x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
  * @param  GPIO_Init pointer to a GPIO_InitTypeDef structure that contains
  *         the configuration information for the specified GPIO peripheral.
  * @retval None
  */
void  HAL_GPIO_Init(volatile GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);

/**
  * @brief  De-initializes the GPIOx peripheral registers to their default reset values.
  * @param  GPIOx where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
  *                      x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
  * @param  GPIO_Pin specifies the port bit to be written.
  *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
  * @retval None
  */

void  HAL_GPIO_DeInit(volatile GPIO_TypeDef  *GPIOx, u16_t GPIO_Pin);
/**
  * @}
  */

/** @addtogroup GPIO_Exported_Functions_Group2
  * @{
  */
/* IO operation functions *****************************************************/

/**
  * @brief  Reads the specified input port pin.
  * @param  GPIOx where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
  *                      x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
  * @param  GPIO_Pin specifies the port bit to read.
  *         This parameter can be GPIO_PIN_x where x can be (0..15).
  * @retval The input port pin value.
  */
GPIO_PinState HAL_GPIO_ReadPin(volatile GPIO_TypeDef* GPIOx, u16_t GPIO_Pin);

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
void HAL_GPIO_WritePin(volatile GPIO_TypeDef* GPIOx, u16_t GPIO_Pin, GPIO_PinState PinState);

/**
  * @brief  Reads the specified input port.
  * @param  GPIOx where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
  *                      x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
  * @retval The input port  value.
  */
u16_t HAL_GPIO_Read(volatile GPIO_TypeDef* GPIOx);
void HAL_GPIO_Write(volatile GPIO_TypeDef* GPIOx,u16_t PortLogic);

/**
  * @brief  Toggles the specified GPIO pins.
  * @param  GPIOx Where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
  *                      x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
  * @param  GPIO_Pin Specifies the pins to be toggled.
  * @retval None
  */
void HAL_GPIO_TogglePin(volatile GPIO_TypeDef* GPIOx, u16_t GPIO_Pin);

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
HAL_StatusTypeDef HAL_GPIO_LockPin(volatile GPIO_TypeDef* GPIOx, u16_t GPIO_Pin);
/**
  * @}
  */
/* ----------------------- Software Interfaces end ------------ */

#endif /* HAL_DRIVERS_STM32F4XX_GPIO_H_ */
