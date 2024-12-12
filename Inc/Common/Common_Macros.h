/*
 ******************************************************************************
 * @file           : Common_Macros.h
 * @author         : Youssef Ibrahem
 * @brief          : common macros
 ******************************************************************************
 */
#ifndef COMMON_COMMON_MACROS_H_
#define COMMON_COMMON_MACROS_H_

/*----------------------- Include Start ---------------------- */

/* ----------------------- Include END ----------------------- */

/* ----------------------- MACROS Start ---------------------- */

/* ----------------------- MACROS END ------------------------ */

/* ----------------------- Macro Functions Start -------------- */
#define SET_BIT(REG,BIT_Msk)	( (REG) |=  (BIT_Msk) )
#define CLEAR_BIT(REG,BIT_Msk)	( (REG) &= ~(BIT_Msk) )
#define TOGGLE_BIT(REG_BIT_Msk)	( (REG) ^= (BIT_Msk)  )
#define READ_BIT(REG,BIT_Msk)	( ((REG) & (BIT_Msk)) )
#define MODIFY_REG(REG,CLEAR_Msk,SET_Msk) 	((REG) = (( (REG) & ~(CLEAR_Msk)) | (SET_Msk)) )

/* ----------------------- Macro Function End ----------------- */

/* ----------------------- User Data Types Start -------------- */

/* ----------------------- User Data Types End ---------------- */

/* ----------------------- Software Interfaces Start ---------- */

/* ----------------------- Software Interfaces end ------------ */

#endif /* COMMON_COMMON_MACROS_H_ */
