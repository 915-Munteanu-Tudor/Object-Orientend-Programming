//
// Created by munte on 21/06/2021.
//

#include "GUIObserver.h"
#include "Exceptions.h"

void ProductWindow::initGUI() {
    layout = new QVBoxLayout();
    this->setLayout(layout);
    this->setWindowTitle(QString::fromStdString(prod_type));
    this->setFixedSize(320,200);
    lbl = new QLabel();
    lbl->setText(QString::fromStdString("The number of products of same type: " + to_string(serv.prod_type(prod_type))));
    layout->addWidget(lbl);
    update();

    this->show();
}

void ProductWindow::update() {
    lbl->setText(QString::fromStdString("The number of products of same type: " + to_string(serv.prod_type(prod_type))));
}

void GUIObserver::initGUI() {
    for (auto it : serv.getProducts()) {
        addObserver(new ProductWindow(serv, observers, it));
    }
    addObserver(this);
    layout = new QVBoxLayout();
    this->setLayout(layout);
    tblView->setModel(tbl);
    layout->addWidget(tblView);
    this->setFixedWidth(600);

    new_id = new QLineEdit();
    new_id->setPlaceholderText("The id of the new product");

    new_name = new QLineEdit();
    new_name->setPlaceholderText("The name of the new product");

    new_type = new QLineEdit();
    new_type->setPlaceholderText("The type of the new product");

    new_price = new QLineEdit();
    new_price->setPlaceholderText("The price of the new product");

    addbtn = new QPushButton("Add");

    hlayout = new QHBoxLayout();
    slider = new QSlider();
    slider->setMinimum(0);
    slider->setMaximum(100);
    sld_lbl = new QLabel();
    sld_lbl->setText(QString::fromStdString("The value from slider is: " + to_string(slider->value())));
    hlayout->addWidget(slider);
    hlayout->addWidget(sld_lbl);

    layout->addWidget(new_id);
    layout->addWidget(new_name);
    layout->addWidget(new_type);
    layout->addWidget(new_price);
    layout->addWidget(addbtn);
    layout->addLayout(hlayout);

    update();

}

void GUIObserver::update() {
    loadData(serv.get_Sorted_prod());
}

void GUIObserver::make_connections() {

    QObject::connect(slider, &QSlider::valueChanged, [&](){
        sld_lbl->setText(QString::fromStdString("The value from slider is: " + to_string(slider->value())));
        update();
    });

    QObject::connect(addbtn, &QPushButton::clicked, [&](){
        if (new_name->text().isEmpty())
            QMessageBox::critical(this, "critical", QString::fromStdString("You cannot put an empty description!"));
        else if (new_price->text().toDouble() < 0 or new_price->text().toDouble() > 100){
            QMessageBox::critical(this, "critical", QString::fromStdString("You cannot put a price not ranged between 0 and 100!"));
        }
        else{
            try {
                serv.add_product(stoi(new_id->text().toStdString()), new_name->text().toStdString(), new_type->text().toStdString(), new_price->text().toDouble());
                update();
                notifyObservers();
            }
            catch (ProductException& ex){
                QMessageBox::critical(this, "critical", QString::fromStdString("The id is not unique!"));
            }
        }
    });

}

void GUIObserver::loadData(const vector<Produs> &prds) {
    tbl->setProducts(prds, slider->value());
}
