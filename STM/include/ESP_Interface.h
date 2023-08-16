/*
 * ESP_Interface.h
 *
 *  Created on: Jul 6, 2023
 *      Author: amres
 */

#ifndef ESP_INTERFACE_H_
#define ESP_INTERFACE_H_
void ESP_Init();
void ESP_SendCommand();
void Router_Connection();
void ConnectToServer(u8 * IP,u8 *PORT);
void ESP8266_VidClearBuffer ( void );
void MUSART_CALLBACK(void);
void functi(void);
u8 Data_fromServer(void);
u8 SendLength(u8 *Length);
u8 SendData(void);
#endif /* ESP_INTERFACE_H_ */
