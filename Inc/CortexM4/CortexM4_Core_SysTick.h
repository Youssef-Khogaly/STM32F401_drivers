/*
 ******************************************************************************
 * @file           : CortexM4_Core_SysTick.h
 * @author         : Youssef Ibrahem
 * @brief          : CortexM4_Core_SysTick.h
 ******************************************************************************
 */
#ifndef CORTEXM4_CORTEXM4_CORE_SYSTICK_H_
#define CORTEXM4_CORTEXM4_CORE_SYSTICK_H_

/*----------------------- Include Start ---------------------- */
#include "Common/Std_types.h"
#include "Common/Common_Macros.h"
#include "CortexM4_Core_SysTick_CFG.h"
/* ----------------------- Include END ----------------------- */

/* ----------------------- MACROS Start ---------------------- */
#define SYSTICK_BASE	(0xE000E010UL)
#define SYSTICK			(*((volatile SysTick_Type * const )SYSTICK_BASE))


#define  SYSTICK_CTRL_ENABLE_Pos	(0x00UL)
#define  SYSTICK_CTRL_ENABLE_Msk	(0x01UL)

#define  SYSTICK_CTRL_TICKINT_Pos	(0x01UL)
#define  SYSTICK_CTRL_TICKINT_Msk	(0x02UL)

#define  SYSTICK_CTRL_CLKSOURCE_Pos	(0x02UL)
#define  SYSTICK_CTRL_CLKSOURCE_Msk	(0x04UL)

#define  SYSTICK_CTRL_COUNTFLAG_Pos	(16UL)
#define  SYSTICK_CTRL_COUNTFLAG_Msk	(65536UL)


#define  SYSTICK_LOAD_RELOAD_Pos	(0UL)
#define  SYSTICK_LOAD_RELOAD_Msk	(0x0FFFFFFUL)

#define  SYSTICK_VAL_CURRENT_Pos	(0UL)
#define  SYSTICK_VAL_CURRENT_Msk	(0x0FFFFFFUL)

#define SYSTICK_MODE_SINGLE_INTERVAL	(0U)
#define SYSTICK_MODE_PERIODIC_INTERVAL	(1U)
/* ----------------------- MACROS END ------------------------ */

/* ----------------------- Macro Functions Start -------------- */


/* ----------------------- Macro Function End ----------------- */

/* ----------------------- User Data Types Start -------------- */
typedef struct {
	volatile u32_t CTRL;	/* Offset: 0x00 (R/W) SysTick control and status register*/
	volatile u32_t LOAD;	/* Offset: 0x04 (R/W) SysTick reload value  register*/
	volatile u32_t VAL;		/* Offset: 0x08 (R/W) SysTick current value  register*/
	volatile u32_t CALIB;	/* Offset: 0x0C (RO)  SysTick calibration  register*/
}SysTick_Type;

typedef void(*ptrFuncion_t)(void);
/* ----------------------- User Data Types End ---------------- */

/* ----------------------- Software Interfaces Start ---------- */

/**
 * @brief  		System Tick Configuration
 * @details 	Init system timer and its interrupt  and disable the system Tick interrupt
 * @Parma[IN] 	SysTick_Ticks number of ticks between two interrupt 24 bit unsigned value
 * @ret 		0 Function Succeeded
 * 				1 Funcation  Failed
 */
u8_t SysTick_Init(u32_t SysTick_Ticks);

/**
 * @brief  		System Tick Deinitialization
 * @details 	Clear the reloaded register  and disable system timer
 * @Parma	 	None
 * @ret 	 	None
 *
 */
void SysTick_deinit(void);

/**
 * @brief  		System Tick wait till reaching the required  ticks
 * @details 	Blocking call , wait till reaching the required ticks
 * @Parma[IN] 	SysTick_Ticks number of ticks between two interrupt 24 bit unsigned value
 * @ret 		None
 */
void SysTick_WaitBlocking(u32_t SysTick_Ticks);


/**
 * @brief  		System Tick Trigger a callback once the calculate the required ticks
 * @details 	Non Blocking Call , Trigger  a callback once calcualte the needed ticks
 * @Parma[IN] 	SysTick_Ticks number of ticks between two interrupt 24 bit unsigned value
 * @Parma[IN] 	call back function address
 * @ret 		None
 */
void SysTick_SingleInterval(u32_t SysTick_Ticks , ptrFuncion_t CallBack );

/**
 * @brief  		System Tick Trigger a callback periodically once  the calculate the required ticks
 * @details 	Non Blocking Call , Trigger  a callback periodically once calcualte the needed ticks
 * @Parma[IN] 	SysTick_Ticks number of ticks between two interrupt 24 bit unsigned value
 * @Parma[IN] 	call back function address
 * @ret 		None
 */
void SysTick_PeriodicInterval(u32_t SysTick_Ticks , ptrFuncion_t CallBack );

/**
 * @brief  		get remaining ticks
 * @Parma[IN] 	None
 * @ret 		remaining ticks to reach the zero
 */
u32_t SysTick_GetRemainingTicks(void);
/* ----------------------- Software Interfaces end ------------ */

#endif /* CORTEXM4_CORTEXM4_CORE_SYSTICK_H_ */
