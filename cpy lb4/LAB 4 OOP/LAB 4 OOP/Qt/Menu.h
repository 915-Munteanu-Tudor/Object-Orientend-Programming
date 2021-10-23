#pragma once

#include <QWidget>
#include "Service.h"

class Menu : public QWidget {
private:
    RepoDog &repoDog;
    Service& service;
public:
    explicit Menu(RepoDog &repoDog, Service& service);

    void showAdmin();

    void showUser();
};