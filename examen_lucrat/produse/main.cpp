#include <iostream>
#include <QApplication>
#include "RepoProduse.h"
#include "Service.h"
#include "GUIObserver.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    //BooksRepo rep;
    RepoProduse rp;
    Service serv(rp);
    GUIObserver gui{ serv };
    gui.show();
    return a.exec();
    //serv.write_to_file();
    return 0;
}