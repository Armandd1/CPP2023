#include "functions.h"


int main(int argc, char *argv[]) {
//    fel1();
    fel2(argc, argv);
//    extra();
    return 0;
}

void fel1() {
    for (int i = 0; i < 127; i++) {
        printf("%i szam: %i\n", i, countBits(i));
    }

    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if (setBit(n, i)) {
            cout << i << " ---> " << n << endl;
        } else {
            cout << "Impossible operation!" << endl;
        }
    }

    double array[50];
    int n;
    cout << "n=";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "array[" << i << "]=";
        cin >> array[i];
    }
    cout << "Mean:" << mean(array, n)<<endl;
    cout << "Szoras:" << stddev(array, n)<<endl;
    pair<double, double> result = max2(array, n);
    cout << "Az elso legnagyobb elem: " << result.first << endl;
    cout << "A masodik legnagyobb elem: " << result.second << endl;
}

void fel2(int argc, char *argv[]) {

    double result = sumNumbersInArguments(argc, argv);
    cout << "Az osszeg: " << result << endl;

    istringstream iss("1 2 3 alma 4");
    double number;
    while (iss >> number) {
        cout << number << endl;
    }

    cout << "A megadott string-ben levo szavak szama = " << countWords("egy ketto harom") << endl;

    cout << "A megadott string code-olva: " << code("1abczZ") << endl;

    string sor;
    for (int i = 0; i < 3; i++) {
        cout << "Adjon meg egy stringet: ";
        getline(cin, sor);
        cout << capitalizeWords(sor) << endl;
    }
}
