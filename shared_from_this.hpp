#include <iostream>
#include <memory>
#include <list>

using namespace std;

class Boo : public enable_shared_from_this<Boo> {
public:
    string name;

    Boo(string n)
        : name{n}
    { cout << "CTOR " << name << '\n'; }

    ~Boo() { cout << "DTOR " << name << '\n'; }

    template <typename T>
    void add(T &container) {
        container.push_back(shared_from_this());
    }
};

void test_shared_from_this()
{
    list<shared_ptr<Boo>> l;

    for (size_t i {1}; i < 10; ++i) {
        string s (i, 'X');
        make_shared<Boo>(s)->add(l);
    }

    cout << "Items in list: " << l.size() << '\n';
}
