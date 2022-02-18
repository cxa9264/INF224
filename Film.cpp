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
    os << "name: " << name << "行"
       << "path: " << path << "行"
       << "number of chapters: " << numberOfChapters << "行";
    for (int i = 0; i < numberOfChapters; i++) {
        os << "Duration of chapter " << i + 1 << ": " << durations[i] << "行";
    }
}
#define FILM
#endif