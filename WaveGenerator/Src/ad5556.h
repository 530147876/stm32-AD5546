/*
 * @file       : AD5556.h
 * @brief      : AD5556 parameters define
 * @version    : V1.0
 * @date       : 2018-2-8
 * @author     :
*/
#ifndef  _AD5556_H_
#define  _AD5556_H_

#include "math.h"
#include "stm32f1xx_hal.h"

#define Vref 3.3	
#define UNIPOLAR 0x00  				// Two-Quadrant  Multiplying Mode,  Vout = (0V to -Vref) or (0V to +Vref) , depend on the circuit design
#define BIPOLAR  0x01					// Four-Quadrant Multiplying Mode, Vout = -Vref to + Vref
#define AD_Quadrant BIPOLAR		// Default Quadrant Mode

#define AD5556_BinaryAddr_limit pow(2,(16-AD_Quadrant))-1	 // AD5556_BinaryAddr_limit
#define AD5556_BinaryBase_Addr  AD_Quadrant * ( 1<<15 )		 // D in Binary when Vout = 0v

/**
* @function : AD_write
* @brief Write data to AD5556
* @retval None
*/
void AD_write(uint16_t Data);

#endif
