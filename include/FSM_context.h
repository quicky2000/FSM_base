#ifndef FSM_CONTEXT
#define FSM_CONTEXT

#include "FSM_context_if.h"

#include <vector>
#include <assert.h>

namespace FSM_base
{
  template <class T_TRANSITION> class FSM_context:public FSM_interfaces::FSM_context_if
  {
  private:
    typedef FSM_interfaces::FSM_types::transition_index_t transition_index_t;
    typedef FSM_interfaces::FSM_transition_if FSM_transition_if;
  public:
    // Constructor and destructors
    FSM_context(void);
    virtual ~FSM_context(void);

    // Methods inherited from interface
    const transition_index_t get_nb_transitions(void)const;
    const FSM_transition_if & get_transition(const transition_index_t & p_index)const;
    bool transitions_computed(void)const;

    // Specific method
    const T_TRANSITION & get_specific_transition(const transition_index_t & p_index)const;
    void set_transitions(const std::vector<const T_TRANSITION *> & p_transitions);

  private:
    const std::vector<const T_TRANSITION *> * m_transitions;
  };

}

#include "FSM_context.hpp"

#endif // FSM_CONTEXT
//EOF
