#ifndef HEATVIEW_H
#define HEATVIEW_H

#include <QWidget>
#include <QCloseEvent>
#include <memory>
#include "workboard.h"
#include "Ui_heatview.h"
//#include "others/ETL/include/etlbase.h"
namespace Ui {
class HeatView;
}

class HeatView : public QWidget
{
    Q_OBJECT
signals:
    void ExitWin();
public:
    explicit HeatView(QWidget *parent = 0);
    ~HeatView();
    void closeEvent(QCloseEvent*){
        emit ExitWin();
    }
    void paintEvent(QPaintEvent*);
    QColor Get_Color(double T);
    void set_Heatdim(const std::shared_ptr<workboard>& sp);
    void ButtonPressBackToMainWindow();
private:
    Ui_HeatView *ui;
    std::shared_ptr<workboard> m_Heatdim;
};

#endif // HEATVIEW_H
