//
// Created by munte on 21/06/2021.
//

#include <fstream>
#include "GUIObserver.h"
#include "Exceptions.h"

void WriterWindow::loadData(const vector<Idea> &ids) {
    tbl->setIdeas(ids);
}

void WriterWindow::update() {
    loadData(serv.getSortedIdeas());
    if (serv.has_accepted(name_wrt)) {
        develop->setEnabled(true);
    } else {
        develop->setEnabled(false);
    }
}

void WriterWindow::initGUI() {
    layout = new QVBoxLayout();
    this->setLayout(layout);
    this->setWindowTitle(QString::fromStdString(name_wrt));
    tblView->setModel(tbl);
    update();
    layout->addWidget(tblView);

    description = new QLineEdit();
    description->setPlaceholderText("Add the description");

    act = new QLineEdit();
    act->setPlaceholderText("Add the act");

    addIdea = new QPushButton("Add idea");

    revise = new QPushButton("Revise idea");

    save_plot = new QPushButton("Save plot");


    //save = new QPushButton("Save idea");

    layout->addWidget(description);
    layout->addWidget(act);
    layout->addWidget(addIdea);
    layout->addWidget(revise);

    layout->addWidget(develop);
    if (serv.has_accepted(name_wrt)) {
        develop->setEnabled(true);
    } else {
        develop->setEnabled(false);
    }
    layout->addWidget(save_plot);

    this->show();
}

void WriterWindow::make_connections() {

    QObject::connect(save_plot, &QPushButton::clicked, [&]() {
        std::ofstream myfile;
        myfile.open(name_wrt + "_plot.txt", std::ios::app);
        int current_act = 0;
        for (auto &el:serv.getSortedIdeas()) {
            if (el.getStatus() == "accepted") {
                if (current_act != el.getAct()) {
                    myfile << "Act " << el.getAct() << ":" << "\n";
                    current_act = el.getAct();
                }
                myfile << el.getDescription() << " (" << el.getCreator() << ")" << "\n";
            }
        }
        myfile.close();
    });

    QObject::connect(develop, &QPushButton::clicked, [&]() {
        for (auto &el:serv.getIdeas()) {
            if (el.getCreator() == name_wrt and el.getStatus() == "accepted") {
                auto hlayout = new QHBoxLayout();
                auto save_btn = new QPushButton("Save");
                auto txt_edt = new QTextEdit();
                hlayout->addWidget(txt_edt);
                hlayout->addWidget(save_btn);
                layout->addLayout(hlayout);
                txt_edt->insertPlainText(QString::fromStdString(el.tostring()));
                auto pair = std::make_shared<std::pair<QPushButton *, QTextEdit *>>(save_btn, txt_edt);
                QObject::connect(save_btn, &QPushButton::clicked, [&, pair]() {

                    std::ofstream myfile;

                    // std::ios::app is the open mode "append" meaning
                    // new data will be written to the end of the file.
                    myfile.open(name_wrt + ".txt", std::ios::app);
                    myfile << pair->second->toPlainText().toStdString() << "\n";
                    myfile.close();
                });
            }
        }
    });

    QObject::connect(revise, &QPushButton::clicked, [&]() {
        if (tblView->currentIndex().isValid()) {
            int selRow = tblView->selectionModel()->selectedIndexes().at(0).row();
            auto cellIndex = tblView->model()->index(selRow, 0);
            auto cellValue = tblView->model()->data(cellIndex, Qt::DisplayRole).toString();

            serv.accept_idea(cellValue.toStdString());
            notifyObservers();
        }
    });

    QObject::connect(tblView->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
        if (tblView->currentIndex().isValid()) {
            int selRow = tblView->selectionModel()->selectedIndexes().at(0).row();

            auto cellIndex = tblView->model()->index(selRow, 1);
            auto cellValue = tblView->model()->data(cellIndex, Qt::DisplayRole).toString();
            if (cellValue.toStdString() == "proposed" && wrt_exp == "Senior") {
                revise->setEnabled(true);
            } else {
                revise->setEnabled(false);
            }
        }

    });

    QObject::connect(addIdea, &QPushButton::clicked, [&]() {
        if (description->text().isEmpty()) {
            QMessageBox::critical(this, "critical", QString::fromStdString("You cannot put an empty description!"));
            return;
        } else if (act->text().toStdString() != "1" and act->text().toStdString() != "2" and
                   act->text().toStdString() != "3") {
            QMessageBox::critical(this, "critical", QString::fromStdString("Invalid act!"));
        } else {
            try {
                serv.add_idea(description->text().toStdString(), name_wrt, act->text().toInt());
                notifyObservers();
            }
            catch (IdeaException &ie) {
                QMessageBox::critical(this, "critical", QString::fromStdString("Idea already exists"));

            }
        }
    });
}

void GUIObserver::initGUI() {
    for (auto it : serv.getWriters()) {
        addObserver(new WriterWindow(serv, observers, it));
    }
    addObserver(this);
    layout = new QVBoxLayout();
    this->setLayout(layout);
}

void GUIObserver::update() {
    QWidget::update();
}

void GUIObserver::make_connections() {

}
