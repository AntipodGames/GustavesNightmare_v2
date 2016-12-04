#ifndef CORE_H
#define CORE_H

#include <QWidget>
#include <AGE/system.hpp>
#include <AGE/engine.hpp>
#include <player.h>
#include <QEvent>
#include <QKeyEvent>

class Environment : public age::Engine
{

    Q_OBJECT
public :
    Environment(){}
    Environment(const std::string& configFile) : age::Engine(configFile){}

    ~Environment(){}

    void _init();
    void _update();

//    PlayerBehav* access_player_behavior(){return (PlayerBehav*)_entities_map["Hero"]->access_behavior();}
};

class Core : public age::System
{

    Q_OBJECT
public:
    Core(const QPoint& position, const QSize& size,QWidget *parent = 0)
        : age::System(parent,position,size){
        _engine.reset(new Environment());
    }
    ~Core(){}

    void _init();
    void _update();
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);
    void mouseMoveEvent(QMouseEvent *Event);

//public slots:
//    void pause();

signals:
    void turnLeft();
    void turnRight();
    void turnUp();
    void turnDown();
    void sendMousePos(int,int);


private:
    bool _left_pressed = false;
    bool _right_pressed = false;
    bool _up_pressed = false;
    bool _down_pressed = false;
    bool _is_alive = true;
};





#endif // CORE_H
