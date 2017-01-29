#include "core.hpp"


void Environment::_init(){
    std::cout << "Environment Initialisation" << std::endl;


//    EntityProp* player_prop(new EntityProp("Hero",400,300,75,75,3,10));
//    PlayerBehav* player_beh(new PlayerBehav(player_prop));
    std::shared_ptr<Player> player = std::make_shared<Player>(Player("Hero",400,300,120,75,3,10));
//    Player* player = new Player("Hero",400,300,75,75,3,10);
    EntityBase::Ptr bouboule = std::make_shared<EntityBase>(EntityBase("Boule",400,300,75,75,3,10));
    bouboule->set_behavior(EntityBase::mob1);
    _entities_map.emplace(player->get_name(),std::static_pointer_cast<age::Entity>(player));
    _entities_map.emplace(bouboule->get_name(),bouboule);
//    EntityProp prop  = *std::static_pointer_cast<EntityProp>(player->access_property());

}

void Environment::_update(){
}



void Core::_init(){

    _engine->_init();

    _engine->load_config_file("config/env_conf.yml");

    setMouseTracking(true);

    _init_view(400,300,800,600);

    _load_graphics("graphics/graphics.yml");

    std::cout << TO_INTEGER(
                     std::static_pointer_cast<Player>(_engine->get_entities()["Hero"])
                            ->access_property()["velocity"])->value << std::endl;

    std::shared_ptr<Player> player(std::static_pointer_cast<Player>(_engine->get_entities()["Hero"]));


    //Connections core to player
    connect(this,SIGNAL(turnDown()),player.get(),SLOT(down()));
    connect(this,SIGNAL(turnUp()),player.get(),SLOT(up()));
    connect(this,SIGNAL(turnLeft()),player.get(),SLOT(left()));
    connect(this,SIGNAL(turnRight()),player.get(),SLOT(right()));
    connect(this,SIGNAL(sendMousePos(int,int)),player.get(),SLOT(updateAngle(int,int)));

    std::cout<< "init !!!" << std::endl;
}

void Core::keyPressEvent(QKeyEvent *Event){
    if(Event->key() == Qt::Key_Z || Event->key() == Qt::Key_Up){
        _up_pressed = true;
    }
    if(Event->key() == Qt::Key_S || Event->key() == Qt::Key_Down){
        _down_pressed = true;
    }
    if(Event->key() == Qt::Key_Q || Event->key() == Qt::Key_Left){
        _left_pressed = true;
    }
    if(Event->key() == Qt::Key_D || Event->key() == Qt::Key_Right){
        _right_pressed = true;
    }
}

void Core::keyReleaseEvent(QKeyEvent *Event){
    if(Event->key() == Qt::Key_Z || Event->key() == Qt::Key_Up){
        _up_pressed = false;
    }
    if(Event->key() == Qt::Key_S || Event->key() == Qt::Key_Down){
        _down_pressed = false;
    }
    if(Event->key() == Qt::Key_Q || Event->key() == Qt::Key_Left){
        _left_pressed = false;
    }
    if(Event->key() == Qt::Key_D || Event->key() == Qt::Key_Right){
        _right_pressed = false;
    }
    //    if(Event->key() == Qt::Key_Space){
    //        emit setPause();
    //        pause();
    //    }
}

void Core::_update(){

    //    if(alive){
    if(_left_pressed)
        emit turnLeft();
    if(_right_pressed)
        emit turnRight();
    if(_up_pressed)
        emit turnUp();
    if(_down_pressed)
        emit turnDown();
    //        if(isShooting)
    //            emit sigShoot(1);
    //    }
}


void Core::mouseMoveEvent(QMouseEvent *Event){
    if(_is_alive)
        emit sendMousePos(Event->x(),Event->y());
}
