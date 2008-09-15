#include "FSM_weighted_transition_index.h"

#include <sstream>
using namespace std;

//------------------------------------------------------------------------------
FSM_weighted_transition_index::FSM_weighted_transition_index(unsigned int p_transition_index,unsigned int p_weight):
  m_transition_index(p_transition_index),
  m_weight(p_weight)
{
}

//------------------------------------------------------------------------------
unsigned int FSM_weighted_transition_index::getTransitionIndex(void)const
{
  return m_transition_index;
}

//------------------------------------------------------------------------------
unsigned int FSM_weighted_transition_index::getWeight(void)const
{
  return m_weight;
}

//------------------------------------------------------------------------------
string FSM_weighted_transition_index::getString(void)const
{
  stringstream l_stream;
  l_stream << "(Index,Weight)=(" << m_transition_index << "," << m_weight << ")" ;
  return l_stream.str();
}

//------------------------------------------------------------------------------
bool FSM_weighted_transition_index::operator<(const FSM_weighted_transition_index_if &p_object2)const
{
  bool l_result = m_weight < p_object2.getWeight();
  if(m_weight == p_object2.getWeight())
    {
      l_result = m_transition_index < p_object2.getTransitionIndex();
    }
  return l_result;
}


//EOF
