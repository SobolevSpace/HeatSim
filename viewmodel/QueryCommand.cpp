#include "QueryCommand.h"

#include "HeatViewModel.h"

InitCondiCommand::InitCondiCommand(HeatViewModel* p) throw() : m_pVM(p)
{

}

void InitCondiCommand::SetParameter(const std::any& param)
{
	m_param = std::any_cast<workboardPass>(param);
}

void InitCondiCommand::Exec()
{
	bool bresult = m_pVM->Query(m_param);
	m_pVM->Fire_OnCommandComplete("Query", bresult);
}