/*
 ******************************************************************************
 * @file           : STM32F4xx_Peripheral_Defs.h
 * @author         : Youssef Ibrahem
 * @brief          : conatins all data structure and memeory mapping for Stm32f4xx
 ******************************************************************************
 */
#ifndef HAL_DRIVERS_STM32F4XX_PERIPHERAL_DEFS_H_
#define HAL_DRIVERS_STM32F4XX_PERIPHERAL_DEFS_H_

/*----------------------- Include Start ---------------------- */
#include "Common/Std_types.h"
#include "Common/Common_Macros.h"
/* ----------------------- Include END ----------------------- */

/* ----------------------- MACROS Start ---------------------- */

		/************* RCC **********************/
#define RCC_REG_BASE					((0x40023800UL))
#define RCC 							( *( (volatile RCC_TypeDef * const )RCC_REG_BASE ) )

#define HAL_RCC_GPIOA_GPIOAEN_Pos		(0U)
#define HAL_RCC_GPIOA_GPIOAEN_Msk		(0x01UL << HAL_RCC_GPIOA_GPIOAEN_Pos)

#define HAL_RCC_GPIOB_GPIOBEN_Pos		(1U)
#define HAL_RCC_GPIOB_GPIOBEN_Msk		(0x01UL << HAL_RCC_GPIOB_GPIOBEN_Pos)

#define HAL_RCC_GPIOC_GPIOCEN_Pos		(2U)
#define HAL_RCC_GPIOC_GPIOCEN_Msk		(0x01UL << HAL_RCC_GPIOC_GPIOCEN_Pos)

#define HAL_RCC_GPIOD_GPIODEN_Pos		(3U)
#define HAL_RCC_GPIOD_GPIODEN_Msk		(0x01UL << HAL_RCC_GPIOD_GPIODEN_Pos)

#define HAL_RCC_GPIOE_GPIOEEN_Pos		(4U)
#define HAL_RCC_GPIOE_GPIOEEN_Msk		(0x01UL << HAL_RCC_GPIOE_GPIOEEN_Pos)

#define HAL_RCC_GPIOH_GPIOHEN_Pos		(7U)
#define HAL_RCC_GPIOH_GPIOHEN_Msk		(0x01UL << HAL_RCC_GPIOH_GPIOHEN_Pos)

#define HAL_RCC_CRC_CRCEN_Pos			(12U)
#define HAL_RCC_CRC_CRCEN_Msk			(0x01UL << HAL_RCC_CRC_CRCEN_Pos)

#define HAL_RCC_DMA1_DMA1EN_Pos			(21U)
#define HAL_RCC_DMA1_DMA1EN_Msk			(0x01UL << HAL_RCC_DMA1_DMA1EN_Pos)

#define HAL_RCC_DMA2_DMA2EN_Pos			(22U)
#define HAL_RCC_DMA2_DMA2EN_Msk			(0x01UL << HAL_RCC_DMA2_DMA2EN_Pos)

#define HAL_RCC_HSE_HSEON_Pos			(16U)
#define HAL_RCC_HSE_HSEON_Msk			(0x01UL << HAL_RCC_HSE_HSEON_Pos)

#define RCC_CFGR_PPRE1_Pos				(0x0010UL)
#define RCC_CFGR_PPRE1_Msk				(0x01C00UL)

#define RCC_CFGR_PPRE2_Pos				(0x0013UL)
#define RCC_CFGR_PPRE2_Msk				(0x0E000UL)

#define RCC_CFGR_HPRE_Pos				(0x0004UL)
#define RCC_CFGR_HPRE_Msk				(0x0F0UL)

#define RCC_CFGR_SW_Pos					(0UL)
#define RCC_CFGR_SW_Msk					(3UL)

#define RCC_CFGR_SW_HSI_SELECT_Msk				(0UL)
#define RCC_CFGR_SW_HSE_SELECT_Msk				(1UL)
#define RCC_CFGR_SW_PLL_SELECT_Msk				(2UL)
#define RCC_CFGR_SW_NOTALLOWED_SELECT_Msk		(3UL)

/** @defgroup RCC_AHB_Clock_Source AHB Clock Source
  * @{
  */
#define RCC_CFGR_HPRE_DIV1			(0x00UL)
#define RCC_CFGR_HPRE_DIV2			(0x080UL)
#define RCC_CFGR_HPRE_DIV4			(0x090UL)
#define RCC_CFGR_HPRE_DIV8			(0x0A0UL)
#define RCC_CFGR_HPRE_DIV16			(0x0B0UL)
#define RCC_CFGR_HPRE_DIV64			(0x0C0UL)
#define RCC_CFGR_HPRE_DIV128		(0x0D0UL)
#define RCC_CFGR_HPRE_DIV256		(0x0E0UL)
#define RCC_CFGR_HPRE_DIV512		(0x0F0UL)

/**
  * @}
  */

/** @defgroup RCC_APB1_Clock_Source APB1/APB2 Clock Source
  * @{
  */
