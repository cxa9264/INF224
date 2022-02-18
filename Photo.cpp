#include "Photo.h"
#ifndef STRING
#include <string>
#define STRING
#endif

using namespace std;

Photo::Photo() : Base::Base() {}

Photo::Photo(string _name, string _path, int _latitude, int _longtitude)
    : Base(_name, _path) {
        latitude = _latitude;
        longtitude = _longtitude;
}

Photo::~Photo() {
    cout << "Photo object deleted: " << endl;
    display(cout);
    cout << endl;
}

void Photo::setLatitude(int _latitude) {
    latitude = _latitude;
}

void Photo::setLongtitude(int _longtitude) {
    longtitude = _longtitude;
}

int Photo::getLongtitude() const {
    return longtitude;
}

int Photo::getLatitude() const {
    return latitude;
}

void Photo::display(ostream& os) const {
    os
    << "name: " << name
    << "行"
    << "path: " << path
    << "行"
    << "longtitude: " << longtitude
    << "行"
    << "latitude: " << latitude
    << "行";
}

void Photo::show() const {
    string cmd = "open -a imagej " + path + " &";
    system(cmd.c_str());
}