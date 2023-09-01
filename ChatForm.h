#ifndef CHATFORM_H
#define CHATFORM_H

#include <QWidget>
#include <QPushButton>

#include "Public.h"

namespace Ui {
class ChatForm;
}

class ChatForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChatForm(QWidget *parent = nullptr);
    ChatForm(UserInfo info, QWidget *parent = nullptr);
    ~ChatForm();
    void init();

    void setInfo(const UserInfo& info);
    void setTitle(const QString& title);
    void setIcon(const QPixmap& image);
    void setText(const QString& text);
    void setTime(const QString& time);

    UserInfo getUserInfo();

    QString getTitle();

private:
    Ui::ChatForm *ui;

    UserInfo m_info;
};

#endif // CHATFORM_H
