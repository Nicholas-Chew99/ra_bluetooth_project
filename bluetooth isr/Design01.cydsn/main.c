/* ========================================
 *
 * Copyright Lik Siang Chew, 2022
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Lik Siang Chew.
 *
 * ========================================
*/
#include "project.h"

char Rx;

CY_ISR(trigger_isr_Handler)
{
    //Rx & Tx can also be changed to 12[2], 12[3]
    //Rx of PSOC = Tx of bluetooth and vice versa
    Rx = UART_1_GetChar();
    if (Rx == 'g') {
        UART_1_PutChar(Rx);
        Pin_1_Write(~Pin_1_Read());

    } else if (Rx == 'r'){
        UART_1_PutChar(Rx);
        Pin_red_Write(~Pin_red_Read());

    } else if (Rx == 'o') {
        UART_1_PutChar(Rx);
        Pin_1_Write(0);
        Pin_red_Write(0);
    } else if (Rx == 'a') {
        UART_1_PutChar(Rx);
        Pin_1_Write(1);
        Pin_red_Write(1);
    }
    
    UART_1_ClearRxBuffer();
    isr_rx_ClearPending();
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint8 ch;
    UART_1_Start();
    char Rx;
    
    isr_rx_StartEx(trigger_isr_Handler);
    for(;;)
    {
        CyDelay(10000);
        UART_1_PutChar('D');
        /* Place your application code here. */

    }
}

/* [] END OF FILE */
