#include <DPalette>

#include <QVBoxLayout>
#include <QIntValidator>
#include <QDebug>
#include <QTimer>

#include "tohelpothers.h"

Tohelpothers::Tohelpothers(QWidget *parent) : QWidget(parent)
{
    askfor = new Askforhelp;

    initUI();
    connection();
    connectflase();
    connecttrue();
    askStackedWidget = new  QStackedWidget(this);
    askStackedWidget->addWidget(Tohwidget);
    askStackedWidget->addWidget(onnection);
    askStackedWidget->addWidget(connectf);
    askStackedWidget->addWidget(connectt);
    askStackedWidget->setCurrentWidget(Tohwidget);
    QVBoxLayout *mainlayout = new QVBoxLayout;
    mainlayout->addWidget(askStackedWidget);
    setLayout(mainlayout);
}

QWidget* Tohelpothers::initUI()
{
    Tohwidget = new QWidget;
    LineEdit = new  QLineEdit(Tohwidget);
    LineEdit->setFixedSize(320,50);
    QFont Fontf;
    Fontf.setPointSize(30);
    Fontf.setLetterSpacing(QFont::AbsoluteSpacing,18);
    LineEdit->setFont(Fontf);
    LineEdit->setAlignment(Qt::AlignCenter);

    QIntValidator *validator = new QIntValidator(0, 999999, this);

    LineEdit->setValidator(validator);
    connect(LineEdit,&QLineEdit::textChanged,this,&Tohelpothers::getLineEdit);
    Label = new  DLabel(Tohwidget);

    Label->setText(tr("请在上方输入你想帮助的人提供给你的验证码，完成后点击连接开始协助对方"));
    Label->setFixedHeight(70);
    QFont Font;
    Font.setPointSize(8);
    Label->setFont(Font);
    //设置颜色
    DPalette Paletteb;
    Paletteb.setColor(QPalette::WindowText,Qt::red);
    Label->setPalette(Paletteb);
    Label->setWordWrap(true);
    PushButtons = new DPushButton(Tohwidget);
    PushButtons->setText(tr("取消"));
    PushButtons->setFixedSize(140,33);
    connect(PushButtons,&DPushButton::clicked,this,&Tohelpothers::mainconnect);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addStretch(0);
    mainLayout->addWidget(LineEdit,0,Qt::AlignCenter);
    mainLayout->addWidget(Label,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    mainLayout->addWidget(PushButtons,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
   // setLayout(mainLayout);
    Tohwidget->setLayout(mainLayout);
    return Tohwidget;
}

QWidget *Tohelpothers::connection()
{
    onnection = new  QWidget;
    spinner = new  DSpinner(onnection);
    spinner->setFixedSize(35,35);
    spinner->start();

    labelk = new  DLabel(onnection);
    labelk->setText(tr("正在建立连接，请稍侯..."));
    Timer = new  QTimer(this);
    Timer->setSingleShot(true);
    connect(Timer, &QTimer::timeout, this, &Tohelpothers::connecttype);

    PushButton = new  QPushButton(onnection);
    PushButton->setText(tr("取消"));
    PushButton->setFixedSize(140,33);
    connect(PushButton,&QPushButton::clicked,this,&Tohelpothers::mainycancel);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addStretch(0);
    mainLayout->addWidget(spinner,0,Qt::AlignCenter);
    mainLayout->addWidget(labelk,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    mainLayout->addWidget(PushButton,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    onnection->setLayout(mainLayout);
    return onnection;
}

QWidget *Tohelpothers::connectflase()
{
    connectf = new QWidget;
    Label = new DLabel(connectf);
    DPalette Paletteb;
    Paletteb.setColor(QPalette::WindowText,Qt::green);
    Label->setPalette(Paletteb);
    Label->setWordWrap(true);
    Label->setText(tr("连接失败"));

    labelk = new  DLabel(connectf);
    labelk->setText(tr("网络连接状态不是很稳定，点击重试按钮再次尝试连接"));
    PushButton = new QPushButton(connectf);
    PushButton->setText(tr("重试"));
    connect(PushButton,&QPushButton::clicked,this,&Tohelpothers::newconnect);

    QVBoxLayout *mainLayout = new  QVBoxLayout;
    mainLayout->addStretch(0);
    mainLayout->addWidget(Label,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    mainLayout->addWidget(labelk,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    mainLayout->addWidget(PushButton,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    connectf->setLayout(mainLayout);
    return connectf;
}

QWidget *Tohelpothers::connecttrue()
{
    connectt = new  QWidget;
    Label = new DLabel(connectt);
    QFont Fontf;
    Fontf.setPointSize(10);
    Label->setFont(Fontf);
    Label->setText(tr("你正在进行远程协助"));

    labelk = new  DLabel(connectt);
    labelk->setText(tr("当前已经有一个连接会话，如果您想建立新的连接，请先断开"));
    PushButton = new QPushButton(connectt);
    PushButton->setText(tr("断开"));
    connect(PushButton,&QPushButton::clicked,this,&Tohelpothers::mainDisconnect);
    QVBoxLayout *mainLayout = new  QVBoxLayout;
    mainLayout->addStretch(0);
    mainLayout->addWidget(Label,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    mainLayout->addWidget(labelk,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    mainLayout->addWidget(PushButton,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    connectt->setLayout(mainLayout);
    return connectt;

}



void Tohelpothers::mainconnect()
{
    QString str2 = PushButtons->text();
    if(str2 == "取消" ){
         emit sendTomain();
    }else if (str2 == "连接") {
         askStackedWidget->setCurrentWidget(onnection);
    }
    Timer->start(5000);
}

void Tohelpothers::getLineEdit()
{
    PushButtons->setText("取消");
    str1 = askfor->getnumber();
    str  = LineEdit->text();
    if(LineEdit->text().count() == 6){
        PushButtons->setText("连接");
    }
}

void Tohelpothers::mainycancel()
{
    emit sendTomaincancel();
    askStackedWidget->setCurrentWidget(Tohwidget);
}

void Tohelpothers::connecttype()
{
    if(str == str1){
        askStackedWidget->setCurrentWidget(connectt);
    }else {
        askStackedWidget->setCurrentWidget(connectf);
    }
    qDebug() << str << str1;
}

void Tohelpothers::mainDisconnect()
{
    emit sendTodisconnect();
    askStackedWidget->setCurrentWidget(Tohwidget);
}

void Tohelpothers::newconnect()
{
     askStackedWidget->setCurrentWidget(onnection);
}

