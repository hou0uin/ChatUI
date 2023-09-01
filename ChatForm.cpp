#include "ChatForm.h"
#include "ui_ChatForm.h"

#include <QDebug>
#include <QFile>
#include <QWidget>

ChatForm::ChatForm(QWidget *parent) :
    ui(new Ui::ChatForm)
{
    init();
}
ChatForm::ChatForm(UserInfo info, QWidget *parent) :
    m_info(info),
    ui(new Ui::ChatForm)
{
    init();
}

ChatForm::~ChatForm()
{
    delete ui;
}

void ChatForm::init()
{
    ui->setupUi(this);

    QFile file(":/style/style/style.css");
    if(file.open(QFile::ReadOnly))
    {
        this->setStyleSheet(file.readAll());
        file.close();
    }
    else
        qDebug() << "load qss failed!";

    setInfo(m_info);

    qDebug() << "ChatForm done";
}

void ChatForm::setInfo(const UserInfo& info)
{
    m_info = info;
    if(m_info.id == -1) // 默认
    {
        setIcon(QPixmap(":/img/chat_def.png"));
        setText("abcdefgNULL");
        setTime("8:00");
    }
    else
    {
        QString path = QString(":/img/chat_%1.png").arg(m_info.id);
        setIcon(QPixmap(path));
    }
    setTitle(m_info.name);
}

void ChatForm::setTitle(const QString& title)
{
    ui->title->setText(title);
}

void ChatForm::setIcon(const QPixmap& image)
{
    ui->icon->setPixmap(image.scaled(ui->icon->rect().size()));
}

void ChatForm::setText(const QString& text)
{
    ui->text->setText(text);
}

void ChatForm::setTime(const QString& time)
{
    ui->time->setText(time);
}

UserInfo ChatForm::getUserInfo()
{
    return m_info;
}


