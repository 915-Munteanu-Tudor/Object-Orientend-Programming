#include <QVBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QLabel>
#include <fstream>
#include <QFormLayout>
#include "User.h"

User::User(RepoDog &repoDog, Service& service): repoDog(repoDog), service(service) {
    this->setWindowTitle("User");

    auto Layout = new QVBoxLayout();
    //this->setFixedSize(300,150);
    this->setStyleSheet("background-color: lightgrey");
    this->setLayout(Layout);

    tbl = new MyTableModel();
    tbl->setDogs(repoDog.getElements());
    tblView = new QTableView();
    //selectionModel = tblView->selectionModel();
    tblView->setStyleSheet("QTableView {background-color: white;}");
    tblView->setModel(tbl);

    tblView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    Layout->addWidget(tblView);

    tbl->setDogs(repoDog.getElements());

//    table = new QTableWidget();
//    table->setStyleSheet("background-color: white");
//    table->setColumnCount(4);
//    table->setRowCount((int) this->repoDog.getElements().size());
//    table->setHorizontalHeaderLabels({"Breed", "Name", "Age", "Photo"});
//    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
//    table->horizontalHeader()->setStyleSheet("::section{font-weight:bold; color: darkblue; font-size: 13px;}");
//    table->verticalHeader()->setStyleSheet("::section{font-weight:bold; color: darkblue; font-size: 13px;}");


//    table->setRowCount((int) this->repoDog.getElements().size());
//    int currentRow = 0;
//    for (auto const &dog: this->repoDog.getElements()) {
//
//        auto breed = new QLabel();
//        breed->setFixedHeight(30);
//        breed->setText(QString::fromStdString(dog.getBreed()));
//        breed->setAlignment(Qt::AlignCenter);
//        table->setCellWidget(currentRow, 0, breed);
//
//        auto nme = new QLabel();
//        nme->setFixedHeight(30);
//        nme->setText(QString::fromStdString(dog.getName()));
//        nme->setAlignment(Qt::AlignCenter);
//        table->setCellWidget(currentRow, 1, nme);
//
//        auto age = new QLabel();
//        age->setFixedHeight(30);
//        age->setText(QString::fromStdString(std::to_string(dog.getAge())));
//        age->setAlignment(Qt::AlignCenter);
//        table->setCellWidget(currentRow, 2, age);
//
//        auto photo = new QLabel();
//        photo->setFixedHeight(30);
//        photo->setText(QString::fromStdString(dog.getPhoto()));
//        photo->setAlignment(Qt::AlignCenter);
//        table->setCellWidget(currentRow, 3, photo);
//
//        currentRow++;
//    }
//    table->resizeColumnsToContents();
//    Layout->addWidget(table);

    auto viewH = new QPushButton("Show adoption list html");
    viewH->setStyleSheet("color: darkblue; background-color: lightblue");
    viewH->setFixedHeight(35);
    Layout->addWidget(viewH);
    QObject::connect(viewH, &QPushButton::clicked, this, &User::showH);

    auto viewC = new QPushButton("Show adoption list csv");
    viewC->setStyleSheet("color: darkblue; background-color: lightblue");
    viewC->setFixedHeight(35);
    Layout->addWidget(viewC);
    QObject::connect(viewC, &QPushButton::clicked, this, &User::showC);

    name= new QLineEdit(this);
    name->setStyleSheet("color: darkblue");
    name->setPlaceholderText("name");
    Layout->addWidget(name);

    auto add = new QPushButton("Add to adoption list");
    add->setStyleSheet("color: darkblue; background-color: lightblue");
    add->setFixedHeight(35);
    Layout->addWidget(add);
    QObject::connect(add, &QPushButton::clicked, this, &User::addDog);

    ofstream myfile("usr.html");
    myfile.close();
    ofstream myfile1("user.csv");
    myfile.close();

    breed1 = new QLineEdit(this);
    breed1->setPlaceholderText("Breed to filter by");
    //Layout->addWidget(breed1);

    age1 = new QLineEdit(this);
    age1->setPlaceholderText("Age to filter by");
    Layout->addWidget(age1);

    filtreaza = new QPushButton("Filtreaza");
    filtreaza->setStyleSheet("color: darkblue; background-color: lightblue");
    filtreaza->setFixedHeight(35);
    //Layout->addWidget(filtreaza);

    list_filtrat = new QListWidget{};
    list_filtrat->setStyleSheet("background-color: white");
    //Layout->addWidget(list_filtrat);

    grup_filtrare = new QGroupBox("Filtreaza caini");
    grup_filtrare->setStyleSheet("color: darkblue");
    lyt_filtr = new QFormLayout;
    lyt_filtr->addRow(breed1);
    lyt_filtr->addRow(age1);
    lyt_filtr->addRow(filtreaza);
    lyt_filtr->addRow(list_filtrat);
    grup_filtrare->setLayout(lyt_filtr);
    Layout->addWidget(grup_filtrare);


    QObject::connect(filtreaza, &QPushButton::clicked, this, &User::populate_filtered);
}

void User::showH(){
    system("start usr.html");
}

void User::showC(){
    system("start user.csv");
}

void User::addDog(){
    string n = name->text().toStdString();
    this->adoptionList = std::make_unique<CsvAdoptionList>();
    this->adoptionList0 = std::make_unique<HtmlAdoptionList>();
    for (const auto& dog:this->repoDog.getElements()) {
        if (dog.getName() == n)
        {
            adoptionList->getAdoptionlist().push_back(dog);
            adoptionList0->getAdoptionlist().push_back(dog);
            adoptionList->write();
            adoptionList0->write();
        }
    }
}

void User::populate_filtered(){
    list_filtrat->clear();
    std::vector<Dog> new_v = repoDog.getElements();
    for(const auto& c: new_v) {
        if (c.getBreed() == breed1->text().toStdString() and c.getAge() < stoi(age1->text().toStdString())){
            list_filtrat->addItem(QString::fromStdString(c.getBreed()) + ";" + QString::fromStdString(c.getName()) + ";" + QString::fromStdString(std::to_string(c.getAge())) + ";" + QString::fromStdString(c.getPhoto() + ";"));
        }

    }
}