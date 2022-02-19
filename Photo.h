#ifndef PHOTO
#include "Base.h"

using namespace std;

class Photo : public Base {
private:
    int longtitude;
    int latitude;
#ifndef TEST_POLYMORPHISM
    Photo();
    Photo(string, string, int, int);
#endif
public:
#ifndef TEST_POLYMORPHISM
    friend class Table;
#endif
#ifdef TEST_POLYMORPHISM
    Photo();
    Photo(string, string, int, int);
#endif
    ~Photo();
    void setLongtitude(int);
    void setLatitude(int);
    int getLongtitude() const;
    int getLatitude() const;
    void show() const override;
    void display(ostream&) const override;
    string getClassName() const override;
};

typedef std::shared_ptr<Photo> PhotoPtr;

#define PHOTO
#endif