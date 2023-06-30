/*
 * FREE_RTOS_NTI.c
 *
 * Created: 6/14/2023 9:41:20 PM
 * Author : yahia
 */ 

//#include <avr/io.h>
#include <util/delay.h>

#include "MCAL/DIO/DIO.h"
#include "MCAL/ADC/ADC.h"
#include "MCAL/Timer/Timer.h"
#include "MCAL/EXTI/Interrupt.h"


#include "HAL/Button/Button.h"
#include "Comm/UART/UART.h"

#include "MCAL/ADC/ADC.h"
#include "HAL/LCD/lcd.h"
#include "HAL/keypad/keypad.h"

#include "FREE_RTOS/FreeRTOS.h"
#include "FREE_RTOS/task.h"
#include "FREE_RTOS/semphr.h"
#include "FREE_RTOS/queue.h"


#define PORTA_RTOS	0
#define PORTB_RTOS	1
#define PORTC_RTOS	2
#define PORTD_RTOS	3
#define block_time	500

/*
void SystemInit(void);


void Task1(void *pv);
void Task2(void *pv);
void Task3(void *pv);
void Task4(void *pv);

static uint8 flag=0;
int main(void)
{
	SystemInit();

	xTaskCreate(Task1, NULL, 100, NULL, 1, NULL);
	xTaskCreate(Task2, NULL, 100, NULL, 2, NULL);
	xTaskCreate(Task3, NULL, 100, NULL, 3, NULL);
	xTaskCreate(Task4, NULL, 100, NULL, 4, NULL);

	vTaskStartScheduler();

	while(1)
	{

	}

}


void SystemInit(void)
{
	//DDRB |= (1<<0)|(1<<1)|(1<<2);
	DIO_set_pin_direction(1,pin1, output);
	DIO_set_pin_direction(1,pin2, output);
	DIO_set_pin_direction(1,pin3, output);
	Button_Init(1, 0);
}


void Task1(void *pv)
{

	while(1)
	{
		if(flag==1){
			DIO_set_pin_value(1,pin1, HIGH);
			}else{
			DIO_set_pin_value(1,pin1, LOW);
		}
		vTaskDelay(1000);  //1 Sec

	}
}

void Task2(void *pv)
{
	while(1)
	{
		if(flag==1){
			DIO_set_pin_value(1,pin2, HIGH);
			}else{
			DIO_set_pin_value(1,pin2, LOW);
		}
		vTaskDelay(1000);  //1 Sec
	}
}

void Task3(void *pv)
{


	while(1)
	{

		if(flag==1){
			DIO_set_pin_value(1,pin3, HIGH);
			}else{
			DIO_set_pin_value(1,pin3, LOW);
		}
		vTaskDelay(1000);  //1 Sec
	}
}

void Task4(void *pv)
{


	while(1)
	{

		if((Button_read(1, 0)==1)&&(flag==0)){
			flag=1;
			}else if(Button_read(1, 0)==1){
			flag=0;
		}
		vTaskDelay(10);  //1 Sec

	}
}
*/

