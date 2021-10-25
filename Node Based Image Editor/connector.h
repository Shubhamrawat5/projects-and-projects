#include <QWidget>
#include <QGraphicsItem>
#include<QPainter>

enum inputConnection{noInput,oneInput,twoInput};
enum outputConnection{noOutput,oneOutput};
enum connectorState{hoverEnter,hoverExit,connected};
//hoverEnter - hover enter when not connected
//hovetExit - hover exit when not connected
//connected - when an edge is connected

class PropertiesWindow:public QWidget{
    Q_OBJECT
public:
    PropertiesWindow(QString title){
        setWindowTitle(title);
    }
};

class connector:public QGraphicsItem{
    int width,height;
    connectorState state;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
public:
    connector(QGraphicsItem*parent=NULL,int width=10,int height=10);
    QRectF boundingRect() const;
    int getWidth();
    int getHeight();
    void setState(connectorState state);
};
