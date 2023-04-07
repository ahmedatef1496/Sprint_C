/*
 * Utils.h
 *
 * Created: 3/24/2023 11:34:56 AM
 *  Author: atef
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define  SET_BIT(reg ,Bit)   ( reg =reg|(1<<Bit))
#define  CLR_BIT(reg,Bit)  (reg =reg&(~1<<Bit))
#define  TOGGLE_BIT(reg,Bit) (reg =reg^(1<<Bit))
#define  READ_BIT(reg,bit)   (reg &(1<<bit))



#endif /* UTILS_H_ */