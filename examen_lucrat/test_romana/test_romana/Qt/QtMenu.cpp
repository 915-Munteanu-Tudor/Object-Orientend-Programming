//
// Created by kida on 5/23/21.
//

#include <QVBoxLayout>
#include "QtMenu.h"

QtMenu::QtMenu(Service &ms) : ms(ms) {
    this->setWindowTitle("Concerte");
    this->setStyleSheet("background-color: black");
    //this->resize(1500, 900);
    ms.read_from_file();
    initGUI();
    make_connections();
}

void QtMenu::initGUI() {
    vLayout = new QVBoxLayout();
    this->setLayout(vLayout);
    QFont sansFont("Helvetica [Cronyx]", 12);
    wl_list = new QListWidget{};
    wl_list->setStyleSheet("QListWidget {background-color: #596866; color: black;}");
    populate_movies();
    vLayout->addWidget(wl_list);
    hLayout = new QHBoxLayout;
    slider = new QSlider(Qt::Horizontal);
    slider->setStyleSheet("QSlider {background-color: #596866; color: black;}");
    slider->setMaximum(10);
    slider->setMinimum(1);
    slider->setValue(1);
    //slider->setTickInterval(1);
    tmpLabel = new QLabel("1");
    tmpLabel->setStyleSheet("QLabel {background-color: #596866; color: black;}");
    hLayout->addWidget(tmpLabel);
    hLayout->addWidget(slider);
    vLayout->addLayout(hLayout);
    modificare = new QPushButton("Modificare");
    modificare->setFont(sansFont);
    modificare->setStyleSheet("QPushButton {background-color: #596866; color: black;}");
    vLayout->addWidget(modificare);

    grup_cumparare = new QGroupBox("Cumparare bilete");
    grup_cumparare->setStyleSheet("QGroupBox {background-color: black; color: white;}");
    QFormLayout *layout3 = new QFormLayout;
    optiune_cumparare = new QLineEdit(this);
    optiune_cumparare->setFont(sansFont);
    optiune_cumparare->setStyleSheet("QLineEdit {background-color: #596866; color: black;}");
    optiune_cumparare->setPlaceholderText("Nr bilete de cumparat");
    layout3->addRow(optiune_cumparare);
    pret = new QLineEdit(this);
    pret->setFont(sansFont);
    pret->setStyleSheet("QLineEdit {background-color: #596866; color: black;}");
    pret->setPlaceholderText("Pret total");
    layout3->addRow(pret);

    bilete = new QLineEdit(this);
    bilete->setFont(sansFont);
    bilete->setStyleSheet("QLineEdit {background-color: #596866; color: black;}");
    bilete->setPlaceholderText("Total bilete");
    layout3->addRow(bilete);

    cumparabtn = new QPushButton("Cumpara");
    cumparabtn->setFont(sansFont);
    cumparabtn->setStyleSheet("QPushButton {background-color: #596866; color: black;}");
    layout3->addRow(cumparabtn);

    grup_cumparare->setLayout(layout3);
    vLayout->addWidget(grup_cumparare);

    grup_adaugare = new QGroupBox("Adauga un concert");
    grup_adaugare->setStyleSheet("QGroupBox {background-color: black; color: white;}");
    QFormLayout *layout4 = new QFormLayout;
    nume_nou = new QLineEdit(this);
    nume_nou->setFont(sansFont);
    nume_nou->setStyleSheet("QLineEdit {background-color: #596866; color: black;}");
    nume_nou->setPlaceholderText("Numele formatiei");
    layout4->addRow(nume_nou);
    data_nou = new QLineEdit(this);
    data_nou->setFont(sansFont);
    data_nou->setStyleSheet("QLineEdit {background-color: #596866; color: black;}");
    data_nou->setPlaceholderText("Data noua");
    layout4->addRow(data_nou);

    pret_nou = new QLineEdit(this);
    pret_nou->setFont(sansFont);
    pret_nou->setStyleSheet("QLineEdit {background-color: #596866; color: black;}");
    pret_nou->setPlaceholderText("Pret nou");
    layout4->addRow(pret_nou);

    numar_nou = new QSpinBox;
    numar_nou->setStyleSheet("QSpinBox {background-color: #596866; color: black;}");
    numar_nou->setMinimum(1);
    numar_nou->setMaximum(1000);
    numar_nou->setSingleStep(1);
    layout4->addRow(numar_nou);
    adauga = new QPushButton("Adauga");
    adauga->setFont(sansFont);
    adauga->setStyleSheet("QPushButton {background-color: #596866; color: black;}");
    layout4->addRow(adauga);

    grup_adaugare->setLayout(layout4);
    vLayout->addWidget(grup_adaugare);

    sortbtn = new QPushButton("Sorteaza cronologic");
    sortbtn->setFont(sansFont);
    sortbtn->setStyleSheet("QPushButton {background-color: #596866; color: black;}");
    vLayout->addWidget(sortbtn);

    combo_box = new QComboBox;
    combo_box->addItem(QString::fromStdString("Ieftin"));
    combo_box->addItem(QString::fromStdString("Rezonabil"));
    combo_box->addItem(QString::fromStdString("Scump"));
    combo_box->setStyleSheet("QComboBox {background-color: #596866; color: white;}");
    vLayout->addWidget(combo_box);

    vizualizeaza = new QPushButton("Vizualizeaza");
    vizualizeaza->setFont(sansFont);
    vizualizeaza->setStyleSheet("QPushButton {background-color: #596866; color: black;}");
    vLayout->addWidget(vizualizeaza);

    export_field = new QLineEdit(this);
    export_field->setFont(sansFont);
    export_field->setStyleSheet("QLineEdit {background-color: #596866; color: black;}");
    export_field->setPlaceholderText("Nume fisier");
    vLayout->addWidget(export_field);

    exporteaza = new QPushButton("Exporteaza");
    exporteaza->setFont(sansFont);
    exporteaza->setStyleSheet("QPushButton {background-color: #596866; color: black;}");
    vLayout->addWidget(exporteaza);
}

