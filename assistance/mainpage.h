#ifndef M_MIANWINDOW_H
#define M_MIANWINDOW_H

#include <DMainWindow>
#include <DToolButton>
#include <DLabel>
#include <DTitlebar>

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
    void setMainTitle(const QString &leftsideicon,const QString &rightsideicon);
private:
    Askforhelp *askForhelp;
    Tohelpothers *tohElpthers;
    QWidget *mainWidget;
    QStackedWidget *mainStackedWidget;
    DLabel *AssisLabelOne;
    DLabel *AssisLabelTwo;
    DToolButton *AssisPushButtonOne;
    DToolButton *AssisPushButtonTwo;
    DTitlebar *mainthis;
    DWidget *MainTitle;
    DLabel * LeftsideIcon;
    DLabel * RightsideIcon;
    QImage *image;

};

#endif // M_MIANWINDOW_H
