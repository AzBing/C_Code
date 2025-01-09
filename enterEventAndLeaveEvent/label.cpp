#include "label.h"
#include <QDebug>
Label::Label(QWidget* parent) : QLabel(parent)
{

}

void Label::enterEvent(QEvent *event)
{
    (void) event;
    qDebug() << "eventEvent";
}

void Label::leaveEvent(QEvent *event)
{
    (void) event;
    qDebug() << "leaveEvent";
}
