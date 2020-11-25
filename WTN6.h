#ifndef __WTN6_H
#define __WTN6_H
#include "main.h"
#include "stdint.h"
#include "stm32f1xx_hal.h"
/*
WTN6ϵ������оƬ
*/
#define  CLK_2A                 PBout(13) //ʱ�������λ��������
#define  P_DATA_2A               PBout(12) //���������λ��������
#define  CLK_2A_PIN             GPIO_PIN_13//ʱ������
#define  P_DATA_2A_PIN          GPIO_PIN_12//��������
#define WTN6_BUSY_Pin		GPIO_PIN_14
#define WTN_GPIO_Port			GPIOB
//Function
void WTN6_Gpio_Init();				//��ʼ��
uint8_t Line_2A_WTN6(uint8_t SB_DATA);//����һ���ֽ�
void WTN6_PlayOneByte(uint8_t val, uint32_t timout);//����һ����ַ
uint8_t WTN6_PlayArray(uint8_t arrlen, uint8_t *soundarr, uint32_t timout);//����һ���ַ��������
uint8_t WTN6_PlayArray_1(uint8_t arrlen, uint8_t *soundarr, uint32_t timout);//����һ���ַ��������
#endif
