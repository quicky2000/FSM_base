//-----------------------------------------------------------------------------
template <class T_SITUATION,class T_TRANSITION>
FSM_situation_analyzer<T_SITUATION,T_TRANSITION>::~FSM_situation_analyzer(void)
{
}

//-----------------------------------------------------------------------------
template <class T_SITUATION,class T_TRANSITION>
void FSM_situation_analyzer<T_SITUATION,T_TRANSITION>::computeTransitions
(
 T_SITUATION* p_situation
 )
{
  assert(!p_situation->getContext()->transitionsComputed());

  p_situation->getContext()->addTransitions(this->getTransitions(p_situation));
}
