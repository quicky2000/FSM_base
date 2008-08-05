#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
template <class T_SITUATION,class T_TRANSITION>
	FSM<T_SITUATION,T_TRANSITION>::FSM
	(
		string p_name,
		FSM_motor<T_SITUATION,T_TRANSITION> *p_motor,
		FSM_situation_analyzer<T_SITUATION,T_TRANSITION> *p_analyzer
	):
	m_name(p_name),
	m_situation(NULL),
	m_motor(p_motor),
	m_analyzer(p_analyzer)
	{
		assert(m_motor);
		assert(m_analyzer);
	}

//-----------------------------------------------------------------------------
template <class T_SITUATION,class T_TRANSITION>
	FSM<T_SITUATION,T_TRANSITION>::~FSM(void)
	{
		if(m_motor)
		{
			delete m_motor;
			m_motor = NULL;
		}
		if(m_analyzer)
		{
			delete m_analyzer;
			m_analyzer = NULL;
		}
		if(m_situation)
		{
			delete m_situation;
			m_situation = NULL;
		}
	}

//-----------------------------------------------------------------------------
template <class T_SITUATION,class T_TRANSITION>
	FSM_situation_if* FSM<T_SITUATION,T_TRANSITION>::getCurrentSituation(void)const
	{
		return m_situation;
	}

//-----------------------------------------------------------------------------
template <class T_SITUATION,class T_TRANSITION>
	void FSM<T_SITUATION,T_TRANSITION>::setCurrentSituation
	(
		FSM_situation_if* p_situation
	)
	{
		assert(p_situation);
		m_situation = dynamic_cast<T_SITUATION*>(p_situation);
		if(m_situation == NULL)
		{
			cout << "FSM<T_SITUATION,T_TRANSITION>::" << __FUNCTION__ << " ERROR : bad situation type" << endl ;
			exit(-1);
		}
	}

//-----------------------------------------------------------------------------
template <class T_SITUATION,class T_TRANSITION>
	void FSM<T_SITUATION,T_TRANSITION>::computeTransitions(void)
	{
		m_analyzer->computeTransitions(m_situation);
	}

//-----------------------------------------------------------------------------
template <class T_SITUATION,class T_TRANSITION>
	void FSM<T_SITUATION,T_TRANSITION>::selectTransition
	(
		unsigned int p_transition_index
	)
	{
		T_TRANSITION* l_selected_transition = this->getSituation()->getContext()->getSpecificTransition(p_transition_index);
		this->setSituation(m_motor->run(this->getSituation(),l_selected_transition));
	}

//-----------------------------------------------------------------------------
template <class T_SITUATION,class T_TRANSITION>
	string FSM<T_SITUATION,T_TRANSITION>::getFsmName(void)const
	{
		return m_name;
	}

//-----------------------------------------------------------------------------
template <class T_SITUATION,class T_TRANSITION>
	void FSM<T_SITUATION,T_TRANSITION>::setSituation
	(
		T_SITUATION *p_situation
	)
	{
		assert(p_situation);
		m_situation = p_situation;		
	}

//-----------------------------------------------------------------------------
template <class T_SITUATION,class T_TRANSITION>
	T_SITUATION* FSM<T_SITUATION,T_TRANSITION>::getSituation(void)const
	{
		return m_situation;		
	}