/*
// task using semaphore UART

void SystemInit(void);

void LP(void *pvParameter);
void MP(void *pvParameter);
void HP(void *pvParameter);

xSemaphoreHandle x= NULL;
TaskHandle_t	LPT;
TaskHandle_t	MPT;
TaskHandle_t	HPT;

void main ()
{
	 SystemInit();
	 UART_voidSendStringBlocking("System Started\r\n");

	xTaskCreate(&LP, NULL, 250, NULL, 1, &LPT);


	// Create a counting semaphore 
	x = xSemaphoreCreateBinary();
	
	xSemaphoreGive(x);
	
	vTaskStartScheduler();
	
	while(1)
	{
		
	}
}

void SystemInit(void)
{
	UART_init();
	//DDRB |= (1<<0)|(1<<1)|(1<<2);
	//DIO_set_pin_direction(1,pin1, output);
	//DIO_set_pin_direction(1,pin2, output);
	//DIO_set_pin_direction(1,pin3, output);
	//Button_Init(1, 0);
}

void LP(void *pvParameter)
{
	uint8 periorty ;
	
	UART_voidSendStringBlocking("LP is starting\r\n");
	if (xSemaphoreTake(x,block_time)==pdPASS)
	{
		UART_voidSendStringBlocking("LP run now\r\n");
		UART_voidWriteDecimalNumber(uxTaskPriorityGet(LPT));
		xTaskCreate(&HP, NULL, 250, NULL, 3, &HPT);
		UART_voidSendStringBlocking("LP After HP\r\n");
		//UART_voidSendStringBlocking("mp created\r\n");
		UART_voidWriteDecimalNumber(uxTaskPriorityGet(LPT));
	
		xTaskCreate(&MP, NULL, 250, NULL, 2, &MPT);
		UART_voidSendStringBlocking("LPT priority after MPT ");
		UART_voidWriteDecimalNumber(uxTaskPriorityGet(LPT));
		UART_voidSendStringBlocking("\r\n");
		
		xSemaphoreGive(x);
	}
	
	while(1)
	{
		vTaskDelay(1000);
	}
	
	
	
}

void HP(void *pvParameter)
{
	uint8 semaphor;
	UART_voidSendStringBlocking("HP Started\r\n");
	semaphor = xSemaphoreTake(x,block_time);
	if(semaphor==pdPASS)
	{
		UART_voidSendStringBlocking("LPT priority after Semaphore Take by HPT ");
		UART_voidWriteDecimalNumber(uxTaskPriorityGet(LPT));
		UART_voidSendStringBlocking("\r\n");
	}
	
	//vTaskDelay(1000);
	while(1);
	
}


void MP(void *pvParameter)
{
	UART_voidSendStringBlocking("mp started\r\n");
	_delay_ms(1000);
	UART_voidSendStringBlocking("mp run now \r\n");
	while(1)
	{
		if(xSemaphoreTake(x,block_time)==1)
		{
			xSemaphoreGive(x);
		}
	}
	//vTaskDelay(1000);
}
*/


// task using semaphore UART
/*
void SystemInit(void);

void LP(void *pvParameter);
void MP(void *pvParameter);
void HP(void *pvParameter);

xSemaphoreHandle x= NULL;
TaskHandle_t	LPT;
TaskHandle_t	MPT;
TaskHandle_t	HPT;

void main ()
{
	SystemInit();
	UART_voidSendStringBlocking("System Started\r\n");

	xTaskCreate(&LP, NULL, 250, NULL, 1, &LPT);
	//xTaskCreate(&MP, NULL, 250, NULL, 1, &LPT);
	
	//xTaskCreate(&HP, NULL, 250, NULL, 2, &LPT);

	// Create a counting semaphore
	x = xSemaphoreCreateMutex();
	
	xSemaphoreGive(x);
	
	vTaskStartScheduler();
	
	while(1)
	{
		
	}
}

void SystemInit(void)
{
	
	UART_init();
	//DDRB |= (1<<0)|(1<<1)|(1<<2);
	DIO_set_pin_direction(1,pin1, output);
	DIO_set_pin_direction(1,pin2, output);
	//DIO_set_pin_direction(1,pin3, output);
	//Button_Init(1, 0);
}

void LP(void *pvParameter)
{
	uint8 periorty ;
	
	UART_voidSendStringBlocking("LP is starting\r\n");
	if (xSemaphoreTake(x,block_time)==pdPASS)
	{
		UART_voidSendStringBlocking("LP run now\r\n");
		UART_voidWriteDecimalNumber(uxTaskPriorityGet(LPT));
		xTaskCreate(&HP, NULL, 250, NULL, 3, &HPT);
		UART_voidSendStringBlocking("LP After HP\r\n");
		//UART_voidSendStringBlocking("mp created\r\n");
		UART_voidWriteDecimalNumber(uxTaskPriorityGet(LPT));
		
		xTaskCreate(&MP, NULL, 250, NULL, 2, &MPT);
		UART_voidSendStringBlocking("LPT priority after MPT ");
		UART_voidWriteDecimalNumber(uxTaskPriorityGet(LPT));
		UART_voidSendStringBlocking("\r\n");
		
		xSemaphoreGive(x);
	}
	
	while(1)
	{
		vTaskDelay(1000);
	}
	
	
	
}

void HP(void *pvParameter)
{
	uint8 semaphor;
	UART_voidSendStringBlocking("HP Started\r\n");
	semaphor = xSemaphoreTake(x,block_time);
	if(semaphor==pdPASS)
	{
		UART_voidSendStringBlocking("LPT priority after Semaphore Take by HPT ");
		UART_voidWriteDecimalNumber(uxTaskPriorityGet(LPT));
		UART_voidSendStringBlocking("\r\n");
	}
	
	//vTaskDelay(1000);
	while(1);
	
}

// test task 1 
void MP(void *pvParameter)
{
	DIO_set_pin_value(PORTB_RTOS,1,HIGH);
	UART_voidSendStringBlocking("MPT started\r\n");
	UART_voidSendStringBlocking("Busy Delay MPT\r\n");
	//_delay_ms(1000);
	UART_voidSendStringBlocking("MPT Waiting\r\n");
	DIO_set_pin_value(PORTB_RTOS,1,LOW);
	vTaskDelay(1000);
	while(1)
	{
		
	}
	//vTaskDelay(1000);
}*/

