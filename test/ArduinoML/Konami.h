#ifndef KONAMI_H
#define KONAMI_H

#include <string>
#include <map>
#include <iostream>
#include "Actuator.h"
#include "State.h"

namespace arduino_ml
{
	class Konami
	{
	public:
		Konami(Joystick* joystick, Led* green_led, Led* red_led, Buzzer* buzzer, char* command)
			: joystick_(joystick), green_led_(green_led), red_led_(red_led), buzzer_(buzzer), wrong_action_button_pressed_state_(true)
		{
			init_konami_conditions();
			init_transitions();
			init_states();
			build_state_machine(command);
		}

		inline State* init_state() { return &init_state_; }
		inline State* password_verified_state() { return &verified_state_; }
		inline State* password_invalid_state() { return &wrong_action_button_pressed_state_; }


	private:
		void init_states()
		{
			init_state_.add_action(green_led_, LOW_STATE);
			init_state_.add_action(red_led_, HIGH_STATE);
			init_state_.add_action(buzzer_, LOW_STATE);
			std::cout << "init_state: " << &init_state_ << std::endl;

			verified_state_.add_action(green_led_, HIGH_STATE);
			verified_state_.add_action(red_led_, LOW_STATE);
			std::cout << "verified_state: " << &verified_state_ << std::endl;

			wrong_action_button_pressed_state_.add_action(red_led_, HIGH_STATE, 500);
			wrong_action_button_pressed_state_.add_action(buzzer_, HIGH_STATE);
			wrong_action_button_pressed_state_.add_action(red_led_, LOW_STATE, 500);
			wrong_action_button_pressed_state_.add_action(buzzer_, LOW_STATE);
			std::cout << "wrong_action_button_pressed_state: " << &wrong_action_button_pressed_state_ << std::endl;
			std::cout << "wrong_action_state_: " << &wrong_action_state_ << std::endl;

			Transition* retry = new Transition(&init_state_);
			retry->add_condition(konami_conditions_["BUTTON_PRESSED"]);

			wrong_action_state_.add_transition(transitions_["WRONG_ACTION_BUTTON_PRESSED"]);
			wrong_action_button_pressed_state_.add_transition(retry);
		}

		void init_konami_conditions()
		{
			konami_conditions_["UP"] = new KonamiCondition(joystick_, Y_PIN, 1023);
			konami_conditions_["DOWN"] = new KonamiCondition(joystick_, Y_PIN, 0);
			konami_conditions_["LEFT"] = new KonamiCondition(joystick_, X_PIN, 0);
			konami_conditions_["RIGHT"] = new KonamiCondition(joystick_, X_PIN, 1023);
			konami_conditions_["BUTTON_PRESSED"] = new KonamiCondition(joystick_, BUTTON_PIN, HIGH_STATE);
		}

		void init_transitions()
		{
			Transition* wrong_action_up_t = new Transition(&wrong_action_state_);
			Transition* wrong_action_down_t = new Transition(&wrong_action_state_);
			Transition* wrong_action_left_t = new Transition(&wrong_action_state_);
			Transition* wrong_action_right_t = new Transition(&wrong_action_state_);
			Transition* wrong_action_button_pressed_t = new Transition(&wrong_action_button_pressed_state_);
			Transition* action_button_pressed_validate_t = new Transition(&verified_state_);

			wrong_action_up_t->add_condition(konami_conditions_["UP"]);
			wrong_action_down_t->add_condition(konami_conditions_["DOWN"]);
			wrong_action_left_t->add_condition(konami_conditions_["LEFT"]);
			wrong_action_right_t->add_condition(konami_conditions_["RIGHT"]);
			wrong_action_button_pressed_t->add_condition(konami_conditions_["BUTTON_PRESSED"]);
			action_button_pressed_validate_t->add_condition(konami_conditions_["BUTTON_PRESSED"]);

			transitions_["WRONG_ACTION_UP"] = wrong_action_up_t;
			transitions_["WRONG_ACTION_DOWN"] = wrong_action_down_t;
			transitions_["WRONG_ACTION_LEFT"] = wrong_action_left_t;
			transitions_["WRONG_ACTION_RIGHT"] = wrong_action_right_t;
			transitions_["WRONG_ACTION_BUTTON_PRESSED"] = wrong_action_button_pressed_t;
			transitions_["ACTION_BUTTON_PRESSED_VALIDATE"] = action_button_pressed_validate_t;
		}

		void build_state_machine(char* command)
		{
			char	*action;
			char	*separator = { " " };
			char 	*buffer;
			char* context = NULL;

			buffer = _strdup(command);
			action = strtok_s(buffer, separator,&context);
			State* prev_state = create_state(action, &init_state_);

			while (action != NULL)
			{
				action = strtok_s(NULL, separator,&context);
				if (action != NULL) prev_state = create_state(action, prev_state);
			}

			prev_state->add_transition(transitions_["ACTION_BUTTON_PRESSED_VALIDATE"]);
			prev_state->add_transition(transitions_["WRONG_ACTION_UP"]);
			prev_state->add_transition(transitions_["WRONG_ACTION_DOWN"]);
			prev_state->add_transition(transitions_["WRONG_ACTION_LEFT"]);
			prev_state->add_transition(transitions_["WRONG_ACTION_RIGHT"]);
		}

		State* create_state(const char* action, State* prev_state)
		{
			State* new_state = new State();
			Transition* transition_to_new_state = new Transition(new_state);
			Transition* t1;
			Transition* t2;
			Transition* t3;
			KonamiCondition* kc;

			if (!strcmp(action, "UP"))
			{
				kc = konami_conditions_["UP"];
				t1 = transitions_["WRONG_ACTION_DOWN"];
				t2 = transitions_["WRONG_ACTION_LEFT"];
				t3 = transitions_["WRONG_ACTION_RIGHT"];
			}
			else if (!strcmp(action, "DOWN"))
			{
				kc = konami_conditions_["DOWN"];
				t1 = transitions_["WRONG_ACTION_UP"];
				t2 = transitions_["WRONG_ACTION_LEFT"];
				t3 = transitions_["WRONG_ACTION_RIGHT"];
			}
			else if (!strcmp(action, "LEFT"))
			{
				kc = konami_conditions_["LEFT"];
				t1 = transitions_["WRONG_ACTION_UP"];
				t2 = transitions_["WRONG_ACTION_DOWN"];
				t3 = transitions_["WRONG_ACTION_RIGHT"];
			}
			else
			{
				kc = konami_conditions_["RIGHT"];
				t1 = transitions_["WRONG_ACTION_UP"];
				t2 = transitions_["WRONG_ACTION_LEFT"];
				t3 = transitions_["WRONG_ACTION_DOWN"];
			}

			transition_to_new_state->add_condition(kc);
			prev_state->add_transition(transition_to_new_state);
			prev_state->add_transition(t1);
			prev_state->add_transition(t2);
			prev_state->add_transition(t3);
			prev_state->add_transition(transitions_["WRONG_ACTION_BUTTON_PRESSED"]);
			static int i;
			std::cout << "new_state "<<++i << ": " << new_state << std::endl;
			return new_state;
		}

		Joystick* joystick_;
		Led* green_led_;
		Led* red_led_;
		Buzzer* buzzer_;
		State init_state_;
		State verified_state_;
		State wrong_action_state_;
		State wrong_action_button_pressed_state_;
		std::map<const char*, KonamiCondition*> konami_conditions_;
		std::map<const char*, Transition*> transitions_;
	};
}

#endif 