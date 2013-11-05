namespace FSM_base
{

  //-----------------------------------------------------------------------------
  template <class T_SITUATION,class T_TRANSITION>
  FSM_situation_analyzer<T_SITUATION,T_TRANSITION>::~FSM_situation_analyzer(void)
  {
  }

  //-----------------------------------------------------------------------------
  template <class T_SITUATION,class T_TRANSITION>
  void FSM_situation_analyzer<T_SITUATION,T_TRANSITION>::compute_transitions
  (
   T_SITUATION & p_situation
   )
  {
    assert(!p_situation.get_context()->transitions_computed());
    p_situation.get_context()->set_transitions(this->get_transitions(p_situation));
  }

}
//EOF
