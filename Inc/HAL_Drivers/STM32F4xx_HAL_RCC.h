/*
 ******************************************************************************
 * @file           : STM32F4xx_HAL_RCC.h
 * @author         : Youssef Ibrahem
 * @brief          : contains static code to control RCC
 ******************************************************************************
 */
#ifndef HAL_DRIVERS_STM32F4XX_HAL_RCC_H_
#define HAL_DRIVERS_STM32F4XX_HAL_RCC_H_

/*----------------------- Include Start ---------------------- */
#include "Common/Common_Macros.h"
#include "HAL_Common.h"
#include "HAL_Drivers/STM32F4xx_Peripheral_Defs.h"

/* ----------------------- Include END ----------------------- */

/* ----------------------- MACROS Start ---------------------- */



/** @defgroup RCC_HSE_Config HSE Config
  * @{
  */
#define RCC_HSE_OFF                      0x00000000U
#define RCC_HSE_ON                       ((u8_t)0x01)
/**
  * @}
  */

/** @defgroup RCC_LSE_Config LSE Config
  * @{
  */
#define RCC_LSE_OFF                    0x00000000U
#define RCC_LSE_ON                     ((u8_t)0x01)
/**
  * @}
  */

/** @defgroup RCC_HSI_Config HSI Config
  * @{
  */
#define RCC_HSI_OFF                      ((u8_t)0x00)
#define RCC_HSI_ON                       ((u8_t)0x01)

/**
  * @}
  */

/** @defgroup RCC_LSI_Config LSI Config
  * @{
  */
#define RCC_LSI_OFF                      ((u8_t)0x00)
#define RCC_LSI_ON                       ((u8_t)0x01)
/**
  * @}
  */


/** @defgroup RCC_Oscillator_Type Oscillator Type
  * @{
  */
#define RCC_OSCILLATORTYPE_NONE            0x00000000U
#define RCC_OSCILLATORTYPE_HSE             0x00000001U
#define RCC_OSCILLATORTYPE_HSI             0x00000002U
#define RCC_OSCILLATORTYPE_LSE             0x00000004U
#define RCC_OSCILLATORTYPE_LSI             0x00000008U
/**
  * @}
  */


/** @defgroup RCC_System_Clock_Type System Clock Type
  * @{
  */
#define RCC_CLOCKTYPE_SYSCLK             0x00000001U
#define RCC_CLOCKTYPE_HCLK               0x00000002U
#define RCC_CLOCKTYPE_PCLK1              0x00000004U
#define RCC_CLOCKTYPE_PCLK2              0x00000008U
/**
  * @}
  */

/** @defgroup RCC_AHB_Clock_Source AHB Clock Source
  * @{
  */
#define RCC_SYSCLK_DIV1                  RCC_CFGR_HPRE_DIV1
#define RCC_SYSCLK_DIV2                  RCC_CFGR_HPRE_DIV2
#define RCC_SYSCLK_DIV4                  RCC_CFGR_HPRE_DIV4
#define RCC_SYSCLK_DIV8                  RCC_CFGR_HPRE_DIV8
#define RCC_SYSCLK_DIV16                 RCC_CFGR_HPRE_DIV16
#define RCC_SYSCLK_DIV64                 RCC_CFGR_HPRE_DIV64
#define RCC_SYSCLK_DIV128                RCC_CFGR_HPRE_DIV128
#define RCC_SYSCLK_DIV256                RCC_CFGR_HPRE_DIV256
#define RCC_SYSCLK_DIV512                RCC_CFGR_HPRE_DIV512
/**
  * @}
  */

/** @defgroup RCC_APB1_Clock_Source APB1 Clock Source
  * @{
  */
#define RCC_HCLK1_DIV1                    RCC_CFGR_PPRE1_DIV1
#define RCC_HCLK1_DIV2                    RCC_CFGR_PPRE1_DIV2
#define RCC_HCLK1_DIV4                    RCC_CFGR_PPRE1_DIV4
#define RCC_HCLK1_DIV8                    RCC_CFGR_PPRE1_DIV8
#define RCC_HCLK1_DIV16                   RCC_CFGR_PPRE1_DIV16
/**
  * @}
  */

/** @defgroup RCC_APB2_Clock_Source APB2 Clock Source
  * @{
  */
#define RCC_HCLK2_DIV1                    RCC_CFGR_PPRE2_DIV1
#define RCC_HCLK2_DIV2                    RCC_CFGR_PPRE2_DIV2
#define RCC_HCLK2_DIV4                    RCC_CFGR_PPRE2_DIV4
#define RCC_HCLK2_DIV8                    RCC_CFGR_PPRE2_DIV8
#define RCC_HCLK2_DIV16                   RCC_CFGR_PPRE2_DIV16
/**
  * @}
  */

/* ----------------------- MACROS END ------------------------ */

/* ----------------------- Macro Functions Start -------------- */




			/*          AHB1         */

