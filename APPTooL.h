#ifndef _APPTOOL_H
#define _APPTOOL_H
#include "stdint.h"
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "main.h"
#define HIGHT                 1
#define LOW                   0
//触发器数组大小
#define TRLENGHT              10
//语音芯片语音地址
#define S_POINT				21
#define S_TEN               10               //十
#define S_HUNDRED			11				//百
#define S_THOUSAND          12				//千
#define S_WAN				13				//万

typedef void(*TrlCallback)(uint8_t);

void SingleTrig(TrlCallback p, uint8_t val, uint8_t inval, uint8_t index, uint8_t com);
uint8_t PrepartData(uint16_t dat, uint8_t *res_dat);// 语音地址分解计算;
uint8_t MergedData(double numdata, uint8_t *dat,uint8_t com);
uint8_t GetPlayData(uint16_t num, uint16_t tim, double mcal, uint8_t *dat);
int insertArray(uint8_t *arr, uint16_t arrlen, uint8_t *inarr, uint16_t inarrlen, uint16_t pos);
int insertOneByte(uint8_t *arr, uint16_t arrlen, uint8_t indata, uint16_t pos);
uint8_t StrJoin(char *mac, char*id, char *lastdata);
uint16_t ConsumeHeat(float weight, float tim, float v);
int GetMax_index(int *arr, int len);
int GetMax(uint32_t *arr, uint16_t len);
uint8_t DataSeparation(double dat, uint8_t *res_dat);//数据转换成语音地址数组
uint8_t GetTimData(uint32_t tdata, uint8_t *dat);//转换播放时间
#endif // !_APPTOOL_H
