#include "UiMain.h"
#include "ui_UiMain.h"

#include "ChatForm.h"

#include <QFile>
#include <QDebug>
#include <QDir>

#define MY_TEST

UiMain::UiMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UiMain)
{

    // 隐藏标题栏
    //    setWindowFlags(Qt::CustomizeWindowHint);    // 可缩放窗口
    setWindowFlags(Qt::FramelessWindowHint);    // 不可缩放窗口

    setMouseTracking(true); // 开启鼠标移动事件捕获

    ui->setupUi(this);

    QFile file(":/style/style/style.css");
    if(file.open(QFile::ReadOnly))
    {
        this->setStyleSheet(file.readAll());
        file.close();
    }
    else
        qDebug() << "load UI qss failed!";

    init();
}

UiMain::~UiMain()
{
    delete ui;
}

void UiMain::init()
{
    // 连接点击信号
    QObject::connect(ui->chatList, &QListWidget::itemClicked, [&](QListWidgetItem *item) {
        QWidget *widget = ui->chatList->itemWidget(item);
        ChatForm *chatForm = qobject_cast<ChatForm *>(widget);
        if (chatForm) {
            UserInfo info = chatForm->getUserInfo();
            qDebug() << "Clicked on ChatForm for " << info.id << " with message: " << info.name;
            ui->label_titel->setText(info.name);
            if(info.id == 1)
                ui->pushButton_yylt->setVisible(false);
            else
                ui->pushButton_yylt->setVisible(true);
        }
    });

    // 设置按钮为图片，并设置图片显示大小
    ui->label_tx->setPixmap(QPixmap(":/img/tx.jpg").scaled(ui->label_tx->rect().size()));

//    ui->pushButton_close->setToolTip(QStringLiteral("关闭"));
//    ui->pushButton_max->setToolTip(QStringLiteral("最大化"));
//    ui->pushButton_min->setToolTip(QStringLiteral("最小化"));
//    ui->pushButton_tab->setToolTip(QStringLiteral("置顶"));

//    ui->pushButton_more->setToolTip(QStringLiteral("聊天信息"));

//    ui->pushButton_bq->setToolTip(QStringLiteral("表情"));
//    ui->pushButton_wj->setToolTip(QStringLiteral("文件"));
//    ui->pushButton_jt->setToolTip(QStringLiteral("截图"));
//    ui->pushButton_ltjl->setToolTip(QStringLiteral("聊天记录"));
//    ui->pushButton_yylt->setToolTip(QStringLiteral("语音聊天"));

//    ui->pushButton_1->setToolTip(QStringLiteral("聊天"));
//    ui->pushButton_2->setToolTip(QStringLiteral("通讯录"));
//    ui->pushButton_3->setToolTip(QStringLiteral("收藏"));
//    ui->pushButton_4->setToolTip(QStringLiteral("聊天文件"));
//    ui->pushButton_5->setToolTip(QStringLiteral("朋友圈"));
//    ui->pushButton_6->setToolTip(QStringLiteral("小程序面板"));
//    ui->pushButton_7->setToolTip(QStringLiteral("手机"));
//    ui->pushButton_8->setToolTip(QStringLiteral("设置及其他"));

//    ui->pushButton_send->setToolTip(QStringLiteral("发送"));
    qDebug() << "done";

#ifdef MY_TEST
    //    ui->chatList->setFocusPolicy(Qt::NoFocus);
    //    ui->chatList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ChatForm* t = new ChatForm();
    QListWidgetItem *item1 = new QListWidgetItem(ui->chatList);
    item1->setSizeHint(t->size());
    ui->chatList->setItemWidget(item1, t);

    ChatForm* t2 = new ChatForm();
    UserInfo info2;
    info2.id = 1;
    info2.name = QStringLiteral("文件传输助手");

    t2->setInfo(info2);
    t2->setTime("23/8/31");
    t2->setText("hello world!");
    QListWidgetItem *item2 = new QListWidgetItem(ui->chatList);
    item2->setSizeHint(t2->size());
    ui->chatList->setItemWidget(item2, t2);

#endif

}

const int TITLE_HEIGHT = 20;    // 拖拽区域距离顶部
void UiMain::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && event->pos().y() < TITLE_HEIGHT)
    {
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void UiMain::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton && event->pos().y() < TITLE_HEIGHT)
    {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}

void UiMain::on_pushButton_close_clicked()
{
    QApplication::quit();
}

void UiMain::on_pushButton_max_clicked()
{
    setWindowState(Qt::WindowMaximized);
}

void UiMain::on_pushButton_min_clicked()
{
    showMinimized();
}

void UiMain::on_pushButton_add_clicked()
{
    qDebug() << "add";
    ChatForm* t = new ChatForm();
    QListWidgetItem *item1 = new QListWidgetItem(ui->chatList);
    item1->setSizeHint(t->size());
    ui->chatList->setItemWidget(item1, t);
}
