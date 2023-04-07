/*
 * DIO_Private.h
 *
 * Created: 3/25/2023 1:16:51 PM
 *  Author: atef
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

extern const DIO_PinStatus_type  PinsStatusArray[TOTAL_PINS];
static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);




#endif /* DIO_PRIVATE_H_ */