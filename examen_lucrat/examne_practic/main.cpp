#include <iostream>
#include <QApplication>
#include "RepoBuildings.h"
#include "RepoEthnologists.h"
#include "Service.h"
#include "GUIObserver.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    //BooksRepo rep;
    RepoEthnologists re;
    RepoBuildings rb;
    Service serv(rb, re);
    GUIObserver gui{ serv };
    gui.show();
    a.exec();
    //serv.write_to_file();
    return 0;
}
