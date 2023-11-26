/* 
 * File:   application.h
 * Author: AyaAli
 *
 * Created on September 22, 2023, 10:53 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include "ECU_Layer/ecu_init.h"
#include "MCAL_Layer/interrupt/mcal_external_interrupt.h"


 void application_initialize(void);
 void welcome_massage(void);
 void loading_massage(void);

#endif	/* APPLICATION_H */

