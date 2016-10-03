#include <ArduinoML.h>
  
arduino_ml::ArduinoBoard board;

void setup() 
{
 /*******************************************************************************
  **                           Creating All Actuators                          **
  *******************************************************************************/
  arduino_ml::Led* red_led = new arduino_ml::Led("red_led",10);
  arduino_ml::Led* green_led = new arduino_ml::Led("green_led",11);
  arduino_ml::Buzzer* buzzer = new arduino_ml::Buzzer("buzzer",12);
  arduino_ml::Joystick* j = new arduino_ml::Joystick("joystick",10,2,1);
    
  board.add_actuator(green_led);
  board.add_actuator(red_led);
  board.add_actuator(buzzer);
  board.add_actuator(j);
  
  arduino_ml::Konami* konami = new arduino_ml::Konami(j,green_led,red_led,buzzer,"UP DOWN LEFT RIGHT");
  
  board.init_pins();
  board.init(konami->init_state());
}

void loop() 
{
  board.iteration();
}
