#ifndef FSM_UI_H
#define FSM_UI_H

#include "FSM_UI_if.h"
#include "assert.h"

namespace FSM_base
{
  template <class T_SITUATION> class FSM_UI:public FSM_interfaces::FSM_UI_if
  {
  private:
    typedef FSM_interfaces::FSM_situation_if FSM_situation_if;
  public:
    // Constructor and destructors
    virtual ~FSM_UI(void);
    
    // Methods inherited from interface
    virtual void display_situation(const FSM_situation_if & p_situation);
    
  private:
    virtual void display_specific_situation(const T_SITUATION & p_situation)=0;
  };
}
#include "FSM_UI.hpp"

#endif // FSM_UI
//EOF
