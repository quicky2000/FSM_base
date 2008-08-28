#ifndef FSM_MOTOR_H
#define FSM_MOTOR_H

#include <string>

template <class T_SITUATION,class T_TRANSITION> class FSM_motor
{
 public:
  // Methods to implement
  virtual std::string toString(void)=0;
  virtual T_SITUATION* run(T_SITUATION* p_situation,T_TRANSITION *p_transition)=0;

  // Virtual destructor
  virtual ~FSM_motor(void);
};

#include "FSM_motor.hpp"

#endif /* FSM_MOTOR_H */
