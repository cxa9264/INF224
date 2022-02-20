#include "Table.h"

#include <sys/stat.h>

#include <algorithm>

#include "Def.h"
#include "Film.h"
#include "Group.h"
#include "Photo.h"
#include "Video.h"

Table::Table() {
#ifdef TEST_SERIALIZATION
    mkdir(SERIALIZE_PATH, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif
}

bool Table::createGroup(const string name) {
    // @breif: create a group
    // @param: name, string, group name
    // @ret: bool, success signal
    groups[name] = new Group(name);
    return true;
}

bool Table::showMedia(const string name, ostream &os) const {
    // @breif: find and play a multimedia object
    // @param: name, string, object name to find
    // @param: os, ostrema&, output stream
    // @ret: bool, success signal
    std::map<string, BasePtr>::const_iterator it = multimedias.find(name);
    if (it != multimedias.end()) {
        it->second->show();
        os << "Start playing...";
        return true;
    }
    os << "Not found!";
    return false;
}

bool Table::findMultimediaDisplay(const string name, ostream &os) const {
    // @breif: find a multimedia object and display
    // @param: name, string, object name to find
    // @param: os, ostrema&, output stream
    // @ret: bool, success signal
    std::map<string, BasePtr>::const_iterator it = multimedias.find(name);
    if (it != multimedias.end()) {
        it->second->display(os);
        return true;
    }
    return false;
}

bool Table::findGroupDisplay(const string name, ostream &os) const {
    // @breif: find a group object and siplay
    // @param: name, string, group name to find
    // @param: os, ostrema&, output stream
    // @ret: bool, success signal
    std::map<string, Group *>::const_iterator it = groups.find(name);
    if (it != groups.end()) {
        it->second->display(os);
        return true;
    }
    return false;
}

Group *Table::findGroup(const string name) const {
    // @breif: find a group object
    // @param: name, string, group name to find
    // @ret: Group *, a pointer to found group, nullptr if not found
    std::map<string, Group *>::const_iterator it = groups.find(name);
    if (it != groups.end()) {
        return it->second;
    }
    return nullptr;
}

BasePtr Table::findMultimedia(const string name) const {
    // @breif: find a multimedia object
    // @param: name, string, object name to find
    // @ret: BasePtr, a pointer to found multimedia, nullptr if not found
    std::map<string, BasePtr>::const_iterator it = multimedias.find(name);
    if (it != multimedias.end()) {
        return it->second;
    }
    return nullptr;
}

bool Table::removeMultimedia(const string name, ostream &os) {
    // @breif: find a multimedia object and remove it
    // @param: name, string, object name to find
    // @ret: bool, success signal
    map<string, BasePtr>::iterator it = multimedias.find(name);
    if (it != multimedias.end()) {
        // remove it from all groups
        for (map<string, Group *>::const_iterator it_groups = groups.begin();
             it_groups != groups.end(); it_groups++) {
            list<BasePtr>::iterator it_group = it_groups->second->find(name);
            if (it_group != it_groups->second->end()) {
                it_groups->second->erase(it_group);
                cout << "Deleted from " << it_groups->first << endl;
            }
        }

        multimedias.erase(it);
        os << "Removed!" << endl;
        return true;
    }
    os << "Err: Not found!" << endl;
    return false;
}

bool Table::removeGroup(const string name, ostream &os) {
    // @breif: find a group object and remove it
    // @param: name, string, object name to find
    // @ret: bool, success signal
    map<string, Group *>::iterator it = groups.find(name);
    if (it != groups.end()) {
        groups.erase(it);
        os << "Removed!" << endl;
        return true;
    }
    os << "Err: Not found!" << endl;
    return false;
}