/*

// test periorty
void HP(void *pvParameter)
{
	
	DIO_set_pin_value(PORTB_RTOS,2,HIGH);
	UART_voidSendStringBlocking("hPT started\r\n");
	UART_voidSendStringBlocking("Busy Delay HPT\r\n");
	//_delay_ms(1000);
	UART_voidSendStringBlocking("HPT Waiting\r\n");
	DIO_set_pin_value(PORTB_RTOS,2,LOW);
	vTaskDelay(1000);
	while(1)
	{
		
	}
	//vTaskDelay(1000);
}
*/

/*
//nested interrupt
void main ()
{
	UART_init();
	void EXT0_Interrupt_enable();
	EXT0_Interrupt_enable();
	while(1)
	{
		
	}
}
ISR(EXTI_INT_0)
{
	DIO_set_pin_value(PORTB_RTOS,0,HIGH);
		UART_voidSendStringBlocking("hPT INT0 \r\n");
		_delay_ms(500);
	
	if(!0)
	{
		// worest (stuck the system)
	}
	else
	{
		// best case
	}
	DIO_set_pin_value(PORTB_RTOS,0,LOW);
}

ISR(EXTI_INT_1)
{
	DIO_set_pin_value(PORTB_RTOS,1,HIGH);
	UART_voidSendStringBlocking("hPT INT1 \r\n");
	_delay_ms(500);
	DIO_set_pin_value(PORTB_RTOS,1,LOW);
}*/


