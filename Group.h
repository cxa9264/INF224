#ifndef GROUP
#include <list>
#include <string>
#include <memory>

#include "Base.h"

class Group : public std::list<BasePtr> {
   private:
    string groupName = "";

   public:
    Group();
    Group(string);
    ~Group();
    string getGrpouName() const;
    void display(ostream& os) const;
    list<BasePtr>::iterator find(const string);
};
#define GROUP
#endif