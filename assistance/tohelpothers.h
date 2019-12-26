#ifndef TOHELPOTHERS_H
#define TOHELPOTHERS_H

#include <DPushButton>
#include <DLabel>
#include <DSpinner>

#include <QWidget>
#include <QLineEdit>
#include <QStackedWidget>

#include "askforhelp.h"

DWIDGET_USE_NAMESPACE
class Tohelpothers : public QWidget
{
    Q_OBJECT
public:
    explicit Tohelpothers(QWidget *parent = nullptr);

signals:
    void sendTomain();
    void sendTomaincancel();
    void sendTodisconnect();

public slots:
    QWidget* initUI();
    QWidget* connection();
    QWidget* connectflase();
    QWidget* connecttrue();
    void mainconnect();
    void getLineEdit();
    void mainycancel();
    void connecttype();
    void mainDisconnect();
    void newconnect();
private:
    QWidget *Tohwidget;
    QWidget *onnection;
    QWidget *connectf;
    QWidget *connectt;
    QLineEdit *LineEdit;
    DPushButton *PushButton;
    DPushButton *PushButtons;
    DLabel *Label;
    DLabel *labelk;
    DSpinner *spinner;
    QStackedWidget *askStackedWidget;
    Askforhelp *askfor;
    QString str;
    QString str1;
public:
    QTimer *Timer;

};

#endif // TOHELPOTHERS_H
