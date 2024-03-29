#ifndef PHOTO
#include "Base.h"

using namespace std;

class Photo : public Base {
private:
    int longtitude;
    int latitude;
#ifdef DISABLE_CONSTRUCTOR
    Photo();
    Photo(string, string, int, int);
#endif
public:
#ifdef DISABLE_CONSTRUCTOR
    friend class Table;
#endif
#ifndef DISABLE_CONSTRUCTOR
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