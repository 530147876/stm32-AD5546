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

#define BIT_8_MASK 0x00FF
/************************Usart Data Nask******************************/
#define COEFFICIENT 0x01
#define IN_PHASE_MASK 0x01
#define REVERSE_PHASE_MASK 0x02
#define RESERVE_MASK 0x00
#define CHANNEL1_MASK 0x01
#define CHANNEL2_MASK 0x02
/**
* @function : AD_WRITE
* @brief Write data to AD5556
* @retval None
*/
void AD_WRITE(uint16_t Data);
/**
* @function : REVERSE_DELAY
* @brief Delay after pin reverse,
* @retval None
*/
void REVERSE_DELAY(void);
void AD_RESET_WR(void);
void AD_SET_WR(void);
void AD_SET_LDAC(void);
void AD_RESET_LDAC(void);
void AD_RESET_RS(void);
void AD_SET_RS(void);
void AD_SET_DATA(uint16_t Data);


#endif
