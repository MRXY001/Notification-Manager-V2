#ifndef TIPBOXWIDGET_H
#define TIPBOXWIDGET_H

#include <QObject>
#include <QWidget>
#include <QList>
#include <QTimer>
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
#include <QPainterPath>
#include <QPropertyAnimation>
#include "tipcard.h"

#define CARDS_INTERVAL 10
#define MARGIN_PARENT_RIGHT 20
#define MARGIN_PARENT_BOTTOM 10
#define CARD_FIXED_WIDTH 200

class TipWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TipWidget(QWidget *parent);
    TipCard* createTipCard(QString key, QString title, QString content);
    TipCard* createTipCard(QString key, QString title, QString content, QString btn1);
    TipCard* createTipCard(QString key, QString title, QString content, QString btn1, QString btn2);


protected:
    void paintEvent(QPaintEvent* event);

private:
    void setAddedAnimation();
    int getCardHeight(int index);

signals:
    void signalCardClosed(QString key);

public slots:
    void slotCardClosed(TipCard *card);
    void adjustPosition();
    void adjustHeight();

private:
    QList<TipCard*> cards;
    int sum_height;

};

#endif // TIPBOXWIDGET_H
