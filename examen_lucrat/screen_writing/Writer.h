//
// Created by munte on 21/06/2021.
//

#ifndef SCREEN_WRITING_WRITER_H
#define SCREEN_WRITING_WRITER_H
#include <iostream>
using namespace std;

class Writer {
public:
    Writer() = default;

    Writer(string name, string expertise);

    const string &getName() const;

    void setName(const string &name);

    const string &getExpertise() const;

    void setExpertise(const string &expertise);

    friend std::ostream &operator<<(std::ostream &os, const Writer &wrt);


    friend std::istream &operator>>(std::istream &is, Writer &wrt);

    std::string tostring(){
        return name + ";" + expertise;
    }

private:
    string name;
    string expertise;
public:

};


#endif //SCREEN_WRITING_WRITER_H
