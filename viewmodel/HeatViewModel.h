 #pragma once
#include "etlbase.h"
#include "../common/parameter.h"
#include "../model/HeatDataModel.h"
#include "./sinks/HeatViewModelSink.h"
#include "./commands/AvgCommand.h"
#include "./commands/CalcCommand.h"

class HeatViewModel : public Proxy_PropertyNotification<HeatViewModel>,
	public Proxy_CommandNotification<HeatViewModel>
{
public:
	HeatViewModel();

	void SetModel(const std::shared_ptr<HeatDataModel>& model);

	std::shared_ptr<workboard> getResult() throw();
	std::shared_ptr<std::vector<double> > getAverage() throw();

	std::shared_ptr<ICommandBase> getCalcCommand();
	std::shared_ptr<ICommandBase> getAvgCommand();

	bool Calculate(const workboardPass& para);
	bool CalcAvg(const pointParameters& p1, const pointParameters& p2);

private:
	std::shared_ptr<HeatDataModel> m_HeatModel;

	std::shared_ptr<CalcCommand> m_cmdCalc;

	std::shared_ptr<AvgCommand> m_cmdAvg;

	std::shared_ptr<HeatViewModelSink> m_sink;

};