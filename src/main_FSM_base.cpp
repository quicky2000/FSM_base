/*    This file is part of FSM_base
      The aim of this software is to provided generic facilities for FSM analyzis
      Copyright (C) 2017  Julien Thevenon ( julien_thevenon at yahoo.fr )

      This program is free software: you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
      the Free Software Foundation, either version 3 of the License, or
      (at your option) any later version.

      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.

      You should have received a copy of the GNU General Public License
      along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#ifdef FSM_BASE_SELF_TEST

#include "FSM_situation.h"
#include "FSM.h"
#include "FSM_transition_if.h"

class example_transition: public FSM_interfaces::FSM_transition_if
{
  public:
    const std::string
    to_string(void) const override
    {
        return "example_transition";
    }

    void
    to_string(std::string & p_string) const override
    {
        p_string = m_class_name;
    }

  private:
    static const std::string m_class_name;
};

const std::string example_transition::m_class_name = "example_transition";

#include "FSM_context.h"
class example_context: public FSM_base::FSM_context<example_transition>
{
  public:
    const std::string
    to_string(void) const override
    {
        return "";
    }

    void
    to_string(std::string & string) const override
    {

    }
    inline ~example_context(void)
    {
    }
  private:
};

class example_situation: public FSM_base::FSM_situation<example_context>
{
  public:
    inline example_situation(void);

    inline example_situation(const example_situation & p_situation);

    inline const std::string
    to_string(void) const override;

    inline void
    to_string(std::string & string) const override;

    inline void increment(void);

    inline void decrement(void);

    const std::string
    get_string_id(void) const override;

    void
    get_string_id(std::string & string) const override;

    bool
    is_final(void) const override;

    bool
    less(const FSM_interfaces::FSM_situation_if *p_object2) const override;

  private:
    unsigned int m_step;
};

//-----------------------------------------------------------------------------
example_situation::example_situation(void):
        FSM_situation(),
        m_step(0)
{

}

//-----------------------------------------------------------------------------
void
example_situation::increment(void)
{
    ++m_step;
}

//-----------------------------------------------------------------------------
const std::string
example_situation::to_string(void) const
{
    return "step = " + std::to_string(m_step);
}

//-----------------------------------------------------------------------------
void
example_situation::to_string(std::string & string) const
{
    string = "step = " + std::to_string(m_step);
}

//-----------------------------------------------------------------------------
example_situation::example_situation(const example_situation & p_situation
                                    ):
        FSM_situation(p_situation),
        m_step(p_situation.m_step)
{}

//-----------------------------------------------------------------------------
const std::string
example_situation::get_string_id(void) const
{
    return std::to_string(m_step);
}

//-----------------------------------------------------------------------------
bool
example_situation::is_final(void) const
{
    return 3 == m_step;
}

//-----------------------------------------------------------------------------
void
example_situation::get_string_id(std::string & string) const
{
    string = std::to_string(m_step);
}

//-----------------------------------------------------------------------------
bool
example_situation::less(const FSM_interfaces::FSM_situation_if *p_object2) const
{
    return m_step < static_cast<const example_situation*>(p_object2)->m_step;
}

//-----------------------------------------------------------------------------
void
example_situation::decrement(void)
{
    m_step--;
}

#include "FSM_motor.h"

class example_motor: public FSM_base::FSM_motor<example_situation,example_transition>
{
  public:
    inline const std::string &
    get_class_name(void) const override;

    inline void
    apply(example_situation & p_situation,
          const example_transition & p_transition
         ) override;

    inline example_situation &
    run(const example_situation & p_situation,
        const example_transition & p_transition
       ) override;

    void
    revert_transition(example_situation & p_situation) override;

  private:
    static const std::string m_class_name;
};

const std::string example_motor::m_class_name = "example_motor";

//-----------------------------------------------------------------------------
const std::string &
example_motor::get_class_name(void) const
{
    return m_class_name;
}

//-----------------------------------------------------------------------------
void
example_motor::apply(example_situation & p_situation,
                     const example_transition & p_transition
                    )
{
    p_situation.increment();
}

//-----------------------------------------------------------------------------
example_situation &
example_motor::run(const example_situation & p_situation,
                   const example_transition & p_transition
                  )
{
    example_situation * l_result = new example_situation(p_situation);
    l_result->get_context()->remove_transitions();
    this->apply(*l_result,p_transition);
    return *l_result;
}

//-----------------------------------------------------------------------------
void
example_motor::revert_transition(example_situation & p_situation)
{
    p_situation.decrement();
}

#include "FSM_situation_analyzer.h"
#include <vector>

class example_analyzer: public FSM_base::FSM_situation_analyzer<example_situation,example_transition>
{
  public:
    const std::string &
    get_class_name(void) const override
    {
        return m_class_name;
    }

  private:
    std::vector<const example_transition *> &
    get_transitions(example_situation & p_situation) override;

  private:
    static const std::string m_class_name;
};

const std::string example_analyzer::m_class_name = "example_analyzer";

//-----------------------------------------------------------------------------
std::vector<const example_transition *> &
example_analyzer::get_transitions(example_situation & p_situation)
{
    std::vector<const example_transition *> * l_result = new std::vector<const example_transition*>();
    l_result->push_back(new example_transition());
    return *l_result;
}

class example_FSM: public FSM_base::FSM<example_situation,example_transition>
{
  public:
    example_FSM(void):
            FSM("example_FSM",
                *new example_motor(),
                *new example_analyzer()
               )
    {}

    void
    configure(void) override
    {

    }
    const std::string &
    get_class_name(void) const override
    {
        return m_class_name;
    }
  private:
    static const std::string m_class_name;
};

const std::string example_FSM::m_class_name = "example_FSM";

int main(int argc, char ** argv)
{
    example_FSM l_fsm;
    example_situation * l_initial_situation = new example_situation();
    l_initial_situation->set_context(*new example_context());
    l_fsm.set_current_situation(*l_initial_situation);
    do
    {
        std::cout << l_fsm.get_situation().to_string() << std::endl;
        l_fsm.compute_transitions();
        example_context * l_context = l_fsm.get_situation().get_context();
        assert(nullptr != l_context);
        unsigned int l_nb_transition = l_context->get_nb_transitions();
        assert(1 == l_nb_transition);
        l_fsm.select_transition(1);
    }
    while(!l_fsm.get_current_situation().is_final());
    return 0;
}
#endif // BASE_FSM_SELF_TEST
//EOF
