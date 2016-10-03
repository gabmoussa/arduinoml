#ifndef STATE_H
#define STATE_H

#include <string>
#include <iterator>
#include <list>

#include "Action.h"
#include "ActuatorState.h"

namespace arduino_ml 
{
	class Transition; /**< Forward declaration of Transition to avoid a include cycle */

	/**
	 * A state memorize a set of actions & possibles transitions.
	 * These actions are executed when the state is activated 
	 */
	class State
	{
	public:
		State(bool loop = false) : loop_(loop) { }

		inline void add_action(Actuator* actuator, ActuatorState nextState, int delay = 0) { actions_.push_back(new Action(actuator, nextState, delay)); }
		inline void add_transition(Transition* transition) { transitions_.push_back(transition); }
		inline std::list<Action*>& actions() { return actions_; }
		inline std::list<Transition*>& transitions() { return transitions_; }
		inline bool loop() const { return loop_; }
		
		void exec_actions()
		{
			for (std::list<Action*>::iterator action = actions_.begin(); action != actions_.end(); ++action)
				(*action)->execute();
		}

		int total_waiting_time()
		{
			int wait_time = 0;
			for (std::list<Action*>::iterator action = actions_.begin(); action != actions_.end(); ++action)
				wait_time += (*action)->sleep_time();
			return wait_time;
		}

	private:
		std::list<Action*> actions_;	/**< The actions to execute when in that state */
		std::list<Transition*> transitions_;	/**< The possibles transitions */
		bool loop_;
	};
}

#endif