#include "Quiz.h"
#include "Quizgame.h"
#include <sstream>

void QuizGame::play() {
    std::cout << "Welcome to the Quiz Game!" << std::endl;

    Quiz currentQuiz = QuizGame::getQuiz();
    currentQuiz.readFromFile(getQuiz().getName());

    std::cout << "You are now playing: " << currentQuiz.getName() << std::endl;

    std::string line;
    int answer;

    for (Question question: currentQuiz.getQuestions()) {
        question.print();

        std::cout << "Your answer: " << std::endl;

        std::getline(std::cin, line);
        std::stringstream sstream(line);

        std::vector<Answer> answers = question.getAnswers();
        int correctAnswer = 0;
        int currentAnswer = 0;

        for (int i = 0; i < answers.size(); ++i) {
            if (answers[i].isCorrect()) {
                correctAnswer |= (1 << i);
            }
        }

        while (sstream >> answer) {
            currentAnswer |= (1 << (answer - 1));
        }

        if (currentAnswer == correctAnswer) {
            std::cout << "Correct!" << std::endl;
            ++score;
        } else {
            std::cout << "Incorrect!" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Your final score is: " << score << "/" << currentQuiz.getQuestions().size() << std::endl;
}