/*

//button with led semaphore free rtos

void SystemInit(void);

void led(void *pvParameter);
void button(void *pvParameter);


xSemaphoreHandle ahmed= NULL;

void main ()
{
	SystemInit();
	UART_voidSendStringBlocking("System Started\r\n");

	xTaskCreate(led, NULL, 250, NULL, 2, NULL);
	xTaskCreate(button, NULL, 250, NULL, 1, NULL);
	

	// Create a counting semaphore
	ahmed = xSemaphoreCreateBinary();
	
	
	
	vTaskStartScheduler();
	
	while(1)
	{
		
	}
}

void SystemInit(void)
{
	
	UART_init();
	//DDRB |= (1<<0)|(1<<1)|(1<<2);
	DIO_set_pin_direction(0,0, output);
	//DIO_set_pin_direction(1,pin2, output);
	//DIO_set_pin_direction(1,pin3, output);
	Button_Init(0, PORTB_RTOS);
}

void button(void *pvParameter)
{
	while(1)
	{

		if ( Button_read(pin0,PORTB_RTOS)==1)
		{
		
			xSemaphoreGive(ahmed);
			while( Button_read(pin0,PORTB_RTOS)==1);
		}
	}
	
}

void led(void *pvParameter)
{
	uint8 static y=0;
	while(1)
	{
		
		if(xSemaphoreTake(ahmed,block_time)==1)
		{
			y^=1;
			UART_voidSendStringBlocking("led on\r\n");
			DIO_set_pin_value(PORTA_RTOS,pin0,y);			
		}
		else
		{
			UART_voidSendStringBlocking("led on\r\n");
			//DIO_set_pin_value(PORTA_RTOS,pin0,LOW);
		}
	}
}
*/
/*
uint16 adc_read , analog;
uint8 digital;

void ISR_Notification(void);
void system_init();
void adc_adc(void * pvparameter)
void POT_Task(void * pvparameter);
void lcd(void * pvparameter);

xSemaphoreHandle bsADC = NULL;
int main()
{
	system_init();
	xTaskCreate(adc_adc  , NULL, 250, NULL, 1, NULL);
	xTaskCreate(POT_Task  , NULL, 100, NULL, 2, NULL);
	xTaskCreate(lcd, NULL, 150, NULL, 3, NULL);
	bsADC=xSemaphoreCreateBinary();
//	vTaskStartScheduler();
	
	while(1)
	{
		
	}
}

void system_init()
{
	LCD_INIT_DIR();
	ADC_init();
	LCD_INIT();
	asm("SEI");
}

void adc_adc(void * pvparameter)
{
	while(1)
	{
	//	ADC_Start_Conversion_ASYN(0,adc_read,&ISR_Notification);
		
		if(xSemaphoreTake(bsADC,portMAX_DELAY)==1)
		{
			digital= ADC_u16ADCRead;
			// read adc process the data
		}
		else 
		{
			// time out
		}
		vTaskDelay(150);
	}
}

void lcd(void * pvparameter)
{
	LCD_sendString("pot = ");
	LCD_VoidIntgerToString(adc_read);
	vTaskDelay(150);
}

void POT_Task(void *pv)
{
	while(1)
	{
		analog = (digital*5000)/1023;   //POT -->A0
		vTaskDelay(100);
	}
}

void ISR_Notification(void)
{
	xSemaphoreGive(bsADC);
}
*/





//////////////////////////////////////////////////////////////////////////
// 3 task adc with lcd 

/*
static uint16 Digital=0;
static uint16 Analog = 0;

void SystemInit(void);
void ISR_Notification(void);

void ADC_Task(void *pv);
void ActionTask(void *pv);
void POT_Task(void *pv);


// Define the semaphore 
xSemaphoreHandle   bsADC = NULL;


int main(void)
{

	SystemInit();

	xTaskCreate(ADC_Task  , NULL, 100, NULL, 1, NULL);
	xTaskCreate(POT_Task  , NULL, 100, NULL, 2, NULL);
	xTaskCreate(ActionTask, NULL, 350, NULL, 4, NULL);
	
	bsADC = xSemaphoreCreateBinary();

	vTaskStartScheduler();
	//LCD_sendString("ahmed");
	while(1){}

}


void ADC_Task(void *pv)
{
	uint8 local_state;

	while(1)
	{

		local_state=ADC_Start_Conversion_ASYN(0,&Digital,&ISR_Notification);
		if(xSemaphoreTake(bsADC, portMAX_DELAY) == pdPASS)
		{
			
			Digital = ADC_u16ADCRead();
			//	Digital;
				UART_voidWriteDecimalNumber(Digital);
		}
		else
		{
			LCD_ChangePOS_XY(4, 1);
			LCD_sendString("TimeOut");
		}
		vTaskDelay(200);
	}
}


void POT_Task(void *pv)
{
	while(1)
	{
		 Analog = ((uint32)Digital*5000)/ 1023 ;
		
		vTaskDelay(100);
	}
}



void ActionTask(void *pv)
{
	LCD_Clear();

	LCD_ChangePOS_XY(0, 0);
	LCD_sendString("POT=");

	LCD_ChangePOS_XY(10, 0);
	LCD_sendString("mv");

	while(1)
	{
		LCD_ChangePOS_XY(5, 0);
		LCD_sendString("    ");
		LCD_ChangePOS_XY(5, 0);
		//LCD_VoidIntgerToString(Analog);
	
	LCD_voidWriteNumber(Analog);
		vTaskDelay(50);
	}

}


void ISR_Notification(void)
{

	xSemaphoreGive(bsADC);
}


void SystemInit(void)
{
	//LCD Init
	LCD_INIT_DIR();
	LCD_INIT();
	UART_init();
	//ADC Init
	ADC_init();
	asm("SEI");

}

*/
//////////////////////////////////////////////////////////////////////////
// multi ADC

