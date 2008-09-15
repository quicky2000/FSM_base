#ifndef FSM_WEIGHTED_TRANSITION_INDEX_H
#define FSM_WEIGHTED_TRANSITION_INDEX_H

#include "FSM_weighted_transition_index_if.h"

#include <string>

class FSM_weighted_transition_index:public FSM_weighted_transition_index_if
{
 public:
  // Constructor
  FSM_weighted_transition_index(unsigned int p_transition_index,unsigned int p_weigth=0);

  // Methods inhereited from interface
  unsigned int getTransitionIndex(void)const;
  unsigned int getWeight(void)const;
  std::string getString(void)const;
  bool operator<(const FSM_weighted_transition_index_if &p_object2)const;

 private:
  unsigned int m_transition_index;
  unsigned int m_weight;
};

#endif /* FSM_WEIGHTED_TRANSITION_INDEX_H */
