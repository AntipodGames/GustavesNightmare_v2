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
