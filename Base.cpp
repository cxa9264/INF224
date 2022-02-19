#include "Base.h"

using namespace std;

Base::Base() {}

Base::Base(string _name, string _path) : name{_name}, path{_path} {}

Base::~Base() {}

string Base::getName() const {
    // @breif: get file name
    // @param: void
    // @ret: string, name of file
    return name;
}

string Base::getPath() const {
    // @breif: get file path
    // @param: void
    // @ret: string, path of file
    return path;
}

void Base::setName(string _name) {
    // @breif: set file name
    // @param: string, file name
    // @ret: void
    name = _name;
}

void Base::setPath(string _path) {
    // @breif: set file path
    // @param: string, file path
    // @ret: void
    path = _path;
}

void Base::display(ostream& os) const {
    // @breif: output file information
    // @param: ostream&, output stream
    // @ret: void
    os
    << "name: " << name
    << endl
    << "path: " << path 
    << endl;
}