#pragma once
#include "Service.h"

class QtApp {
public:
    int argc;
    char **argv;
    RepoDog repoDog;
    Service& service;
    QtApp(int argc, char **argv, Service &service);
    int loop();

};