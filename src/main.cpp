#include <iostream>
#include <core.hpp>
#include <QApplication>
#include <QFrame>


using namespace std;

int main(int argc, char** argv)
{

    QApplication* App = new QApplication(argc,argv);
    QFrame* main_frame = new QFrame();
    main_frame->setWindowTitle("gustaves nightmare");
    main_frame->resize(800,600);
    main_frame->show();

    Core* core = new Core(QPoint(0,0),QSize(800,600),main_frame);

    core->show();

    return App->exec();
}

