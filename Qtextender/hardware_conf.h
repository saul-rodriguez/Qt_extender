#ifndef HARDWARE_CONF_H
#define HARDWARE_CONF_H


/*
 * I2C EXPANDER DEFINITIONS
 */

//MCP23017 I2C address
#define EXTENDER_ADDRESS 0x20

//Raspberry pin definitions in BCM

//InterruptA is connected to GPIO.1 (BCM 18)
//InterruptB is connected to GPIO.4 (BCM 23)

#define MCP23017_1_INTA 18
#define MCP23017_1_INTB 23

//Mcp23017 extender Hardware definitions
//  Only A0 enabled as output, the rest of the pins are inputs
#define TRISA 0xFE
#define TRISB 0xFF

//All inputs configured with pull-up resistors
#define A_PULLUP 0xFE
#define B_PULLUP 0xFF

//Interruption configuration
//  B0,B1 configured as interrupts
#define INTA_PINS1 0x00
#define INTB_PINS1 0b00000011


/*
 * Some Macro definitions
 */

//  LED connected to A0
#define LED_A0_OFF ext.writePin(PORTA,0,false)
#define LED_A0_ON ext.writePin(PORTA,0,true)
#define READ_GPB1 ext.readPin(PORTB,1)

//  Pushbuttons connected to B0, B1
#define BUT1 0b00000001
#define BUT2 0b00000010

/*
 * These are dummy definitions necessary
 * to setup a second expander (not connected in this example)
 */
#define MCP23017_2_INTA 0
#define MCP23017_2_INTB 0
#define INTA_PINS2 0x00
#define INTB_PINS2 0x00

#endif // HARDWARE_CONF_H
