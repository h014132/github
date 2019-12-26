#include <DPalette>

#include <QVBoxLayout>
#include <QPixmap>
#include <QDebug>
#include <QAction>

#include "mainpage.h"

#define NUM_FIXEA  70
#define NUM_FIXEB 140
#define NUM_FIXEC  33

Mainpage::Mainpage(QWidget *parent) : DMainWindow(parent)
{
    mainWidget = new QWidget;
    askForhelp = new Askforhelp;
    tohElpthers = new Tohelpothers;
    initUI();
    mainStackedWidget = new  QStackedWidget(this);
    mainStackedWidget->addWidget(mainWidget);
    mainStackedWidget->addWidget(askForhelp);
    mainStackedWidget->addWidget(tohElpthers);
    mainStackedWidget->setCurrentWidget(mainWidget);
    setCentralWidget(mainStackedWidget);

    connect(AssisPushButtonOne,&DToolButton::clicked,this,&Mainpage::Forhelp);
    connect(AssisPushButtonTwo,&DToolButton::clicked,this,&Mainpage::helpothers);
    connect(askForhelp,&Askforhelp::sendsignalmain,this,&Mainpage::returnmain);
    connect(askForhelp,&Askforhelp::sendtomain,this,&Mainpage::askcancel);
    connect(tohElpthers,&Tohelpothers::sendTomain,this,&Mainpage::tohcancel);
    connect(tohElpthers,&Tohelpothers::sendTomaincancel,this,&Mainpage::tohTcancel);
    connect(tohElpthers,&Tohelpothers::sendTodisconnect,this,&Mainpage::tohTdisconnect);
}

void Mainpage::initUI()
{
    AssisLabelOne = new DLabel(mainWidget);
    QPixmap Pixmap("://assisa.jpg");
    DPalette palettea(AssisLabelOne->palette());
    palettea.setBrush(DPalette::Background,QBrush(Pixmap));
    AssisLabelOne->setPalette(palettea);
    AssisLabelOne->setAutoFillBackground(true);
    Pixmap.scaled(AssisLabelOne->size());
    AssisLabelOne->setScaledContents(true);
    AssisLabelOne->setPixmap(Pixmap);
    AssisLabelOne->setFixedWidth(NUM_FIXEA);
    AssisLabelOne->setFixedHeight(NUM_FIXEA);

    AssisLabelTwo = new DLabel(mainWidget);
    AssisLabelTwo->setFixedWidth(260);
    AssisLabelTwo->setFixedHeight(NUM_FIXEA);
    //设置字号
    QFont Font;
    Font.setPointSize(8);
    AssisLabelTwo->setFont(Font);

    //设置颜色
//    DPalette Paletteb;
//    Paletteb.setColor(QPalette::WindowText,Qt::red);
//    AssisLabelTwo->setPalette(Paletteb);
    AssisLabelTwo->setWordWrap(true);
    AssisLabelTwo->setEnabled(false);
    AssisLabelTwo->setText(tr("这是由deepin团队开发的远程协助应用，如果您在使用过程中遇到了困难，或者有人求助于你，请点击下方的我要求助或帮助别人."));
    AssisLabelTwo->setAlignment(Qt::AlignCenter);

    AssisPushButtonOne = new DToolButton(mainWidget);
    QAction *pAction = new QAction(this);
    pAction->setText(QString::fromLocal8Bit("我要求助"));
    pAction->setIcon(QIcon("://assisb.svg"));
    AssisPushButtonOne->setIconSize(QSize());
    AssisPushButtonOne->setDefaultAction(pAction);
    AssisPushButtonOne->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    AssisPushButtonOne->setFixedSize(NUM_FIXEB,NUM_FIXEC);

    AssisPushButtonTwo = new DToolButton(mainWidget);
    QAction *pActioni = new QAction(this);
    pActioni->setText(QString::fromLocal8Bit("帮助别人"));
    pActioni->setIcon(QIcon("://assisc.svg"));
    AssisPushButtonTwo->setIconSize(QSize());
    AssisPushButtonTwo->setDefaultAction(pActioni);
    AssisPushButtonTwo->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    AssisPushButtonTwo->setFixedSize(NUM_FIXEB,NUM_FIXEC);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addStretch(0);
    mainLayout->addWidget(AssisLabelOne,0,Qt::AlignHCenter);
    mainLayout->addStretch(0);
    mainLayout->addWidget(AssisLabelTwo,0,Qt::AlignHCenter);
    mainLayout->addStretch(0);
    mainLayout->addWidget(AssisPushButtonOne,0,Qt::AlignHCenter);
    mainLayout->addWidget(AssisPushButtonTwo,0,Qt::AlignHCenter);
    mainLayout->addStretch(10);
    mainWidget->setLayout(mainLayout);
}

void Mainpage::Forhelp()
{
    mainStackedWidget->setCurrentWidget(askForhelp);
    askForhelp->Timer->start(2000);
}

void Mainpage::helpothers()
{
    mainStackedWidget->setCurrentWidget(tohElpthers);
}

void Mainpage::returnmain()
{
    mainStackedWidget->setCurrentWidget(mainWidget);
}

void Mainpage::askcancel()
{
    mainStackedWidget->setCurrentWidget(mainWidget);
}

void Mainpage::tohcancel()
{
    mainStackedWidget->setCurrentWidget(mainWidget);
}

void Mainpage::tohTcancel()
{
    mainStackedWidget->setCurrentWidget(mainWidget);
}

void Mainpage::tohTdisconnect()
{
    mainStackedWidget->setCurrentWidget(mainWidget);
}

