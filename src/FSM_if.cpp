#include "FSM_if.h"

using namespace std;

namespace FSM_interfaces
{
  //-----------------------------------------------------------------------------
  void register_fsm(const string & p_FSM_type,
                    FSM_creator_t p_creator,
                    map<string,FSM_creator_t>  & p_factory
                    )
  {
    p_factory.insert(map<string,FSM_creator_t>::value_type(p_FSM_type,p_creator));
  }
}
//EOF
