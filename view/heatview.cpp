#include "heatview.h"
#include "ui_heatview.h"
#include <QPainter>
#include <cstdlib>
#include <ctime>
HeatView::HeatView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui_HeatView)
{
    ui->setupUi(this);
    setWindowTitle("HeatView");
	init();
}

HeatView::~HeatView()
{
    delete ui;
}

void HeatView::init()
{
	connect(ui->SliderSelectTime, SIGNAL(valueChanged(int)),this, SLOT(ChangeTime()));
}

void HeatView::ChangeTime() {
	//update();
	emit SendTime(ui->SliderSelectTime->value());
}

void HeatView::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
	//int size = m_Heatdim->getSize();
	int size = 100;
	this->resize(size * 4, size * 4+20);
	std::vector<std::vector<point> > A;
	m_Heatdim->getPointMat(A);
    /////////////////////////////////////////////////
    srand((int)time(0));
    for(int i=0;i<size*size;i++){
        //painter.setPen(Get_Color(i%200));
        painter.fillRect(QRect((i%size)*(this->frameGeometry().width()/size),(i/size)*((this->frameGeometry().height()-20)/size),
                       int(this->frameGeometry().width()/size*1) ,int((this->frameGeometry().height()-20)/size*1)),
                         QBrush(Get_Color(A[i/100][i%100].getTemperature())));
    }

    /*painter.fillRect(QRect(0,this->frameGeometry().height()/2,
        this->frameGeometry().width()/2,this->frameGeometry().height()/2  ),
           QBrush(Get_Color(200.0)));
    painter.fillRect(QRect(0,0,this->frameGeometry().width(),this->frameGeometry().height() ),QBrush(Get_Color(-55.0)));
*/
//painter.setPen(QColor(0, 160, 230));

}

void HeatView::set_Heatdim(const std::shared_ptr<workboard>& sp)
{
    m_Heatdim=sp;
}

//
QColor HeatView::Get_Color(double T)
{
	const int upper_bound = 511;
	const int lower_bound = 0;
	int Tint = int(T);
//	Tint += 273;
    if(T>=upper_bound)return QColor(255,255,255);
    if(T<=lower_bound)return QColor(0,0,0);
    return QColor(Tint*10 ,Tint*10, Tint*10 );
}



