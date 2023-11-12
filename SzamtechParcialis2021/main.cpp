#include <iostream>
#include "PlayList.h"

int main() {


    Video *video1 = new Video("1", "title1", 1, "uploader1", 1);
    Video *video2 = new Video("2", "title2", 2, "uploader2", 2);
    Video *video3 = new Video("3", "title3", 3, "uploader3", 3);
    Video *video4 = new Video("4", "title4", 4, "uploader4", 4);
    Video *video5 = new Video("5", "title5", 5, "uploader5", 5);
    Video *video6 = new Video("6", "title6", 6, "uploader6", 6);
    Video *video7 = new Video("7", "title7", 7, "uploader7", 7);
    Video *video8 = new Video("8", "title8", 8, "uploader8", 8);
    Video *video9 = new Video("9", "title9", 9, "uploader9", 9);


    PlayList Unreal;
    Unreal.append(video6);
    Unreal.append(video8);

    PlayList NVIDIA;
    Unreal.append(video3);
    Unreal.append(video9);

    PlayList playList = Unreal + NVIDIA;
    playList.setTitle("tech");
    PlayList playList2 = playList;
    playList2.setTitle("All");

    playList2.append(video1);
    playList2.append(video2);
    playList2.append(video4);
    playList2.append(video5);
    playList2.append(video7);
    playList2.sort();

    cout << playList2;

    return 0;
}
