/*
 * @file       : AD5556.c
 * @brief      : AD5556 operation function
 * @version    : V1.0
 * @date       : 2018-2-8
 * @author     :
*/
#include "AD5556.h"
#include "stdint.h"

/**
	* @function : reverse_delay
  * @brief Delay after pin reverse,
  * @retval None
  */
void REVERSE_DELAY(void)
{
	__nop();__nop();__nop();__nop();__nop();
	// 3 * (1/72Mhz) = 41.7ns 
} 
/**
	* @function : AD_RESET_WR
  * @brief WR Pin Reset (active low)
  * @retval None
  */
void AD_RESET_WR(void)
{
	HAL_GPIO_WritePin(WR_N_1_GPIO_Port,WR_N_1_Pin,GPIO_PIN_RESET);
}

void AD_SET_WR(void)
{
	HAL_GPIO_WritePin(WR_N_1_GPIO_Port,WR_N_1_Pin,GPIO_PIN_SET);
}
/**
* @function : AD_SET_LDAC
* @brief LDAC Pin Set (active high)
* @retval None
*/
void AD_SET_LDAC(void)
{
	HAL_GPIO_WritePin(LDAC_1_GPIO_Port,LDAC_1_Pin,GPIO_PIN_SET);
}	

void AD_RESET_LDAC(void)
{
	HAL_GPIO_WritePin(LDAC_1_GPIO_Port,LDAC_1_Pin,GPIO_PIN_RESET);
}	
/**
* @function : AD_RESET_RS
* @brief RS Pin Reset (active low)
* @retval None
*/
void AD_RESET_RS(void)
{
	HAL_GPIO_WritePin(RS_N_1_GPIO_Port,RS_N_1_Pin,GPIO_PIN_RESET);
}	

void AD_SET_RS(void)
{
	HAL_GPIO_WritePin(RS_N_1_GPIO_Port,RS_N_1_Pin,GPIO_PIN_SET);
}	
/**
* @function : AD_SET_DATA
* @brief Set (or reset) data pin
* @para uint16_t Data :   
* @retval None
*/
void AD_SET_DATA(uint16_t Data)
{
	HAL_GPIO_WritePin(GPIOA,D0_Pin,(Data & (uint16_t)(1<<0)) >> 0);
	HAL_GPIO_WritePin(GPIOA,D1_Pin,(Data & (uint16_t)(1<<1)) >> 1);
	HAL_GPIO_WritePin(GPIOA,D2_Pin,(Data & (uint16_t)(1<<2)) >> 2);
	HAL_GPIO_WritePin(GPIOA,D3_Pin,(Data & (uint16_t)(1<<3)) >> 3);
	HAL_GPIO_WritePin(GPIOA,D4_Pin,(Data & (uint16_t)(1<<4)) >> 4);
	HAL_GPIO_WritePin(GPIOA,D5_Pin,(Data & (uint16_t)(1<<5)) >> 5);
	HAL_GPIO_WritePin(GPIOA,D6_Pin,(Data & (uint16_t)(1<<6)) >> 6);
	HAL_GPIO_WritePin(GPIOA,D7_Pin,(Data & (uint16_t)(1<<7)) >> 7);
	
	HAL_GPIO_WritePin(GPIOB,D8_Pin,(Data & (uint16_t)(1<<8)) >> 8);
	HAL_GPIO_WritePin(GPIOB,D9_Pin,(Data & (uint16_t)(1<<9)) >> 9);
	HAL_GPIO_WritePin(GPIOB,D10_Pin,(Data & (uint16_t)(1<<10)) >> 10);
	HAL_GPIO_WritePin(GPIOB,D11_Pin,(Data & (uint16_t)(1<<11)) >> 11);
	HAL_GPIO_WritePin(GPIOB,D12_Pin,(Data & (uint16_t)(1<<12)) >> 12);
	HAL_GPIO_WritePin(GPIOB,D13_Pin,(Data & (uint16_t)(1<<13)) >> 13);
	HAL_GPIO_WritePin(GPIOB,D14_Pin,(Data & (uint16_t)(1<<14)) >> 14);
	HAL_GPIO_WritePin(GPIOB,D15_Pin,(Data & (uint16_t)(1<<15)) >> 15);
}
/**
* @function : AD_write
* @brief Write data to AD5556
* @retval None
*/
void AD_WRITE(uint16_t Data)
{
	AD_SET_DATA(Data);
	AD_RESET_WR();
	REVERSE_DELAY();
	AD_SET_WR();
	REVERSE_DELAY();
	AD_SET_LDAC();
	REVERSE_DELAY();
	AD_RESET_LDAC();
	
	AD_SET_RS();
}