/*
static uint16 Digital=0;
static uint16 Analog1 = 0;

uint16 static temp;
static uint16 Analog2 = 0;

void SystemInit(void);
void ISR_Notification(void);

void ADC_Task(void *pv);
void ActionTask(void *pv);
void POT_Task(void *pv);
void LM35_Task(void *pv);



// Define the semaphore
xSemaphoreHandle   bsADC = NULL;
Chain_t ADC_chain;

int main(void)
{
	uint8 channel_arr[3]={0,7,6};
	uint16 channel_result[3]={0};
	uint8 channel_size=3;
	
	
	ADC_chain.ChainChannel=channel_arr;
	ADC_chain.ChainResult=channel_result;
	ADC_chain.ChainSize=channel_size;
	ADC_chain.ChainNotificationFunc=&ISR_Notification;
	SystemInit();
	
	//ADC_chain[0].ChainChannel=0;
	//ADC_chain[1].ChainChannel=7;
	//ADC_chain->ChainSize=2;
	
	//ADC_chain->ChainNotificationFunc=&ISR_Notification;
	

	xTaskCreate(ADC_Task  , NULL, 100, NULL, 1, NULL);
	xTaskCreate(POT_Task  , NULL, 100, NULL, 2, NULL);
	xTaskCreate(LM35_Task , NULL, 100, NULL, 4, NULL);
	xTaskCreate(ActionTask, NULL, 350, NULL, 3, NULL);
	
	bsADC = xSemaphoreCreateBinary();

	vTaskStartScheduler();
	//LCD_sendString("ahmed");
	while(1){}

}


void ADC_Task(void *pv)
{
	uint8 local_state;

	while(1)
	{
		
		local_state=ADC_Start_Chain_Conversion_ASYN(&ADC_chain);
		if(xSemaphoreTake(bsADC, portMAX_DELAY) == pdPASS)
		{
			UART_voidSendStringBlocking("im here");
			//ADC_chain->ChainResult[0];
			//ADC_chain->ChainResult[1];
			//	Digital;
			UART_voidSendStringBlocking("im adc\r\n");
			//UART_voidSendStringBlocking("channel0\r\n");
			//UART_voidWriteDecimalNumber(ADC_chain->ChainResult[0]);
			//UART_voidSendStringBlocking("channel1\r\n");
			//UART_voidWriteDecimalNumber(ADC_chain->ChainResult[1]);
		}
		else
		{
			LCD_ChangePOS_XY(4, 1);
			LCD_sendString("TimeOut");
		}
		vTaskDelay(100);
	}
}


void POT_Task(void *pv)
{
	while(1)
	{
		UART_voidSendStringBlocking("im pot\r\n");
		Analog1 = ((uint32)ADC_chain.ChainResult[0]*5000)/ 1023 ;
		
		vTaskDelay(100);
	}
}



void ActionTask(void *pv)
{
	LCD_Clear();
// pot
	LCD_ChangePOS_XY(0, 0);
	LCD_sendString("POT=");

	LCD_ChangePOS_XY(10, 0);
	LCD_sendString("mv");

//temp
	LCD_ChangePOS_XY(0, 1);
	LCD_sendString("tem=");

	LCD_ChangePOS_XY(10, 1);
	LCD_sendString("c");

	while(1)
	{
		UART_voidSendStringBlocking("im LCD\r\n");
		LCD_ChangePOS_XY(5, 0);
		LCD_sendString("    ");
		LCD_ChangePOS_XY(5, 0);
		LCD_voidWriteNumber(Analog1);
		UART_voidWriteDecimalNumber(Analog1);
		UART_voidSendStringBlocking("\r\n");
		LCD_ChangePOS_XY(5, 1);
		LCD_sendString("    ");
		LCD_ChangePOS_XY(5, 1);
		LCD_voidWriteNumber(temp);
		UART_voidWriteDecimalNumber(temp);
		UART_voidSendStringBlocking("\r\n");
		vTaskDelay(50);
	}

}


void ISR_Notification(void)
{
	xSemaphoreGive(bsADC);
}


void SystemInit(void)
{
	//LCD Init
	LCD_INIT_DIR();
	LCD_INIT();
	UART_init();
	//ADC Init
	ADC_init();
	asm("SEI");

}







void LM35_Task(void *pv)
{
	
	while(1)
	{
		UART_voidSendStringBlocking("im temp\r\n");
		Analog2 = ((uint32)ADC_chain.ChainResult[1]*5000)/ 1023 ;
		temp = Analog2/10;
		vTaskDelay(100);
	}
}*/




