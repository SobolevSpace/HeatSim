#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view=new HeatView;
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Generate_HeatView()
{
    //view=new HeatView;
    view->show();
    //this->hide();
    //connect(view,SIGNAL(ExitWin()),this,SLOT(show()));
}
void MainWindow::init()
{
    Set_Buttons();
}
void MainWindow::Set_Buttons()
{
     connect(ui->Button_GenHeatView, SIGNAL(clicked(bool)), this, SLOT(Generate_HeatView()));
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
