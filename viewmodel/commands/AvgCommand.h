#pragma once

#include "etlbase.h"
#include "../../common/parameter.h"
#include <utility>

class HeatViewModel;

class AvgCommand : public ICommandBase
{
public:
	AvgCommand(HeatViewModel* p) throw();

	virtual void SetParameter(const std::any& param);
	virtual void Exec();

private:
	HeatViewModel * m_pVM;

	std::pair<pointParameters, pointParameters> m_param;
};