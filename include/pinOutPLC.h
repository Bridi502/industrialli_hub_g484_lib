#ifndef PINOUTPLC_H
#define PINOUTPLC_H

#include <Arduino.h>

//############################################################################
// PinOut PCB CTRL
#define PGOOD1 PE14
#define PGOOD2 PE13
// LED debug
#define LED_DEBUG PB11

//Buzzer

#define BUZZER PA0

// SD Card
#define SDCARD_DETECT PD8
#define SDCARD_CS PB12

#define SPI2_SCK PB13
#define SPI2_MISO PB14
#define SPI2_MOSI PB15

// EEPROM
#define EEPROM_WP PD9

#define I2C3_SCL PC8
#define I2C3_SDA PC9

// Serial 1 - IHM NEXTION
#define NEXTION_RXD1 PC5
#define NEXTION_TXD1 PC4

// Serial 2 - Módulos de expansão
#define RS485_MOD_RE_DE PA1
#define RS485_MOD_TXD2 PA2
#define RS485_MOD_RXD2 PA3

// Módulo LoRa
#define	SPI4_MISO	PE5
#define	SPI4_MOSI	PE6
#define	SPI4_SCK	PE2
#define	SPI4_LORA_CS	PE3

#define	LORA_I2C4_SCL	PC6
#define	LORA_I2C4_SDA	PB7

#define	LORA_USART3_TX	PB10
#define	LORA_USART3_RX	PE15

#define	LORA_GPIO_PE4	PE4
#define	LORA_GPIO_PF9	PF9
#define	LORA_GPIO_PF10	PF10
#define	LORA_GPIO_PC2	PC2
#define	LORA_GPIO_PC1	PC1
#define	LORA_GPIO_PC0	PC0




//############################################################################
// PinOut PCB I/O
// Serial 4 - RS485
#define	RS485_TER_SEL	PC12
#define	RS485_UART4_RX	PC11
#define	RS485_UART4_TX	PC10
#define	RS485_UART4_RE_DE	PA15




// Ethernet
#define SPI1_W5500_CS PA4
#define GPIO_W5500_INT PA10
#define GPIO_W5500_RST PC7


/*
// SPI3 - PinOut
#define SPI3_SCK PC10
#define SPI3_MISO PC11
#define SPI3_MOSI PC12

*/


void pinModePLC();


#endif