void QtMenu::make_connections() {
    QObject::connect(slider, &QSlider::valueChanged, this, [=](){
        tmpLabel->setText(QString::number(slider->value()));
    });
    QObject::connect(modificare, &QPushButton::clicked, [&]() {
        if (wl_list->selectedItems().isEmpty()) {
            QMessageBox::critical(this, "Error", "No concerts selected");
            return;
        }
        QListWidgetItem* concert_item = wl_list->selectedItems().at(0);

        std::string movie_raw[10];
        int nr_words = 0;
        for(int i = 0; i < concert_item->text().toStdString().size(); i++) {
            if (concert_item->text().toStdString()[i] == ';' || concert_item->text().toStdString()[i] == '\0') {
                nr_words++;
            } else {
                movie_raw[nr_words] += concert_item->text().toStdString()[i];
            }
        }
        for(auto &c : *ms.get_elements()) {
            if(c.getNumeFormatie() == movie_raw[0]) {
                if(slider->value() * c.getNumarBilete() > 500) {
                    QMessageBox::critical(this, "Error", "Prea multe bilete");
                    return;
                }
                else {
                    c.setNumarBilete(c.getNumarBilete() * slider->value());
                    populate_movies();
                    return;
                }
            }
        }

    });
    QObject::connect(cumparabtn, &QPushButton::clicked, [&]() {
        if (wl_list->selectedItems().isEmpty()) {
            QMessageBox::critical(this, "Error", "No concerts selected");
            return;
        }
        QListWidgetItem* concert_item = wl_list->selectedItems().at(0);

        std::string movie_raw[10];
        int nr_words = 0;
        for(int i = 0; i < concert_item->text().toStdString().size(); i++) {
            if (concert_item->text().toStdString()[i] == ';' || concert_item->text().toStdString()[i] == '\0') {
                nr_words++;
            } else {
                movie_raw[nr_words] += concert_item->text().toStdString()[i];
            }
        }
        for(auto &c : *ms.get_elements()) {
            if(c.getNumeFormatie() == movie_raw[0]) {
                if(c.getNumarBilete() < stoi(optiune_cumparare->text().toStdString())) {
                    QMessageBox::critical(this, "Error", "Not enough tickets");
                    return;
                }
                else {
                    c.setNumarBilete(c.getNumarBilete() - stoi(optiune_cumparare->text().toStdString()));
                    populate_movies();
                    pret_total += stoi(optiune_cumparare->text().toStdString()) * c.getPretBilet();
                    nr_bilete += stoi(optiune_cumparare->text().toStdString());
                    bilete->setText(QString::fromStdString(std::to_string(nr_bilete)));
                    pret->setText(QString::fromStdString(std::to_string(pret_total)));
                    return;
                }
            }
        }
    });

    QObject::connect(sortbtn, &QPushButton::clicked, this, &QtMenu::populate_movies_sorted);

    QObject::connect(adauga, &QPushButton::clicked, this, &QtMenu::add);


    //QObject::connect(combo_box, &QComboBox::currentIndexChanged, [&](){
    QObject::connect(vizualizeaza, &QPushButton::clicked, [&](){
        if(combo_box->currentText().toStdString() == "Ieftin") {
            wl_list->clear();
            for(const auto& c: *ms.get_elements()) {
                wl_list->addItem(QString::fromStdString(c.getNumeFormatie() + ";" + c.getDate().to_string() + ";" + std::to_string(c.getNumarBilete()) + ";" + std::to_string(c.getPretBilet())));
                if(c.getPretBilet() < 50) {
                    wl_list->item(wl_list->count() - 1)->setForeground(Qt::green);
                }
            }
        }
        else if(combo_box->currentText().toStdString() == "Rezonabil") {
            wl_list->clear();
            for(const auto& c: *ms.get_elements()) {
                wl_list->addItem(QString::fromStdString(c.getNumeFormatie() + ";" + c.getDate().to_string() + ";" + std::to_string(c.getNumarBilete()) + ";" + std::to_string(c.getPretBilet())));
                if(c.getPretBilet() >= 51 && c.getPretBilet() <= 150) {
                    wl_list->item(wl_list->count() - 1)->setForeground(Qt::magenta);
                }
            }
        }
        else {
            wl_list->clear();
            for(const auto& c: *ms.get_elements()) {
                wl_list->addItem(QString::fromStdString(c.getNumeFormatie() + ";" + c.getDate().to_string() + ";" + std::to_string(c.getNumarBilete()) + ";" + std::to_string(c.getPretBilet())));
                if(c.getPretBilet() > 151 && c.getPretBilet() <= 250) {
                    wl_list->item(wl_list->count() - 1)->setForeground(Qt::yellow);
                }
            }
        }
    });

    QObject::connect(exporteaza, &QPushButton::clicked, [&]() {
        std::ofstream f(export_field->text().toStdString());
        std::string optiune = combo_box->currentText().toStdString();
        for (const Concert &mv: *ms.get_elements()) {
            if(optiune == "Ieftin" && mv.getPretBilet() < 50)
                f << mv;
            else if(optiune == "Rezonabil" && mv.getPretBilet() > 50 && mv.getPretBilet() <= 150)
                f << mv;
            else if(optiune == "Scump" && mv.getPretBilet() > 150)
                f << mv;
        }
        f.close();
    });

}

