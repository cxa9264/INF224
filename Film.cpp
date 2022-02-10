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
    numberOfChapters = num;
    delete durations;
    durations = new int[num];
    for (int i = 0; i < num; i++) {
        durations[i] = _durations[i];
    }
}

const int* Film::getDurations(int& num) const {
    num = numberOfChapters;
    return durations;
}

const int* Film::getDurations() const {
    return durations;
}

int Film::getNumberOfChapters() const {
    return numberOfChapters;
}


void Film::display(ostream& os) const {
    os << "name: " << name << endl
       << "path: " << path << endl
       << "number of chapters: " << numberOfChapters << endl;
    for (int i = 0; i < numberOfChapters; i++) {
        os << "Duration of chapter " << i + 1 << ": " << durations[i] << endl;
    }
}
#define FILM
#endif