/* ========================================
 *
 * Copyright Lik Siang Chew, 2022
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF LIK SIANG CHEW.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint8 ch;
    UART_1_Start();
    char Rx;
    for(;;)
    {
        /* Place your application code here. */
        if(UART_1_GetRxBufferSize() > 0)
		{
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
            
	        //UART_1_PutChar(Rx);
            UART_1_ClearRxBuffer();
            //Pin_1_Write(~Pin_1_Read());
		}
        
        if (Pin_2_Read() == 0) {
            Pin_1_Write(0);
            CyDelay(500);
        }
    }
}

/* [] END OF FILE */
