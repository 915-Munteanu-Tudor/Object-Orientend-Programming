//
// Created by munte on 20/06/2021.
//

#ifndef Q_A_SITE_GUIOBSERVER_H
#define Q_A_SITE_GUIOBSERVER_H

#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QPainterPath>
#include <QtWidgets/QMainWindow>
#include <iostream>

#include <qstring.h>
#include <QString.h>
#include <QtWidgets/qwidget.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget.h>
#include <QFormLayout.h>
#include <QLineEdit.h>
#include <QPushButton.h>
#include <qDebug>
#include <QMessageBox.h>
#include <qpalette.h>
#include <qbrush.h>
#include <QTableWidget.h>
#include <QStandardItemModel.h>
#include <QHeaderView>
#include <QLabel.h>
#include <QPainter>
#include <QSpinBox.h>
#include "Service.h"

using std::vector;

//Clasa Observer cu metoda virtuala update
class Observer {
public:
    virtual void update() = 0;
};


class UserWindow : public Observer, QWidget {
public:
    void notifyObservers() {
        for (auto& o : observers) {
            o->update();
        }
    }
    string name_user;
    Service& serv;
    vector <Observer*>& observers;
    User& user;
    QVBoxLayout* layout;
    QListWidget* list;
    QLineEdit* text;
    QPushButton* addBtn;
    QListWidget* answers;
    QLineEdit* new_ans;
    QPushButton* ans_btn;
    QSpinBox* votes;

    UserWindow(Service& serv, vector<Observer*>& observers, User& usr) : serv {serv}, observers{observers}, user{usr}{
        initGUI();
        //update();
        name_user = usr.getName();
        make_connections();
    };
    void loadData(const vector<Question>& questions);
    void update() override;
    void initGUI();
    void make_connections();

};


class GUIObserver : public QWidget, Observer{
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }
private:
    Service& serv;
    vector<Observer*> observers;
    QVBoxLayout* layout;
    QLineEdit* search;
    QListWidget* answers;
    QLabel* question;

public:
    GUIObserver(Service& service) : serv{ service } {
        initGUI();
        make_connections();
    }
    void initGUI();
    void update() override;
    void make_connections();

};

class PaintWindow : public Observer, QWidget {
private:
    Service& serv;
    vector<Observer*> observers;
public:
    PaintWindow(Service& service, vector<Observer*>& observers) : serv{ service }, observers(observers) {
        this->show();
    }
    void update() override;
    void paint_bars(const vector<Answer>& sfs);
    void paintEvent(QPaintEvent *event) override;

};
#endif //Q_A_SITE_GUIOBSERVER_H
