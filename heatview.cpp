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

}

HeatView::~HeatView()
{
    delete ui;
}
void HeatView::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    /////////////////////////////////////////////////
    srand((int)time(0));
    for(int i=0;i<120000;i++){
        painter.setPen(Get_Color(i%200));
        painter.fillRect(QRect((i%400)*(this->frameGeometry().width()/400),(i/400)*(this->frameGeometry().height()/300),
                       int(this->frameGeometry().width()/400*1) ,int(this->frameGeometry().height()/300*1)),
                         QBrush(Get_Color(rand()%256-55)));
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
QColor HeatView::Get_Color(double T)
{
    if(T>=200.0)return QColor(255,0,0);
    if(T<=-55.0)return QColor(0,0,255);
    return QColor( int(T+55.0),0,255-int(T+55.0) );
}
void HeatView::ButtonPressBackToMainWindow()
{

}

