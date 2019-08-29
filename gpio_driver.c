
#include "gpio_driver.h"


void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_ConfigPinParam *GPIO_PinConfig)
{    
     GPIOx->MODER &= ~(0x03 << (2*GPIO_PinConfig->pin));
	GPIOx->MODER |=  (GPIO_PinConfig->mode << (2*GPIO_PinConfig->pin));

	if(GPIO_PinConfig->mode == GPIO_GENERAL_PURPOSE_OP_MODE)
		GPIOx->OTYPER |=  (GPIO_PinConfig->output_type << GPIO_PinConfig->pin);

	GPIOx->OSPEEDR |= (GPIO_PinConfig->speed  << (2*GPIO_PinConfig->pin));

	GPIOx->PUPDR   |= (GPIO_PinConfig->pull_up_down  << (2*GPIO_PinConfig->pin));
     
	if(GPIO_PinConfig->pin < 8)
		GPIOx->AFR[0] |=  (GPIO_PinConfig->alternate_func << (4*GPIO_PinConfig->pin));
	else
		GPIOx->AFR[1] |=  (GPIO_PinConfig->alternate_func  << (4* (GPIO_PinConfig->pin %8)));

     

};


uint8_t GPIO_Read(GPIO_TypeDef * GPIOx,uint8_t PIN_NO){
     
    uint32_t value = (GPIOx->IDR>>PIN_NO) & 0x00000001;
     return value;
};


void GPIO_Write(GPIO_TypeDef * GPIOx ,uint8_t PIN_NO ,uint8_t value){
     if(value)
          GPIOx->ODR |= (1<<PIN_NO);
     else 
          GPIOx->ODR &= ~(1<<PIN_NO);

};
