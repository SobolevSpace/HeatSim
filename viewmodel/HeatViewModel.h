#pragma once
#include "../others/ETL/include/etlbase.h"
#include "../model/HeatDataModel.h"

class HeatViewModel:public Proxy_PropertyNotification
	:public Proxy_CommandNotification
{
public:
	



	void SetWorkboard(std::shared_ptr<workboard> board);


private:
	std::shared_ptr<workboard> m_workboard;
}