#include "quizgame.h"

// Ékezetek kiírása Windows alatt
#ifdef _WIN32
#include <Windows.h>
#endif /* _WIN32 */


int main() {
    // Ékezetek kiírása Windows alatt
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif /* _WIN32 */

    Quiz quiz;
    quiz.setName("Teszt kvíz");
    quiz.readFromFile("quiz.txt");

    QuizGame game;
    game.playQuiz(quiz);
}