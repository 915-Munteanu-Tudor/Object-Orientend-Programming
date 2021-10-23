#include <iostream>
#include <QApplication>
#include "RepoWriter.h"
#include "RepoIdea.h"
#include "Service.h"
#include "GUIObserver.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    //BooksRepo rep;
    RepoIdea ri;
    RepoWriter rw;
    Service serv(ri, rw);
    GUIObserver gui{ serv };
    gui.show();
    return a.exec();
    //serv.write_to_file();
    return 0;
}
