#include "HeatViewModelSink.h"

#include "HeatViewModel.h"

HeatViewModelSink::HeatViewModelSink(HeatViewModel* p) throw() : m_pVM(p)
{

}

void HeatViewModelSink::OnPropertyChanged(const std::string& str)
{
	if (str == "heat_result") {
		m_pVM->SetWorkboard(m_pVM->GetModel().getResult());
		m_pVM->Fire_OnPropertyChanged(str);
	}
}