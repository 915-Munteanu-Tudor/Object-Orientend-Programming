#include <QAbstractScrollArea>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include "Admin.h"
#include "QHeaderView"
#include <QLineEdit>
#include <QMessageBox>
#include <QShortcut>
#include "vector"

Admin::Admin(RepoDog &repoDog, Service &service) : repoDog(repoDog), service(service) {
    this->setWindowTitle("Administrator");
    this->setStyleSheet("background-color: lightgrey");
    this->initgui();
    connect();

}

void Admin::connect(){
    auto* undoShortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
    auto* redoShortcut =  new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this);
    QObject::connect(undoShortcut, &QShortcut::activated, [&]() {
        try {

            service.Undo();
            fill_with_data();
        }
        catch (exception &ex) {
            QMessageBox::critical(this, "Error", "No more undo to perform.");
        }

    });
    QObject::connect(redoShortcut, &QShortcut::activated, [&]() {
        try {
            service.Redo();
            fill_with_data();
        }
        catch (exception &ex) {
            QMessageBox::critical(this, "Error", "No more redo to perform.");
        }

    });

    QObject::connect(add, &QPushButton::clicked, this, &Admin::addDog);
    QObject::connect(remove, &QPushButton::clicked, this, &Admin::rmvDog);
    QObject::connect(update, &QPushButton::clicked, this, &Admin::updDog);
    QObject::connect(btnUndo, &QPushButton::clicked, [&]() {
        try {

            service.Undo();
            fill_with_data();
        }
        catch (exception &ex) {
            QMessageBox::critical(this, "Error", "No more undo to perform.");
        }

    });
    QObject::connect(btnRedo, &QPushButton::clicked, [&]() {
        try {
            service.Redo();
            fill_with_data();
        }
        catch (exception &ex) {
            QMessageBox::critical(this, "Error", "No more redo to perform.");
        }

        });
}

void Admin::addDog(){
    try {
        string breed = breedAdd->text().toStdString();
        string name = nameAdd->text().toStdString();
        string age = ageAdd->text().toStdString();
        string photo = photoAdd->text().toStdString();
        Dog mama(breed, name, stoi(age), photo);

        service.add_dog(mama);
    }
    catch (...) {
        QMessageBox::critical(this, "Error", "Dog already exists.");
    }
    fill_with_data();

}

void Admin::rmvDog(){

    string name = nameRemove->text().toStdString();

    try {
        service.remove_dog(name);
    }
    catch (...) {
        QMessageBox::critical(this, "Error", "Dog does not exist.");
    }
    fill_with_data();
}

void Admin::updDog(){
    char age1[20];
    string nameup = nameUp1->text().toStdString();
    string breed = breedUp->text().toStdString();
    string name = nameUp->text().toStdString();
    string age = ageUp->text().toStdString();
    strcpy(age1, age.c_str());
    string photo = photoUp->text().toStdString();
    try {
        service.update_dog(nameup, breed, name, age1, photo);
    }
    catch (...) {
        QMessageBox::critical(this, "Error", "Dog does not exist.");
    }
    fill_with_data();
}


void Admin::fill_with_data(){
    table->setRowCount((int) this->service.getElements().size());
    int currentRow = 0;
    for (auto const &dog: this->service.getElements()) {

        auto breed = new QLabel();
        breed->setFixedHeight(30);
        breed->setText(QString::fromStdString(dog.getBreed()));
        breed->setAlignment(Qt::AlignCenter);
        table->setCellWidget(currentRow, 0, breed);

        auto name = new QLabel();
        name->setFixedHeight(30);
        name->setText(QString::fromStdString(dog.getName()));
        name->setAlignment(Qt::AlignCenter);
        table->setCellWidget(currentRow, 1, name);

        auto age = new QLabel();
        age->setFixedHeight(30);
        age->setText(QString::fromStdString(std::to_string(dog.getAge())));
        age->setAlignment(Qt::AlignCenter);
        table->setCellWidget(currentRow, 2, age);

        auto photo = new QLabel();
        photo->setFixedHeight(30);
        photo->setText(QString::fromStdString(dog.getPhoto()));
        photo->setAlignment(Qt::AlignCenter);
        table->setCellWidget(currentRow, 3, photo);

        currentRow++;
    }
    table->resizeColumnsToContents();

}

