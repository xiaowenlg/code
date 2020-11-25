#ifndef __button_H
#define __button_H
#include "stdint.h"
#include "stm32f1xx_hal.h"



//���ð���
#define KEY2_Pin GPIO_PIN_8				//PA8                ��ʼ����
#define KEY2_GPIO_Port GPIOA
#define KEY3_Pin GPIO_PIN_11			//PA11				//���ð���
#define KEY3_GPIO_Port GPIOA
//�����ṹ��
typedef struct K_Info
{
	GPIO_TypeDef *GPIOx; //�����˿�
	uint16_t GPIO_Pin;   //��������
	uint8_t Key_count;;  //ע�ᰴ������
}Key_Message;
typedef void(*fun)(Key_Message keynum); //�ص�������ʽ

void Key_Gpio_init();
uint16_t GetKey_Value(Key_Message *t_keymessage, uint16_t *KeyValue);
void  Decide_KeyValue(uint16_t value, uint16_t *lastvalue, Key_Message *t_keymessage, fun callback);
void ScanKeys(uint16_t *KeyValue, uint16_t *lastvalue, Key_Message *t_keymessage, fun callback);
#endif // !__button_H
