#ifndef FSM_MOTOR_H
#define FSM_MOTOR_H

#include <string>

namespace FSM_base
{
  template <class T_SITUATION,class T_TRANSITION> class FSM_motor
  {
  public:
    // Methods to implement
    virtual const std::string & get_class_name(void)const=0;
    virtual T_SITUATION & run(const T_SITUATION & p_situation,
			      const T_TRANSITION & p_transition)=0;

    // Virtual destructor
    inline virtual ~FSM_motor(void){};
  };
}

#include "FSM_motor.hpp"

#endif // FSM_MOTOR_H 
//EOF
