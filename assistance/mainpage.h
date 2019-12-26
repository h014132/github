#ifndef M_MIANWINDOW_H
#define M_MIANWINDOW_H

#include <DMainWindow>
#include <DToolButton>
#include <DLabel>

#include <QStackedWidget>
#include <QWidget>
#include <QTimer>

#include "askforhelp.h"
#include "tohelpothers.h"


DWIDGET_USE_NAMESPACE
class Mainpage : public DMainWindow
{
    Q_OBJECT
public:
    explicit Mainpage(QWidget *parent = nullptr);

signals:

public slots:
    void initUI();
    void Forhelp();
    void helpothers();
    void returnmain();
    void askcancel();
    void tohcancel();
    void tohTcancel();
    void tohTdisconnect();
private:
    Askforhelp *askForhelp;
    Tohelpothers *tohElpthers;
    QWidget *mainWidget;
    QStackedWidget *mainStackedWidget;
    DLabel *AssisLabelOne;
    DLabel *AssisLabelTwo;
    DToolButton *AssisPushButtonOne;
    DToolButton *AssisPushButtonTwo;
};

#endif // M_MIANWINDOW_H
