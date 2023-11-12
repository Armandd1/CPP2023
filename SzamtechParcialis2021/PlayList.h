//
// Created by arman on 2023. 11. 12.
//

#ifndef SZAMTECHPARCIALIS2021_PLAYLIST_H
#define SZAMTECHPARCIALIS2021_PLAYLIST_H

using namespace std;

#include <string>
#include <iostream>
#include <ostream>
#include "Video.h"


class PlayList {
    string title;
    Video **list;
    int capacity;
    int count;

public:
    PlayList(int capacity = 200) {
        this->capacity = capacity;
        this->count = 0;
        this->list = new Video *[capacity];
    }

    PlayList(const PlayList &copy) {
        this->title = copy.title;
        this->capacity = copy.capacity;
        this->count = copy.count;
        this->list = new Video *[copy.capacity];
        for (int i = 0; i < copy.count; i++) {
            this->list[i] = new Video(copy.list[i]->getId(), copy.list[i]->getTitle(), copy.list[i]->getLength(),
                                      copy.list[i]->getUploader(), copy.list[i]->getUploaded());
        }
    }

    PlayList(PlayList &&move) {
        this->title = move.title;
        this->capacity = move.capacity;
        this->count = move.count;
        this->list = move.list;
        move.list = nullptr;
    }

    ~PlayList() {
        for (int i = 0; i < count; i++) {
            delete list[i];
        }
        delete[] list;
    }

    const string &getTitle() const {
        return title;
    }

    void setTitle(const string &title) {
        this->title = title;
    }


    int videos() const {
        return count;
    }

    void append(Video *video) {
        if (count < capacity) {
            list[count] = video;
            count++;
        }
    }

    void sort() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (list[j + 1]->getUploaded() < list[j]->getUploaded()) {
                    swap(list[j], list[j + 1]);
                }
            }
        }
    }


    Video *operator[](int index) {
        return list[index];
    }

    const Video *operator[](int index) const {
        return list[index];
    }

    PlayList &operator=(const PlayList &copy) {
        this->title = copy.title;
        this->capacity = copy.capacity;
        this->count = copy.count;
        this->list = new Video *[copy.capacity];
        for (int i = 0; i < copy.count; i++) {
            this->list[i] = new Video(copy.list[i]->getId(), copy.list[i]->getTitle(), copy.list[i]->getLength(),
                                      copy.list[i]->getUploader(), copy.list[i]->getUploaded());
        }
    }

    PlayList &operator=(PlayList &&move) {
        this->title = move.title;
        this->capacity = move.capacity;
        this->count = move.count;
        this->list = move.list;
        move.list = nullptr;
    }

    friend PlayList operator+(const PlayList &a, const PlayList &b) {
        PlayList copy = a;
        for (int i = 0; i < b.count; i++) {
            copy.append(b.list[i]);
        }
        return copy;
    }

    friend ostream &operator<<(ostream &os, const PlayList &playlist) {
        for (int i = 0; i < playlist.count; i++) {
            playlist.list[i]->print(os);
        }
        return os;
    }

};


#endif //SZAMTECHPARCIALIS2021_PLAYLIST_H
