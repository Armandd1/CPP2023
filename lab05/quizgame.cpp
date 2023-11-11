#include "Quiz.h"
#include "Quizgame.h"
#include <sstream>

void QuizGame::playQuiz(Quiz quiz) const {
    // Bevezető
    std::cout << "Welcome to the Quiz Game!" << std::endl;
    std::cout << "You are now playing: " << quiz.getName() << std::endl;

    // Jelenleg beolvasott sor és válasz
    std::string line;
    int answer;

    // Jelenlegi pontszám
    int score = 0;

    // Minden kérdésre válaszolunk
    for (Question question : quiz.getQuestions()) {
        // Kiírjuk a kérdést
        question.print();

        // Beolvasunk egy egész sort, ami tartalmazza a válaszokat
        std::cout << "Your answer: " << std::endl;

        std::getline(std::cin, line);
        std::stringstream sstream(line);

        // A válaszokat bitenként eltároljuk
        std::vector<Answer> answers = question.getAnswers();
        int correctAnswer = 0;
        int currentAnswer = 0;

        // A helyes válaszokat bitenként tároljuk el
        for (int i = 0; i < answers.size(); ++i) {
            if (answers[i].isCorrect()) {
                correctAnswer |= (1 << i);
            }
        }

        // A játékos által megadott válaszokat is
        // hasonlóan bitenként tároljuk el
        while (sstream >> answer) {
            // A válaszok 1-től kezdődnek, de a bitenkénti tárolás 0-tól
            currentAnswer |= (1 << (answer - 1));
        }

        // Összehasonlítjuk a két választ és kiírjuk az eredményt
        if (currentAnswer == correctAnswer) {
            std::cout << "Correct!" << std::endl;
            ++score;
        } else {
            std::cout << "Incorrect!" << std::endl;
        }
    }

    // Kiírjuk a végeredményt is
    std::cout << std::endl;
    std::cout << "Your final score is: " << score << "/" << quiz.getQuestions().size() << std::endl;
}