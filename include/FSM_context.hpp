#include <iostream>
#include <cstdlib>
using namespace std;

//-----------------------------------------------------------------------------
template <class T_TRANSITION>
FSM_context<T_TRANSITION>::~FSM_context(void)
{
  for(typename vector<T_TRANSITION*>::iterator l_iter =  m_transitions.begin();
      m_transitions.end() != l_iter;
      ++l_iter)
    {
      delete *l_iter;
    }
  m_transitions.clear();
}

//-----------------------------------------------------------------------------
template <class T_TRANSITION>
FSM_context<T_TRANSITION>::FSM_context(void)
{
  m_transition_added = false;
}

//-----------------------------------------------------------------------------
template <class T_TRANSITION>
unsigned int FSM_context<T_TRANSITION>::getNbTransitions(void)const
{
  assert(m_transition_added);
  return m_transitions.size();
}

//-----------------------------------------------------------------------------
template <class T_TRANSITION>
FSM_transition_if* FSM_context<T_TRANSITION>::getTransition
(
 unsigned int p_index
 )const
{
  assert(m_transition_added);
  if(p_index > m_transitions.size())
    {
      cout << "FSM error : asked transition doesnt exist" << endl ;
      exit(-1);
    }
  return m_transitions[p_index];
}

//-----------------------------------------------------------------------------
template <class T_TRANSITION>
T_TRANSITION* FSM_context<T_TRANSITION>::getSpecificTransition
(
 unsigned int p_index
 )const
{
  assert(m_transition_added);
  if(p_index > m_transitions.size())
    {
      cout << "FSM error : asked transition doesnt exist" << endl ;
      exit(-1);
    }
  return m_transitions[p_index];
}

//-----------------------------------------------------------------------------
template <class T_TRANSITION>
void FSM_context<T_TRANSITION>::addTransitions(const vector<T_TRANSITION*> &p_transitions)
{
  m_transition_added = true;
  m_transitions = p_transitions;
}

//-----------------------------------------------------------------------------
template <class T_TRANSITION>
bool FSM_context<T_TRANSITION>::transitionsComputed(void)const
{
  return m_transition_added;
}