// project smart home RTOS round 1 (minded)

// this for gas sensor
static uint16 Digital=0;
static uint16 Analog1 = 0;
// this for temp sensor
uint16 static temp;
static uint16 Analog2 = 0;
// password init 
uint8 password[3]={1,2,3};
// this password that take from the user
uint8 static keypad_pass[3]={0};

// system init
void SystemInit(void);
// this func used for set call back (notification func )for ADC interrupt 
void ISR_Notification(void);

void ADC_Task(void *pv);
void ActionTask(void *pv);
void POT_Task(void *pv);
void LM35_Task(void *pv);
void keypad_task(void * pvparameter);

void check_pass(void);
uint8 static flag = 0 ; // pass true or false
uint8 local_counter=0;	// the try counter we you enter password


// Define the semaphore
xSemaphoreHandle   bsADC = NULL;
xSemaphoreHandle   lcd = NULL;
// this var for adc chain
Chain_t ADC_chain;

int main(void)
{
	//arr for channels used (channel 6 not used now)
	uint8 channel_arr[3]={0,7,6};
	// arr for  channels result	
	uint16 channel_result[3]={0};
	//  no of channel used	
	uint8 channel_size=3;
	
	// pass the var to struct (ADC_chain)
	ADC_chain.ChainChannel=channel_arr;
	ADC_chain.ChainResult=channel_result;
	ADC_chain.ChainSize=channel_size;
	ADC_chain.ChainNotificationFunc=&ISR_Notification;
	// system init
	SystemInit();
	
	/* task creater*/
	xTaskCreate(ADC_Task  , NULL, 100, NULL, 2, NULL);
	xTaskCreate(POT_Task  , NULL, 100, NULL, 3, NULL);
	xTaskCreate(LM35_Task , NULL, 100, NULL, 5, NULL);
	xTaskCreate(ActionTask, NULL, 350, NULL, 4, NULL);
	xTaskCreate(keypad_task, NULL, 350, NULL, 1, NULL);
	
	/* init the semaphore binary */
	bsADC = xSemaphoreCreateBinary();
	lcd = xSemaphoreCreateBinary();
	
	/*start the RTOS*/
	vTaskStartScheduler();

	while(1){}

}


/* this task for ADC to cal the conversion */
void ADC_Task(void *pv)
{
	uint8 local_state; // check the function return true if work correct false if not

	while(1)
	{
		// this function use to swap between the sensor in adc multiplexer 
		local_state=ADC_Start_Chain_Conversion_ASYN(&ADC_chain);
		if(xSemaphoreTake(bsADC, portMAX_DELAY) == pdPASS)
		{
			//UART_voidSendStringBlocking("im here");
			//UART_voidSendStringBlocking("im adc\r\n");
	
		}
		else
		{
			LCD_ChangePOS_XY(4, 1);
			LCD_sendString("TimeOut");
		}
		vTaskDelay(100);
	}
}

