#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#define PI 3.14159

#include <AGE/entity.hpp>


class EntityBase : public age::Entity{

public:
    EntityBase(){}
    EntityBase(std::string n, int x, int y, int w, int h, int v, int l) :
        age::Entity(n,x,y,w,h,v)
    {
        _property.emplace("life",INTEGER_PTR(l));
    }
    EntityBase(const EntityBase& eb) :
        age::Entity(eb){}

    ~EntityBase(){}

    void increaseX();
    void increaseY();
    void decreaseX();
    void decreaseY();


    void teleport(int x,int y);

    void set_velocity(float v);
    void decreaseLife(int pt);

protected:
    float calcAngle(float x1, float y1, float x2, float y2);
};



#endif // ENTITIES_HPP

