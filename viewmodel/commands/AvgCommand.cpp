#include "AvgCommand.h"

AvgCommand::AvgCommand(HeatViewModel* p) throw() : m_pVM(p)
{

}

void AvgCommand::SetParameter(const std::any& param)
{
	m_param = std::any_cast<std::pair<int, int>>(param);
}

void AvgCommand::Exec()
{

}