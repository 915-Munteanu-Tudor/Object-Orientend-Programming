#pragma once


#include <utility>
#include <algorithm>

#include "Dog.h"
#include "repoDog.h"
#include "exceptions.h"

class Undo {
public:
    virtual void doUndo() = 0;
    virtual void doRedo() = 0;
    virtual ~Undo() = default;
};

class UndoAdd : public Undo {
private:
    Dog b;
    RepoDog& repo;

public:
    UndoAdd(RepoDog& dog, Dog dog1) : repo(dog), b(dog1){} ;


    void doUndo() override {
        repo.remove_dog(b.getName());
    }

    void doRedo() override {
        repo.add_dog(b, true);
    }

};

class UndoDelete : public Undo {
private:
    Dog b;
    RepoDog& repo;

public:
    UndoDelete(RepoDog& repo,  const Dog& b) : repo{ repo }, b{ b }{}

    void doUndo() override {
        repo.add_dog(b, true);
    }

    void doRedo() override {
        repo.remove_dog(b.getName());
    }
};

class UndoUpdate :public Undo {
private:
    Dog b1_vechi;
    Dog b2_nou;
    RepoDog& repo;


public:


    UndoUpdate(const Dog &b1, const Dog &b2, RepoDog &repo) : b1_vechi(b1), b2_nou(b2), repo(repo) {}

    void doUndo() override {
        auto age = std::to_string(b1_vechi.getAge());
        auto age1 = age.c_str();
        repo.update_dog(b2_nou.getName(), b1_vechi.getBreed(), b1_vechi.getName(), const_cast<char *>(age1), b1_vechi.getPhoto());

    }
    void doRedo() override {
        auto age = std::to_string(b2_nou.getAge());
        auto age1 = age.c_str();

        repo.update_dog(b1_vechi.getName(), b2_nou.getBreed(), b2_nou.getName(), const_cast<char *>(age1), b2_nou.getPhoto());
    }
};




