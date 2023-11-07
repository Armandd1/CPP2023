//
// Created by arman on 2023. 11. 07..
//

#include "quizgame.h"
#include <sstream>
#include <iostream>

using namespace std;

void QuizGame::playQuiz(Quiz quiz) const {
    // Bevezető
    std::cout << "Welcome to the Quiz Game!" << std::endl;
    std::cout << "You are now playing: " << quiz.getName() << std::endl;
    std::cout << "Every line must be end with '|'\n"
                 "If there is more possible answer please separate the answers with '|'\n"
                 "ex: answer 1 | answer 2 |\n"
                 "Warning!!! if you miss a '|', then the outcome will be incorrect\n" << std::endl;

    // Jelenleg beolvasott sor és válasz
    std::string line;
    int answer;
    string str;

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
        string currentAnswerString;

        // A helyes válaszokat bitenként tároljuk el
        for (int i = 0; i < answers.size(); ++i) {
            if (answers[i].isCorrect()) {
                correctAnswer |= (1 << i);
            }
        }

        // A játékos által megadott válaszokat is
        // hasonlóan bitenként tároljuk el
        while (sstream >> str) {
            // A válaszok 1-től kezdődnek, de a bitenkénti tárolás 0-tól

            if(str != "|"){
                if(!currentAnswerString.empty()) currentAnswerString.append(" ");
                currentAnswerString.append(str);
            } else {
                answer = question.getNumberFromString(currentAnswerString);
                if(answer == -1){
                    continue;
                }
                currentAnswer |= (1 << answer);
                currentAnswerString.clear();
            }


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
