#pragma once

#include "../others/ETL/include/etlbase.h"

#include "../common/workboard.h"

class HeatViewModel;

class QueryCommand : public ICommandBase
{
public:
	QueryCommand(HeatViewModel *p) throw();

	virtual void SetParameter(const std::any& param);
	virtual void Exec();

private:
	HeatViewModel* m_pVM;

	workboardPass m_param;
};