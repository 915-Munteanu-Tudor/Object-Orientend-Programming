//
// Created by munte on 18/06/2021.
//

#include <mshtmlc.h>
#include "GUIObserver.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QPainterPath>

void GUIObserver::initGUI() {
    for (auto pg : serv.getProgrammers()) {
        addObserver(new ProgrammerWindow(serv, observers, pg));
    }
    addObserver(this);
    update();

}

void GUIObserver::update() {
    paint_circles(serv.getSourceFiles());
}

void GUIObserver::paint_circles(const vector<SourceFile> &sfs) {
    QPainter p{ this };
    //p.drawLine(0, 0, width(), height());
    //p.drawImage(x,0,QImage("sky.jpg"));
    p.setPen(Qt::green);
    p.setFont(QFont("Arial", 30));
    //p.drawText(rect(), Qt::AlignTop | Qt::AlignHCenter, "Qt QPainter");
    //p.fillRect(0, 100, 100, 100,Qt::BrushStyle::Dense1Pattern);
    int x = 100;
    int y = 100;
    for(auto &prog: serv.getProgrammers()) {
        if(prog.getToRevise() == 0) {
            p.setPen(Qt::blue);
        }
        else {
            p.setPen(Qt::green);
        }
        int radius = prog.getNrRevisedFiles() * 10;
        p.drawEllipse(QPointF(x,y), radius, radius);
        p.drawText(QPoint(x, y), QString::fromStdString(prog.getName()));
        x = x + 100;
        y = y + 100;
    }
}

void GUIObserver::paintEvent(QPaintEvent *event) {
    paint_circles(serv.getSourceFiles());
}

void ProgrammerWindow::loadData(const vector<SourceFile> &sfs) {
    table->setRowCount((int) sfs.size());
    int currentRow = 0;
    for (auto const &sf: sfs) {
        auto name = new QTableWidgetItem(QString::fromStdString(sf.getName()));
        //name->setFixedHeight(30);
        //name->setText(QString::fromStdString(sf.getName()));
        //name->setAlignment(Qt::AlignCenter);
        table->setItem(currentRow, 0, name);

        auto status = new QTableWidgetItem(QString::fromStdString(sf.getStatus()));
        table->setItem(currentRow, 1, status);

        auto creator = new QTableWidgetItem(QString::fromStdString(sf.getCreator()));
        table->setItem(currentRow, 2, creator);

        auto reviewer = new QTableWidgetItem(QString::fromStdString(sf.getReviewer()));
        table->setItem(currentRow, 3, reviewer);

        /* auto status = new QLabel();
         status->setFixedHeight(30);
         status->setText(QString::fromStdString(sf.getStatus()));
         status->setAlignment(Qt::AlignCenter);
         table->setCellWidget(currentRow, 1, status);

         auto creator = new QLabel();
         creator->setFixedHeight(30);
         creator->setText(QString::fromStdString(sf.getCreator()));
         creator->setAlignment(Qt::AlignCenter);
         table->setCellWidget(currentRow, 2, creator);

         auto reviewer = new QLabel();
         reviewer->setFixedHeight(30);
         reviewer->setText(QString::fromStdString(sf.getReviewer()));
         reviewer->setAlignment(Qt::AlignCenter);
         table->setCellWidget(currentRow, 3, reviewer);*/
        QFont font;
        font.setBold(true);
        if (sf.getStatus() == "not_revised") {
            name->setFont(font);
            status->setFont(font);
            creator->setFont(font);
            reviewer->setFont(font);
            /* name->setStyleSheet("QLabel{font-weight:bold}");
             status->setStyleSheet("QLabel{font-weight:bold}");
             creator->setStyleSheet("QLabel{font-weight:bold}");
             reviewer->setStyleSheet("QLabel{font-weight:bold}");*/
        }
        if (sf.getStatus() == "revised") {
            name->setBackground(Qt::green);
            status->setBackground(Qt::green);
            creator->setBackground(Qt::green);
            reviewer->setBackground(Qt::green);
            /*name->setStyleSheet("QLabel{background-color: lightgreen}");
            status->setStyleSheet("QLabel{background-color: lightgreen}");
            creator->setStyleSheet("QLabel{background-color: lightgreen}");
            reviewer->setStyleSheet("QLabel{background-color: lightgreen}");*/
        }
        currentRow++;
    }
    table->resizeColumnsToContents();
}

