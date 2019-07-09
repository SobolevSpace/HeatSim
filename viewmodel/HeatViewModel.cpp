#include"HeatViewModel.h"

HeatViewModel::HeatViewModel() : m_workboard(std::make_shared<workboard>())
	m_cmdQuery(std::make_shared<QueryCommand>(this))
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
	return m_workboard;
}

std::shared_ptr<ICommandBase> HeatViewModel::getQueryCommand()
{
	return std::static_pointer_cast<ICommandBase>(m_cmdQuery);
}

HeatDataModel& HeatViewModel::GetModel() throw()
{
	return *m_HeatModel;
}

void HeatViewModel::SetWorkboard(std::shared_ptr<workboard> board)
{

}

bool HeatViewModel::Query(workboardPass para)
{
	return m_HeatModel->Query(para);
}