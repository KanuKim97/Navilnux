//------------------------------------------------------------------------------
// 화일명 : gpio.c
// 설  명 : ezBoot의 GPIO 제어 루틴이다. 
// 
// 작성자 : 유영창 (주)제이닷디엔티 frog@falinux.com
// 작성일 : 2001년 10월 8일
// 수  정 : 2003-06-07	오재경 (주)제이닷디엔티 freefrug@falinux.com  -- 푸지
// 저작권 : (주)제이닷디엔티 
// 주  의 : 
//------------------------------------------------------------------------------

//******************************************************************************
//
// 헤더 정의
//
//******************************************************************************
#include <pxa255.h>
#include <gpio.h>

//******************************************************************************
//
// 광역 변수 정의
//
//******************************************************************************
//static int GPIODataV = 0;

//******************************************************************************
//
// 함수 정의
//
//******************************************************************************
//------------------------------------------------------------------------------
// 설명 : GPIO 의 부가기능을 설정한다.
// 주의 :
//------------------------------------------------------------------------------
void set_GPIO_mode(int gpio_mode)
{
	int gpio = gpio_mode & GPIO_MD_MASK_NR;
    	int fn = (gpio_mode & GPIO_MD_MASK_FN) >> 8;
    	int gafr;

    	if (gpio_mode & GPIO_MD_MASK_DIR) GPDR(gpio) |=  GPIO_bit(gpio);
    	else                              GPDR(gpio) &= ~GPIO_bit(gpio);
    
    	gafr = GAFR(gpio) & ~(0x3 << (((gpio) & 0xf)*2));
    	GAFR(gpio) = gafr |  (fn  << (((gpio) & 0xf)*2));
}
//------------------------------------------------------------------------------
// 설명 : GPIO 를 초기화 한다.
// 주의 : start.S 루틴에서 처리하였다.
//------------------------------------------------------------------------------
void GPIOInit(void)
{
	
}
//------------------------------------------------------------------------------
// 설명 : GPIO 에 연결된 LED를 설정한다. 
// 매계 : value : LED의 OnOff 패턴 
// 반환 : LedIndex : 제어하고자 하는 LED Index
//        value    : 0 -> LED off, 1 -> LED on 
// 주의 : 없음 
//------------------------------------------------------------------------------
void  GPIO_SetLED( int LedIndex, int value )
{
	if( value )
	{
		// led on
		switch( LedIndex )
		{
		case 0 : GPCR0 = LED_0; break;
		case 1 : GPCR0 = LED_1; break;
		case 2 : GPCR0 = LED_2; break;
		case 3 : GPCR0 = LED_3; break;
		}
	}
	else
	{
		// led off
		switch( LedIndex )
		{
		case 0 : GPSR0 = LED_0; break;
		case 1 : GPSR0 = LED_1; break;
		case 2 : GPSR0 = LED_2; break;
		case 3 : GPSR0 = LED_3; break;
		}
	}
}


