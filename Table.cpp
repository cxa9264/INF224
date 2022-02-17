#include "Table.h"
#include "Photo.h"
#include "Video.h"
#include "Group.h"
#include "Film.h"

Table::Table() {}

bool Table::showMedia(const string name, ostream &os=cout) const {
    std::map<string, BasePtr>::const_iterator it = multimedias.find(name);
    if (it != multimedias.end()) {
        it->second->show();
        return true;
    }
    return false;
}

bool Table::findMultimediaDisplay(const string name, ostream &os) const {
    std::map<string, BasePtr>::const_iterator it = multimedias.find(name);
    if (it != multimedias.end()) {
        it->second->display(os);
        return true;
    }
    return false;
}

bool Table::findGroupDisplay(const string name, ostream &os) const {
    std::map<string, Group *>::const_iterator it = groups.find(name);
    if (it != groups.end()) {
        it->second->display(os);
        return true;
    }
    return false;
}

const Group * Table::findGroup(const string name) const {
    std::map<string, Group *>::const_iterator it = groups.find(name);
    if (it != groups.end()) {
        return it->second;
    }
    return nullptr;
}

const BasePtr Table::findMultimedia(const string name) const {
    std::map<string, BasePtr>::const_iterator it = multimedias.find(name);
    if (it != multimedias.end()) {
        return it->second;
    }
    return nullptr;
}