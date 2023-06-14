
#include "stm32f10x.h"
 void Delay(u32 count)
 {
  u32 i=0;
  for(;i<count;i++);

 }
 int main(void)
 {	
  GPIO_InitTypeDef  GPIO_InitStructure;
 	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PA�˿�ʱ��
	
	//13LED������PA5���ߵ�ƽʹ��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				       //LED0-->PA.5 �˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		  //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		  //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);					      //�����趨������ʼ��GPIOA.5
  GPIO_SetBits(GPIOA,GPIO_Pin_5);						            //PA.5 �����

  while(1)
	{
	  GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		Delay(4000000);
		GPIO_SetBits(GPIOA,GPIO_Pin_5);
		Delay(2000000);
	}
 }

