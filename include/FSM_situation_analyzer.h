#ifndef _FSM_SITUATION_ANALYZER_
#define _FSM_SITUATION_ANALYZER_

#include <vector>
#include <assert.h>
using namespace std;

template <class T_SITUATION,class T_TRANSITION> class FSM_situation_analyzer
{
	public:
		// Methods to implement
		virtual string toString(void)=0;
		virtual vector<T_TRANSITION*> getTransitions(T_SITUATION* p_situation)=0;
		void computeTransitions(T_SITUATION* p_situation);

		// Virtual destructor
		virtual ~FSM_situation_analyzer(void);

};

#include "FSM_situation_analyzer.hpp"

#endif
