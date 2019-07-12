#include"HeatViewModel.h"

HeatViewModel::HeatViewModel() : 
	m_cmdCalc(std::make_shared<CalcCommand>(this)),
	m_cmdAvg(std::make_shared<AvgCommand>(this)),
	m_sink(std::make_shared<HeatViewModelSink>(this))
{

}

void HeatViewModel::SetModel(const std::shared_ptr<HeatDataModel>& model)
{
	m_HeatModel = model;
	m_HeatModel->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(m_sink));
}

std::shared_ptr<workboard> HeatViewModel::getResult() throw()
{
	return m_HeatModel->getResult();
}

std::shared_ptr<std::vector<double> > HeatViewModel::getAverage() throw()
{
	return m_HeatModel->getAverage();
}

std::shared_ptr<ICommandBase> HeatViewModel::getCalcCommand()
{
	return std::static_pointer_cast<ICommandBase>(m_cmdCalc);
}

std::shared_ptr<ICommandBase> HeatViewModel::getAvgCommand()
{
	return std::static_pointer_cast<ICommandBase>(m_cmdAvg);
}

bool HeatViewModel::Calculate(const workboardPass& para)
{
	return m_HeatModel->Calc(para);
}

bool HeatViewModel::CalcAvg(const pointParameters& p1, const pointParameters& p2)
{
	return m_HeatModel->CalcAvg(p1, p2);
}