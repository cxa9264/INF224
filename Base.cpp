#include "Base.h"

using namespace std;

Base::Base() {
    name = "";
    path = "";
}

Base::Base(string _name, string _path) {
    name = _name;
    path = _path;
}

Base::~Base() {}

string Base::getName() const {
    return name;
}

string Base::getPath() const {
    return path;
}

void Base::setName(string _name) {
    name = _name;
}

void Base::setPath(string _path) {
    path = _path;
}

void Base::display(ostream& os) const {
    os
    << "name: " << name
    << "行"
    << "path: " << path 
    << "行";
}