#ifndef VIDEO

#include <memory>
#include <string>

#include "Base.h"

using namespace std;

class Video : public Base {
   protected:
    int duration;
#ifndef TEST_POLYMORPHISM
    Video();
    Video(string, string);
    Video(string, string, int);
#endif
   public:
#ifndef TEST_POLYMORPHISM
    friend class Table;
#endif
#ifdef TEST_POLYMORPHISM
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