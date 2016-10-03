#ifndef TRANSITION_H
#define TRANSITION_H
#include <string>

#include "State.h"
#include "Condition.h"

namespace arduino_ml	
{
	/**
	 * A transition.
	 * A transition is executed when all of is conditions are verified.
	 * When the transition is completed the current state is set to the transition's next_state.
	 */
	class Transition
	{
	 public:
		Transition(State* next_state) : next_state_(next_state) {}
		inline std::list<AbstractCondition*>& conditions() { return conditions_; }
		inline void add_condition(AbstractCondition* condition) { conditions_.push_back(condition); }
		inline bool is_possible() 
		{ 
			for (std::list<AbstractCondition*>::iterator it = conditions_.begin(); it != conditions_.end(); ++it)
			{
				if(!(*it)->isValid()) return false;
			}
			return true;
		}
		
		inline State* next_state()  { return next_state_; }

	 private:
		std::list<AbstractCondition*> conditions_;  /**< The conditions to be verified in order to execute the transition */
		State* next_state_; /**< The next state reached through the transition */
	};
}

#endif 

