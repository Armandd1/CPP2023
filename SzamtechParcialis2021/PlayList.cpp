//
// Created by arman on 2023. 11. 12.
//

#include "PlayList.h"

bool compareByUploadYear(const Video *a, const Video *b) {
    return a->getUploaded() < b->getUploaded();
}

void PlayList::sort() {
    std::sort(list, list + count, compareByUploadYear);
}