#include "QueryCommand.h"

#include "HeatViewModel.h"

QueryCommand::QueryCommand(HeatViewModel* p) throw() : m_pVM(p)
{

}

void QueryCommand::SetParameter(const std::any& param)
{
	m_param = std::any_cast<workboardPass>(param);
}

void QueryCommand::Exec()
{
	bool bresult = m_pVM->Query(m_param);
	m_pVM->Fire_OnCommandComplete("Query", bresult);
}