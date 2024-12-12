/**
 ******************************************************************************
 * @file           : CortexM4_Core_NVIC.c
 * @author         : Youssef Ibrahem
 * @brief          : CortexM4_Core_NVIC driver
 ******************************************************************************
 */
#include "CortexM4/CortexM4_Core_NVIC.h"
















/**
 * \brief 		Enable Interrupt
 * \details 	Enable  a specific interrupt in NVIC
 * \parma [in] IRQn Device specific interrupt  number
 * \Note 		IRQn Must not be negative
 */
void NVIC_EnableIRQ(IRQn_Type IRQn){

	if((s32_t)IRQn >= 0L )
	{

		NVIC->ISER[(((u32_t)IRQn) >> 5UL)] |= ( 1UL <<((((u32_t)IRQn) & 0x1FU) ) ) ;
	}
	else
	{
		/*nothing*/
	}
}
/**
 * \brief 		Disable Interrupt
 * \details 	Disable  a specific interrupt in NVIC
 * \parma [in] IRQn Device specific interrupt  number
 * \Note 		IRQn Must not be negative
 */
void NVIC_DisableIRQ(IRQn_Type IRQn){
	if((s32_t)IRQn >= 0L )
	{

		NVIC->ICER[(((u32_t)IRQn) >> 5UL)] |= ( 1UL <<((((u32_t)IRQn) & 0x1FU) ) ) ;
	}
	else
	{
		/*nothing*/
	}
}
/**
 * \brief 		set Interrupt pending
 * \details 	set interrupt in pending state
 * \parma [in] IRQn Device specific interrupt  number
 * \Note 		IRQn Must not be negative
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn){
	if((s32_t)IRQn >= 0L )
	{

		NVIC->ISPR[(((u32_t)IRQn) >> 5UL)] |= ( 1UL <<((((u32_t)IRQn) & 0x1FU) ) ) ;
	}
	else
	{
		/*nothing*/
	}
}
/**
 * \brief 		Clear Interrupt pending
 * \details 	Clear interrupt in pending state
 * \parma [in] IRQn Device specific interrupt  number
 * \Note 		IRQn Must not be negative
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn){
	if((s32_t)IRQn >= 0L )
	{

		NVIC->ICPR[(((u32_t)IRQn) >> 5UL)] |= ( 1UL <<((((u32_t)IRQn) & 0x1FU) ) ) ;
	}
	else
	{
		/*nothing*/
	}
}
/**
 * \brief 		Get Active interrupt
 * \details 	check if  IRQn is in active state or not
 * \parma [in] IRQn Device specific interrupt  number
 * \return 		0 IRQn interrupt is not active
 * \return 		1 IRQn  if the status of the corresponding interrupt is active or active and pending
 * \Note 		IRQn Must not be negative
 */
u32_t NVIC_GetActiveIRQ(IRQn_Type IRQn){

	if((s32_t)IRQn >= 0L )
	{
		return ((u32_t)( (NVIC->IABR[ (((u32_t)IRQn) >> 5UL)]) >> ((((u32_t)IRQn) & 0x1FUL)  ) ) & 0x01UL);
	}
	else
	{
		/*nothing*/
	}
	return 0;
}

/**
 * \brief 		Get interrupt priority
 * \details 	read interrupt priority
 * \parma [in] IRQn Device specific interrupt  number
 * \return 		interrupt priority
 * 				Value is automatically aligned to  implemented priority bits of mcu
 * \Note 		IRQn Must not be negative
 *
 */
u32_t NVIC_GetPriority(IRQn_Type IRQn)
{

	if((s32_t)IRQn >= 0L )
	{
		return( (NVIC->IPR[((u32_t)IRQn)]) >> ((8U - NVIC_PRIORITY_BITS) ) );
	}
	else
	{
		/*nothing*/

	}

	return 0UL;
}
/**
 * \brief 		set interrupt priority
 * \details 	set interrupt priority
 * \parma [in] IRQn Device specific interrupt  number
 * \parma [in] priority priority to be set
 * \Note 		IRQn Must not be negative
 *
 */
void NVIC_SetPriority(IRQn_Type IRQn , u32_t priority)
{
	if((s32_t)IRQn >= 0L )
	{
		NVIC->IPR[((u32_t)IRQn)] = ( (u8_t)((u8_t)priority << (8U - NVIC_PRIORITY_BITS)) );
	}
	else
	{
		/*nothing*/
	}
}







