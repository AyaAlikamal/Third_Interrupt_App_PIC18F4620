/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"
led_t led1 = {
.Port_Name = PORTC_INDEX,
.pin = PIN0,
.led_statues = LED_OFF
};

led_t led2 = {
.Port_Name = PORTC_INDEX,
.pin = PIN1,
.led_statues = LED_OFF
};

led_t led3 = {
.Port_Name = PORTC_INDEX,
.pin = PIN2,
.led_statues = LED_OFF
};

led_t led4 = {
.Port_Name = PORTC_INDEX,
.pin = PIN3,
.led_statues = LED_OFF
};

void RB0_INT_ISR_HIGH(void){
led_turn_on(&led1);
__delay_ms(300);
led_turn_off(&led1);
}
void RB0_INT_ISR_LOW(void){
led_turn_on(&led2);
__delay_ms(300);
led_turn_off(&led2);
}
void RB1_INT_ISR_HIGH(void){
led_turn_off(&led1);

}
void RB1_INT_ISR_LOW(void){
led_turn_off(&led2);
}
void RB2_INT_ISR_HIGH(void){
led_turn_on(&led3);
}
void RB2_INT_ISR_LOW(void){
led_turn_on(&led4);
}
void RB3_INT_ISR_HIGH(void){
led_turn_off(&led3);
}
void RB3_INT_ISR_LOW(void){
led_turn_off(&led4);
}



 Ex_Interrupt_RBx_t RB_Int0_obj= {
 .Ext_Intterrupt_HIGH = RB0_INT_ISR_HIGH,
 .Ext_Intterrupt_LOW = RB0_INT_ISR_LOW,
 .priority = Interrupt_Periority_HIGH,
 .mcu_pin.port = PORTB_INDEX,
 .mcu_pin.pin = PIN4,
 .mcu_pin.direction = Input
 };
 
 Ex_Interrupt_RBx_t RB_Int1_obj= {
 .Ext_Intterrupt_HIGH = RB1_INT_ISR_HIGH,
 .Ext_Intterrupt_LOW = RB1_INT_ISR_LOW,
 .priority = Interrupt_Periority_HIGH,
 .mcu_pin.port = PORTB_INDEX,
 .mcu_pin.pin = PIN5,
 .mcu_pin.direction = Input
 };
 
 Ex_Interrupt_RBx_t RB_Int2_obj= {
 .Ext_Intterrupt_HIGH = RB2_INT_ISR_HIGH,
 .Ext_Intterrupt_LOW = RB2_INT_ISR_LOW,
 .priority = Interrupt_Periority_HIGH,
 .mcu_pin.port = PORTB_INDEX,
 .mcu_pin.pin = PIN6,
 .mcu_pin.direction = Input
 };
 
 Ex_Interrupt_RBx_t RB_Int3_obj= {
 .Ext_Intterrupt_HIGH = RB3_INT_ISR_HIGH,
 .Ext_Intterrupt_LOW = RB3_INT_ISR_LOW,
 .priority = Interrupt_Periority_HIGH,
 .mcu_pin.port = PORTB_INDEX,
 .mcu_pin.pin = PIN7,
 .mcu_pin.direction = Input
 };
 
int main() {
   
Std_ReturnType ret = E_NOT_OK;
ret = Interrupt_RBx_Initialization(&RB_Int0_obj);
ret = Interrupt_RBx_Initialization(&RB_Int1_obj);
ret = Interrupt_RBx_Initialization(&RB_Int2_obj);
ret = Interrupt_RBx_Initialization(&RB_Int3_obj);


ret = led_initialize(&led1);
ret = led_initialize(&led2);
ret = led_initialize(&led3);
ret = led_initialize(&led4);

application_initialize();

while(1){  

}
 return (EXIT_SUCCESS);
}
void application_initialize(void){
   ECU_Layer_initialize();
  
}
