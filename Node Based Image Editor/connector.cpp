#include "connector.h"

void connector::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if(state!=connected) state=hoverEnter;
    update();
    QGraphicsItem::hoverEnterEvent(event);
}

void connector::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    if(state!=connected) state=hoverExit;
    update();
    QGraphicsItem::hoverLeaveEvent(event);
};

void connector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect=boundingRect();
    QPainterPath path;
    path.addRoundedRect(rect,2,2);
    QPen pen(Qt::white);
    painter->setPen(pen);
    painter->drawPath(path);
    if(state==hoverEnter) painter->fillRect(rect,QBrush(QColor(200,200,200)));
    else if(state==connected) painter->fillRect(rect,QBrush(Qt::white));
};

connector::connector(QGraphicsItem*parent,int width,int height)
    :QGraphicsItem(parent),width(width),height(height)
{
    setAcceptHoverEvents(true);
    state=hoverExit;
    setToolTip("Right-click for creating edges\nMiddle-button for deleting edges");
}

QRectF connector::boundingRect() const {
    return QRectF(0,0,width,height);
}

int connector::getWidth(){
    return width;
}
int connector::getHeight(){
    return height;
}
void connector::setState(connectorState state){
    this->state=state;
    update();
}
