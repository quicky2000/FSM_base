#ifndef FSM_SITUATION_ANALYZER
#define FSM_SITUATION_ANALYZER

#include <vector>
#include <string>
#include <assert.h>

namespace FSM_base
{
  template <class T_SITUATION,class T_TRANSITION> class FSM_situation_analyzer
  {
  public:
    // Methods to implement
    virtual const std::string & get_class_name(void)const=0;
    
    void compute_transitions(T_SITUATION & p_situation);

    // Virtual destructor
    virtual ~FSM_situation_analyzer(void);

  private:
    virtual std::vector<const T_TRANSITION *> & get_transitions(T_SITUATION & p_situation)=0;

  };
}

#include "FSM_situation_analyzer.hpp"

#endif // FSM_SITUATION_ANALYZER 
//EOF
