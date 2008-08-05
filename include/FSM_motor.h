#ifndef _FSM_MOTOR_H_
#define _FSM_MOTOR_H_

#include <string>
using namespace std;

template <class T_SITUATION,class T_TRANSITION> class FSM_motor
{
	public:
		// Methods to implement
		virtual string toString(void)=0;
		virtual T_SITUATION* run(T_SITUATION* p_situation,T_TRANSITION *p_transition)=0;

		// Virtual destructor
		virtual ~FSM_motor(void);
};

#include "FSM_motor.hpp"

#endif
