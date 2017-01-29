#include <iostream>
#include "entities.hpp"


void EntityBase::increaseX(){
    TO_INTEGER(_property["x"])->value
            +=TO_INTEGER(_property["velocity"])->value;
}

void EntityBase::increaseY(){
    TO_INTEGER(_property["y"])->value
            +=TO_INTEGER(_property["velocity"])->value;
}

void EntityBase::decreaseX(){
    TO_INTEGER(_property["x"])->value
            -=TO_INTEGER(_property["velocity"])->value;
}


void EntityBase::decreaseY(){
    TO_INTEGER(_property["y"])->value
            -=TO_INTEGER(_property["velocity"])->value;
}

void EntityBase::teleport(int x, int y){
    TO_INTEGER(_property["x"])->value = x;
    TO_INTEGER(_property["y"])->value = y;
}

void EntityBase::decreaseLife(int pt){
    TO_INTEGER(_property["life"])->value -= pt;
}

void EntityBase::set_velocity(float v){
    TO_INTEGER(_property["velocity"])->value = v;
}

float EntityBase::calcAngle(float x1, float y1, float x2, float y2){
    float angle;

    if(x1 - x2 > 0)
        angle = atan((y1 - y2)/(x1 - x2)) + PI;
    else if(x1 - x2 < 0)
        angle = atan((y1 - y2)/(x1 - x2));

    return angle;
}

std::function<void(age::Entity::_property_t)> EntityBase::mob1 =
        [](age::Entity::_property_t p)
{

    int x_max = 600, x_min = 300, y_min = 200 , y_max = 400;

    if(TO_DOUBLE(p["angle"])->value == 0)
        TO_INTEGER(p["x"])->value+=TO_INTEGER(p["velocity"])->value;


    if(TO_DOUBLE(p["angle"])->value == PI)
        TO_INTEGER(p["x"])->value-=TO_INTEGER(p["velocity"])->value;


    if(TO_INTEGER(p["x"])->value > x_max)
        TO_DOUBLE(p["angle"])->value = PI;

    if(TO_INTEGER(p["x"])->value < x_min)
        TO_DOUBLE(p["angle"])->value = 0;
};
