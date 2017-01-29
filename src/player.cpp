#include "player.h"
#include <iostream>

//******/SLOTS\*******\\

void Player::left(){
    std::cout << "left : " << TO_INTEGER(_property["x"])->value << std::endl;
    decreaseX();
    //    if(tz.intersection(collision_map,sf::Color::Black))
//        prop.increaseX();
    TO_INTEGER(_property["frame"])->value++;
//    updateAngle(mousePosX,mousePosY);
}

void Player::right(){

    std::cout << "right : " << TO_INTEGER(_property["x"])->value << std::endl;
    increaseX();

//    if(tz.intersection(collision_map,sf::Color::Black))
//        _property->decreaseX();

    TO_INTEGER(_property["frame"])->value++;
    //    updateAngle(mousePosX,mousePosY);

}

void Player::up(){
    std::cout << "up : " << TO_INTEGER(_property["y"])->value << std::endl;
    decreaseY();

//    if(tz.intersection(collision_map,sf::Color::Black))
//        _property->increaseY();
    TO_INTEGER(_property["frame"])->value++;
}

void Player::down(){
    std::cout << "down : " << TO_INTEGER(_property["y"])->value << std::endl;
    increaseY();
//    if(tz.intersection(collision_map,sf::Color::Black))
//        _property->decreaseY();
    TO_INTEGER(_property["frame"])->value++;

}


void Player::updateAngle(int mouseX,int mouseY){
    mousePosX = mouseX;
    mousePosY = mouseY;
    TO_DOUBLE(_property["angle"])->value =
            calcAngle(TO_INTEGER(_property["x"])->value,
                TO_INTEGER(_property["y"])->value,mouseX,mouseY);
//    std::cout << TO_FLOAT(_property["angle"])->value << std::endl;
}

//void Player::stopInv(){
//    invincible = false;
//    invincibilityTimer.stop();
//    nom = "Hero";
//}

//void Player::invincibility(bool b){
//    invincible = b;
//    if(b)
//        invincibilityTimer.start();
//}

//**********************\\
