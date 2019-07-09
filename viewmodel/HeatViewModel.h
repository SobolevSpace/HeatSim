#pragma once
#include "../others/ETL/include/etlbase.h"
#include "../model/HeatDataModel.h"
#include "HeatViewModelSink.h"

class HeatViewModel:public Proxy_PropertyNotification
	:public Proxy_CommandNotification
{
public:
	HeatViewModel();

	void SetModel(const std::shared_ptr<HeatDataModel>& model);

	std::shared_ptr<workboard> getResult() throw();

	std::shared_ptr<ICommandBase> getQueryCommand();

	HeatDataModel& GetModel() throw();

	void SetWorkboard(std::shared_ptr<workboard> board);
	bool Query(workboardPass para);

private:
	std::shared_ptr<HeatDataModel> m_HeatModel;

	std::shared_ptr<workboard> m_workboard;

	std::shared_ptr<QueryCommand> m_cmdQuery;

	std::shared_ptr<HeatViewModelSink> m_sink;
}