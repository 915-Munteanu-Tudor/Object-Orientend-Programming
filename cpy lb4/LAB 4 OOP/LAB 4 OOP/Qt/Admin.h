#pragma once

#include <QWidget>
#include <QTableWidget>
#include <QGroupBox>
#include <Service.h>
//#include "repoDog.h"


class Admin : public QWidget {
public:
    RepoDog &repoDog;
    Service& service;
    Admin(RepoDog &repoDog, Service &service);

private:
    void initgui();
    QGroupBox* undrdBox;
    QFormLayout* undrdLayout;
    QPushButton* btnUndo;
    QPushButton* btnRedo;
    QVBoxLayout* layout;
    QTableWidget* table;
    QHBoxLayout* buttonsLayout;
    QPushButton* add;
    QPushButton* remove;
    QPushButton* update;
    QGroupBox* addbox;
    QLineEdit* breedAdd;
    QLineEdit* nameAdd;
    QLineEdit* ageAdd;
    QLineEdit* photoAdd;
    QLineEdit* nameRemove;
    QGroupBox* rmvbox;
    QLineEdit* nameUp;
    QLineEdit* ageUp;
    QLineEdit* photoUp;
    QLineEdit* breedUp;
    QGroupBox* upbox;
    QLineEdit* nameUp1;

    void fill_with_data();

    void connect();

    void addDog();

    void rmvDog();

    void updDog();
};
