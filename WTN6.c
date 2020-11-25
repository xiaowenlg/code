/************************************************************************/
/*WTN6ϵ�� ����оƬ����                                                 */
/************************************************************************/


#include "WTN6.h"
#include "system.h"
#include "dwt_stm32_delay.h"
#include "stdio.h"
#include "math.h"

void WTN6_Gpio_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	__HAL_RCC_GPIOB_CLK_ENABLE();
	/*WTN6040���ų�ʼ��*/
	/*PB13---OUT*/ /*�� PB12---OUT*/
	GPIO_InitStruct.Pin = CLK_2A_PIN | P_DATA_2A_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(WTN_GPIO_Port, &GPIO_InitStruct);
	/*PB15---INPUT*/
	GPIO_InitStruct.Pin = WTN6_BUSY_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(WTN_GPIO_Port, &GPIO_InitStruct);
}

uint8_t Line_2A_WTN6(uint8_t SB_DATA)
{
	uint8_t S_DATA, B_DATA, j;
	CLK_2A = 1; //ʱ����
	P_DATA_2A = 1; //������
	S_DATA = SB_DATA;
	CLK_2A = 0;
	osDelay(5);
	B_DATA = S_DATA & 0X01;
	//PBout(13) = 1;
	for (j = 0; j < 8; j++)
	{

		CLK_2A = 0; // ����
		P_DATA_2A = B_DATA; //��������һλ
		//SendByte2(B_DATA);

		DWT_Delay_us(300); //��ʱ 300us 
		CLK_2A = 1; //����
		DWT_Delay_us(300); //��ʱ 300us 

		S_DATA = S_DATA >> 1;
		B_DATA = S_DATA & 0X01;
	}
	P_DATA_2A = 1;
	CLK_2A = 1;


}
///////////////////
//************************************
// ����:    WTN6040_PlayOneByte
// ����ȫ��:  WTN6040_PlayOneByte
// ��������:    public 
// ����ֵ:   void
// Qualifier:
// ����: uint8_t val    ���ŵ�ַ
// ����: uint32_t timout   �ȴ������ź�ʱ�䣬��λms
//************************************
void WTN6_PlayOneByte(uint8_t val, uint32_t timout)
{
	long tim = HAL_GetTick();
	while (HAL_GetTick() - tim < timout)
	{
		if (HAL_GPIO_ReadPin(WTN_GPIO_Port, WTN6_BUSY_Pin) != 0)
		{
			break;
		}
	}
	//while (HAL_GPIO_ReadPin(WTN6040_BUSY_GPIO_Port, WTN6040_BUSY_Pin) != 1);
	Line_2A_WTN6(val);


}
uint8_t WTN6_PlayArray(uint8_t arrlen, uint8_t *soundarr, uint32_t timout)
{
	uint8_t res = 0;
	uint8_t i = 0;
	long tim = HAL_GetTick();
	for (i = 0; i < arrlen; i++)
	{
		WTN6_PlayOneByte(soundarr[i], timout);
		//osDelay(10);
		//Uart_printf(&DEBUG_UART.huart, "Data=========%d:%x\r\n", i, soundarr[i]);//���Բ�������
	}

	while (HAL_GetTick() - tim < timout)
	{
		if (HAL_GPIO_ReadPin(WTN_GPIO_Port, WTN6_BUSY_Pin) != 0)
		{
			break;
		}
	}
	//while (HAL_GPIO_ReadPin(WTN6040_BUSY_GPIO_Port, WTN6040_BUSY_Pin) != 1);
	if (i == arrlen)
		res = 1;
	else
		res = 1;//�������
	//Line_2A_WTN6(9);
	return res;
}
uint8_t WTN6_PlayArray_1(uint8_t arrlen, uint8_t *soundarr,uint32_t timout)
{
	uint8_t res = 0;
	uint8_t i = 0;
	for (i = 0; i < arrlen; i++)
	{
		WTN6_PlayOneByte(soundarr[i],timout);
		//osDelay(10);
		//Uart_printf(&DEBUG_UART.huart, "Data=========%d:%x\r\n", i, soundarr[i]);//���Բ�������
	}

	return res;
}