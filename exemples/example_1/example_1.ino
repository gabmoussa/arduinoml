#include <ArduinoML.h>
  
arduino_ml::ArduinoBoard board;

void setup() 
{
 /*******************************************************************************
  **                           Creating All Actuators                          **
  *******************************************************************************/
  
  board.add_actuator(new arduino_ml::Led("led",11));
  board.add_actuator(new arduino_ml::Buzzer("buzzer",10));
  board.add_actuator(new arduino_ml::Button("button",12));
  
 /********************************************************************************
  **                            Creating All States                             **
  ********************************************************************************/
  
  arduino_ml::State* init = new arduino_ml::State();
  arduino_ml::State* pressed = new arduino_ml::State();
  
 /********************************************************************************
  **                     Adding Actions to each State                           **
  ********************************************************************************/
  
  init->add_action(board.actuator("led"),arduino_ml::LOW_STATE);
  init->add_action(board.actuator("buzzer"),arduino_ml::LOW_STATE);
  pressed->add_action(board.actuator("led"),arduino_ml::HIGH_STATE);
  pressed->add_action(board.actuator("buzzer"),arduino_ml::HIGH_STATE);
  
 /********************************************************************************
  **                           Creating Transitions                             **
  ********************************************************************************/
  
  arduino_ml::Transition* t1 = new arduino_ml::Transition(pressed);
  arduino_ml::Transition* t2 = new arduino_ml::Transition(init);
   
 /********************************************************************************
  **                   Adding Conditions to each Transition                     **
  ********************************************************************************/
  
  t1->add_condition(new arduino_ml::Condition(board.actuator("button"),arduino_ml::HIGH_STATE));
  t2->add_condition(new arduino_ml::Condition(board.actuator("button"),arduino_ml::LOW_STATE));
 
 /********************************************************************************
  **                       Adding Transitions to each State                     **
  ********************************************************************************/
  
  init->add_transition(t1);
  pressed->add_transition(t2);
  
  board.init_pins();
  board.init(init);
}

void loop() 
{
  board.iteration();
}
