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
        painter.fillRect(QRect((i%size)*(this->frameGeometry().width()/size),(i/size)*((this->frameGeometry().height()-20)/size),
                       int(this->frameGeometry().width()/size*1) ,int((this->frameGeometry().height()-20)/size*1)),
                         QBrush(Get_Color(A[i/100][i%100].getTemperature())));
    }


}

void HeatView::set_Heatdim(const std::shared_ptr<workboard>& sp)
{
    m_Heatdim=sp;
}

QColor HeatView::Get_Color(double T)
{
	const int upper_bound = 373;
	const int lower_bound = 273;
	int r, g, b;
	double percent = (T + 273 - lower_bound) / (upper_bound - lower_bound + 1);
	int Tint = int(percent * 255 * 4 )% 255;
	if (percent < 0) {
		r = g = b = 0x00;
	}
	else if (percent > 1) {
		r = g = b = 0xff;
	}
	else {
		if (percent < 0.25) {
			r = 0x00;
			g = Tint;
			b = 0xFF;
		}
		else if (percent < 0.5) {
			r = 0x00;
			g = 0xFF;
			b = 255 - Tint;
		}
		else if (percent < 0.75) {
			r = Tint;
			g = 0xFF;
			b = 0x00;
		}
		else {
			r = 0xFF;
			g = 255 - Tint;
			b = 0x00;
		}
	}
	return QColor(r, g, b);
}



