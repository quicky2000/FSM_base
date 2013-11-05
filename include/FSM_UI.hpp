
namespace FSM_base
{
  //-----------------------------------------------------------------------------
  template <class T_SITUATION>
  FSM_UI<T_SITUATION>::~FSM_UI(void)
  {
  }


  //-----------------------------------------------------------------------------
  template <class T_SITUATION>
  void FSM_UI<T_SITUATION>::display_situation
  (
   const FSM_situation_if & p_situation
   )
  {
    assert(dynamic_cast<const T_SITUATION*>(&p_situation) != NULL);
    const T_SITUATION *l_situation = static_cast<const T_SITUATION*>(&p_situation);
    this->display_specific_situation(*l_situation);

  }

}
//EOF
