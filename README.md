# Magma_Mini_Bot


## INTROUDUCTION: 

This code is to support the Kalani Highschools MAGMA Robotics pre-FIRST season's Mini-bot project.  The goal of this project is to familiarize students with the skills and thought processes needed to succeed during this years FIRST robotics season.  Kalani HS will be building 6 "Mini-bots" which will compete in a number of mini-competitions.

In order to keep costs per bot down it was decided to go with an Arduino based robot using Mobile phone based Bluetooth controllers.

## Bill of Materials:


## Instructions:

### Arduino Setup Instructions:

1. Download Arduino IDE <https://www.arduino.cc/en/Main/Software>
2. Install
3. Test Arduino Installation and board by loading the test sketch “Blink”
4. Open Arduino.exe
5. Open example sketch Blink
  Go to File>Examples>01.Basics> “Blink”
6. Set your board type to UNO
  * Tools>Board>”Arduino/Genuino UNO”
7. Set your COMM port
  * Tools>Port> “This value will vary depending on what USB port you are plugged into.  It should be something like “COM4 (Arduino/Genuino)”.
8. Upload sketch to arduino
  * Click upload button at top or Sketch>Upload
9. Sketch should upload successfully to arduino and onboard led should start blinking.
10. Bonus: Try modifying the delay values on lines 34 and 36 then re-uploading the sketch.
11. Side note:  I prefer the IDE to show line numbers to make debugging easier.  To enable this go to File>preferences and check the box that says “Display Line Numbers”

### Testing the Bluefruit BLE shield

1. The bluetooth shield will need to have some headers soldered on to put onto the arduino.  Follow the soldering assembly instructions here: <https://learn.adafruit.com/adafruit-bluefruit-le-shield/assembly>
2. Once complete then install the shield onto the arduino board.  Be careful to not bend the pins as you do so.
3. Download and install the Adafruit IOS/Android app onto your the mobile device of your preference. Search for “Adafruit Bluefruit LE Connect” in the app store of your choice, install.
4. We will need to install some additional libraries before we are ready to test.
   * Sketch>Include Library>Manage Libraries
   * Search for “Adafruit BluefruitLE nRF51”
   * Click on install in the bottom right corner of the result.
5. Load the controller test sketch to the Arduino
   * File>examples>Adafruit BluefruitLE nRF51>controller (this will be all the way at the bottom, you may need to hover over the arrow at the bottom of the menu to see)
   * Upload Sketch to arduino
6. Once the sketch is successfully uploaded then open the serial monitor feature of the arduino IDE.
   * Tools>Serial Monitor
   * Change the baud rate from 9600 to 115200. There is a drop down box in the lower right corner of the screen to do so.  You should see some text appearing which starts with ” Adafruit Bluefruit App Controller Example”
7. Open up the Adafruit BluefruitLE app on your mobile device and connect to the arduino
   * Note: Ensure that bluetooth is enable on your device
   *You should see a device listed at the bottom that says “Adafruit Bluefruit LE”, click on the connect button to connect.
   * The device should now be connected and be showing you signal strength in dBM and a list of modules.  We are going to select the controller module. Click on the controller module.
   * On the next screen will display a number of data streams to turn on, these would allow you to control the device using motion data from your mobile device, we are not going to use those for now.  Click on the control pad option at the bottom. You should now see an array of direction arrows and 4 buttons.  
   * Start mashing buttons and take a look at the serial monitor on your computer.  You should see some text indicators showing each time a button is pressed and release.
   * Note the button numbers associated with the direction buttons, we will need these later.
8. Play around with some of the other features available.  
   * Turn on Gyro then look at the serial display as you move your phone around.
   * Do the same for the accelerometer

### Importing Code from this Git Repo
1. 

Resources:

1. BLE Shield: <https://learn.adafruit.com/adafruit-bluefruit-le-shield?view=all>
2. Arduino IDE <https://www.arduino.cc/en/Main/Software>
3. Motor Driver Manual
<https://docs.google.com/document/d/178uDa3dmoG0ZX859rWUOS2Xyafkd8hSsSET5-ZLXMYQ/edit>
4. Motor Driver Tutorial
<https://tutorial.cytron.io/2013/07/29/controlling-md10c-with-arduino/>



