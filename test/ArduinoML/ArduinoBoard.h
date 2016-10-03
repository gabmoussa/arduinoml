#ifndef ARDUINOBOARD_H
#define ARDUINOBOARD_H

#include <string>
#include <map>
#include <iostream>
#include "Actuator.h"
#include "State.h"

namespace arduino_ml 
{	
	/**
	 * The Arduino board.
	 * It keep a pointer to all actuators & implement a state machine.
	 * For each iteration() call the machine check if a transition can be done from the current state.
	 * If that is the case then the current state is set to the next state and 
	 * all actions of the newly reached state are executed.
	 */
	class ArduinoBoard
	{
	public:
		ArduinoBoard(float frequency = 0 )
		{
			if (frequency) period_ = 1000.0 / frequency;
			else period_ = 0;
		}

		inline void add_actuator(Actuator* actuator) { actuators_[actuator->name()] = actuator; }
		inline Actuator* actuator(std::string name) { return actuators_[name]; }
		inline void init(State* init_state) { current_state_ = init_state; current_state_->exec_actions(); }
		void init_pins()
		{
			std::map<std::string, Actuator*>::iterator it;
			for (it = actuators_.begin(); it != actuators_.end(); ++it)
			{
				Actuator* actuator = it->second;
				std::cout << "pinMode(" << actuator->pin_number()<< ", " << static_cast<int>(actuator->io_type()) << ")" << std::endl;
			}
		}
		void iteration() 
		{ 
			bool delayed = false;
			std::list<Transition*>& transitions = current_state_->transitions();
			for (std::list<Transition*>::iterator t = transitions.begin(); t != transitions.end(); ++t)
			{
				if ((*t)->is_possible()) 
				{ 
					current_state_ = (*t)->next_state();
					current_state_->exec_actions();
					std::cout << "change state : " << current_state_ << std::endl;
					if (period_) std::this_thread::sleep_for(std::chrono::milliseconds((period_ - current_state_->total_waiting_time())));
					delayed = true;
					break;
				}
			}
			if (current_state_->loop())
			{
				current_state_->exec_actions();
				if (period_) std::this_thread::sleep_for(std::chrono::milliseconds(period_ - current_state_->total_waiting_time()));
				delayed = true;
			}
			if (!delayed) std::this_thread::sleep_for(std::chrono::milliseconds(period_));
		}

	private:
		std::map<std::string, Actuator*> actuators_;
		State* current_state_;
		int period_;
	};
}

#endif 