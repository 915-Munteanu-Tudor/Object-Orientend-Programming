#include <utility>
#include <vector>
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "string"
#include <algorithm>
#include <ctime>

using namespace std;

class Channel {
public:
    Channel() = default;
    virtual void send(string msg) = 0;
    virtual ~Channel() = default;
};

class Telephone : public Channel {
private:
    string number;
public:
    Telephone(string nr) : Channel{}, number{std::move(nr )}{};

    void send(string msg) override {
        cout << "dialing: " << number << "\n";
        if (rand() % 10 == 0) {
            throw std::exception();
        }
    }
    virtual ~Telephone() = default;
};

class Fax :public Telephone {

public:
    Fax(string nr) : Telephone{std::move(nr) } {};

    void send(string msg) override {
        try {
            Telephone::send(msg);
            cout << "sending fax";
        }
        catch (std::exception& ex) {

        }
    }
    virtual ~Fax() = default;
};

class SMS :public Telephone {

public:
    SMS(string nr) : Telephone{std::move(nr) } {};

    void send(string msg) override {
        try {
            Telephone::send(msg);
            cout << "sending SMS";
        }
        catch (std::exception& ex) {

        }
    }
    virtual ~SMS() = default;
};

class Failover : public Channel {
private:
    Channel* c1;
    Channel* c2;
public:
    Failover(Channel* c1, Channel* c2) :Channel{}, c1{ c1 }, c2{ c2 } {};
    void send(string msg) override {
        try {
            c1->send(msg);
        }
        catch (std::exception& ex) {
            c2->send(msg);
        }
    }
};

class Contact {
private:
    Channel* c1;
    Channel* c2;
    Channel* c3;
public:
    Contact(Channel* c1, Channel* c2, Channel* c3) : c1{ c1 }, c2{ c2 }, c3{ c3 }{};
    void sendAlarm(const string& msg) {
        while (true) {
            try {
                c1->send(msg);
                return;
            }
            catch (std::exception& ex) {
                try {
                    c2->send(msg);
                    return;
                }
                catch (std::exception& ex) {
                    try {
                        c3->send(msg);
                        return;
                    }
                    catch (std::exception& ex) {

                    }
                }
            }
        }
    }
};

Contact func(vector<Channel*>& dealoca) {
    string nr_tel = "1234567";
    Fax* f = new Fax(nr_tel);
    SMS* s = new SMS(nr_tel);
    Telephone* t = new Telephone(nr_tel);
    Failover* f1 = new Failover(f, s);
    Failover* f2 = new Failover(t, f);
    Failover* f3 = new Failover(f2, s);
    Contact c1{ t,f1,f3 };

    dealoca.push_back(f);
    dealoca.push_back(s);
    dealoca.push_back(t);
    dealoca.push_back(f1);
    dealoca.push_back(f2);

    return c1;
}
int main() {

    {
        vector<Channel*> dealoca;

        srand(time(nullptr));
        Contact c = func(dealoca);
        c.sendAlarm("aa");
        c.sendAlarm("bb");
        c.sendAlarm("cc");

        for (auto& el : dealoca) {
            delete el;
        }
    }

    std::cout << "Memory leak:" << _CrtDumpMemoryLeaks();


    return 0;
}