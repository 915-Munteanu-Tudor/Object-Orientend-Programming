//
// Created by kida on 5/11/21.
//

#ifndef A67_915_MURARIU_ALEXANDRA_QTUI_H
#define A67_915_MURARIU_ALEXANDRA_QTUI_H


#include "../Service.h"

class QtUi {
private:
    int argc;
    char **argv;
    Service &ms;
public:
    explicit QtUi(int argc, char **argv, Service &ms);

    int mainloop();
};


#endif //A67_915_MURARIU_ALEXANDRA_QTUI_H