#define HAL_RCC_GPIOA_CLK_ENABLE()			( SET_BIT(RCC.AHB1ENR,HAL_RCC_GPIOA_GPIOAEN_Msk) )
#define HAL_RCC_GPIOB_CLK_ENABLE()			( SET_BIT(RCC.AHB1ENR,HAL_RCC_GPIOB_GPIOBEN_Msk) )
#define HAL_RCC_GPIOC_CLK_ENABLE()			( SET_BIT(RCC.AHB1ENR,HAL_RCC_GPIOC_GPIOCEN_Msk) )
#define HAL_RCC_GPIOD_CLK_ENABLE()			( SET_BIT(RCC.AHB1ENR,HAL_RCC_GPIOD_GPIODEN_Msk) )
#define HAL_RCC_GPIOE_CLK_ENABLE()			( SET_BIT(RCC.AHB1ENR,HAL_RCC_GPIOE_GPIOEEN_Msk) )
#define HAL_RCC_GPIOH_CLK_ENABLE()			( SET_BIT(RCC.AHB1ENR,HAL_RCC_GPIOH_GPIOHEN_Msk) )

#define HAL_RCC_CRC_CLK_ENABLE()			( SET_BIT(RCC.AHB1ENR,HAL_RCC_CRC_CRCEN_Msk) )
#define HAL_RCC_DMA1_CLK_ENABLE()			( SET_BIT(RCC.AHB1ENR,HAL_RCC_DMA1_DMA1EN_Msk) )
#define HAL_RCC_DMA2_CLK_ENABLE()			( SET_BIT(RCC.AHB1ENR,HAL_RCC_DMA2_DMA2EN_Msk) )



#define HAL_RCC_GPIOA_CLK_DISABLE()			( CLEAR_BIT(RCC.AHB1ENR,HAL_RCC_GPIOA_GPIOAEN_Msk) )
#define HAL_RCC_GPIOB_CLK_DISABLE()			( CLEAR_BIT(RCC.AHB1ENR,HAL_RCC_GPIOB_GPIOBEN_Msk) )
#define HAL_RCC_GPIOC_CLK_DISABLE()			( CLEAR_BIT(RCC.AHB1ENR,HAL_RCC_GPIOC_GPIOCEN_Msk) )
#define HAL_RCC_GPIOD_CLK_DISABLE()			( CLEAR_BIT(RCC.AHB1ENR,HAL_RCC_GPIOD_GPIODEN_Msk) )
#define HAL_RCC_GPIOE_CLK_DISABLE()			( CLEAR_BIT(RCC.AHB1ENR,HAL_RCC_GPIOE_GPIOEEN_Msk) )
#define HAL_RCC_GPIOH_CLK_DISABLE()			( CLEAR_BIT(RCC.AHB1ENR,HAL_RCC_GPIOH_GPIOHEN_Msk) )

#define HAL_RCC_CRC_CLK_DISABLE()			( CLEAR_BIT(RCC.AHB1ENR,HAL_RCC_CRC_CRCEN_Msk) )
#define HAL_RCC_DMA1_CLK_DISABLE()			( CLEAR_BIT(RCC.AHB1ENR,HAL_RCC_DMA1_DMA1EN_Msk) )
#define HAL_RCC_DMA2_CLK_DISABLE()			( CLEAR_BIT(RCC.AHB1ENR,HAL_RCC_DMA2_DMA2EN_Msk) )

					/* -----------------*/






/* ----------------------- Macro Function End ----------------- */

/* ----------------------- User Data Types Start -------------- */
/**
  * @brief  RCC Internal/External Oscillator (HSE, HSI, LSE and LSI) configuration structure definition
  */
typedef struct
{
  u8_t OscillatorType;       /*!< The oscillators to be configured.
                                      This parameter can be a value of @ref RCC_Oscillator_Type                   */

  u8_t HSEState;             /*!< The new state of the HSE.
                                      This parameter can be a value of @ref RCC_HSE_Config                        */

  u8_t LSEState;             /*!< The new state of the LSE.
                                      This parameter can be a value of @ref RCC_LSE_Config                        */

  u8_t HSIState;             /*!< The new state of the HSI.
                                      This parameter can be a value of @ref RCC_HSI_Config                        */

  u8_t LSIState;             /*!< The new state of the LSI.
                                      This parameter can be a value of @ref RCC_LSI_Config                        */

}RCC_OscInitTypeDef;


/**
  * @brief  RCC System, AHB and APB busses clock configuration structure definition
  */
typedef struct
{
  u32_t ClockType;             /*!< The clock to be configured.
                                       This parameter can be a value of @ref RCC_System_Clock_Type      */

  u32_t AHBCLKDivider;         /*!< The AHB clock (HCLK) divider. This clock is derived from the system clock (SYSCLK).
                                       This parameter can be a value of @ref RCC_AHB_Clock_Source       */

  u32_t APB1CLKDivider;        /*!< The APB1 clock (PCLK1) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_APB1_Clock_Source */

  u32_t APB2CLKDivider;        /*!< The APB2 clock (PCLK2) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_APB2_Clock_Source */
}RCC_ClkInitTypeDef;

/**
  * @}
  */

/* ----------------------- User Data Types End ---------------- */

/* ----------------------- Software Interfaces Start ---------- */

	/* Initialization and de-initialization functions  **/
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_DeInit(void);

	/* configure prescallers and dividers */
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct);
/* ----------------------- Software Interfaces end ------------ */

#endif /* HAL_DRIVERS_STM32F4XX_HAL_RCC_H_ */
