#ifndef FILM
#include "Film.h"

#include <string>

Film::Film() : Video::Video() {}

Film::Film(string _name, string _path) : Video::Video(_name, _path) {}

Film::Film(string _name, string _path, const int _durations[], int num)
    : Video::Video(_name, _path) {
    numberOfChapters = num;
    durations = new int[num];
    for (int i = 0; i < num; i++) {
        durations[i] = _durations[i];
    }
}

Film::Film(const Film& from) : Video(from) {
    numberOfChapters = from.numberOfChapters;
    if (from.durations != nullptr) {
        durations = new int[numberOfChapters];
        for (int i = 0; i < numberOfChapters; i++) {
            durations[i] = from.durations[i];
        }
    } else {
        durations = nullptr;
    }
}

Film& Film::operator=(const Film& from) {
    Video::operator=(from);
    numberOfChapters = from.numberOfChapters;
    if (from.durations != nullptr) {
        if (durations != nullptr) {
            delete[] durations;
        }
        durations = new int[numberOfChapters];
        for (int i = 0; i < numberOfChapters; i++) {
            durations[i] = from.durations[i];
        }
    } else {
        durations = nullptr;
    }
    return *this;
}

Film::~Film() { delete[] durations; }

void Film::setDurations(int _durations[], int num) {
    // @breif: set duration of each chapter
    // @param _durations: int[], contains durations of each chapter
    // @param num: int, number of chapters, same as the length of _durations
    // @ret: void
    numberOfChapters = num;
    delete durations;
    durations = new int[num];
    for (int i = 0; i < num; i++) {
        durations[i] = _durations[i];
    }
}

const int* Film::getDurations(int& num) const {
    // @breif: get duration of each chapter
    // @param num: int&, to return the number of chapters
    // @ret: const int*, constant pointer to durations, containing duration of each chapter
    num = numberOfChapters;
    return durations;
}

int Film::getNumberOfChapters() const {
    // @breif: get number of chapters
    // @param: void
    // @ret: number of chapters
    return numberOfChapters;
}


void Film::display(ostream& os) const {
    // @breif: show information of film
    // @param: ostream&, output stream
    // @ret: void
    os << "name: " << name << endl
       << "path: " << path << endl
       << "number of chapters: " << numberOfChapters << endl;
    for (int i = 0; i < numberOfChapters; i++) {
        os << "Duration of chapter " << i + 1 << ": " << durations[i] << endl;
    }
}

string Film::getClassName() const {
    // @breif: get class name
    // @param: void
    // @ret: string, "Film"
    return "Film";
}

#define FILM
#endif