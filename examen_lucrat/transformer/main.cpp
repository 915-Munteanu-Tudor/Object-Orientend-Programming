#include <iostream>
#include <algorithm>
#include "vector"

using namespace std;

class Transformer{
public:
    Transformer() = default;

    virtual void transform(vector<int>& nrs) = 0;
};

class Adder: public Transformer{
private:
    int cat;
public:
    Adder(int cat) : cat(cat) {}

    void transform(vector<int>& nrs) override{
        for (auto &el:nrs){
            el+=cat;
        }
    }
};

class Swapper:public Transformer{
public:
    Swapper() = default;

    void transform(vector<int>& nrs) override{
        for (int i = 0; i < nrs.size()-1; i+=2) {
            swap(nrs[i],nrs[i+1]);
        }
    }
};

class Nuller: public Adder{
public:
    Nuller(int cat) : Adder(cat) {}

    void transform(vector<int>& nrs) override{
        for(auto &el:nrs){
            if (el > 10){
                el = 0;
            }
        }
    }
};

class Composite: public Transformer{
private:
    Transformer* t1;
    Transformer* t2;
public:
    Composite(Transformer *t1, Transformer *t2) : t1(t1), t2(t2) {}

    void transform(vector<int>& nrs) override{
        t1->transform(nrs);
        t2->transform(nrs);
    }
};

class Numbers{
private:
    vector<int> nr;
    Transformer* t1;
public:
    Numbers(Transformer *t1) : t1(t1) {}

    void addd(int x){
        nr.push_back(x);
    }
    vector<int>& transform(){
        std::sort(nr.begin(), nr.end(), greater<>());
        t1->transform(nr);
        return nr;
    }
};

int main() {

    auto n = new Nuller(9);
    auto s = new Swapper();
    auto a = new Adder(3);
    auto c1 = new Composite(s,a);
    auto c2 = new Composite(n,c1);

    auto x = new Numbers(c2);
    x->addd(1); // pune 1
    x->addd(3); // pune 3
    x->addd(5); // pune 5
    // le ordoneaza => 5 3 1
    // face adder => 8 6 4
    // face swap => 6 8 4
    // face nuller => 6 8 4
    for(auto &el:x->transform()){
        cout << el << " ";
    }
    return 0;
}
