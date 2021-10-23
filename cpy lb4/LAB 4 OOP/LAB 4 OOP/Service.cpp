//
// Created by munte on 01/06/2021.
//

#include "Service.h"

void Service::add_dog(const Dog &dog, bool save) {
    repo.add_dog(dog,save);
    auto ptr = std::make_unique<UndoAdd>(this->repo, dog);
    undo.push_back(std::move(ptr));
}

void Service::remove_dog(const string &nm) {

    Dog b;
    for (auto &dog:this->repo.getElements()) {
        if (dog.getName() == nm) {

            auto ptr = std::make_unique<UndoDelete>(this->repo, dog);
            undo.push_back(std::move(ptr));
            break;
        }

    }
    repo.remove_dog(nm);
}

void Service::update_dog(const string &nm, const string &nm1, const string &nm2, char *ag, const string &nm3) {

    Dog b1_vechi;
    Dog b2_nou(nm1,nm2,stoi(ag),nm3);
    for (auto &dog:this->repo.getElements()) {
        if (dog.getName() == nm) {
            b1_vechi = dog;
            auto ptr = std::make_unique<UndoUpdate>(b1_vechi, b2_nou, this->repo);
            undo.push_back(std::move(ptr));
            break;
        }

    }
    repo.update_dog(nm, nm1, nm2, ag, nm3);
}

std::vector<Dog> Service::filter_dogs(const string &nm, const char *nm1) {
    return repo.filter_dogs(nm,nm1);
}

const vector<Dog> &Service::getElements() const {
    return repo.getElements();
}

void Service::Undo() {

    if (undo.empty()) {
        throw std::runtime_error("No more redo!");
    }

    undo.back()->doUndo();
    redo.push_back(std::move(undo.back()));
    undo.pop_back();
}

void Service::Redo() {
    if (redo.empty()) {
        throw std::runtime_error("No more redo!");
    }

    redo.back()->doRedo();
    undo.push_back(std::move(redo.back()));
    redo.pop_back();
}




