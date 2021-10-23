//
// Created by kida on 5/11/21.
//

#include "QtUi.h"
#include "QtMenu.h"
#include <QApplication>

QtUi::QtUi(int argc, char **argv, Service &sm) : argc(argc), argv(argv), ms(sm){
}

int QtUi::mainloop() {
    QApplication application(argc, argv);
    QtMenu menu(this->ms);
    menu.show();
    return QApplication::exec();
}