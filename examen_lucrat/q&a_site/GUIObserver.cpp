//
// Created by munte on 20/06/2021.
//

#include "GUIObserver.h"

void UserWindow::loadData(const vector<Question> &questions) {
    list->clear();
    for (auto it:questions) {
        auto item = new QListWidgetItem(QString::fromStdString(it.tostring()));
        list->addItem(item);
    }
}

void UserWindow::update() {
    loadData(serv.getSortQuestions());
}

void UserWindow::initGUI() {

    this->setWindowTitle(QString::fromStdString(user.getName()));
    layout = new QVBoxLayout();
    this->setLayout(layout);
    list = new QListWidget();
    loadData(serv.getSortQuestions());
    layout->addWidget(list);
    text = new QLineEdit();
    text->setPlaceholderText("Question text");
    layout->addWidget(text);
    addBtn = new QPushButton("Add");
    layout->addWidget(addBtn);
    answers = new QListWidget();
    layout->addWidget(answers);
    new_ans = new QLineEdit();
    new_ans->setPlaceholderText("Add your answer");
    layout->addWidget(new_ans);
    ans_btn = new QPushButton("Add Answer");
    layout->addWidget(ans_btn);
    votes = new QSpinBox();
    votes->setMinimum(0);
    votes->setMaximum(1500);
    layout->addWidget(votes);
    this->show();
}

void UserWindow::make_connections() {
    QObject::connect(votes, &QSpinBox::textChanged, [&](){
        if(answers->currentItem() != nullptr) {
            int id = stoi(answers->currentItem()->text().split(QString::fromStdString(";"))[0].toStdString());
            serv.change_votes(id, votes->value());
            notifyObservers();
        }
    });
    QObject::connect(ans_btn, &QPushButton::clicked, [&](){
        if (new_ans->text().isEmpty()){
            QMessageBox::critical(this, "critical", QString::fromStdString("You cannot put an empty description!"));
        }
        else{
            int id = stoi(list->currentItem()->text().split(QString::fromStdString(";"))[0].toStdString());
            serv.add_answer(name_user, id, new_ans->text().toStdString());
        }
    });

    QObject::connect(list, &QListWidget::itemSelectionChanged, [&](){
        answers->clear();
        if(list->currentItem() != nullptr) {
            for (auto &it: serv.getTopAnswers(
                    stoi(list->currentItem()->text().split(QString::fromStdString(";"))[0].toStdString()))) {
                auto item = new QListWidgetItem(QString::fromStdString(it.tostring()));
                answers->addItem(item);
                if (it.getUser() == name_user) {
                    item->setBackground(Qt::yellow);
                }
            }
        }
    });
    QObject::connect(answers, &QListWidget::itemSelectionChanged, [&](){
        if(answers->currentItem() != nullptr) {
            if (answers->currentItem()->text().split(QString::fromStdString(";"))[2].toStdString() != name_user) {
                votes->setEnabled(true);
                votes->setValue(answers->currentItem()->text().split(QString::fromStdString(";"))[4].toInt());
            } else {
                votes->setEnabled(false);
            }
        }

    });


    QObject::connect(addBtn, &QPushButton::clicked, [&]() {
        if (text->text().isEmpty()) {
            QMessageBox::critical(this, "critical", QString::fromStdString("You cannot put an empty description!"));
        }
        else {
            serv.add_question(name_user, text->text().toStdString());
            notifyObservers();
        }
    });
}

void GUIObserver::initGUI() {
    for (auto pg : serv.getUsers()) {
        addObserver(new UserWindow(serv, observers, pg));
    }
    addObserver(new PaintWindow(serv, observers));
    addObserver(this);
    layout = new QVBoxLayout();
    this->setLayout(layout);
    search = new QLineEdit();
    search->setPlaceholderText(QString::fromStdString("Search the question"));
    layout->addWidget(search);
    question = new QLabel();
    layout->addWidget(question);
    answers = new QListWidget();
    layout->addWidget(answers);
    update();
}

void GUIObserver::update() {

}

void GUIObserver::make_connections() {
    QObject::connect(search, &QLineEdit::textChanged, [&]() {
        int max_match = 0;
        int max_size = 0;
        int max_id = 0;
        std::string max_text;
        int curr_match = 0;
        for (auto qst:serv.getQuestions()) {
            max_size = max(search->text().toStdString().size(), qst.getText().size());
            curr_match = 0;
            for (int i = 0; i < max_size; i++) {
                if (search->text().toStdString()[i] == qst.getText()[i]) {
                    curr_match++;
                }
            }
            if (curr_match > max_match) {
                max_match = curr_match;
                max_id = qst.getId();
                max_text = qst.getText();
            }
        }
        question->setText(QString::fromStdString(max_text));
        answers->clear();
        if (serv.getTopAnswers(max_id).size() >= 3) {
            for (int i = 0; i < 3; i++) {
                auto item = new QListWidgetItem(
                        QString::fromStdString(serv.getTopAnswers(max_id).at(i).getText()));
                answers->addItem(item);
            }
        } else {
            for (int i = 0; i < serv.getTopAnswers(max_id).size(); i++) {
                auto item = new QListWidgetItem(
                        QString::fromStdString(serv.getTopAnswers(max_id).at(i).getText()));
                answers->addItem(item);
            }
        }

    });
}

void PaintWindow::update() {
    paint_bars(serv.getAnswers());
}

void PaintWindow::paint_bars(const vector<Answer> &sfs) {
    QPainter p{ this };
    //p.drawLine(0, 0, width(), height());
    //p.drawImage(x,0,QImage("sky.jpg"));
    p.setPen(Qt::green);
    p.setFont(QFont("Arial", 10));
    //p.drawText(rect(), Qt::AlignTop | Qt::AlignHCenter, "Qt QPainter");
    //p.fillRect(0, 100, 100, 100,Qt::BrushStyle::Dense1Pattern);
    int x = 0;
    int y = 10;
    for(auto &a: serv.getAnswers()) {
        int height = a.getVotes();
        p.drawRect(x, y, 25, height*2);
        p.drawText(QPoint(x, y), QString::fromStdString(to_string(a.getId())));
        x = x + 50;
    }
}

void PaintWindow::paintEvent(QPaintEvent *event) {
    paint_bars(serv.getAnswers());
}
