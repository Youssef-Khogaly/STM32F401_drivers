/*
 ******************************************************************************
 * @file           : CortexM4_Core_SCB.h
 * @author         : Youssef Ibrahem
 * @brief          : Contains Declarations to control  system control block
 ******************************************************************************
 */
#ifndef CORTEXM4_CORE_SCB_H_
#define CORTEXM4_CORE_SCB_H_

/*----------------------- Include Start ---------------------- */
#include "Common/Std_types.h"
/* ----------------------- Include END ----------------------- */

/* ----------------------- MACROS Start ---------------------- */

			/*Memory mapping for SCB*/
#define SCB_BASE	(0xE000ED00UL)	/*!*System control block base address*/
#define SCB			((volatile SCB_Type*)SCB_BASE )


/*			priority grouping  field		*/
#define SCB_PRIGROUP_0			(0x07UL)/*!< 0 [none] bits for pre-emption priority
 	 	 	 	 	 	 	 	 	 	 	   4 [7:4]  bits for subpriority>!*/

#define SCB_PRIGROUP_1			(0x06UL)/*!< 1 [7] bits for pre-emption priority
 	 	 	 	 	 	 	 	 	 	 	   3 [6:4] bits for subpriority>!*/

#define SCB_PRIGROUP_2			(0x05UL)/*!< 2 [7:6] bits for pre-emption priority
 	 	 	 	 	 	 	 	 	 	 	   2 [5:4] bits for subpriority!>*/

#define SCB_PRIGROUP_3			(0x04UL)/*!< 3 [7:5] bits for pre-emption priority
 	 	 	 	 	 	 	 	 	 	 	   1 [4] bits for subpriority>!*/

#define SCB_PRIGROUP_4			(0x00UL)/*!< 4 [7:4] bits for pre-emption priority
 	 	 	 	 	 	 	 	 	 	 	   0 [None] bits for subpriority>!*/

#define SCB_AIRCR_PRIGROUP_POS			(8UL)
#define SCB_AIRCR_PRIGROUP_MASK	(0x0700UL)

#define SCB_AIRCR_VECTKEY_POS		(16UL)
#define SCB_AIRCR_VECTKEY_MASK	(0xFFFF0000UL)

/* ----------------------- MACROS END ------------------------ */

/* ----------------------- Macro Functions Start -------------- */


/* ----------------------- Macro Function End ----------------- */

/* ----------------------- User Data Types Start -------------- */
typedef struct {
	volatile u32_t CPUID; 		/*Offset(0x00) (RO)CPUID base register*/
	volatile u32_t ICSR;			/*Offset(0x04) (R/W)Interrupt control and state register */
	volatile u32_t VTOR;			/*Offset(0x08) (R/W)Vector table offset register */
	volatile u32_t AIRCR;		/*Offset(0x0C) (R/W)Application interrupt and reset control register */
	volatile u32_t SCR;			/*Offset(0x10) (R/W)System control register */
	volatile u32_t CCR;			/*Offset(0x14) (R/W)Configuration and control register */

	volatile u32_t SHPR1;		/*Offset(0x18) (R/W) System handler priority registers  */
	volatile u32_t SHPR2;		/*Offset(0x1C) (R/W) System handler priority registers  */
	volatile u32_t SHPR3;		/*Offset(0x20) (R/W) System handler priority registers  */
	volatile u32_t SHCSR;		/*Offset(0x24) (R/W) System handler control and state register */
	union
	{
		struct
		{
			volatile u8_t MMSR;		/*(R/W) MemManage Fault Status Register */
			volatile u8_t BFSR;		/*(R/W) BusFault Status Register */
			volatile u16_t UFSR;		/*(R/W) UsageFault Status Register */
		};
		volatile u32_t CFSR; 	/*Offset(0x28) (R/W) Configurable fault status register (CFSR; UFSR+BFSR+MMFSR) */
	};
	volatile u32_t HFSR; 		/*Offset(0x2C) (R/W) Hard fault status register */
	volatile u32_t RESERVED1;
	volatile u32_t MMAR;			/*Offset(0x34) (R/W)  Memory management fault address register  */
	volatile u32_t BFAR;			/*Offset(0x38) (R/W)   Bus fault address register   */
	volatile u32_t AFSR;			/*Offset(0x3C) (R/W)  Auxiliary fault status register  */
}SCB_Type;


/* ----------------------- User Data Types End ---------------- */

/* ----------------------- Software Interfaces Start ---------- */

/**
 * 	\brief set group priority
 * 	\details set priority group using the required unlock sequence
 * 	\parma	[in]	PriorityGroup priority grouping macro field
 */
void SCB_SetPriorityGrouping(u32_t PriorityGroup);

/**
 * 	\brief return group priority
 * 	\details get priority group using the required unlock sequence
 * 	\parma	none
 * 	\return	PriorityGroup priority grouping macro field
 */
u32_t SCB_GetPriorityGrouping(void);
/* ----------------------- Software Interfaces end ------------ */

#endif /* CORTEXM4_CORE_SCB_H_ */
