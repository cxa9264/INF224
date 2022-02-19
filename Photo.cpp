#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>

#include "Photo.h"
#include "Def.h"

using namespace std;

Photo::Photo() : Base::Base() {}

Photo::Photo(string _name, string _path, int _latitude, int _longtitude)
    : Base(_name, _path) {
        latitude = _latitude;
        longtitude = _longtitude;
}

Photo::~Photo() {
#ifdef TEST_SMART_PTR
    cout << "Photo object deleted: " << endl;
    display(cout);
    cout << endl;
#endif
}

void Photo::setLatitude(int _latitude) {
    // @breif: set photo latitude
    // @param: int, latitude
    // @ret: void
    latitude = _latitude;
}

void Photo::setLongtitude(int _longtitude) {
    // @breif: set photo longtitude
    // @param: int, longtitude
    // @ret: void
    longtitude = _longtitude;
}

int Photo::getLongtitude() const {
    // @breif: get photo longtitude
    // @param: void
    // @ret: longtitude of photo
    return longtitude;
}

int Photo::getLatitude() const {
    // @breif: get photo latitude
    // @param: void
    // @ret: latitude of photo
    return latitude;
}

void Photo::display(ostream& os) const {
    // @breif: show information of photo
    // @param: ostream&, output stream
    // @ret: void
    os
    << "name: " << name
    << endl
    << "path: " << path
    << endl
    << "longtitude: " << longtitude
    << endl
    << "latitude: " << latitude
    << endl;
}

void Photo::show() const {
    // @breif: show photo with imagej
    // @param: void
    // @ret: void
#ifdef MACOS
    string cmd = "open -a imagej " + path + " &";
#endif
#ifdef LINUX
    string cmd = "imagej " + path + " &";
#endif
    system(cmd.c_str());
}

string Photo::getClassName() const {
    // @breif: return class name
    // @param: void
    // @ret: string, "Photo"
    return "Photo";
}