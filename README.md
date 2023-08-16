# OTA
Access Control System using over the air technology

Implementing an Acces Control System with two modes: 
1-Online Mode: Using HTML,CSS & PHP we made a website which let the employee enter their PW and we integrate the web server with the WIFI Module ESP to take the value from website and send it through UART1 to the STM to start displaying the employee photo of TFT, His Name on the LDM and opening the gate for 30 seconds on 7Segment

2-Offline Mode: Same application as the online but if there's no internet connection the employee will start write their PW on the Keypad on AVR kit and the AVR will send the data thorugh UART2 to the STM and excute the same program

STM32F401CC Components:
STD types
Bit Math
RCC
SYSTICK
UART1/UART2
SPI
GPIO
TFT
LED MATRIX
Serial to parallel
COM PIM


AVR AtMega32 Components:
STD Types
Bit math
GPIO
UART
LCD
Keypad
Motor


Python Script for Web
HTML
CSS
PHP
