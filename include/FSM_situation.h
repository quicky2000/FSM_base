#ifndef FSM_SITUATION
#define FSM_SITUATION

#include "FSM_situation_if.h"
#include "assert.h"

template <class T_CONTEXT> class FSM_situation:public FSM_situation_if
{
 public:
  // Constructors and destructors
  FSM_situation(void);
  FSM_situation(const FSM_situation &p_situation);
  virtual ~FSM_situation(void);

  // Methods inherited from interface
  FSM_context_if* getCurrentContext(void)const;
  virtual string toString(void)const=0;
  bool isValid(void)const;
  void setInvalid(void);

  // Specific methods
  T_CONTEXT* getContext(void)const;
  void setContext(T_CONTEXT *p_context);

 private:
  T_CONTEXT *m_context;
  bool m_valid;
};

#include "FSM_situation.hpp"

#endif /* FSM_SITUATION */
