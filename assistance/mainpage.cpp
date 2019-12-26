#include <DPalette>

#include <QVBoxLayout>
#include <QPixmap>
#include <QDebug>
#include <QAction>
#include <QTime>

#include "mainpage.h"

#define NUM_FIXEA  70
#define NUM_FIXEB 140
#define NUM_FIXEC  33

Mainpage::Mainpage(QWidget *parent) : DMainWindow(parent)
{
    MainTitle = nullptr;
    mainthis= this->titlebar();
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
    QPixmap Pixmap("://assisd.png");
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

    AssisLabelTwo->setWordWrap(true);
    AssisLabelTwo->setEnabled(false);
    AssisLabelTwo->setText(tr("这是由deepin团队开发的远程协助应用，"
                              "如果您在使用过程中遇到了困难，或者有人求助于你，"
                              ""
                              "请点击下方的我要求助或帮助别人."));
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
    setMainTitle("://assisb.svg", tr("我要求助"));
}

void Mainpage::helpothers()
{
    mainStackedWidget->setCurrentWidget(tohElpthers);
    qDebug()<<"askforhelp"<<askForhelp->getValifyCode();
    tohElpthers->getRandomNumber(askForhelp->getValifyCode());
  //  qDebug()<<"*****"<<askForhelp->setRandomNumber();
    setMainTitle("://assisc.svg", "帮助别人");
}

void Mainpage::returnmain()
{
    mainStackedWidget->setCurrentWidget(mainWidget);
    setMainTitle(nullptr, "远程协助");

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

void Mainpage::setMainTitle(const QString &leftsideicon, const QString &rightsideicon)
{
    image = new QImage;
    LeftsideIcon=new DLabel(this);
    LeftsideIcon->setPixmap(QPixmap::fromImage(*image));
    LeftsideIcon->setScaledContents(true);
    LeftsideIcon->setFixedSize(18,18);

    RightsideIcon=new DLabel(this);

    QHBoxLayout* myLayout = new QHBoxLayout();
    myLayout->addStretch(0);
    myLayout->addWidget(LeftsideIcon,0,Qt::AlignCenter);
    myLayout->addWidget(RightsideIcon,0,Qt::AlignCenter);

    MainTitle= new DWidget(this);
    MainTitle->setLayout(myLayout);
    mainthis->setCustomWidget(MainTitle);

    LeftsideIcon->setPixmap(QPixmap(leftsideicon));
    RightsideIcon->setText(rightsideicon);
}



