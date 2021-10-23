#include <iostream>
#include <utility>
#include <cstring>
#include "vector"
#include "error.h"
#include "string"
#include "fstream"
#include "ostream"
#include "cassert"

using namespace std;
class HTMLElement{
public:
    virtual string getHTMLString() = 0;

    virtual ~HTMLElement() = default;
    virtual ostream &operator<<(ostream &os) = 0;

};

class HTMLParagraph: public HTMLElement{
private:
    string pargraph;
public:
    HTMLParagraph(string pargraph) : pargraph(std::move(pargraph)) {}

    string getHTMLString() override{
        return "<p>" + pargraph + "</p>";
    }

    ostream &operator<<(ostream &os) override {
        os << getHTMLString();
        return os;
    }

    friend ostream &operator<<(ostream &os, HTMLParagraph paragraph) {
        os << paragraph.getHTMLString();
        return os;
    }
};

class HTMLImage: public HTMLElement{
private:
    string image;
public:
    HTMLImage(string image) : image(std::move(image)) {}

    string getHTMLString() override{
        return "<img>" + image + "</img>";
    }
    ostream &operator<<(ostream &os) override {
        os << getHTMLString();
        return os;
    }

    friend ostream &operator<<(ostream &os, HTMLImage imag) {
        os << imag.getHTMLString();
        return os;
    }

};

template<typename T> class HTMLBuilder{
private:
    vector<T> html;
public:

    auto begin() {
        return this->html.begin();
    }

    auto end() {
        return this->html.end();
    }

    auto size() const{
        html->size();
    }

    auto operator+=(T other){
        if(other == nullptr){
            throw runtime_error("Cannot add a null element!");
        }
        html.push_back(other);
        return *this;
    }

    ostream &operator<<(ostream &os) {
        for(auto &el:html){
            os << el;
        }
        return os;
    }

};


void fct1() {
    HTMLElement* p1 = new HTMLParagraph{ "Examination" };
    assert(p1->getHTMLString() == "<p>Examination</p>");
    HTMLElement* p2 = nullptr;
    HTMLElement* i1 = new HTMLImage{ "a.jpg" };
    HTMLElement* i2 = new HTMLImage{ "b.jpg" };
    assert(i2->getHTMLString() == "<img>b.jpg</img>");
    HTMLBuilder<HTMLElement*> html{};
    try {
        html += p2;
        assert(false);
    } catch (runtime_error& e) {
        assert(strcmp(e.what(), "Cannot add a null element!") == 0); }

    ((html += p1) += i1) += i2;
    cout << html; // prints: <html><body><p>Examination</p><img>a.jpg</img><img>b.jpg</img></html></body>
    delete p1; delete p2;
    delete i1; delete i2;
}

int main(){
    fct1();
}