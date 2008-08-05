#include "FSM_UI_if.h"

FSM_UI_if::~FSM_UI_if(void)
{
}

void registerFsmUi(string p_fsm_name,FSM_UI_creator p_creator,map<string,FSM_UI_creator> *p_factory)
{
	p_factory->insert(map<string,FSM_UI_creator>::value_type(p_fsm_name,p_creator));
}
