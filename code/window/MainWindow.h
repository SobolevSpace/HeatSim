#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QMainWindow>
#include <QSpinBox>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QObject>
#include <QPushButton>
#include <QToolBar> 
#include "../view/heatview.h"
#include "ui_MainWindow.h"
#include "sink/MainWindowPropertySink.h"
#include "sink/MainWindowCommandSink.h"
#include "../common/parameter.h"
#include "../view/myheader.h"
#include "../view/QtGuiClass.h"
#include "../view/CoordinateView.h"
#include "../view/InvironmentSetting.h"
class MainWindow : public QMainWindow
{
	Q_OBJECT

signals:
	void select_function(int function, int shape = LINE, QString path = QString());
public:
	void CreateActions();
	void CreateButtons();
	void CreateSpinBox();
	void closeEvent(QCloseEvent* event);
	bool saved;
	QString filename, filename2;
	QMenu *pMenu;
	QAction *Help, *Line, *Rectangle, *Ellipse, *Polygon, *Delete, *Picture, *Select, *Move, *RotateL, *RotateR, *Amplify, *Shrink, *Random, *Text;
	QAction *Generate,*Average;
	QToolBar *pToolBar;
	QAction *Property_Normal, *Property_HeatIsulation, *Property_HeatSource;
	QAction *Invironment;
	QSpinBox *SpinBoxPainterWidth, *SpinBoxPainterColorR, *SpinBoxPainterColorG, *SpinBoxPainterColorB;
	QDoubleSpinBox *SpinBoxTem;
	QtGuiClass *qt_gui_class;
	QSlider *pSliderColorR, *pSliderColorG, *pSliderColorB, *pSliderWidth;
	QAction *LineWidth, *LineColor;

private slots:
	void visualize_LineWidthChange();
	void visualize_ColorChange();
	void windowResize(int w, int h);

	void draw_line();
	void draw_random();
	void draw_rectangle();
	void draw_ellipse();
	void draw_polygon();
	void Delete_figure();
	void set_drawshape_to_Default();
	void set_drawshape_to_Move();
	void Amplify_figure();
	void Shrink_figure();
	void set_property_normal();
	void set_property_heatinsulation();
	void set_property_heatsource();
	void help();

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void init();
	void inInvironmentSettingview();
	void set_CalcCommand(const std::shared_ptr<ICommandBase>& cmd) throw();
	void set_AverageCommand(const std::shared_ptr<ICommandBase>& cmd)throw();
	std::shared_ptr<IPropertyNotification> get_PropertySink() throw();
	std::shared_ptr<ICommandNotification> get_CommandSink() throw();
	void Transport(CType type, double changeval);
	void askAverageTem();

	HeatView *view;
	CoordinateView *Coorview;
	InvironmentSetting *Settingview;
private:
	QTimer *m_timer;
	int count;
	void Updatewb();

	workboard initial_condition;


private:
	std::shared_ptr<ICommandBase> m_cmdCalc;
	std::shared_ptr<ICommandBase> m_cmdAverage;
	std::shared_ptr<MainWindowPropertySink> m_sinkProperty;
	std::shared_ptr<MainWindowCommandSink> m_sinkCommand;
public Q_SLOTS:
	void Generate_HeatView();
	void AverageTem_Coordinate();
	void TimerTimeOut();
	void InitTimer();
	
private Q_SLOTS:
	void RecieveTime(int val);
private Q_SLOTS:
	void ChangeTempAndAlpha(double T, double Alpha);
private:
	Ui_MainWindowClass *ui;

};

#endif // MAINWINDOW_H