void ProgrammerWindow::initGUI() {
    this->setWindowTitle(QString::fromStdString(pg.getName()));
    layout = new QVBoxLayout();
    this->setLayout(layout);

    table = new QTableWidget();
    table->setStyleSheet("background-color: white");
    table->setColumnCount(4);
    table->setRowCount((int) serv.getSourceFiles().size());
    table->setHorizontalHeaderLabels({"Filename", "Status", "Creator", "Reviewer"});
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    table->horizontalHeader()->setStyleSheet("::section{font-weight:bold; color: darkblue; font-size: 13px;}");
    table->verticalHeader()->setStyleSheet("::section{font-weight:bold; color: darkblue; font-size: 13px;}");
    loadData(serv.getSortByName());
    layout->addWidget(table);

    revise = new QPushButton("Revise");
    revise->setEnabled(false);
    layout->addWidget(revise);
    revised = new QLabel();
    revised->setText(QString::fromStdString("Revised: " + to_string(pg.getNrRevisedFiles())));
    to_revise = new QLabel();
    to_revise->setText(QString::fromStdString("Unrevised: " + to_string(pg.getToRevise())));
    layout->addWidget(revised);
    layout->addWidget(to_revise);

    hlayout = new QHBoxLayout();
    addBtn = new QPushButton("Add");

    file_to_add = new QLineEdit();
    file_to_add->setPlaceholderText(QString::fromStdString("Name of file"));
    hlayout->addWidget(file_to_add);
    hlayout->addWidget(addBtn);

    layout->addLayout(hlayout);
    this->show();
}

void ProgrammerWindow::update() {
    loadData(serv.getSourceFiles());
}

void ProgrammerWindow::add_file() {

    if (file_to_add->text().isEmpty()) {
        QMessageBox::warning(this, "warning", QString::fromStdString("The filename cannot be empty!"));
        return;
    } else {
        for (const auto &sfs : serv.getSourceFiles()) {
            if (file_to_add->text() == QString::fromStdString(sfs.getName())) {
                QMessageBox::warning(this, "warning", QString::fromStdString("The filename should be unique!"));
                return;
            }
        }
        serv.add(file_to_add->text().toStdString(), name_pg);
        notifyObservers();
        update();
    }
}

void ProgrammerWindow::make_connections() {
    QObject::connect(revise, &QPushButton::clicked, [&](){
        for(auto &sf : serv.getSourceFiles()) {
            if(QString::fromStdString(sf.getName()) == table->item(table->currentRow(), 0)->text()) {
                sf.setStatus("revised");
                sf.setReviewer(name_pg);
                revised_pg++;
                revised->setText(QString::fromStdString("Revised: " + to_string(revised_pg)));
                to_revise_pg--;
                to_revise->setText(QString::fromStdString("Unrevised: " + to_string(to_revise_pg)));

                if(to_revise_pg == 0) {
                    QMessageBox::information(this, "information", QString::fromStdString("Congratulations!"));
                    for(auto& prog : serv.getProgrammers()) {
                        if(prog.getName() == name_pg) {
                            prog.setToRevise(0);
                            return;
                        }
                    }
                }
                notifyObservers();
                return;
            }
        }
    });
    QObject::connect(table, &QTableWidget::itemSelectionChanged, [&]() {
        //table->setSortingEnabled(true);
        //QModelIndex index = table->selectionModel()->selectedColumns().first();
        if (table->item(table->currentRow(), 1)->text() == QString::fromStdString("not_revised") &&
            table->item(table->currentRow(), 2)->text() != QString::fromStdString(name_pg)) {
            revise->setEnabled(true);
        } else {
            revise->setEnabled(false);
        }
        if (table->currentColumn() == 0)
            loadData(serv.getSortByName());
        if (table->currentColumn() == 1)
            loadData(serv.getSortByStatus());
        if (table->currentColumn() == 2)
            loadData(serv.getSortByCreator());
        if (table->currentColumn() == 3)
            loadData(serv.getSortByReviewer());
    });

    QObject::connect(addBtn, &QPushButton::clicked, [&]() {
        add_file();
    });
}

