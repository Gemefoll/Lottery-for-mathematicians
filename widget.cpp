#include "widget.h"
#include "ui_widget.h"
#include <qprocess.h>
#include <QStringList>
#include <QFile>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

bool is_win(QString s) {
    QProcess *p = new QProcess(nullptr);
    QStringList arg;
    p->start("../../target/release/untitled2", arg);
    if (!p->waitForStarted())
        return false;
    p->write(s.toStdString().data());
    p->closeWriteChannel();

    if (!p->waitForFinished()) {
        return false;
    }
    QByteArray result = p->readAll();
    std::string a = result.toStdString();
    // std::cout << a << std::endl;
    return !(a == "1\n" || a == "2\n" || a == "4\n");
}

bool is_number(QString s) {
    for (QChar c: s) {
        if (c <= '0' || c >= '9') {
            return false;
        }
    }
    return true;
}

void Widget::on_pushButton_clicked()
{
    QString s = Widget::ui->plainTextEdit->toPlainText().trimmed();
    if (!is_number(s)) {
        Widget::ui->label->setText("Введите натуральное число");
        return;
    }
    if (is_win(s)) {
        Widget::ui->label->setText("Вы выиграли!");
    } else {
        Widget::ui->label->setText("Вы проиграли, попробуйте снова!");
    }
}

