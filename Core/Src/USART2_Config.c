#include "USART2_Config.h"
#include <stm32f103x6.h>

void USART2_Init(void){
   //Enable GPIOA Clock
   RCC -> APB2ENR |= (1<<2);
   //Enable USART2 Clock
   RCC -> APB1ENR |= (1<17);

   /*
      -USARTx_TX Full duplex Alternate Function push-pull
      -USART2_TX -> PA2
      -USARTx_RX Full duplex Input floating
      -USART2_RX -> PA3
   */

   //PA2 OUTPUT Mode, Max 50 Mhz
   GPIOA -> CRL |= (1<<8);
   GPIOA -> CRL |= (1<<9);
   //PA2 Alternate Function push-pull
   GPIOA -> CRL &= ~(1<<10);
   GPIOA -> CRL |=  (1<<11);

   //PA3 INPUT Mode
   GPIOA -> CRL &= ~(1<<12);
   GPIOA -> CRL &= ~(1<<13);
   //PA3 Floating Input
   GPIOA -> CRL |=  (1<<14);
   GPIOA -> CRL &= ~(1<<15);
   //No REMAP
   AFIO -> MAPR &= ~(1<<3);

   //USART ENABLE
   USART2 -> CR1 |= (1<<13);

   //1 Start bit 8 data bits n stop bit
   USART2 -> CR1 &= ~(1<<12);

   //1 Stop bit
   USART2 -> CR2 &= ~(1<<12);
   USART2 -> CR2 &= ~(1<<13);

   //Transmitter Enable
   USART2 -> CR1 |= (1<<3);

   //115200 BAUD RATE
   USART2 -> BRR = (13<<4);
   USART2 -> BRR = (80<<0);

}
void USART2_TransmitData(uint8_t data){
   USART2 -> DR = data;
}
void USART2_ReceiveData(uint8_t data){
    
}