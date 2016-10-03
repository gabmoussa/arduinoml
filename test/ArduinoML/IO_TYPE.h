#ifndef IO_TYPE_H
#define IO_TYPE_H

namespace arduino_ml 
{
	/**
	 * The possibles values of I/O.
	 * INPUT_DEVICE has the same value as Arduino INPUT
	 * OUTPUT_DEVICE has the same value as Arduino OUTPUT
	 * The purpose of this enum is to reduce the possibility of the i/o values 
	 * ( Arduino.h define INPUT & OUPUT as macro.....) 
	 */
	enum IO_TYPE
	{
		INPUT_DEVICE, //< 0
		OUTPUT_DEVICE //< 1
	};
}
	
#endif 