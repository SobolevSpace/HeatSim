#include "precomp.h"

#include "MainWindowPropertySink.h"

#include "MainWindow.h"

MainWindowPropertySink::MainWindowPropertySink(MainWindow* pW) throw() : m_pW(pW)
{
}

void MainWindowPropertySink::OnPropertyChanged(const std::string& str)
{
    if( str == "view update" ) {
        m_pW->view->update();
    }

}
