#include <string.h>
#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"

#include "BluefruitConfig.h"
#include "MiniBot.h"

#if SOFTWARE_SERIAL_AVAILABLE
  #include <SoftwareSerial.h>
#endif

    #define FACTORYRESET_ENABLE         1
    #define MINIMUM_FIRMWARE_VERSION    "0.6.6"
    #define MODE_LED_BEHAVIOUR          "MODE"

/* ...hardware SPI, using SCK/MOSI/MISO hardware SPI pins and then user selected CS/IRQ/RST */
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);

// A small helper
void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

// function prototypes over in packetparser.cpp
uint8_t readPacket(Adafruit_BLE *ble, uint16_t timeout);
float parsefloat(uint8_t *buffer);
void printHex(const uint8_t * data, const uint32_t numBytes);

// the packet buffer
extern uint8_t packetbuffer[];


/**************************************************************************/
/*!
    @brief  Sets up the HW an the BLE module (this function is called
            automatically on startup)
*/
/**************************************************************************/
void setup(void)
{
  while (!Serial);  // required for Flora & Micro
  delay(500);

  Serial.begin(115200);
  Serial.println(F("Adafruit Bluefruit App Controller"));
  Serial.println(F("-----------------------------------------"));

  /* Initialise the module */
  Serial.print(F("Initialising the Bluefruit LE module: "));

  if ( !ble.begin(VERBOSE_MODE) )
  {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }
  Serial.println( F("OK!") );

  if ( FACTORYRESET_ENABLE )
  {
    /* Perform a factory reset to make sure everything is in a known state */
    Serial.println(F("Performing a factory reset: "));
    if ( ! ble.factoryReset() ){
      error(F("Couldn't factory reset"));
    }
  }


  /* Disable command echo from Bluefruit */
  ble.echo(false);

  Serial.println("Requesting Bluefruit info:");
  /* Print Bluefruit information */
  ble.info();

  Serial.println(F("Please use Adafruit Bluefruit LE app to connect in Controller mode"));
  Serial.println(F("Then activate/use the game controller!"));
  Serial.println();

  ble.verbose(false);  // debug info is a little annoying after this point!

  /* Wait for connection */
  while (! ble.isConnected()) {
      delay(500);
  }

  // Set Bluefruit to DATA mode
  Serial.println( F("Switching to DATA mode!") );
  ble.setMode(BLUEFRUIT_MODE_DATA);

  Serial.println(F("******************************"));

  /*************************************************************/
  /*!
   * Mini bot pin declarations here
   */
   /************************************************************/

   pinMode(MOTOR_1_PWM_PIN, OUTPUT);  ///Motor #1s PWM setup as output, see Minibot.h for pin assignment (default is 9)
   pinMode(MOTOR_2_PWM_PIN, OUTPUT);  ///Motor #2 PWM pin setup as output, see Minibot.h for pin assignment (default is 10)

}

/**************************************************************************/
/*!
    @brief  Constantly poll for new command or response data
*/
/**************************************************************************/
void loop(void)
{
  

  /*enclose all code within this conditional statement so that nothing runs if you lose blue tooth connectivity*/
     if (ble.isConnected()) {  

          //Serial.println("Connected and READY to GO!");

          /* Wait for new data to arrive */
          uint8_t len = readPacket(&ble, BLE_READPACKET_TIMEOUT);
          /*if packet is empty then skip*/
          if (len == 0) return;

          /* Got a packet! use this as a debug statement to see what packet came in */
          // printHex(packetbuffer, len);

          /*read the second character in the packet if its a B then its a button press*/
          if (packetbuffer[1] == 'B') {
            //create an integer and convert 3rd character from a char into an integer
            uint8_t buttnum = packetbuffer[2] - '0';
            //create a boolean variable and convert 4th character from a char to a boolean
            boolean pressed = packetbuffer[3] - '0';
           
          buttoncommands(buttnum,pressed);  //call function that takes actions for each button
           
          }
    } else {
          Serial.println("No Bluetooth Connection Detected!");
          stop_all_motors(); //call function to stop all drive motors
    }
 }
 
