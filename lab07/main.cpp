#include "quizgame.h"
#include <iostream>

// Ékezetek kiírása Windows alatt
//#ifdef _WIN32
//#include <Windows.h>
//#endif /* _WIN32 */


using namespace std;

int main() {
    // Ékezetek kiírása Windows alatt
//    #ifdef _WIN32
//    SetConsoleOutputCP(CP_UTF8);
//    #endif /* _WIN32 */



    Quiz quiz;
    quiz.setName("Teszt_kviz");
    quiz.readFromFile("kviz.txt");

    QuizGame game;
    game.playQuiz(quiz);
}