#define RCC_CFGR_PPRE1_DIV1			(0x00UL)
#define RCC_CFGR_PPRE1_DIV2			(0x01000UL)
#define RCC_CFGR_PPRE1_DIV4			(0x01400UL)
#define RCC_CFGR_PPRE1_DIV8			(0x01800UL)
#define RCC_CFGR_PPRE1_DIV16		(0x01C00UL)
/**
  * @}
  */

/** @defgroup RCC_APB2_Clock_Source APB1/APB2 Clock Source
  * @{
  */
#define RCC_CFGR_PPRE2_DIV1			(0x00UL)
#define RCC_CFGR_PPRE2_DIV2			(0x008000UL)
#define RCC_CFGR_PPRE2_DIV4			(0x00A000UL)
#define RCC_CFGR_PPRE2_DIV8			(0x00C000UL)
#define RCC_CFGR_PPRE2_DIV16		(0x00E000UL)
/**
  * @}
  */



		/****************************************/

		/*******************GPIO Start*************/

#define GPIOA_REG_BASE					((0x40020000UL))
#define GPIOB_REG_BASE					((0x40020400UL))
#define GPIOC_REG_BASE					((0x40020800UL))
#define GPIOD_REG_BASE					((0x40020C00UL))
#define GPIOE_REG_BASE					((0x40021000UL))
#define GPIOH_REG_BASE					((0x40021C00UL))

#define GPIOA							( ( (volatile GPIO_TypeDef * const )GPIOA_REG_BASE ) )
#define GPIOB							( ( (volatile GPIO_TypeDef * const )GPIOB_REG_BASE ) )
#define GPIOC							( ( (volatile GPIO_TypeDef * const )GPIOC_REG_BASE ) )
#define GPIOD							( ( (volatile GPIO_TypeDef * const )GPIOD_REG_BASE ) )
#define GPIOE							( ( (volatile GPIO_TypeDef * const )GPIOE_REG_BASE ) )
#define GPIOH							( ( (volatile GPIO_TypeDef * const )GPIOH_REG_BASE ) )



#define GPIO_LCKR_LCKK_Msk				((u32_t)65536UL)
		/*******************GPIO END*************/
/* ----------------------- MACROS END ------------------------ */

/* ----------------------- Macro Functions Start -------------- */
		/************* RCC **********************/
		/***** Check paramaters Macros ********/

#define IS_RCC_PtrOscInitType(RCC_PtrOscInitType)			(NULL != (RCC_PtrOscInitType) )
#define IS_RCC_OscillatorType(Oscillator)				    ((RCC_OSCILLATORTYPE_HSE == (Oscillator)) || ((Oscillator) == RCC_OSCILLATORTYPE_HSI) \
															 || ((Oscillator) == RCC_OSCILLATORTYPE_LSE) || ((Oscillator) == RCC_OSCILLATORTYPE_LSI) )

#define IS_RCC_OsillatorType_HSE(Oscillator)				((RCC_OSCILLATORTYPE_HSE == (Oscillator)))
#define IS_RCC_OsillatorType_HSI(Oscillator)				((RCC_OSCILLATORTYPE_HSI == (Oscillator)))
#define IS_RCC_OsillatorType_LSE(Oscillator)				((RCC_OSCILLATORTYPE_LSE == (Oscillator)))
#define IS_RCC_OsillatorType_LSI(Oscillator)				((RCC_OSCILLATORTYPE_LSI == (Oscillator)))


#define IS_RCC_HSEState_ON(HSE)								( ((HSE) == RCC_HSE_ON)  )
#define IS_RCC_LSEState_ON(LSE)								( ((LSE) == RCC_LSE_ON)  )
#define IS_RCC_HSIState_ON(HSI)								( ((HSI) == RCC_HSI_ON)  )
#define IS_RCC_LSIState_ON(LSI)								( ((LSI) == RCC_LSI_ON)  )





		/****************************************/
		/*******************GPIO Start*************/
		/*******************GPIO END*************/
/* ----------------------- Macro Function End ----------------- */

/* ----------------------- User Data Types Start -------------- */
		/************* RCC **********************/

typedef struct
{
  volatile u32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  volatile u32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  volatile u32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  volatile u32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  volatile u32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  volatile u32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  volatile u32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  u32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  volatile u32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  volatile u32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  u32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  volatile u32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  volatile u32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  volatile u32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  u32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  volatile u32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  volatile u32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  u32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  volatile u32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  volatile u32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  volatile u32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  u32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  volatile u32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  volatile u32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  u32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  volatile u32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  volatile u32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  u32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  volatile u32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  volatile u32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  u32_t      RESERVED7[1];  /*!< Reserved, 0x88                                                                    */
  volatile u32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
} RCC_TypeDef;


		/********************RCC END ***************/

		/*******************GPIO Start*************/
/**
  * @brief General Purpose I/O
  */

typedef struct
{
  volatile u32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  volatile u32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  volatile u32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  volatile u32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  volatile u32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  volatile u32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  volatile u32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  volatile u32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  volatile u32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;


		/*******************GPIO END*************/
/* ----------------------- User Data Types End ---------------- */

/* ----------------------- Software Interfaces Start ---------- */

/* ----------------------- Software Interfaces end ------------ */

#endif /* HAL_DRIVERS_STM32F4XX_PERIPHERAL_DEFS_H_ */
