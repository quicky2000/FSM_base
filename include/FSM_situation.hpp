//-----------------------------------------------------------------------------
template <class T_CONTEXT>
FSM_situation<T_CONTEXT>::FSM_situation(void):
  m_context(NULL)  
{
}

//-----------------------------------------------------------------------------
template <class T_CONTEXT>
FSM_situation<T_CONTEXT>::FSM_situation(const FSM_situation &p_situation)
{
  m_context = new T_CONTEXT(*(p_situation.getContext()));
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
	FSM_context_if* FSM_situation<T_CONTEXT>::getCurrentContext(void)const
	{
		return m_context;
	}

//-----------------------------------------------------------------------------
template <class T_CONTEXT>
	T_CONTEXT* FSM_situation<T_CONTEXT>::getContext(void)const
	{
		return m_context;
	}

//-----------------------------------------------------------------------------
template <class T_CONTEXT>
	void FSM_situation<T_CONTEXT>::setContext
	(
		T_CONTEXT *p_context
	)
	{
		assert(p_context != NULL);
		m_context = p_context;
	}

