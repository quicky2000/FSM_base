#include "FSM_if.h"

//-----------------------------------------------------------------------------
FSM_if::~FSM_if(void)
{
}

//-----------------------------------------------------------------------------
void registerFsm
(
	string p_FSM_type,
	FSM_creator p_creator,
	map<string,FSM_creator> *p_factory
)
{
	p_factory->insert(map<string,FSM_creator>::value_type(p_FSM_type,p_creator));
}
