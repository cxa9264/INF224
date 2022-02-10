#ifndef GROUP
#include <list>
#include <string>
#include <memory>

#include "Base.h"

class Group : public std::list<BasePtr> {
   private:
    string groupName = "";

   public:
    Group(string);
    ~Group();
    string getGrpouName() const;
    void display(ostream& os) const;
    
};
#define GROUP
#endif