#ifndef ACTUATOR_H
#define ACTUATOR_H
 
#include <string>
#include <iostream>
#include "ActuatorState.h"
#include "IO_TYPE.h"
 
 
 namespace arduino_ml 
 {	
	/**
	 * An actuator is a device that can be connected to an arduino's pin.
	 */
	class Actuator
	{
	  public:
	  
		Actuator(const std::string& name, int pin_number, IO_TYPE io_type = INPUT_DEVICE)
			: name_(name), pin_number_(pin_number), io_type_(io_type) { }
		virtual ~Actuator() { };

		inline const std::string&  name() const { return name_;  }
		inline int pin_number() const { return pin_number_;  }
		inline void set_pin_number(int pin_number) { pin_number_ = pin_number; }
		inline IO_TYPE io_type() const { return io_type_;  }
		inline void set_io_type(IO_TYPE io_type) { io_type_ = io_type; }
		inline ActuatorState  current_state() const { std::cout << "digitalRead(" << pin_number_ << ")" << std::endl; int value; std::cin >> value; static_cast<ActuatorState>(value); }
		inline void set_current_state(ActuatorState state) { std::cout << "digitalWrite(" << pin_number_ << ", " << static_cast<int>(state) << ")" << std::endl; }
	  
	protected:
		  std::string name_;
		  int pin_number_;
		  IO_TYPE io_type_;
	};

	class Led : public Actuator
	{
	public:
		Led(const std::string& name, int pin_number) : Actuator(name, pin_number, OUTPUT_DEVICE) { }
	};

	class Buzzer : public Actuator
	{
	public:
		Buzzer(const std::string& name, int pin_number) : Actuator(name, pin_number, OUTPUT_DEVICE) { }
	};

	class Button : public Actuator
	{
	public:
		Button(const std::string& name, int pin_number) : Actuator(name, pin_number,INPUT_DEVICE) { }
	};

	class Joystick : public Actuator
	{
	public:
		Joystick(const std::string& name, int button_pin_number, int x_pin_number, int y_pin_number) : 
			Actuator(name, button_pin_number, INPUT_DEVICE), x_pin_number_(x_pin_number), y_pin_number_(y_pin_number) {}

		inline int current_x_value() const { std::cout << "analogRead(" << x_pin_number_ << ")" << std::endl; int value; std::cin >> value;  return value; }
		inline int current_y_value() const { std::cout << "analogRead(" << y_pin_number_ << ")" << std::endl; int value; std::cin >> value;  return value; }
		inline int current_button_value() const { std::cout << "digitalRead(" << pin_number_ << ")" << std::endl; int value; std::cin >> value;  return value; }

	private:
		int x_pin_number_;
		int y_pin_number_;
	};

	typedef enum
	{
		BUTTON_PIN,
		X_PIN,
		Y_PIN
	} PinType;
}

#endif 