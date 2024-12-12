/**
 ******************************************************************************
 * @file           : CortexM4_Core_NVIC.h
 * @author         : Youssef Ibrahem
 * @brief          : CortexM4_Core_NVIC driver header file
 ******************************************************************************
 */

#ifndef CORTEXM4_CORE_NVIC_H_
#define CORTEXM4_CORE_NVIC_H_


/*----------------------- Include Start ---------------------- */
#include 	 "common/Std_types.h"
/* ----------------------- Include END ----------------------- */

/* ----------------------- MACROS Start ---------------------- */

#define NVIC_BASE	(0xE000E100UL)

#define NVIC		((volatile NVIC_Type*)NVIC_BASE)

#define NVIC_PRIORITY_BITS		((u8_t)4U)
/* ----------------------- MACROS END ------------------------ */

/* ----------------------- Macro Functions Start -------------- */


/* ----------------------- Macro Function End ----------------- */

/* ----------------------- User Data Types Start -------------- */
/**
 * @brief STM32F401CCu6 NVIC regeister
 */
typedef struct {
	volatile u32_t ISER[8U]; /* !Offset<0> (R/W ) The NVIC_ISER0-NVIC_ISER7 registers enable interrupts	*/
	u32_t RESERVED1[24U];
	volatile u32_t ICER[8U]; /* !Offset<0x80> (R/W ) The NVIC_ICER0-NVIC_ICER7 registers disable interrupts	*/
	u32_t RESERVED2[24U];
	volatile u32_t ISPR[8U]; /* !Offset<0x100> (R/W ) The NVIC_ISPR0-NVIC_ISPR7 registers force interrupts into the pending state	*/
	u32_t RESERVED3[24U];
	volatile u32_t ICPR[8U]; /* !Offset<0x180> (R/W ) The NVIC_ICPR0-NCVIC_ICPR7 registers remove the pending state from interrupts	*/
	u32_t RESERVED4[24U];
	volatile u32_t IABR[8U]; /* !Offset<0x200> (R/W ) The NVIC_IABR0-NVIC_IABR7 registers indicate which interrupts are active	*/
	u32_t RESERVED5[56U];
	volatile u8_t IPR[240U]; /* !Offset<0x300> (R/W ) The NVIC_IPR0-NVIC_IPR239 registers provide an 8-bit priority field for each interrupt and */
	u32_t RESERVED6[643U];
	volatile u32_t STIR; /* !Offset<0xE00> (WO) Write to the STIR to generate an interrupt from software	*/

}NVIC_Type;
/**
  * @}
  */
/**
 * @brief STM32F401CCu6 Interrupt Number Definition
 */
