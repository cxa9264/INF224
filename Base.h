#ifndef BASE
#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Base {
protected:
    string name;
    string path;
public:
    Base();
    Base(string, string);
    virtual ~Base();
    string getName() const;
    string getPath() const;
    void setName(string);
    void setPath(string);
    virtual void display(ostream&) const;
    virtual void show() const = 0;
};

typedef shared_ptr<Base> BasePtr;
#define BASE
#endif