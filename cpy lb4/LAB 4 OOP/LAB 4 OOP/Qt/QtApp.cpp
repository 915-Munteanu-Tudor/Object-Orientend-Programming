#include "QtApp.h"
#include <QApplication>
#include "Menu.h"

QtApp::QtApp(int argc, char **argv, Service &service) : argc(argc), argv(argv), service(service) {}

int QtApp::loop() {

    QApplication app(this->argc, this->argv);
    Menu menu(this->repoDog, this->service);
    menu.show();
    return QApplication::exec();
}