void Admin::initgui(){
    layout = new QVBoxLayout();
    this->setLayout(layout);

    table = new QTableWidget();
    table->setStyleSheet("background-color: white");
    table->setColumnCount(4);
    table->setRowCount((int) this->repoDog.getElements().size());
    table->setHorizontalHeaderLabels({"Breed", "Name", "Age", "Photo"});
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    table->horizontalHeader()->setStyleSheet("::section{font-weight:bold; color: darkblue; font-size: 13px;}");
    table->verticalHeader()->setStyleSheet("::section{font-weight:bold; color: darkblue; font-size: 13px;}");

    fill_with_data();



    layout->addWidget(table);

    breedAdd = new QLineEdit(this);
    breedAdd->setPlaceholderText("breed");

    nameAdd = new QLineEdit(this);
    nameAdd->setPlaceholderText("name");

    ageAdd = new QLineEdit(this);
    ageAdd->setPlaceholderText("age");

    photoAdd = new QLineEdit(this);
    photoAdd->setPlaceholderText("photo");

    buttonsLayout = new QHBoxLayout();

    add = new QPushButton("Add a dog");
    add->setStyleSheet("color: darkblue; background-color: lightblue");

    addbox = new QGroupBox(tr("add"));
    auto* addLayout = new QFormLayout;
    addLayout->addRow(breedAdd);
    addLayout->addRow(nameAdd);
    addLayout->addRow(ageAdd);
    addLayout->addRow(photoAdd);
    addLayout->setFormAlignment(Qt::AlignBottom);
    addLayout->addRow(add);
    addbox->setLayout(addLayout);
    buttonsLayout->addWidget(addbox);


    remove = new QPushButton("Remove a dog");
    remove->setStyleSheet("color: darkblue; background-color: lightblue");

    nameRemove = new QLineEdit(this);
    nameRemove->setPlaceholderText("name");

    rmvbox = new QGroupBox(tr("remove"));
    auto* rmvLayout = new QFormLayout;
    rmvLayout->addRow(nameRemove);
    rmvLayout->setFormAlignment(Qt::AlignBottom);
    rmvLayout->addRow(remove);
    rmvbox->setLayout(rmvLayout);
    buttonsLayout->addWidget(rmvbox);


    nameUp1 = new QLineEdit(this);
    nameUp1->setPlaceholderText("the dog to be updated");

    breedUp = new QLineEdit(this);
    breedUp->setPlaceholderText("breed");

    nameUp = new QLineEdit(this);
    nameUp->setPlaceholderText("name");

    ageUp = new QLineEdit(this);
    ageUp->setPlaceholderText("age");

    photoUp = new QLineEdit(this);
    photoUp->setPlaceholderText("photo");

    update = new QPushButton("Update a dog");
    update->setStyleSheet("color: darkblue; background-color: lightblue");

    upbox = new QGroupBox(tr("update"));
    auto* upLayout = new QFormLayout;
    upLayout->addRow(nameUp1);
    upLayout->addRow(breedUp);
    upLayout->addRow(nameUp);
    upLayout->addRow(ageUp);
    upLayout->addRow(photoUp);
    upLayout->addRow(update);
    upbox->setLayout(upLayout);
    buttonsLayout->addWidget(upbox);

    btnUndo = new QPushButton{ "&Undo" };
    btnRedo = new QPushButton{ "&Redo" };
    undrdBox = new QGroupBox(tr("Undo and redo"));
    undrdLayout = new QFormLayout;
    undrdLayout->addRow(btnUndo);
    undrdLayout->addRow(btnRedo);
    undrdBox->setLayout(undrdLayout);
    buttonsLayout->addWidget(undrdBox);

    layout->addLayout(buttonsLayout);
}
