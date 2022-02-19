//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>

#include "Base.h"
#include "Def.h"
#include "Film.h"
#include "Group.h"
#include "Photo.h"
#include "Table.h"
#include "Video.h"

using namespace std;

int startServer(const Table *);

void testFilm() {
    //@breif: test encapsulation of class Fill
    //@param: void
    //@ret: void

    int durations[] = {1, 2, 3, 4};
    Film *film = new Film("video1",
                          "\"32991_1633696598454270.mp4\"",
                          durations, 4);
    film->display(cout);
    int num = 0;
    const int *getDuration = film->getDurations(num);
    for (int i = 0; i < film->getNumberOfChapters(); i++) {
        cout << getDuration[i] << endl;
    }
    cout << num << endl;
}

int main(int argc, const char *argv[]) {
#ifdef TEST_POLYMORPHISM
    Base *base[2];
    base[0] = new Photo("Photo 1", "\"image.png\"", 1920, 1080);
    base[1] = new Video("video1", "\"32991_1633696598454270.mp4\"");

    for (int i = 0; i < 2; i++) {
        base[i]->show();
    }

    delete base[0];
    delete base[1];
#endif

#ifdef TEST_FILM
    testFilm();
#endif

#ifdef TEST_SERVER
    Table *table = new Table();
    table->create<Photo>("Photo 1", "\"image.png\"", 1920, 1080);
    table->create<Video>("video1", "\"32991_1633696598454270.mp4\"");

    startServer(table);
#endif

    return 0;
}
