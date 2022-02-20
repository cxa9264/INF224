#ifndef FILM
#include <memory>

#include "Video.h"

class Film : public Video {
   private:
    int* durations = nullptr;
    int numberOfChapters = 0;

#ifdef DISABLE_CONSTRUCTOR
    Film();
    Film(string, string);
    Film(string, string, const int[], int);
    Film(const Film&);
    Film& operator=(const Film&);
#endif
   public:
#ifdef DISABLE_CONSTRUCTOR
    friend class Table;
#endif
#ifndef DISABLE_CONSTRUCTOR
    Film();
    Film(string, string);
    Film(string, string, const int[], int);
    Film(const Film&);
    Film& operator=(const Film&);
#endif
    ~Film();
    void setDurations(int[], int);
    void display(ostream&) const override;
    const int* getDurations(int&) const;
    int getNumberOfChapters() const;
    string getClassName() const override;
};

typedef std::shared_ptr<Film> FilmPtr;

#define FILM
#endif