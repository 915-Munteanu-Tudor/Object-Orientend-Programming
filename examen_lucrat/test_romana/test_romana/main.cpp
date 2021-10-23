#include <iostream>
#include "Repository.h"
#include "Service.h"
#include "Qt/QtUi.h"

int main(int argc, char** argv) {
    auto *v = new std::vector<Concert>;
    Repository repo = Repository(v, "concerte.txt");
    Service cs = Service(repo);
    return QtUi(argc, argv, cs).mainloop();
}
