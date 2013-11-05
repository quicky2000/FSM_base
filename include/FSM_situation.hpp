namespace FSM_base
{
  //-----------------------------------------------------------------------------
  template <class T_CONTEXT>
  FSM_situation<T_CONTEXT>::FSM_situation(void):
    m_context(NULL),
    m_valid(true)
  {
  }

  //-----------------------------------------------------------------------------
  template <class T_CONTEXT>
  FSM_situation<T_CONTEXT>::FSM_situation(const FSM_situation &p_situation):
    m_context(new T_CONTEXT(*(p_situation.getContext()))),
    m_valid(p_situation.isValid())
  {
  }

  //-----------------------------------------------------------------------------
  template <class T_CONTEXT>
  FSM_situation<T_CONTEXT>::~FSM_situation(void)
  {
    if(m_context != NULL)
      {
	delete m_context ;
	m_context = NULL;
      }
  }

  //-----------------------------------------------------------------------------
  template <class T_CONTEXT>
  typename FSM_situation<T_CONTEXT>::FSM_context_if * FSM_situation<T_CONTEXT>::get_current_context(void)const
  {
    return m_context;
  }

  //-----------------------------------------------------------------------------
  template <class T_CONTEXT>
  bool FSM_situation<T_CONTEXT>::is_valid(void)const
  {
    return m_valid;
  }

  //-----------------------------------------------------------------------------
  template <class T_CONTEXT>
  T_CONTEXT * FSM_situation<T_CONTEXT>::get_context(void)const
  {
    assert(m_context);
    return m_context;
  }

  //-----------------------------------------------------------------------------
  template <class T_CONTEXT>
  void FSM_situation<T_CONTEXT>::set_context
  (
   T_CONTEXT & p_context
   )
  {
    m_context = & p_context;
  }

  //-----------------------------------------------------------------------------
  template <class T_CONTEXT>
  void FSM_situation<T_CONTEXT>::set_invalid
  (
   void
   )
  {
    m_valid = false;
  }

}
//EOF
