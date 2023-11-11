#include "Quiz.h"
#include "QuizGame.h"

//#ifdef _WIN32
//#include <Windows.h>
//#endif /* _WIN32 */

int main() {

//#ifdef _WIN32
//    SetConsoleOutputCP(CP_UTF8);
//#endif /* _WIN32 */

    Quiz quiz("quiz");
    quiz.readFromFile("kviz.txt");
    QuizGame game;
    game.playQuiz(quiz);

    return 0;
}