/*
 ******************************************************************************
 * @file           : CortexM4_Core_SCB.c
 * @author         : Youssef Ibrahem
 * @brief          : contains the  static code to control system control block
 ******************************************************************************
 */

#include "CortexM4/CortexM4_Core_SCB.h"



/**
 * 	\brief set group priority
 * 	\details set priority group using the required unlock sequence
 * 	\parma	[in]	PriorityGroup priority grouping macro field
 */
void SCB_SetPriorityGrouping(u32_t PriorityGroup)
{

	u32_t l_register_temp = SCB->AIRCR;
	 /*Clear Prigroup bits and vectkey bits*/
	l_register_temp &= ~( SCB_AIRCR_VECTKEY_MASK | SCB_AIRCR_PRIGROUP_MASK	);
	/* assign priority group config*/
	l_register_temp |= ((0x05FAUL << SCB_AIRCR_VECTKEY_POS)| ((PriorityGroup & 0x07UL) << SCB_AIRCR_PRIGROUP_POS) );
	SCB->AIRCR = l_register_temp;

}

/**
 * 	\brief return group priority
 * 	\details get priority group using the required unlock sequence
 * 	\parma	none
 * 	\return	PriorityGroup priority grouping macro field
 */
u32_t SCB_GetPriorityGrouping(void)
{
	return ((SCB->AIRCR & SCB_AIRCR_PRIGROUP_MASK) >> SCB_AIRCR_PRIGROUP_POS);
}