/* this function use for gas sensor if the value > 2500 the buz open & the door*/
void POT_Task(void *pv)
{
	while(1)
	{
		
		// analog equation calculation
		Analog1 = ((uint32)ADC_chain.ChainResult[0]*5000)/ 1023 ;
		/* if the flag true (i.e the system open (true password) ) the gas sensor start detect*/
		if(flag==1)
		{
			if(Analog1>2500)
			{
				DIO_set_pin_value(PORTC_RTOS,pin1,HIGH); // buz and door on
			}
			else
			{
				DIO_set_pin_value(PORTC_RTOS,pin1,LOW); // buz and door off
			}
			
		}
		
		else
		{
			// do nothing
		}
		
		
		vTaskDelay(100);
	}
}


//	this task used for show in the LCD
void ActionTask(void *pv)
{
	uint8 static welcome=1,swap=0;
	while(1)
	{
			if(flag==0)//  if the password wrong or in the init 
			{				
							xSemaphoreGive(lcd);
					LCD_ChangePOS_XY(0, 0);
								//LCD_voidWriteNumber(local_counter);
					LCD_sendString("enter password");
	
			}

			 else if (flag ==1) // if pass is right
			{
				
				if(welcome==1) // i need this fun run on time only if the pass correct
				{
					xSemaphoreGive(lcd);
					LCD_Clear();
					LCD_sendString("correct password");
				
					welcome=0; //change it to zero 
					vTaskDelay(1000); // wait for 1000 sec 
				}
				
				if(swap==0) // swap use for swapping between 2 line in lcd( first for temp , pot ) and ( second for the door and fan)
				{
					xSemaphoreGive(lcd);
					LCD_Clear();
					// this for gas sensor
					LCD_ChangePOS_XY(0, 0);
					LCD_sendString(" POT=");

					LCD_ChangePOS_XY(10, 0);
					LCD_sendString("mv");

					//	this for temp sensor
					LCD_ChangePOS_XY(0, 1);
					LCD_sendString(" temp=");

					LCD_ChangePOS_XY(11, 1);
					LCD_sendString("c");
					
					// this for gas sensor value
					LCD_ChangePOS_XY(5, 0);
					LCD_sendString("    ");
					LCD_ChangePOS_XY(5, 0);
					LCD_voidWriteNumber(Analog1);
					
					// this for temp sensor value
					LCD_ChangePOS_XY(6, 1);
					LCD_sendString("    ");
					LCD_ChangePOS_XY(6, 1);
					LCD_voidWriteNumber(temp);
				
					swap=1;
				}
				else if (swap==1)
				{
					LCD_Clear();
					// door and buzzer for gas sensor
					LCD_ChangePOS_XY(0, 0);
					LCD_sendString(" door=");
					
					if(Analog1>2500) // if the value greater than 2500 the door open
					{
						LCD_ChangePOS_XY(7, 0);
						LCD_sendString("open");
					}
					else // the door closed
					{
						LCD_ChangePOS_XY(7, 0);
						LCD_sendString("close");
					}
					

					//temp
					LCD_ChangePOS_XY(0, 1);
					LCD_sendString(" fan=");
					// if temp > 20 the fan open 
					if(temp>20)
					{
						LCD_ChangePOS_XY(5, 1);
						LCD_sendString("open");
					}
					else // the fan closed
					{
						LCD_ChangePOS_XY(5, 1);
						LCD_sendString("close");
					}
					
				//	_delay_ms(2000);
					swap=0;
				}
				

			}
		
		
		vTaskDelay(1000);
	}

}

// this function used for ADC notification when end conversion the adc give the semaphore
void ISR_Notification(void)
{
	xSemaphoreGive(bsADC);
}


// this fun for system init
void SystemInit(void)
{
	/*LCD Init*/
	LCD_INIT_DIR();
	LCD_INIT();
	
	/* keypad init*/
	keypad_init();
	
	DIO_set_pin_direction(PORTC_RTOS,pin0,output) ;	// fan
	DIO_set_pin_direction(PORTC_RTOS,pin1,output) ;	// window
	
	/*ADC Init*/
	ADC_init();
	
	/* open global init*/
	asm("SEI");
	
}

