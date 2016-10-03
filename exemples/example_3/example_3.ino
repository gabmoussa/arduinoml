#include <ArduinoML.h>
  
arduino_ml::ArduinoBoard board;

void setup() 
{
 /*******************************************************************************
  **                           Creating All Actuators                          **
  *******************************************************************************/
  
  board.add_actuator(new arduino_ml::Led("led",11));
  board.add_actuator(new arduino_ml::Button("button",12));
  
 /********************************************************************************
  **                            Creating All States                             **
  ********************************************************************************/
  
  arduino_ml::State* init = new arduino_ml::State();
  arduino_ml::State* pressed_off = new arduino_ml::State();
  arduino_ml::State* released_on = new arduino_ml::State();
  arduino_ml::State* pressed_on = new arduino_ml::State();
  
 /********************************************************************************
  **                     Adding Actions to each State                           **
  ********************************************************************************/
  
  init->add_action(board.actuator("led"),arduino_ml::LOW_STATE);
  released_on->add_action(board.actuator("led"),arduino_ml::HIGH_STATE);
  
 /********************************************************************************
  **                           Creating Transitions                             **
  ********************************************************************************/
  
  arduino_ml::Transition* button_pressed1 = new arduino_ml::Transition(pressed_off);
  arduino_ml::Transition* button_released1 = new arduino_ml::Transition(released_on);
  arduino_ml::Transition* button_pressed2 = new arduino_ml::Transition(pressed_on);
  arduino_ml::Transition* button_released2 = new arduino_ml::Transition(init);
   
 /********************************************************************************
  **                   Adding Conditions to each Transition                     **
  ********************************************************************************/
  
  button_pressed1->add_condition(new arduino_ml::Condition(board.actuator("button"),arduino_ml::HIGH_STATE));
  button_released1->add_condition(new arduino_ml::Condition(board.actuator("button"),arduino_ml::LOW_STATE));
  button_pressed2->add_condition(new arduino_ml::Condition(board.actuator("button"),arduino_ml::HIGH_STATE));
  button_released2->add_condition(new arduino_ml::Condition(board.actuator("button"),arduino_ml::LOW_STATE));
 
 /********************************************************************************
  **                       Adding Transitions to each State                     **
  ********************************************************************************/
  
  init->add_transition(button_pressed1);
  pressed_off->add_transition(button_released1);
  released_on->add_transition(button_pressed2);
  pressed_on->add_transition(button_released2);
  
  
  board.init_pins();
  board.init(init);
}

void loop() 
{
  board.iteration();
}
