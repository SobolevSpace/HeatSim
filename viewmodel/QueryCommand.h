#pragma once

#include "../others/ETL/include/etlbase.h"

#include "../common/workboard.h"

class HeatViewModel;

class InitCondiCommand : public ICommandBase
{
public:
	InitCondiCommand(HeatViewModel *p) throw();

	virtual void SetParameter(const std::any& param);
	virtual void Exec();

private:
	HeatViewModel* m_pVM;

	newpara m_param;
};