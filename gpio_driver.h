	#ifndef GPIO_DRIVER_H
	#define GPIO_DRIVER_H
	#include "STM32F446xx.h"


	#define GPIO_RCC_CLK_ENABLE()					(RCC->AHB1ENR |= (1<<RCC_AHB1ENR_CRCEN_Pos))
	#define GPIO_RCC_CLK_DISABLE()				(RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_CRCEN_Pos))

	#define GPIO_RCC_CLK_GPIOA_ENABLE()	 	     (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOAEN_Pos))
	#define GPIO_RCC_CLK_GPIOA_DISABLE()              (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOAEN_Pos))

	#define GPIO_RCC_CLK_GPIOB_ENABLE()		     (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOBEN_Pos))
	#define GPIO_RCC_CLK_GPIOB_DISABLE()	          (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOBEN_Pos))

	#define GPIO_RCC_CLK_GPIOC_ENABLE()		     (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOCEN_Pos))
	#define GPIO_RCC_CLK_GPIOC_DISABLE()	          (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOCEN_Pos))

	#define GPIO_RCC_CLK_GPIOD_ENABLE()		     (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIODEN_Pos))
	#define GPIO_RCC_CLK_GPIOD_DISABLE()	          (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIODEN_Pos))

	#define GPIO_RCC_CLK_GPIOE_ENABLE()		     (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOEEN_Pos))
	#define GPIO_RCC_CLK_GPIOE_DISABLE()	          (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOEEN_Pos))

	#define GPIO_RCC_CLK_GPIOF_ENABLE()		     (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOFEN_Pos))
	#define GPIO_RCC_CLK_GPIOF_DISABLE()	          (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOFEN_Pos))

	#define GPIO_RCC_CLK_GPIOG_ENABLE()		     (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOGEN_Pos))
	#define GPIO_RCC_CLK_GPIOG_DISABLE()	          (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOGEN_Pos))

	#define GPIO_RCC_CLK_GPIOH_ENABLE()		     (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOHEN_Pos))
	#define GPIO_RCC_CLK_GPIOH_DISABLE()	          (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOHEN_Pos))


	typedef enum {
		GPIO_INPUT_MODE, GPIO_GENERAL_PURPOSE_OP_MODE, GPIO_ALTERNATE_FN, ANALOG_MODE
	}GPIO_ConfigPinsMode;

	typedef enum{
		GPIO_OUTPUT_PUSH_PULL, GPIO_OUTPUT_OPEN_DRAIN
	}GPIO_ConfigOutputType;

	typedef enum{
		GPIO_LOW_SPEED, GPIO_MEDIUM_SPEED, GPIO_FAST_SPEED, GPIO_HIGH_SPEED
	}GPIO_ConfigSpeedMode;

	typedef enum{
		GPIO_NO_PULL_UP_DOWN, GPIO_PULL_UP,GPIO_PULL_DOWN
	}GPIO_ConfigPullUpDown;

	typedef enum{
		AF0,AF1,AF2,AF3,AF4,AF5,AF6,AF7,AF8,AF9,AF10,AF11,AF12,AF13,AF14,AF15
	}GPIO_AlternatFunction;

	typedef struct{

		uint32_t pin;
		uint32_t mode;
		uint32_t output_type;
		uint32_t speed;
		uint32_t pull_up_down;
		uint32_t clk;
		uint32_t alternate_func;

	}GPIO_ConfigPinParam;


	void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_ConfigPinParam *GPIO_PinConfig);

	uint8_t GPIO_Read(GPIO_TypeDef * GPIOx,uint8_t PIN_NO);

	void GPIO_Write(GPIO_TypeDef * GPIOx,uint8_t PIN_NO,uint8_t VALUE);


	#endif
