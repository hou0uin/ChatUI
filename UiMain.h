#ifndef UIMAIN_H
#define UIMAIN_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class UiMain;
}

class UiMain : public QWidget
{
    Q_OBJECT

public:
    explicit UiMain(QWidget *parent = nullptr);
    ~UiMain();

    void init();

private slots:
    //鼠标按下
    void mousePressEvent(QMouseEvent* event);
    //鼠标移动
    void mouseMoveEvent(QMouseEvent* event);

    void on_pushButton_close_clicked();

    void on_pushButton_max_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_add_clicked();

private:
    Ui::UiMain *ui;

    QPoint m_dragPosition; // 记录鼠标点击时的位置
};

#endif // UIMAIN_H
