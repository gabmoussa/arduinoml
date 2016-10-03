#ifndef CONDITION_H
#define CONDITION_H	

#include "ActuatorState.h"
#include "Actuator.h"

namespace arduino_ml
{


	class AbstractCondition
	{
	public:
		virtual inline bool isValid() = 0;
	};

	/**
	 * A condition is compose by an actuator & an actuator state.
	 * The condition is verified if the actuator is in the indicated state.
	 */
	class Condition : public AbstractCondition
	{
	public:
		Condition(Actuator* actuator,ActuatorState actuator_state) 
			: actuator_(actuator), actuator_state_(actuator_state) { }
		virtual inline bool isValid() { return actuator_->current_state() == static_cast<int>(actuator_state_); }
		
	private:
		Actuator* actuator_;	/**< The actuator */
		ActuatorState actuator_state_;  /**< State of the actuator to match */
	};

	class KonamiCondition : public AbstractCondition
	{
	public:
		KonamiCondition(Joystick* joystick,PinType pin_type, int value)
			: joystick_(joystick), pin_type_(pin_type), value_(value) { }
		
		KonamiCondition(Joystick* joystick, PinType pin_type, ActuatorState actuator_state)
			: joystick_(joystick), pin_type_(pin_type), value_(static_cast<int>(actuator_state)) { }
		
		virtual inline bool isValid()
		{ 
			if (pin_type_ == X_PIN) return joystick_->current_x_value() == value_;
			else if (pin_type_ == Y_PIN) return joystick_->current_y_value() == value_;
			else joystick_->current_button_value() ==  value_;
		}

	private:
		Joystick* joystick_;	/**< The joystick */
		PinType pin_type_;
		int value_;
		
	};
}

#endif 