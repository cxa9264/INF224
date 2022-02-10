#ifndef TABLE

#include <map>

#include "Base.h"
#include "Group.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"

class Table {
   private:
    std::map<string, BasePtr> multimedias{};
    std::map<string, Group *> groups{};

   public:
    Table();
    template <typename T>
    bool create(const string name_, const string path_ = "",
                const int longtitude_ = 0, const int latitude_ = 0,
                const int duration_ = 0, const int durations_[] = nullptr,
                const int numberOfChapters_ = 0);
    const BasePtr findMultimedia(const string) const;
    const Group * findGroup(const string) const;
    bool findMultimediaDisplay(const string) const;
    bool findGroupDisplay(const string) const;
    bool showMedia(const string) const;
}; 


template <typename T>
bool Table::create(const string name_, const string path_, const int longtitude_,
            const int latitude_, const int duration_,
            const int durations_[], const int numberOfChapters_) {
    T* multimediaObject = new T();
    if (Photo *p = dynamic_cast<Photo *>(multimediaObject)) {
        PhotoPtr photo(new Photo(name_, path_, longtitude_, latitude_));
        multimedias[name_] = photo;
    } else if (Video *p = dynamic_cast<Video *>(multimediaObject)) {
        VideoPtr video(new Video(name_, path_, duration_));
        multimedias[name_] = video;
    } else if (Group *p = dynamic_cast<Group *>(multimediaObject)) {
        groups[name_] = new Group(name_);
    } else if (Film *p = dynamic_cast<Film *>(multimediaObject)) {
        FilmPtr film(new Film(name_, path_, durations_, numberOfChapters_));
        multimedias[name_] = film;
    } else {
        delete multimediaObject;
        return false;
    }
    delete multimediaObject;
    return true;
}

#define TABLE
#endif