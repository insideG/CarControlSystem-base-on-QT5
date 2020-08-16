#include "homewindow.h"
#include <QApplication>
#include<QStyleFactory>
#include"mscplayer.h"
#include "vdoplayer.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    homewindow HomeInterface;
    MscPlayer MscInterface ;
    vdoplayer VdoInterface;

    QApplication::setStyle(QStyleFactory::create("Fusion"));

    HomeInterface.setWindowTitle("Car control System");
    MscInterface.setWindowTitle("media player");
    VdoInterface.setWindowTitle("video player");

    HomeInterface.show();
    MscInterface.hide();
    VdoInterface.hide();

    QObject::connect(&HomeInterface,SIGNAL(ShowMscInterface()),
                     &MscInterface,SLOT(GetShowMscInterface()));

    QObject::connect(&MscInterface,SIGNAL(ShowHomeInterface()),
                     &HomeInterface,SLOT(GetShowHomeInterface()));

    QObject::connect(&HomeInterface,SIGNAL(ShowVdoInterface()),
                     &VdoInterface,SLOT(GetShowVdoInterface()));

    QObject::connect(&VdoInterface,SIGNAL(ShowHomeInterface()),
                     &HomeInterface,SLOT(GetShowHomeInterface()));



    return a.exec();
}
