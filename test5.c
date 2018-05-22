#include "LPC11XX.H"

#define LED1_ON()  (LPC_GPIO2->DATA &= 0xFFFE)
#define LED1_OFF() (LPC_GPIO2->DATA |= 0x0001)

#define KEY1_DOWN() ((LPC_GPIO3->DATA & 0x01) != 0x01)

unsigned char state = 0;

int main()
{
	
	LPC_GPIO2->DIR = 0xF;

    SysTick->CTRL = 0;//�ο�ʱ��
    SysTick->LOAD = 0xBEBBEE; //��������
    SysTick->VAL = 0;//����
    SysTick->CTRL |= 0x3;//ϵͳ���������ж�ʹ��
    NVIC_EnableIRQ(SysTick_IRQn);

    while(1)
    {
    	if(state)
    		LED1_ON();
    	else
    		LED1_OFF();
    }
}


void SysTick_Handler(void)
{
	state = ~state;
}