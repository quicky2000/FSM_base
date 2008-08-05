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
		vector<T_TRANSITION*> l_transitions = this->getTransitions(p_situation);
		typename vector<T_TRANSITION*>::iterator l_iter = l_transitions.begin();
		typename vector<T_TRANSITION*>::iterator l_iter_end = l_transitions.end();
		while(l_iter != l_iter_end)
		{
			p_situation->getContext()->addTransition(*l_iter);
			l_iter++;
		}
	}
