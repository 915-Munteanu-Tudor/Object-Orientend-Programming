//
// Created by munte on 18/06/2021.
//

#ifndef CODE_REVISION_GUIOBSERVER_H
#define CODE_REVISION_GUIOBSERVER_H
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


class ProgrammerWindow : public Observer, QWidget {
public:
    void notifyObservers() {
        for (auto& o : observers) {
            o->update();
        }
    }
    string name_pg;
    int to_revise_pg;
    int revised_pg;
    Service& serv;
    vector <Observer*>& observers;
    Programmer& pg;
    QTableWidget* table;
    QVBoxLayout* layout;
    QLabel* revised;
    QLabel* to_revise;
    QLineEdit* file_to_add;
    QPushButton* addBtn;
    QHBoxLayout* hlayout;
    QPushButton* revise;


    ProgrammerWindow(Service& serv, vector<Observer*>& observers, Programmer& pg) : serv {serv}, observers{observers}, pg{pg}{
        initGUI();
        //update();
        name_pg = pg.getName();
        to_revise_pg = pg.getToRevise();
        revised_pg = pg.getNrRevisedFiles();
        make_connections();
    };
    void loadData(const vector<SourceFile>& sfs);
    void update() override;
    void initGUI();
    void make_connections();
    void add_file();
};


class GUIObserver : public QWidget, Observer{
   void addObserver(Observer* obs) {
       observers.push_back(obs);
   }
private:
    Service& serv;
    vector<Observer*> observers;
public:
    GUIObserver(Service& service) : serv{ service } {
        initGUI();
    }
    void initGUI();
    void update() override;
    void paint_circles(const vector<SourceFile>& sfs);
    void paintEvent(QPaintEvent *event) override;

};




#endif //CODE_REVISION_GUIOBSERVER_H
