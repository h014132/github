#ifndef ASKFORHELP_H
#define ASKFORHELP_H

#include <QWidget>
#include <DLabel>
#include <DPushButton>
#include <QStackedWidget>
#include <DSpinner>

DWIDGET_USE_NAMESPACE

class Askforhelp : public QWidget
{
    Q_OBJECT
public:
    explicit Askforhelp(QWidget *parent = nullptr);
    QString getnumber();

signals:
    void sendsignalmain();
    void sendtomain();

public slots:
    QWidget* initUI();
    QWidget* Verification();
    QWidget* Copysuccess();
    void generate();
    void copytrue();
    void sendmain();
    void sendtomaincancel();
private:
    QWidget *askwidget;
    QWidget *erification;
    QWidget *opysuccess;
    QStackedWidget *askStackedWidget;
    DLabel *LabelOne;
    DLabel *LabelOnes;
    DLabel *LabelTwo;
    DPushButton *pushButton;
    DSpinner *spinner;
    QString str;
public:
    QTimer *Timer;

};

#endif // ASKFORHELP_H
