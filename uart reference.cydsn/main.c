/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>

#define BUF_SIZE 64 // USBUART fixed buffer size

void usbPutString(char *s);
void usbPutChar(char c);

CY_ISR_PROTO(switchISR);

char displaystring[BUF_SIZE] = "UART Lab Exercise 4\n";

CY_ISR(switchISR) {
    usbPutString(displaystring);
    
}

int main(void) {
    CyGlobalIntEnable;

    USBUART_Start(0,USBUART_5V_OPERATION);
    
    usbPutString(displaystring);

    for(;;) {
        //lol
    }
}

void usbPutString(char *s) {
    while (USBUART_CDCIsReady() == 0);
    s[63]='\0';
    s[62]='!';
    USBUART_PutData((uint8*)s,strlen(s));
}

void usbPutChar(char c){
    while (USBUART_CDCIsReady() == 0);
    USBUART_PutChar(c);
}

/* [] END OF FILE */
