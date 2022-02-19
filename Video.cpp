#include <string>
#include "Video.h"

using namespace std;

Video::Video() : Base::Base() { duration = 0; }

Video::Video(string _name, string _path) : Base::Base(_name, _path) {
    duration = 0;
}

Video::Video(string _name, string _path, int _duration)
    : Base::Base(_name, _path) {
    duration = _duration;
}

void Video::setDuration(int _duration) { duration = _duration; }

int Video::getDuration() const { return duration; }

void Video::display(ostream& os) const {
    os << "name: " << name << endl
       << "path: " << path << endl
       << "duration: " << duration << endl;;
}

void Video::show() const {
    string cmd = "mpv " + path + " &";
    system(cmd.c_str());
}

Video::~Video() {
#ifdef TEST_SMART_PTR
    cout << "Video object deleted: " << endl;
    display(cout);
    cout << endl;
#endif
}

string Video::getClassName() const {
    return "Video";
}