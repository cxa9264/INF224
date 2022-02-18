#include "Group.h"

#include <iostream>
#include <string>


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
    os << "Group name: " << groupName << "行";
    for (list<BasePtr>::const_iterator iter = begin(); iter != end(); ++iter) {
        (*iter)->display(os);
        os << "行";
    }
}
