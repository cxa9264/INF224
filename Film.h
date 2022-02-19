#ifndef FILM
#include <memory>

#include "Video.h"

class Film : public Video {
   private:
    int* durations = nullptr;
    int numberOfChapters = 0;

   public:
    Film();
    Film(string, string);
    Film(string, string, const int[], int);
    Film(const Film&);
    Film& operator=(const Film&);
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