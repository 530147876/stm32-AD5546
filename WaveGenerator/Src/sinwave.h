/*
 * @file       : Sinwave.h
 * @brief      : Function declaration
 * @version    : V1.0
 * @date       : 2018-2-8
 * @author     :
*/
#ifndef  __SINEWAVE_H
#define  __SINEWAVE_H

#include "stdint.h"
#include "math.h"
#include "AD5556.h"

#define PI  3.1415926

extern uint16_t SineWave_Value[256];
/**
	* @function : SineWave_Init
  * @brief Init sinwave data
  * @retval None
  */
void SineWave_Init(void);
/**
	* @function : Set_WaveFre
  * @brief set sinwave frenquece
  * @retval None
  */
void Set_WaveFre(uint16_t fre);

#endif

