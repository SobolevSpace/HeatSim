#include "precomp.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui_MainWindowClass)
{
	ui->setupUi(this);
	view = new HeatView;
	init();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::init()
{
	Set_Buttons();
	count = 0;
	m_timer = new QTimer(this);
	//定时器触发信号槽
	connect(m_timer, SIGNAL(timeout()), this, SLOT(TimerTimeOut()));
}

void MainWindow::Generate_HeatView()
{
	view->show();
	InitTimer();
	
	//view->resize(100, 100);
	//m_cmdQuery->SetParameter();
	//m_cmdQuery->Exec();

	//this->hide();
	//connect(view,SIGNAL(ExitWin()),this,SLOT(show()));
}

void MainWindow::Set_Buttons()
{
	connect(ui->Button_GenHeatView, SIGNAL(clicked(bool)), this, SLOT(Generate_HeatView()));
	//connect(ui->actionGenerate, SIGNAL(triggered()), this, SLOT(Generate_HeatView()));
}

void MainWindow::set_QueryCommand(const std::shared_ptr<ICommandBase>& cmd) throw()
{
	m_cmdQuery = cmd;
}

std::shared_ptr<IPropertyNotification> MainWindow::get_PropertySink() throw()
{
	return std::static_pointer_cast<IPropertyNotification>(m_sinkProperty);
}

std::shared_ptr<ICommandNotification> MainWindow::get_CommandSink() throw()
{
	return std::static_pointer_cast<ICommandNotification>(m_sinkCommand);
}

void MainWindow::InitTimer()
{

	count = 0;
	m_timer->start(50);

}

void MainWindow::TimerTimeOut()
{
	if (count == 400) {
		m_timer->stop();
		return;
	}
	count++;
	ui->labelCount->setText(QString::number(count));
	//std::any param(std::make_any<workboardPass>());
	//workboardPass& wbp = std::any_cast<workboardPass&>(param);
	//wbp.setChangeType(TIME);
	//wbp.setChangeValue(count*0.05);
	//wbp.setWorkBoard(initial_condition);
	//m_cmdQuery->SetParameter(param);
	//m_cmdQuery->Exec();
	view->update();
}
