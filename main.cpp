//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Base.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Group.h"
#include "Table.h"

using namespace std;

#define TEST_SERVER

int startServer(const Table *);

void testFilm() {
    //@breif: test encapsulation of class Fill
    //@param: void
    //@ret: void

    int durations[] = {1, 2, 3, 4};
    Film *film = new Film(
        "video1",
        "\"/Users/hugo/Library/Mobile Documents/com~apple~CloudDocs/TELECOM/INF224/TP/32991_1633696598454270.mp4\"",
        durations,
        4
    );
    film->display(cout);
    int num = 0;
    const int *getDuration = film->getDurations(num);
    for (int i = 0; i < film->getNumberOfChapters(); i++) {
        cout << getDuration[i] << endl;
    }
    cout << num << endl;
}

void testTable() {
    Table *table = new Table();
    table->create<Photo>(
        "Photo 1",
        "\"/Users/hugo/Library/Mobile Documents/com~apple~CloudDocs/TELECOM/INF224/TP/image.png\"",
        1920,
        1080
    );
    table->create<Video>(
        "video1",
        "\"/Users/hugo/Library/Mobile Documents/com~apple~CloudDocs/TELECOM/INF224/TP/32991_1633696598454270.mp4\""
    );

    const VideoPtr video = dynamic_pointer_cast<Video>(table->findMultimedia("video1"));

    video->show();

    // table->showMedia("video1");
    // table->showMedia("Photo 1");

    delete table;
}

int main(int argc, const char* argv[])
{
    // testFilm();

    // PhotoPtr photo(new Photo(
    //     "photo1",
    //     "\"/Users/hugo/Library/Mobile Documents/com~apple~CloudDocs/TELECOM/INF224/TP/image.png\"",
    //     1920,
    //     1080
    // ));

    // VideoPtr video(new Video(
    //     "video1",
    //     "\"/Users/hugo/Library/Mobile Documents/com~apple~CloudDocs/TELECOM/INF224/TP/32991_1633696598454270.mp4\""
    // ));

    // Group *group = new Group("a group");
    // group->push_back(photo);
    // group->push_back(video);
    // group->display(cout);
    
    // Group *group2 = new Group("group2");
    // group2->push_back(PhotoPtr(new Photo(
    //     "photo3",
    //     "\"/Users/hugo/Library/Mobile Documents/com~apple~CloudDocs/TELECOM/INF224/TP/image.png\"",
    //     1920,
    //     1080
    // )));

    // group2->display(cout);
    // group2->pop_back();

    // group->pop_back();
    // group->pop_back();

    // cout << 'f' << endl;

    // testTable();

#ifdef TEST_SERVER
    Table *table = new Table();
    table->create<Photo>(
        "Photo 1",
        "\"/Users/hugo/Library/Mobile Documents/com~apple~CloudDocs/TELECOM/INF224/TP/image.png\"",
        1920,
        1080
    );
    table->create<Video>(
        "video1",
        "\"/Users/hugo/Library/Mobile Documents/com~apple~CloudDocs/TELECOM/INF224/TP/32991_1633696598454270.mp4\""
    );

    startServer(table);
#endif

    return 0;
}