typedef enum
{
/******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                                */
/******  STM32 specific Interrupt Numbers **********************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                         */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
  TAMP_STAMP_IRQn             = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line             */
  RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI line                        */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                            */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                              */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                              */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                              */
  EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                              */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                              */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                              */
  DMA1_Stream0_IRQn           = 11,     /*!< DMA1 Stream 0 global Interrupt                                    */
  DMA1_Stream1_IRQn           = 12,     /*!< DMA1 Stream 1 global Interrupt                                    */
  DMA1_Stream2_IRQn           = 13,     /*!< DMA1 Stream 2 global Interrupt                                    */
  DMA1_Stream3_IRQn           = 14,     /*!< DMA1 Stream 3 global Interrupt                                    */
  DMA1_Stream4_IRQn           = 15,     /*!< DMA1 Stream 4 global Interrupt                                    */
  DMA1_Stream5_IRQn           = 16,     /*!< DMA1 Stream 5 global Interrupt                                    */
  DMA1_Stream6_IRQn           = 17,     /*!< DMA1 Stream 6 global Interrupt                                    */
  ADC_IRQn                    = 18,     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                     */
  TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
  TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
  TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                             */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                             */
  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                             */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                              */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                              */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                              */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                              */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                             */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                             */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                           */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                           */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
  OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
  DMA1_Stream7_IRQn           = 47,     /*!< DMA1 Stream7 Interrupt                                            */
  SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                             */
  TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                             */
  SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                             */
  DMA2_Stream0_IRQn           = 56,     /*!< DMA2 Stream 0 global Interrupt                                    */
  DMA2_Stream1_IRQn           = 57,     /*!< DMA2 Stream 1 global Interrupt                                    */
  DMA2_Stream2_IRQn           = 58,     /*!< DMA2 Stream 2 global Interrupt                                    */
  DMA2_Stream3_IRQn           = 59,     /*!< DMA2 Stream 3 global Interrupt                                    */
  DMA2_Stream4_IRQn           = 60,     /*!< DMA2 Stream 4 global Interrupt                                    */
  OTG_FS_IRQn                 = 67,     /*!< USB OTG FS global Interrupt                                       */
  DMA2_Stream5_IRQn           = 68,     /*!< DMA2 Stream 5 global interrupt                                    */
  DMA2_Stream6_IRQn           = 69,     /*!< DMA2 Stream 6 global interrupt                                    */
  DMA2_Stream7_IRQn           = 70,     /*!< DMA2 Stream 7 global interrupt                                    */
  USART6_IRQn                 = 71,     /*!< USART6 global interrupt                                           */
  I2C3_EV_IRQn                = 72,     /*!< I2C3 event interrupt                                              */
  I2C3_ER_IRQn                = 73,     /*!< I2C3 error interrupt                                              */
  FPU_IRQn                    = 81,     /*!< FPU global interrupt                                              */
  SPI4_IRQn                   = 84      /*!< SPI4 global Interrupt                                              */
} IRQn_Type;
/**
  * @}
  */
/* ----------------------- User Data Types End ---------------- */

/* ----------------------- Software Interfaces Start ---------- */
/**
 * \brief 		Enable Interrupt
 * \details 	Enable  a specific interrupt in NVIC
 * \parma [in] IRQn Device specific interrupt  number
 * \Note 		IRQn Must not be negative
 */
void NVIC_EnableIRQ(IRQn_Type IRQn);
/**
 * \brief 		Disable Interrupt
 * \details 	Disable  a specific interrupt in NVIC
 * \parma [in] IRQn Device specific interrupt  number
 * \Note 		IRQn Must not be negative
 */
void NVIC_DisableIRQ(IRQn_Type IRQn);
/**
 * \brief 		set Interrupt pending
 * \details 	set interrupt in pending state
 * \parma [in] IRQn Device specific interrupt  number
 * \Note 		IRQn Must not be negative
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn);
/**
 * \brief 		Clear Interrupt pending
 * \details 	Clear interrupt in pending state
 * \parma [in] IRQn Device specific interrupt  number
 * \Note 		IRQn Must not be negative
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
/**
 * \brief 		Get Active interrupt
 * \details 	check if  IRQn is in active state or not
 * \parma [in] IRQn Device specific interrupt  number
 * \return 		0 IRQn interrupt is not active
 * \return 		1 IRQn  if the status of the corresponding interrupt is active or active and pending
 * \Note 		IRQn Must not be negative
 *
 */
u32_t NVIC_GetActiveIRQ(IRQn_Type IRQn);

/**
 * \brief 		Get interrupt priority
 * \details 	read interrupt priority
 * \parma [in] IRQn Device specific interrupt  number
 * \return 		interrupt priority
 * 				Value is automatically aligned to  implemented priority bits of mcu
 * \Note 		IRQn Must not be negative
 *
 */
u32_t NVIC_GetPriority(IRQn_Type IRQn);
/**
 * \brief 		set interrupt priority
 * \details 	set interrupt priority
 * \parma [in] IRQn Device specific interrupt  number
 * \parma [in] priority priority to be set
 * \Note 		IRQn Must not be negative
 *
 */
void NVIC_SetPriority(IRQn_Type IRQn , u32_t priority);
/* ----------------------- Software Interfaces end ------------ */


#endif /* CORTEXM4_CORE_NVIC_H_ */
