/*
 ******************************************************************************
 * @file           : CortexM4_Core_SysTick_CFG.h
 * @author         : Youssef Ibrahem
 * @brief          : CortexM4_Core_SysTick_CFG.h
 ******************************************************************************
 */
#ifndef CORTEXM4_CORTEXM4_CORE_SYSTICK_CFG_H_
#define CORTEXM4_CORTEXM4_CORE_SYSTICK_CFG_H_

/*----------------------- Include Start ---------------------- */


/* ----------------------- Include END ----------------------- */

/* ----------------------- MACROS Start ---------------------- */

#define SYSTICK_CLKSOURCE_AHB_DIV_8			(0UL)
#define SYSTICK_CLKSOURCE_AHB				    (4UL)

/**
 * @options:
 * 			SYSTICK_CLKSOURCE_AHB_DIV_8
 * 			SYSTICK_CLKSOURCE_AHB
 */
#define	SYSTICK_CLKSOURCE_SELECTION			(SYSTICK_CLKSOURCE_AHB_DIV_8)
/* ----------------------- MACROS END ------------------------ */

/* ----------------------- Macro Functions Start -------------- */


/* ----------------------- Macro Function End ----------------- */

/* ----------------------- User Data Types Start -------------- */

/* ----------------------- User Data Types End ---------------- */

/* ----------------------- Software Interfaces Start ---------- */

/* ----------------------- Software Interfaces end ------------ */

#endif /* CORTEXM4_CORTEXM4_CORE_SYSTICK_CFG_H_ */
