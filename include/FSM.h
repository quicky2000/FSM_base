#ifndef FSM_H
#define FSM_H

#include "FSM_if.h"
#include "FSM_motor.h"
#include "FSM_situation_analyzer.h"
#include <assert.h>

template <class T_SITUATION,class T_TRANSITION> class FSM: public FSM_if
{
 public:
  // Constructors and destructors
  FSM(std::string p_FSM_name,FSM_motor<T_SITUATION,T_TRANSITION> *p_motor,FSM_situation_analyzer<T_SITUATION,T_TRANSITION> *p_analyzer);
  virtual ~FSM(void);

  // Methods inherited from interface class
  FSM_situation_if* getCurrentSituation(void)const;
  void setCurrentSituation(FSM_situation_if* p_situation);
  void selectTransition(unsigned int p_transition_index);
  void computeTransitions(void);
  virtual void configure(void)=0;
  virtual std::string toString(void)const=0;
  std::string getFsmName(void)const;

  // Specific methods
  void setSituation(T_SITUATION *p_situation);
  T_SITUATION* getSituation(void)const;

 private:
  std::string m_name;
  T_SITUATION *m_situation;
  FSM_motor<T_SITUATION,T_TRANSITION> *m_motor;
  FSM_situation_analyzer<T_SITUATION,T_TRANSITION> *m_analyzer;
};

#include "FSM.hpp"

#endif /* FSM_H */
