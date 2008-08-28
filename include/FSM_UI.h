#ifndef FSM_UI_H
#define FSM_UI_H

#include "FSM_UI_if.h"
#include "assert.h"

template <class T_SITUATION> class FSM_UI:public FSM_UI_if
{
 public:
  // Constructor and destructors
  virtual ~FSM_UI(void);

  // Methods inherited from interface
  virtual void displaySituation(const FSM_situation_if *p_situation);

 private:
  virtual void displaySpecificSituation(const T_SITUATION *p_situation)=0;
};

#include "FSM_UI.hpp"

#endif /* FSM_UI_H */
