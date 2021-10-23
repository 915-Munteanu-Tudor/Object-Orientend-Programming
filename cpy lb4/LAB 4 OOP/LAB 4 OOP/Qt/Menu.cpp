//
// Created by munte on 11/05/2021.
//

#include <QVBoxLayout>
#include <QPushButton>
#include "User.h"
#include "Admin.h"
#include "Menu.h"

Menu::Menu(RepoDog &repoDog, Service& service): repoDog(repoDog), service(service) {
    this->setWindowTitle("Choose mode");
    this->resize(300, 150);

    auto layout = new QVBoxLayout();
    this->setStyleSheet("background-color: grey");
    this->setLayout(layout);

    auto admin = new QPushButton("Administrator");
    QObject::connect(admin, &QPushButton::clicked, this, &Menu::showAdmin);
    admin->setStyleSheet("color: darkblue; background-color: white");
    admin->setFixedHeight(35);
    layout->addWidget(admin);

    auto user = new QPushButton("User");
    QObject::connect(user, &QPushButton::clicked, this, &Menu::showUser);
    user->setStyleSheet("color: darkblue; background-color: white");
    user->setFixedHeight(35);
    layout->addWidget(user);
}

void Menu::showAdmin() {
    auto admin = new Admin(this->repoDog, this->service);
    admin->show();
}

void Menu::showUser() {
    auto user = new User(this->repoDog, this->service);
    user->show();
}
