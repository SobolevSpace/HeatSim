#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QMainWindow>
#include "heatview.h"
#include "ui_MainWindow.h"
#include "MainWindowPropertySink.h"
#include "MainWindowCommandSink.h"


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void init();
	void Set_Buttons();
	void set_QueryCommand(const std::shared_ptr<ICommandBase>& cmd) throw();
	std::shared_ptr<IPropertyNotification> get_PropertySink() throw();
	std::shared_ptr<ICommandNotification> get_CommandSink() throw();

	HeatView *view;

private:
	QTimer *m_timer;
	int count;
	void InitTimer();
///////////////////////
	workboard initial_condition;
//////////////////////

private:
	std::shared_ptr<ICommandBase> m_cmdQuery;
	std::shared_ptr<MainWindowPropertySink> m_sinkProperty;
	std::shared_ptr<MainWindowCommandSink> m_sinkCommand;
public Q_SLOTS:
	void Generate_HeatView();
	void TimerTimeOut();

private:
	Ui_MainWindowClass *ui;

};

#endif // MAINWINDOW_H