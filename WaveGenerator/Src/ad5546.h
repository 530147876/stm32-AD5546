/*
 * @file       : AD5546.h
 * @brief      : AD5546 parameters define
 * @version    : V1.0
 * @date       : 2018-2-8
 * @author     :
*/
#ifndef  _AD5546_H_
#define  _AD5546_H_

#include "math.h"
#include "stm32f1xx_hal.h"

#define Vref 3.3	
#define UNIPOLAR 0x00  				// Two-Quadrant  Multiplying Mode,  Vout = (0V to -Vref) or (0V to +Vref) , depend on the circuit design
#define BIPOLAR  0x01					// Four-Quadrant Multiplying Mode, Vout = -Vref to + Vref
#define AD_QUADRANT BIPOLAR		// Default Quadrant Mode

#define AD5546_BINARYADDR_LIMIT pow(2,(16-AD_QUADRANT))-1	 // AD5556_BinaryAddr_limit
#define AD5546_BINARYBASE_ADDR AD_QUADRANT * ( 1<<15 )		 // D in Binary when Vout = 0v

/************************Usart Data Nask******************************/
#define COEFFICIENT 0x01							// 固定系数
#define IN_PHASE_MASK 0x01						// 同相
#define REVERSE_PHASE_MASK 0x02				// 反相
#define RESERVE_MASK 0x00							// 保留位
#define CHANNEL1_MASK 0x01						// 通道1
#define CHANNEL2_MASK 0x02						// 通道2
/**
* @function : AD_write
* @brief Write data to AD5546
* @retval None
*/
void AD_write(uint16_t Data);

#endif
