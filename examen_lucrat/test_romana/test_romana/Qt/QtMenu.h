//
// Created by kida on 5/23/21.
//

#ifndef TEST_ROMANA_QTMENU_H
#define TEST_ROMANA_QTMENU_H


#include <QWidget>
#include <QListWidget>
#include "../Service.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QLabel>
#include <QtWidgets>
#include <QPushButton>

class QtMenu : public QWidget {
private:
    Service &ms;
    QListWidget* wl_list;
    QVBoxLayout* vLayout;
    QSlider* slider;
    QPushButton* modificare;
    QLabel* tmpLabel;
    QHBoxLayout* hLayout;
    int nr_bilete = 0;
    int pret_total = 0;
    QLineEdit* optiune_cumparare;
    QLineEdit* bilete;
    QLineEdit* pret;
    QGroupBox* grup_cumparare;
    QPushButton* cumparabtn;
    QPushButton* sortbtn;
    QLineEdit* nume_nou;
    QLineEdit* data_nou;
    QLineEdit* pret_nou;
    QSpinBox* numar_nou;
    QPushButton* adauga;
    QGroupBox* grup_adaugare;
    QComboBox* combo_box;
    QPushButton* vizualizeaza;
    QLineEdit* export_field;
    QPushButton* exporteaza;
public:
    explicit QtMenu(Service &ms);
    void initGUI();
    void populate_movies();
    void make_connections();
    void populate_movies_sorted();
    void add();
};


#endif //TEST_ROMANA_QTMENU_H