// this task set password 
void keypad_task(void * pvparameter)
{
	uint8 static i=0 , max_pass=3, local_result=0;
	//uint8 keypad_button=0;
	uint8 test = 0;
		//vTaskDelete(ActionTask);
		xSemaphoreTake(lcd,portMAX_DELAY);
		
		while(1)
		{
			if (test==0) // the test used to scan the pass if the pass right this fun shouldn't run again 
			{
				local_result= keypad_scan();
				while(i<max_pass)
				{
					while(local_result==0) // if return type =0 wait for it to get the value
					{
						local_result= keypad_scan();
					}
					keypad_pass[i]=local_result;
					LCD_ChangePOS_XY(i,1);
					LCD_voidWriteNumber(keypad_pass[i]);
					//LCD_Send_Data('keypad_pass[i]'+0);
					i++;
					local_result=0; // reset again to default
				}
							check_pass();

				if (i==3 && flag==1)
				{
					test=1;
				}
				else
				{
					i=0;
				}
		 
					//xTaskCreate(ActionTask, NULL, 350, NULL, 4, NULL);
			
			}

			/*
			if (flag == 1)
			{
				keypad_button=keypad_scan(); // reset the keypad to init ( ex: 0 )
				while(keypad_button==0x00) // block the code to get val
				{
					keypad_button=keypad_scan();
				}
				/*
				switch (keypad_button)
				{
					case 1 : DIO_get_pin_value(PORTC_RTOS,pin0,HIGH)	;	break; // door open
					case 2 : DIO_get_pin_value(PORTC_RTOS,pin0,LOW)	;	break; // door close
					default: // do nothing	;
						break;
				}
				
				if(keypad_button==1)
				{
					DIO_get_pin_value(PORTC_RTOS,pin0,HIGH)	;
				}
				if(keypad_button==2)
				{
					DIO_get_pin_value(PORTC_RTOS,pin0,LOW)	;
				}
				
			}*/
			vTaskDelay(50);
		}
		

}



// this task use to calculate the temp the temp 

void LM35_Task(void *pv)
{
	while(1)
	{
		//UART_voidSendStringBlocking("im temp\r\n");
		Analog2 = ((uint32)ADC_chain.ChainResult[1]*5000)/ 1023 ;
		temp = Analog2/10;
		if(flag==1)
		{
			if (temp>20) // open the fan
			{
				DIO_set_pin_value(PORTC_RTOS,pin0,HIGH);
			}
			else // close the fan
			{
				DIO_set_pin_value(PORTC_RTOS,pin0,LOW); 
			}
		}
		else
		{
			// do nothing
		}
		vTaskDelay(100);
	}
	
}


/*
void check_pass(void)
{
	uint8 i =0 ;
	uint8 max_password=3,local_count=0;
	
	while(local_count<3)
	{
		
	
		//for(i=0;i<max_password;i++)
		
			// check the password true or not if false break the loop and print wrong pass
			if(keypad_pass[i]==password[i])
			{
				flag=0;
				local_count++;
				break;
				i++;
			}
			else
			{
				flag=0;
				i=0;
				break;
			}
		
			if(i == max_password) // i = 3 all value are equal and its true
			{
				flag=1;
				break;
		
			}
	}
}*/


/* this function used to check the password */
void check_pass(void)
{
	uint8 i,y=0;

	for (i = 0; i < 3; i++)
	{
		if (keypad_pass[i] != password[i]) // if the pass was wrong  
		{
			flag =0; 
			local_counter++; // try 
				LCD_Clear();
			LCD_ChangePOS_XY(0, 0);
			LCD_sendString("wrong password");
		
	
			y=0;	// reset the counter  
			vTaskDelay(1000);
		}
		else
		{
			y++; // in every true ++
		}
	
	}
		if(y==3) // if y = max password 
		{
			flag = 1; // change the flag to be true
			//xSemaphoreGive(lcd);

		}

}