#include <ArduinoML.h>
  
arduino_ml::ArduinoBoard board(0.5);
arduino_ml::State* initial;

void setup() 
{
 /*******************************************************************************
  **                           Creating All Actuators                          **
  *******************************************************************************/
  
  board.add_actuator(new arduino_ml::Led("led",11));
  
 /********************************************************************************
  **                            Creating All States                             **
  ********************************************************************************/
  
 initial = new arduino_ml::State(true);
  
 /********************************************************************************
  **                     Adding Actions to each State                           **
  ********************************************************************************/
  
  initial->add_action(board.actuator("led"),arduino_ml::HIGH_STATE,200);
  initial->add_action(board.actuator("led"),arduino_ml::LOW_STATE,200);
  initial->add_action(board.actuator("led"),arduino_ml::HIGH_STATE,200);
  initial->add_action(board.actuator("led"),arduino_ml::LOW_STATE,200);

  
 /********************************************************************************
  **                           Creating Transitions                             **
  ********************************************************************************/
  
   
 /********************************************************************************
  **                   Adding Conditions to each Transition                     **
  ********************************************************************************/
 
 /********************************************************************************
  **                       Adding Transitions to each State                     **
  ********************************************************************************/
    
  board.init_pins();
  board.init(initial);
}

void loop() 
{
  board.iteration();
}
