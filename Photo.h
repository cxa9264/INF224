#ifndef PHOTO
#include "Base.h"

using namespace std;

class Photo : public Base {
private:
    int longtitude;
    int latitude;
public:
    Photo();
    Photo(string, string, int, int);
    ~Photo();
    void setLongtitude(int);
    void setLatitude(int);
    int getLongtitude() const;
    int getLatitude() const;
    void show() const override;
    void display(ostream&) const override;
};

typedef std::shared_ptr<Photo> PhotoPtr;

#define PHOTO
#endif