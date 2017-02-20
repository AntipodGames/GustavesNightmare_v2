#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#define PI 3.14159

#include <AGE/entity.hpp>
#include "core.hpp"


namespace scripts{
//HELP FUNCTIONS
inline void increaseX(age::Entity::_property_t& p){
    TO_INTEGER(p["x"])->value
            +=TO_INTEGER(p["velocity"])->value;
}
inline void increaseY(age::Entity::_property_t& p){
    TO_INTEGER(p["y"])->value
            +=TO_INTEGER(p["velocity"])->value;
}
inline void decreaseX(age::Entity::_property_t& p){
    TO_INTEGER(p["x"])->value
            -=TO_INTEGER(p["velocity"])->value;
}
inline void decreaseY(age::Entity::_property_t& p){
    TO_INTEGER(p["y"])->value
            -=TO_INTEGER(p["velocity"])->value;
}


inline void teleport(age::Entity::_property_t& p,int x,int y){
    TO_INTEGER(p["x"])->value = x;
    TO_INTEGER(p["y"])->value = y;
}

inline void set_velocity(age::Entity::_property_t& p,float v){
    TO_INTEGER(p["velocity"])->value = v;
}
inline void decreaseLife(age::Entity::_property_t& p,int pt)
{
    TO_INTEGER(p["life"])->value -= pt;
}
inline float calcAngle(float x1, float y1, float x2, float y2){
    float angle;

    if(x1 - x2 > 0)
        angle = atan((y1 - y2)/(x1 - x2)) + PI;
    else if(x1 - x2 < 0)
        angle = atan((y1 - y2)/(x1 - x2));

    return angle;
}

//ENTITY BEHAVIORS
static std::function<void(age::Entity::_property_t&)> mob1 =
        [](age::Entity::_property_t& p)
{

    int x_max = 600, x_min = 300; /*y_min = 200 , y_max = 400;*/

    if(TO_DOUBLE(p["angle"])->value == PI/2.)
        TO_INTEGER(p["x"])->value+=TO_INTEGER(p["velocity"])->value;


    if(TO_DOUBLE(p["angle"])->value == -PI/2.)
        TO_INTEGER(p["x"])->value-=TO_INTEGER(p["velocity"])->value;


    if(TO_INTEGER(p["x"])->value > x_max){
        TO_DOUBLE(p["angle"])->value = -PI/2.;
        TO_STRING(p["state"])->value = "blue";
    }

    if(TO_INTEGER(p["x"])->value < x_min){
        TO_DOUBLE(p["angle"])->value =  PI/2.;
        TO_STRING(p["state"])->value = "red";
    }
};

//GLOBAL SCRIPTS
inline void init_level_test(age::Engine::entites_map_t& ent_map){
    TO_INTEGER(ent_map["blurg_1"]->access_property()["x"])->value = 400;
    TO_INTEGER(ent_map["blurg_1"]->access_property()["y"])->value = 300;
    TO_DOUBLE(ent_map["blurg_1"]->access_property()["angle"])->value = PI/2.;
    TO_STRING(ent_map["blurg_1"]->access_property()["state"])->value = "red";


    ent_map["blurg_1"]->set_behavior(mob1);
}

}



#endif // ENTITIES_HPP

