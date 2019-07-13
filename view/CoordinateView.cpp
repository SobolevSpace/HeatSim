#include "CoordinateView.h"

CoordinateView::CoordinateView(QWidget *parent)
	: QWidget(parent),O(QPoint(35,280))
{
	ui.setupUi(this);
	image = new QImage(600, 300, QImage::Format_RGB32); 
	QColor backColor = qRgb(255, 255, 255);    
	image->fill(backColor);
}

CoordinateView::~CoordinateView()
{
}

void CoordinateView::set_AverageData(const std::shared_ptr<std::vector<double>> sp)
{
	AverageData = sp;
}

void CoordinateView::Paint()
{
	delete image;
	image = new QImage(600, 300, QImage::Format_RGB32);
	QPainter painter(image);
	painter.setRenderHint(QPainter::Antialiasing, true);//���÷����ģʽ
	width = 580 - O.x(), height = 260;
	painter.drawRect(5, 5, 600 - 10, 300 - 10);//��Χ�ľ��Σ���(5,5)�𣬵�(590,290)��������Χ����5�ļ�϶��
	painter.drawLine(O.x(), O.y(), width + O.x(), O.y());//������x���Ϊwidth
	painter.drawLine(O.x(), O.y() - height, O.x(), O.y());//������y�߶�Ϊheight

	const int n = 400;
	double _ma = 0;
	double _mi = 99999.9;
	int maxpos = 0, minpos = 0;
	for (int i = 0;i < n;i++)
	{
		if ((*AverageData)[i] > _ma) {
			_ma = (*AverageData)[i];
			maxpos = i;
		}
		if ((*AverageData)[i] < _mi) {
			_mi = (*AverageData)[i];
			minpos = i;
		}
	}


	double kx = (double)width / (n - 1);//x���ϵ��
	if(_ma-_mi<=10){
		_ma = _ma + 10;
		_mi = _mi - 10;
	}
	double ky = (double)height / (_ma - _mi);//y����ı���ϵ��

	QPen pen, penPoint;
	pen.setColor(Qt::black);
	pen.setWidth(2);
	penPoint.setColor(Qt::blue);
	penPoint.setWidth(5);

	for (int i = 0;i < n - 1;i++)
	{
		painter.setPen(pen);
		painter.drawLine(O.x() + kx * i, O.y() - ((*AverageData)[i] - _mi) * ky, 
			O.x() + kx * (i + 1), O.y() - ((*AverageData)[i + 1] - _mi) * ky);
		painter.setPen(penPoint);
		painter.drawPoint(O.x() + kx * i, O.y() - ((*AverageData)[i] - _mi) * ky);
	}
	painter.drawPoint(O.x() + kx * (n - 1), O.y() - ((*AverageData)[n - 1]-_mi) * ky);

	//���ƿ̶���
	QPen penDegree;
	penDegree.setColor(Qt::black);
	penDegree.setWidth(2);
	painter.setPen(penDegree);

	//x��̶���
	for (int i = 0;i < 10;i++)//�ֳ�10��
	{
		painter.drawLine(O.x() + (i + 1)*width / 10, O.y(), O.x() + (i + 1)*width / 10, O.y() + 4);
		painter.drawText(O.x() + (i + 0.65)*width / 10,
			O.y() + 10, QString::number(((i + 1)*((double)n / 10))*0.05));
	}
	painter.drawText(O.x()+width-20, O.y()-5, QString("t/sec"));

	//y��̶���
	double _maStep = (double)(_ma - _mi) / 10;
	for (int i = 0;i < 10;i++)
	{
		painter.drawLine(O.x(), O.y() - (i + 1)*height / 10,
			O.x() - 4, O.y() - (i + 1)*height / 10);
		painter.drawText(O.x() - 30, O.y() - (i + 0.85)*height / 10,
			QString::number(   double(int(((_maStep*(i + 1))+_mi)*10))/10     ));
	}
	painter.drawText(O.x(), O.y()-height, QString("T/Celsius"));


}

void CoordinateView::Update() {
	show();
	Paint();
}