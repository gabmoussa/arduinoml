#include <ArduinoML.h>

arduino_ml::ArduinoBoard board;

void setup(){
	arduino_ml::Led* led_rouge = new arduino_ml::Led("led_rouge", 10);
	arduino_ml::Led* led_verte = new arduino_ml::Led("led_verte", 11);
	arduino_ml::Buzzer* buzzer = new arduino_ml::Buzzer("buzzer", 12);
	arduino_ml::Joystick* joystick = new arduino_ml::Joystick("joystick", 10, 2, 1);

	board.add_actuator(led_rouge);
	board.add_actuator(led_verte);
	board.add_actuator(buzzer);
	board.add_actuator(joystick);

	arduino_ml::Konami* konami = new arduino_ml::Konami(joystick, led_verte, led_rouge, buzzer, "UP DOWN RIGHT LEFT");
	board.init_pins();
	board.init(konami->init_state());
}
void loop(){
	board.iteration();
}


int main()
{
	setup();
	while (true)
	{
		loop();
	}

	return 0;
}