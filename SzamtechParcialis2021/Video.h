//
// Created by arman on 2023. 11. 12.
//

#ifndef SZAMTECHPARCIALIS2021_VIDEO_H
#define SZAMTECHPARCIALIS2021_VIDEO_H

using namespace std;

#include <string>
#include <iostream>
#include <ostream>

class Video {
    string id;
    string title;
    double length;
    string uploader;
    long uploaded;

public:
    Video(const string &id, const string &title, double length, const string &uploader, long uploaded) {
        this->id = id;
        this->title = title;
        this->length = length;
        this->uploader = uploader;
        this->uploaded = uploaded;
    }

    const string &getId() const {
        return id;
    }

    const string &getTitle() const {
        return title;
    }

    double getLength() const {
        return length;
    }

    const string &getUploader() const {
        return uploader;
    }

    long getUploaded() const {
        return uploaded;
    }

    void print(ostream &os) const {
        os << id << " " << title << " " << length << " " << uploader << " " << uploaded << endl;
    }

    friend ostream &operator<<(ostream &os, const Video &video) {
        video.print(os);
    }


};


#endif //SZAMTECHPARCIALIS2021_VIDEO_H
