#ifndef VIDEO

#include <memory>
#include <string>

#include "Base.h"
#include "Def.h"

using namespace std;

class Video : public Base {
   protected:
    int duration;
#ifdef DISABLE_CONSTRUCTOR
    Video();
    Video(string, string);
    Video(string, string, int);
#endif
   public:
#ifdef DISABLE_CONSTRUCTOR
    friend class Table;
#endif
#ifndef DISABLE_CONSTRUCTOR
    Video();
    Video(string, string);
    Video(string, string, int);
#endif
    ~Video();
    void display(ostream&) const override;
    void show() const override;
    void setDuration(int);
    int getDuration() const;
    string getClassName() const override;
};

typedef shared_ptr<Video> VideoPtr;

#define VIDEO
#endif