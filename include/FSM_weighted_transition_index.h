#ifndef FSM_WEIGHTED_TRANSITION_INDEX_H
#define FSM_WEIGHTED_TRANSITION_INDEX_H

#include "FSM_weighted_transition_index_if.h"

#include <string>

namespace FSM_base
{
  class FSM_weighted_transition_index:public FSM_interfaces::FSM_weighted_transition_index_if
  {
  private:
    typedef FSM_interfaces::FSM_types::transition_index_t transition_index_t;
    typedef FSM_interfaces::FSM_types::transition_weight_t transition_weight_t;
  public:
    // Constructor
    FSM_weighted_transition_index(const transition_index_t & p_transition_index,
                                  const transition_weight_t & p_weight=0);
    
    // Methods inhereited from interface
    const transition_index_t & get_transition_index(void)const;
    const transition_weight_t & get_weight(void)const;
    const std::string get_string(void)const;
    void get_string(std::string &)const;
    bool operator<(const FSM_weighted_transition_index_if & p_object2)const;
    
  private:
    const transition_index_t m_transition_index;
    const transition_weight_t m_weight;
  };
}

#endif /* FSM_WEIGHTED_TRANSITION_INDEX_H */
//EOF