void QtMenu::populate_movies() {
    wl_list->clear();
    for(const auto& c: *ms.get_elements()) {
        wl_list->addItem(QString::fromStdString(c.getNumeFormatie() + ";" + c.getDate().to_string() + ";" + std::to_string(c.getNumarBilete()) + ";" + std::to_string(c.getPretBilet())));

    }
}

void QtMenu::populate_movies_sorted() {
    wl_list->clear();
    std::vector<Concert> new_v = *ms.get_elements();
    std::sort(new_v.begin(), new_v.end());
    for(const auto& c: new_v) {
        wl_list->addItem(QString::fromStdString(c.getNumeFormatie() + ";" + c.getDate().to_string() + ";" + std::to_string(c.getNumarBilete()) + ";" + std::to_string(c.getPretBilet())));

    }
}

void QtMenu::add() {
    Concert c;
    c.setNumeFormatie(nume_nou->text().toStdString());
    int nr_words = 0;
    std::string data_raw[10];
    for(int i = 0; i < data_nou->text().toStdString().size(); i++) {
        if(data_nou->text().toStdString()[i] == '/' || data_nou->text().toStdString()[i] == '\0') {
            nr_words++;
        }
        else {
            data_raw[nr_words] += data_nou->text().toStdString()[i];
        }
    }
    int dummy = 0;
    if(nr_words != 1) {
        QMessageBox::critical(this, "Error", "Data invalida");
        return;
    }
    else if(!ms.tryParse(data_raw[0], dummy) || !ms.tryParse(data_raw[1], dummy)) {
        QMessageBox::critical(this, "Error", "Data invalida");
        return;
    }
    else if(stoi(data_raw[0]) > 12 || stoi(data_raw[0]) < 1 || stoi(data_raw[1]) > 31 || stoi(data_raw[1]) < 1) {
        QMessageBox::critical(this, "Error", "Data invalida");
        return;
    }
    else if(pret_nou->text().toInt() < 10 || pret_nou->text().toInt() > 250) {
        QMessageBox::critical(this, "Error", "Pret invalid");
        return;
    }
    c.setDate(Data(stoi(data_raw[0]), stoi(data_raw[1])));
    c.setPretBilet(pret_nou->text().toInt());
    c.setNumarBilete(numar_nou->value());
    ms.get_elements()->push_back(c);
    populate_movies();
}
