#include "AvgCommand.h"
#include "../HeatViewModel.h"

AvgCommand::AvgCommand(HeatViewModel* p) throw() : m_pVM(p)
{

}

void AvgCommand::SetParameter(const std::any& param)
{
	m_param = std::any_cast<std::pair<pointParameters, pointParameters>>(param);
}

void AvgCommand::Exec()
{
	m_pVM->CalcAvg(m_param.first, m_param.second);
	m_pVM->Fire_OnCommandComplete("avg_Result", true);
}