#ifndef FSM_CONTEXT
#define FSM_CONTEXT

#include "FSM_context_if.h"

#include <vector>
#include <assert.h>

template <class T_TRANSITION> class FSM_context:public FSM_context_if
{
 public:
  // Constructor and destructors
  FSM_context(void);
  virtual ~FSM_context(void);

  // Methods inherited from interface
  unsigned int getNbTransitions(void)const;
  FSM_transition_if* getTransition(unsigned int p_index)const;

  // Specific method
  T_TRANSITION* getSpecificTransition(unsigned int p_index)const;
  void addTransition(T_TRANSITION *p_transition);
  bool transitionsComputed(void)const;

 private:
  vector<T_TRANSITION*> m_transitions;
  bool m_transition_added;
};

#include "FSM_context.hpp"

#endif /* FSM_CONTEXT */
