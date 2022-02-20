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

#ifdef TEST_SERVER
int startServer(Table *);
#endif

#ifdef TEST_FILM
void testFilm() {
    //@breif: test encapsulation of class Fill
    //@param: void
    //@ret: void

    int durations[] = {1, 2, 3, 4};
    int newDurations[] = {1, 2, 5, 7, 9};
    Film *film = new Film("video1",
                          "\"32991_1633696598454270.mp4\"",
                          durations, 4);
    film->display(cout);
    int num = 0;
    const int *getDuration = film->getDurations(num);
    for (int i = 0; i < film->getNumberOfChapters(); i++) {
        cout << getDuration[i] << endl;
    }
    cout << num << endl << endl;

    // set new durations
    film->setDurations(newDurations, 5);
    film->display(cout);
}
#endif

int main(int argc, const char *argv[]) {
#ifdef TEST_POLYMORPHISM
    Base *base[2];
    base[0] = new Photo("Photo 1", "\"image.png\"", 2880, 1800);
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

#ifdef TEST_DEEPCOPY
    int durations[] = {1, 2, 3, 4};
    int newDurations[] = {1, 2, 3, 4, 5};
    Film *film = new Film("video1",
                          "\"32991_1633696598454270.mp4\"",
                          durations, 4);
    film->display(cout);

    Film *filmCopy = new Film(*film);
    Film filmEqCopy = *film;
    
    film->setDurations(newDurations, 5);

    cout << "filmCopy" << endl;
    filmCopy->display(cout);
    cout << endl << "film" << endl;
    film->display(cout);
    cout << endl << "filmEqCopy" << endl;
    filmEqCopy.display(cout);
#endif

#ifdef TEST_GROUP
    Group *groupF1 = new Group("F1");
    Group *group2 = new Group("group2");

    PhotoPtr photo1 = PhotoPtr(new Photo("Photo 1", "\"image.png\"", 2880, 1800));
    PhotoPtr photo2 = PhotoPtr(new Photo("w13", "\"image.jpeg\"", 960, 680));
    VideoPtr video1 = VideoPtr(new Video("video1", "\"32991_1633696598454270.mp4\""));

    groupF1->push_back(photo1);
    groupF1->push_back(photo2);
    group2->push_back(video1);
    group2->push_back(photo1);

    groupF1->display(cout);
    group2->display(cout);

    group2->pop_back();
    groupF1->pop_back();
    groupF1->pop_back();
    group2->pop_back();
    cout << group2->size() << " " << groupF1->size() << endl;

    delete group2;
    delete groupF1;
#endif

#ifdef TEST_TABLE
    Table *table = new Table();

    table->create<Photo>("Photo 1", "\"image.png\"", 2880, 1800);
    table->create<Video>("video1", "\"32991_1633696598454270.mp4\"");
    table->create<Photo>("w13", "\"image.jpeg\"", 960, 680);

    cout << "Find w13: " << table->findMultimediaDisplay("w13", cout) << endl;
    cout << "Find Photo: " << table->findMultimediaDisplay("Photo", cout) << endl;

    PhotoPtr photo = dynamic_pointer_cast<Photo>(table->findMultimedia("w13"));
    photo->display(cout);

    table->createGroup("F1");
    Group *group = table->findGroup("F1");
    group->push_back(photo);
    group->push_back(dynamic_pointer_cast<Video>(table->findMultimedia("video1")));

#ifdef TEST_SERVER
    startServer(table);
#endif
#ifndef TEST_SERVER
    cout << "remove w13: " << table->removeMultimedia("w13") << endl;
    cout << "remove group: " << table->removeGroup("F1") << endl;
    cout << "remove not exist group: " << table->removeGroup("F1") << endl;
    cout << "remove not exist mm: " << table->removeMultimedia("w13") << endl;
    cout << "find removed object: " << table->findMultimedia("w13") << endl;

    table->create<Photo>("Photo 1", "\"image.png\"", 2880, 1800);
#endif
    delete table;
#endif

    return 0;
}
