#ifndef FSM_SITUATION_ANALYZER
#define FSM_SITUATION_ANALYZER

#include <vector>
#include <string>
#include <assert.h>

template <class T_SITUATION,class T_TRANSITION> class FSM_situation_analyzer
{
 public:
  // Methods to implement
  virtual std::string toString(void)=0;
  virtual std::vector<T_TRANSITION*> getTransitions(T_SITUATION* p_situation)=0;
  void computeTransitions(T_SITUATION* p_situation);

  // Virtual destructor
  virtual ~FSM_situation_analyzer(void);

};

#include "FSM_situation_analyzer.hpp"

#endif /* FSM_SITUATION_ANALYZER */
