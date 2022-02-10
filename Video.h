#ifndef VIDEO

#include <string>
#include <memory>
#include "Base.h"

using namespace std;

class Video : public Base {
protected:
    int duration;
    Video();
    Video(string, string);
    Video(string, string, int);

public:
    friend class Table;
    ~Video();
    void display(ostream&) const override;
    void show() const override;
    void setDuration(int);
    int getDuration() const;
};

typedef shared_ptr<Video> VideoPtr;

#define VIDEO
#endif