//
// Created by munte on 22/06/2021.
//

#include "GUIObserver.h"

void EthnologistWindow::loadData(const vector<Building> &bld) {
    table->setRowCount((int) bld.size());
    int currentRow = 0;
    for (Building sf: serv.getSortByArea(name_eth)) {

        auto name = new QTableWidgetItem(QString::fromStdString(to_string(sf.getId())));
        table->setItem(currentRow, 0, name);

        auto descriere = new QTableWidgetItem(QString::fromStdString(sf.getDescription()));
        table->setItem(currentRow, 1, descriere);

        auto them_area = new QTableWidgetItem(QString::fromStdString(sf.getThematicArea()));
        table->setItem(currentRow, 2, them_area);

        auto coords = new QTableWidgetItem(QString::fromStdString(sf.coords_tostring()));
        table->setItem(currentRow, 3, coords);

        if (sf.getThematicArea() == them_area_eth){
            name->setBackground(Qt::blue);
            descriere->setBackground(Qt::blue);
            them_area->setBackground(Qt::blue);
            coords->setBackground(Qt::blue);
        }

        currentRow++;
    }
    table->resizeColumnsToContents();
}

void EthnologistWindow::update() {
    loadData(serv.getSortByArea(them_area_eth)); //sorted urmeaza

}

void EthnologistWindow::initGUI() {
    this->setWindowTitle(QString::fromStdString(name_eth));
    layout = new QVBoxLayout();
    this->setLayout(layout);

    string hex = "aaaaaa";
    string hex_char = "0123456789ABCDEF";
    int i;
    for(i=0;i<6;i++)
    {
        hex[i] = hex_char[rand()%16];
    }
    this->setStyleSheet(QString::fromStdString("background-color:#"+hex));

    table = new QTableWidget();
    table->setStyleSheet("background-color: white");
    table->setColumnCount(4);
    table->setRowCount((int) serv.getEthnologists().size());
    table->setHorizontalHeaderLabels({"Id", "Description", "Thematic_area", "Coordinates"});
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    table->horizontalHeader()->setStyleSheet("::section{font-weight:bold; color: darkblue; font-size: 13px;}");
    table->verticalHeader()->setStyleSheet("::section{font-weight:bold; color: darkblue; font-size: 13px;}");
    loadData(serv.getBuildings()); // urmeaza sortat
    layout->addWidget(table);

    id = new QLineEdit();
    id->setPlaceholderText("Enter the id");

    description = new QLineEdit();
    description->setPlaceholderText("Enter the description");

    coordinates = new QLineEdit();
    coordinates->setPlaceholderText("Enter the coordinates");

    addbtn = new QPushButton("Add");

    layout->addWidget(id);
    layout->addWidget(description);
    layout->addWidget(coordinates);
    layout->addWidget(addbtn);

    updated_description = new QLineEdit();
    updated_description->setPlaceholderText("New description");

    updated_location = new QLineEdit();
    updated_location->setPlaceholderText("New location");

    upbtn = new QPushButton("Update");

    layout->addWidget(updated_description);
    layout->addWidget(updated_location);
    layout->addWidget(upbtn);

    update();
    this->show();
}

void EthnologistWindow::make_connections() {

    QObject::connect(table, &QTableWidget::itemSelectionChanged, [&](){

        if (table->item(table->currentRow(), 2)->text() == QString::fromStdString(them_area_eth)) {
            upbtn->setEnabled(true);
        } else {
            upbtn->setEnabled(false);
        }
    });

    QObject::connect(upbtn, &QPushButton::clicked, [&](){
        vector<string> loc;
        loc.push_back(updated_location->text().toStdString());
        for (auto &el: serv.getCoords()){
            if (el == updated_location->text().toStdString())
            {
                QMessageBox::critical(this, "critical", QString::fromStdString("The added buildings overlaps an existing one!"));
                return;
            }
        }

        if (updated_location->text().toStdString().size() < 2){
            QMessageBox::critical(this, "critical", QString::fromStdString("The added buildings has to take up at least 1 sector!"));
            return;
        }
        serv.update_buildings(table->item(table->currentRow(), 0)->text().toInt(),updated_description->text().toStdString(),loc);
        notifyObservers();
    });

    QObject::connect(addbtn, &QPushButton::clicked, [&](){

        if (description->text().isEmpty()){
            QMessageBox::critical(this, "critical", QString::fromStdString("You cannot add a building with empty description!"));
        }

        vector<string> cords;
        cords.push_back(coordinates->text().toStdString());

        for (auto &el: serv.getCoords()){
            if (el == coordinates->text().toStdString())
            {
                QMessageBox::critical(this, "critical", QString::fromStdString("The added buildings overlaps an existing one!"));
                return;
            }
        }

        if (coordinates->text().toStdString().size() < 2){
            QMessageBox::critical(this, "critical", QString::fromStdString("The added buildings has to take up at least 1 sector!"));
            return;
        }


        try {
            serv.add_building(id->text().toInt(), description->text().toStdString(), them_area_eth, cords);
        }
        catch (exception& ex) {
            QMessageBox::critical(this, "critical", QString::fromStdString("You can add a building only with unique id!"));
            return;
        }
        notifyObservers();

    });

}

void GUIObserver::initGUI() {
    for (auto pg : serv.getEthnologists()) {
        addObserver(new EthnologistWindow(serv, observers, pg));
    }
    addObserver(this);
    update();

}

void GUIObserver::update() {
    QWidget::update();
}

void GUIObserver::make_connections() {

}
