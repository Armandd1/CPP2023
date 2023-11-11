//
// Created by arman on 2023. 11. 07.
//

#ifndef LAB07_QUIZGAME_H
#define LAB07_QUIZGAME_H


#include "quiz.h"
#include "user.h"

class QuizGame {
private:
    User& user;
    const Quiz& quiz;
    double score = 0;
public:
    QuizGame(User& user, const Quiz& quiz) : user(user), quiz(quiz){}
    void play();
    double getScore() const { return score; }
    User getUser() const { return user; }
    Quiz getQuiz() const { return quiz; }
};


#endif //LAB07_QUIZGAME_H
