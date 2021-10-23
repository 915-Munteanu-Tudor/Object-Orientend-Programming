#include <iostream>
#include <QApplication>
#include "RepoProgrammer.h"
#include "RepoSourceFile.h"
#include "Service.h"
#include "GUIObserver.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    //BooksRepo rep;
    RepoProgrammer rp;
    RepoSourceFile rsf;
    Service serv(rp, rsf);
    GUIObserver gui{ serv };
    gui.show();
    return a.exec();
}
