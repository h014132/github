#include <DPalette>

#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QApplication>
#include <QFile>
#include <QClipboard>

#include "askforhelp.h"

#define NUM_FIXEA  70

Askforhelp::Askforhelp(QWidget *parent) : QWidget(parent)
{
    initUI();
    Verification();
    Copysuccess();
    Timer = new  QTimer(this);
    Timer->setSingleShot(true);
    connect(Timer, &QTimer::timeout, this, &Askforhelp::generate);
    askStackedWidget = new  QStackedWidget(this);
    askStackedWidget->addWidget(askwidget);
    askStackedWidget->addWidget(erification);
    askStackedWidget->addWidget(opysuccess);
    askStackedWidget->setCurrentWidget(askwidget);
    QVBoxLayout *mainlayout = new QVBoxLayout;
    mainlayout->addWidget(askStackedWidget);
    setLayout(mainlayout);
}

QString Askforhelp::getString()
{
    return nullptr;
}

QWidget* Askforhelp::initUI()
{
    askwidget = new QWidget;
    spinner = new  DSpinner(askwidget);
    spinner->setFixedSize(35,35);
    spinner->start();

    LabelTwo = new DLabel(askwidget);
    LabelTwo->setText(tr("正在生成请求验证码，请稍后..."));
    LabelTwo->setFixedHeight(NUM_FIXEA);
    LabelTwo->setWordWrap(true);


    pushButton = new  DPushButton(askwidget);
    DPalette palette(pushButton->palette());
    palette.setBrush(DPalette::WindowText,QBrush(Qt::blue));
    pushButton->setPalette(palette);
    pushButton->setText(tr("取消"));
    pushButton->setFixedSize(140,33);
    connect(pushButton,&DPushButton::clicked,this,&Askforhelp::sendtomaincancel);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addStretch(0);
    mainLayout->addWidget(spinner,0,Qt::AlignCenter);
    mainLayout->addWidget(LabelTwo,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    mainLayout->addWidget(pushButton,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    askwidget->setLayout(mainLayout);
    return askwidget;
}

QWidget* Askforhelp::Verification()
{
    erification = new QWidget;
    LabelOnes = new DLabel(erification);

    LabelOnes->setText("");

  //  LabelOnes->setText(tr("%1").arg(rand));

   // str = QString::number(rand);
    //设置字号
    QFont Fontf;
    Fontf.setPointSize(30);
    Fontf.setLetterSpacing(QFont::AbsoluteSpacing,18);
    LabelOnes->setFont(Fontf);
//    qDebug()<<str;

    LabelOnes->setFixedHeight(NUM_FIXEA);

    LabelTwo = new DLabel(erification);
    LabelTwo->setText(tr("要开始共享您的桌面，"
                         "请将上面的验证码提供给协助您的人员，"
                         "他们输入验证码后，"
                         "您的共享会话会立即开始"));
    LabelTwo->setAlignment(Qt::AlignCenter);
    QFont Font;
    Font.setPointSize(8);
    LabelTwo->setFont(Font);
    LabelTwo->setWordWrap(true);
    LabelTwo->setEnabled(false);
    LabelTwo->setFixedHeight(NUM_FIXEA);


    pushButton = new  DPushButton(erification);
    pushButton->setText(tr("复制"));
    pushButton->setFixedSize(140,33);

    connect(pushButton,&DPushButton::clicked,this,&Askforhelp::copytrue);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addStretch(0);
    mainLayout->addWidget(LabelOnes,0,Qt::AlignCenter);
    mainLayout->addWidget(LabelTwo,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    mainLayout->addWidget(pushButton,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    erification->setLayout(mainLayout);
    return erification;
}

QWidget* Askforhelp::Copysuccess()
{
    opysuccess = new QWidget;
    LabelOne = new  DLabel(opysuccess);
    QFont Fontf;
    Fontf.setPointSize(18);
    LabelOne->setFont(Fontf);
    LabelOne->setText(tr("成功复制到粘贴板"));

    LabelTwo = new  DLabel(opysuccess);
    QFont Font;
    Font.setPointSize(8);
    LabelTwo->setFont(Font);
    LabelTwo->setEnabled(false);
    LabelTwo->setAlignment(Qt::AlignCenter);
    LabelTwo->setText(tr("正在等待连接，请稍后...\n"
                         "连接成功后，此界面会自动隐藏到任务栏"));


    pushButton = new  DPushButton(opysuccess);
    pushButton->setFixedSize(140,33);
    pushButton->setText(tr("返回"));
    connect(pushButton,&DPushButton::clicked,this,&Askforhelp::sendmain);

    QVBoxLayout *mainLayout = new  QVBoxLayout;
    mainLayout->addStretch(0);
    mainLayout->addWidget(LabelOne,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    mainLayout->addWidget(LabelTwo,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    mainLayout->addWidget(pushButton,0,Qt::AlignCenter);
    mainLayout->addStretch(0);
    opysuccess->setLayout(mainLayout);
    return opysuccess;
}

void Askforhelp::generate()
{
    if(Timer->isActive())
        Timer->stop();
    m_valifyCodeStr= setRandomNumber();
    LabelOnes->setText(m_valifyCodeStr);
    qDebug()<<"**********88"<<m_valifyCodeStr;
    askStackedWidget->setCurrentWidget(erification);
}

void Askforhelp::copytrue()
{
    QClipboard *clipboard = QApplication::clipboard();   //获取系统剪贴板指针
    QString originalText = LabelOnes->text();	     //获取剪贴板上文本信息
    clipboard->setText(originalText);
    qDebug()<<"originalText"<<originalText;
    askStackedWidget->setCurrentWidget(opysuccess);
}

void Askforhelp::sendmain()
{
    emit sendsignalmain();
    askStackedWidget->setCurrentWidget(askwidget);
}

void Askforhelp::sendtomaincancel()
{
    if(Timer->isActive())
         Timer->stop();
    emit sendtomain();
    askStackedWidget->setCurrentWidget(askwidget);
}

QString Askforhelp::setRandomNumber()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));          //设置随机数种子
    return QString::number(qrand() % (999999 - 100000)+100000); //产生十以内的随机数(0-9)
}

QString Askforhelp::getValifyCode()
{
    return m_valifyCodeStr;
}



