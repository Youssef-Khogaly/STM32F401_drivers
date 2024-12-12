/*
 ******************************************************************************
 * @file           : CortexM4_Core_SysTick.c
 * @author         : Youssef Ibrahem
 * @brief          : CortexM4_Core_SysTick.c
 ******************************************************************************
 */

#include "CortexM4/CortexM4_Core_SysTick.h"

/* Static global variables */
static volatile ptrFuncion_t SysTick_pFunc_CallBack = NULL;
static volatile  u8_t SysTickMode = SYSTICK_MODE_SINGLE_INTERVAL;




/**
 * @brief  		System Tick Configuration
 * @details 	Init system timer and its interrupt  and disable the system Tick timer
 * @Parma[IN] 	SysTick_Ticks number of ticks between two interrupt 24 bit unsigned value
 * @ret 		0 Function Succeeded
 * 				1 Funcation  Failed
 */
u8_t SysTick_Init(u32_t SysTick_Ticks)
{
	u8_t retVal = 0;
	if(SysTick_Ticks <= SYSTICK_LOAD_RELOAD_Msk)
	{
		/*Disable systick timer*/
		CLEAR_BIT(SYSTICK.CTRL ,SYSTICK_CTRL_ENABLE_Msk);
		/* set reload reg to SysTick_Ticks*/
		SYSTICK.LOAD = (SysTick_Ticks-1UL);
		/* reset systick counter value*/
		SYSTICK.VAL = 0;
		/* select processor clock */

	#if ((SYSTICK_CLKSOURCE_SELECTION == SYSTICK_CLKSOURCE_AHB) || (SYSTICK_CLKSOURCE_SELECTION == SYSTICK_CLKSOURCE_AHB_DIV_8))
		MODIFY_REG(SYSTICK.CTRL , SYSTICK_CTRL_CLKSOURCE_Msk , SYSTICK_CLKSOURCE_SELECTION );

	#else
		#error "Invalid SysTick Clock source"
	#endif

		/*disable Systick IRQ*/
		CLEAR_BIT(SYSTICK.CTRL , SYSTICK_CTRL_TICKINT_Msk);
	}
	else
	{
		retVal = 1;
	}
	return retVal;
}

/**
 * @brief  		System Tick Deinitialization
 * @details 	Clear the reload register  and disable system timer
 * @Parma	 	None
 * @ret 	 	None
 *
 */
void SysTick_deinit(void)
{
	CLEAR_BIT(SYSTICK.CTRL ,SYSTICK_CTRL_ENABLE_Msk);
	SYSTICK.LOAD = 0;
	SYSTICK.VAL = 0;
	CLEAR_BIT(SYSTICK.CTRL , SYSTICK_CTRL_TICKINT_Msk);

}


/**
 * @brief  		System Tick wait till reaching the required  ticks
 * @details 	Blocking call , wait till reaching the required ticks
 * @Parma[IN] 	SysTick_Ticks number of ticks between two interrupt 24 bit unsigned value
 * @ret 		None
 */
void SysTick_WaitBlocking(u32_t SysTick_Ticks)
{
	/*Disable systick timer*/
	CLEAR_BIT(SYSTICK.CTRL ,SYSTICK_CTRL_ENABLE_Msk);
	/*Set reloaded reg*/
	SYSTICK.LOAD = (SysTick_Ticks & SYSTICK_LOAD_RELOAD_Msk);
	/*Enable Systick */
	SET_BIT(SYSTICK.CTRL ,SYSTICK_CTRL_ENABLE_Msk);
	/*wait till count flag  = 1*/
 	while( 0UL == (SYSTICK.CTRL & SYSTICK_CTRL_COUNTFLAG_Msk) )
		;
	/*disable systick */
	CLEAR_BIT(SYSTICK.CTRL ,SYSTICK_CTRL_ENABLE_Msk);
	/*reset counter reg and reload reg*/
	SYSTICK.LOAD = 0;
	SYSTICK.VAL = 0;

}


/**
 * @brief  		System Tick Trigger a callback once the calculate the required ticks
 * @details 	Non Blocking Call , Trigger  a callback once calcualte the needed ticks
 * @Parma[IN] 	SysTick_Ticks number of ticks between two interrupt 24 bit unsigned value
 * @Parma[IN] 	call back function address
 * @ret 		None
 */
void SysTick_SingleInterval(u32_t SysTick_Ticks , ptrFuncion_t CallBack )
{
	if(NULL != CallBack)
	{
		/*Set reloaded reg*/
		SYSTICK.LOAD = (SysTick_Ticks & SYSTICK_LOAD_RELOAD_Msk);
		// copy user callback function address
		SysTick_pFunc_CallBack = CallBack;
		/*enable systick periodic interval mode */
		SysTickMode = SYSTICK_MODE_SINGLE_INTERVAL;
		/*enable systick IRQ*/
		SET_BIT(SYSTICK.CTRL , SYSTICK_CTRL_TICKINT_Msk);
		/* Set systick timer irq priority least urgent : Highest priority Number */

		/*enable systick*/
		SET_BIT(SYSTICK.CTRL ,SYSTICK_CTRL_ENABLE_Msk);
	}
	else { /* nothing*/}

}


/**
 * @brief  		System Tick Trigger a callback periodically once  the calculate the required ticks
 * @details 	Non Blocking Call , Trigger  a callback periodically once calcualte the needed ticks
 * @Parma[IN] 	SysTick_Ticks number of ticks between two interrupt 24 bit unsigned value
 * @Parma[IN] 	call back function address
 * @ret 		None
 */
void SysTick_PeriodicInterval(u32_t SysTick_Ticks , ptrFuncion_t CallBack )
{
	if(NULL != CallBack)
	{
		/*Set reloaded reg*/
		SYSTICK.LOAD = (SysTick_Ticks & SYSTICK_LOAD_RELOAD_Msk);
		// copy user callback function address
		SysTick_pFunc_CallBack = CallBack;
		/*enable systick single interval mode */
		SysTickMode = SYSTICK_MODE_PERIODIC_INTERVAL;
		/*enable systick IRQ*/
		SET_BIT(SYSTICK.CTRL , SYSTICK_CTRL_TICKINT_Msk);
		/* Set systick timer irq priority least urgent : Highest priority Number */

		/*enable systick*/
		SET_BIT(SYSTICK.CTRL ,SYSTICK_CTRL_ENABLE_Msk);
	}
	else { /* nothing*/}

}





u32_t SysTick_GetRemainingTicks(void)
{
	return (SYSTICK.VAL) ;
}









void SysTick_Handler(void)
{
	if(SYSTICK_MODE_SINGLE_INTERVAL == SysTickMode)
	{
		CLEAR_BIT(SYSTICK.CTRL ,SYSTICK_CTRL_ENABLE_Msk);
		SYSTICK.LOAD = 0;
		SYSTICK.VAL = 0;
		CLEAR_BIT(SYSTICK.CTRL , SYSTICK_CTRL_TICKINT_Msk);

	}
	else {/*nothing*/}
	if(SysTick_pFunc_CallBack)
	{
		SysTick_pFunc_CallBack();
	}
	else
	{ /*nothing*/}
}










