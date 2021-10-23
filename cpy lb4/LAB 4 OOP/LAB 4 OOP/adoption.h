#include <vector>
#include "repoDog.h"


class AdoptionList{

protected:
    std::vector<Dog>adoptionlist;
public:

    virtual void write();

    vector<Dog> &getAdoptionlist();
};

class CsvAdoptionList: public AdoptionList{
public:
    void write() override;

};

class HtmlAdoptionList: public AdoptionList{
    void write() override;
};