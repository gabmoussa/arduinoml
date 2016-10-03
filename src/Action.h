
#ifndef ACTION_H
#define ACTION_H	

#include "ActuatorState.h"
#include "Actuator.h"


namespace arduino_ml
{
	/**
	 * An action refer to an actuator's state change. 
	 */
	class Action
	{
	public:
		Action(Actuator* actuator,ActuatorState actuator_state,int sleep_time = 0) 
			: actuator_(actuator), actuator_state_(actuator_state), sleep_time_(sleep_time) { }
		
		inline ActuatorState actuator_state() { return actuator_state_; }
		inline Actuator* actuator() { return actuator_; }
		inline int sleep_time() const { return sleep_time_; }
		inline void execute() { if (!sleep_time_) delay(sleep_time_); actuator_->set_current_state(actuator_state_); }

	private:
		Actuator* actuator_;
		ActuatorState actuator_state_;
		int sleep_time_;
	};
	
}

#endif 