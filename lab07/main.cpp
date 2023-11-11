#include "Quiz.h"
#include "QuizGame.h"

//#ifdef _WIN32
//#include <Windows.h>
//#endif /* _WIN32 */

int main() {
    User users[] = {User("Peter"), User("Kati")};
    Quiz quizzes[] = {Quiz("kviz.txt"), Quiz("kviz2.txt")};
    int num_users = sizeof(users) / sizeof(users[0]);
    int num_quizzes = sizeof(quizzes) / sizeof(quizzes[0]);
    for (int i = 0; i < num_users; ++i) {
        for (int j = 0; j < num_quizzes; ++j) {
            QuizGame game(users[i], quizzes[j]);
            game.play();
            cout << "Name: " << game.getUser().getName() << ", score: " <<
                 game.getScore() << endl << endl;
        }
    }
    cout << endl << "****************" << endl;
    cout << "Users' results:" << endl;
    for (int i = 0; i < num_users; ++i) {
        cout << users[i] << endl;
    }
    cout << "****************" << endl;
    return 0;
}