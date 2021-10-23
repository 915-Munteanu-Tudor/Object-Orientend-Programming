#include <iostream>
#include <QApplication>
#include "RepoAnswers.h"
#include "RepoQuestions.h"
#include "RepoUsers.h"
#include "Service.h"
#include "GUIObserver.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    //BooksRepo rep;
    RepoUsers ru;
    RepoQuestions rq;
    RepoAnswers ra;
    Service serv(ru, rq, ra);
    GUIObserver gui{ serv };
    gui.show();
    a.exec();
    serv.write_to_file();
    return 0;
}
