/*
 * @file       : Sinwave.c
 * @brief      : Sin wave data creat and opreation
 * @version    : V1.0
 * @date       : 2018-2-8
 * @author     :
*/

#include "sinwave.h"	

uint16_t SineWave_Value[256] = {0};	
/**
	* @function : SineWave_Data
  * @brief Creat sinwave data
  * @retval None
  */
static void SineWave_Data(uint16_t cycle ,uint16_t *waveData){
	uint16_t i;
	for( i=0;i<cycle;i++)
	{
		waveData[i]=(uint16_t)(sin((1.0 * i / (cycle - 1)) * 2 * PI) * (AD5556_BINARYADDR_LIMIT + 1) + AD5556_BINARYBASE_ADDR);
	}
}
/**
	* @function : SineWave_Init
  * @brief Init sinwave data
  * @retval None
  */
void SineWave_Init(void){
  SineWave_Data( 256 ,SineWave_Value);
}
/**
	* @function : Set_WaveFre
  * @brief set sinwave frenquece
  * @retval None
  */
void Set_WaveFre(uint16_t fre){

}

