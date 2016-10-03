#ifndef KONAMI_H
#define KONAMI_H

#include <string>
#include <vector>

#include "Actuator.h"
#include "State.h"

namespace arduino_ml 
{	
	class Konami
	{
	public:
		Konami(Joystick* joystick, Led* green_led, Led* red_led, Buzzer* buzzer,char* command) : joystick_(joystick), green_led_(green_led), red_led_(red_led), buzzer_(buzzer)
		{ 
			init_state_ = new State();
			init_state_->add_action(green_led, LOW_STATE);
			init_state_->add_action(red_led, HIGH_STATE);
			init_state_->add_action(buzzer, LOW_STATE);

			State* button_pushed_error = new State(true);
			button_pushed_error->add_action(red_led, HIGH_STATE);
			button_pushed_error->add_action(buzzer, LOW_STATE, 1000);

			KonamiCondition* button_pressed = new KonamiCondition(joystick, BUTTON_PIN, HIGH_STATE);

			Transition* t_error = new Transition(button_pushed_error);
			Transition* retry = new Transition(init);

			t_error->add_condition(button_pressed);
			retry->add_condition(button_pressed);

			init_state_->add_transition(t_error);

			password_valid_state_ = new State();
			State* s_error = new State();

			char	*action;
			char	*separator = { " " };
			char 	*buffer;

			buffer = strdup(command);
			action = strtok(buffer, separator);

			while (action != NULL)
			{
				action = strtok(NULL, separator);
				if (action != NULL)
				{

				}
			}
		}

		inline State* init_state() { return init_state_; }


	private:
		Joystick* joystick_;
		Led* green_led_;
		Led* red_led_;
		Buzzer* buzzer_;
		State* init_state_;
		State* password_valid_state_;
	};
}

#endif 