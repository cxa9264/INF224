#include "Group.h"

#include <iostream>
#include <string>

Group::Group() {}

Group::Group(string _name) {
    // @breif: constructor
    // @param: _name: name of the group
    // @ret: void
    groupName = _name;
}

Group::~Group() {}

void Group::display(ostream& os) const {
    // @breif: display all attributes of the objects in the list
    // @param: void
    // @ret: void
    os << "Group name: " << groupName << endl;
    for (list<BasePtr>::const_iterator iter = begin(); iter != end(); ++iter) {
        (*iter)->display(os);
        os << endl;
    }
}

list<BasePtr>::iterator Group::find(const string name){
    // @breif: find a element with its name
    // @param: name, string, name to find
    // @ret: list<BasePtr>::iterator, iterator to the found element
    list<BasePtr>::iterator it = begin();
    for (; it != end(); it++) {
        if (it->get()->getName() == name) {
            break;
        }
    }
    return it;
}
