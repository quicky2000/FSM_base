#include "FSM_UI_if.h"

namespace FSM_interfaces
{
  void register_fsm_ui(const std::string & p_fsm_name,
                       FSM_UI_creator_t p_creator,
                       std::map<std::string,FSM_UI_creator_t> & p_factory)
  {
    p_factory.insert(std::map<std::string,FSM_UI_creator_t>::value_type(p_fsm_name,p_creator));
  }
}
//EOF
