#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <AGE/entity.hpp>
#include <entities.hpp>
#include <AGE/types.hpp>
#include <QTimer>
#include <SFML/Graphics.hpp>


class Player : public QObject, public age::Entity
{
    Q_OBJECT

public:
    Player(){}
    Player(std::string n, int x, int y, int w, int h, int v, int l) :
        Entity(n,w,h,v)
    {
        _property.emplace("x",INTEGER_PTR(x));
        _property.emplace("y",INTEGER_PTR(y));
        _property.emplace("life",INTEGER_PTR(l));
    }
    Player(const Player& pl) :
        age::Entity(pl){}

    ~Player(){}



public slots:
    void left();
    void right();
    void up();
    void down();

    void updateAngle(int mouseX, int mouseY);
//    void invincibility(bool);
//    void stopInv();
//    void updateAngle(double a){_property->_angle = a;}

private:
    int mousePosX = 0;
    int mousePosY = 0;
//    int invincible = false;
//    QTimer invincibilityTimer;

//    std::shared_ptr<sf::Image> collision_map;

};

#endif // PLAYER_H
