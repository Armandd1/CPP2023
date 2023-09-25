#include <iostream>
#include <cmath>

using namespace std;

int countBits(int number);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);


int main() {
//    for(int i=0; i<127;i++){
//    printf("%i szam: %i\n",i, countBits(i));}

//    for (int i = 0; i < 35; ++i) {
//        int n = 0;
//        if(setBit(n, i)){
//            cout<<i<<" ---> " << n <<endl;
//        }else{
//            cout<<"Impossible operation!" << endl;
//        }
//    }

double array[50];
int n;
cout<< "n=";
cin>>n;
for(int i=0; i<n; i++){
    cout<<"array["<<i<<"]=";
    cin>>array[i];
}
cout<<"Mean:" << mean(array,n);


    return 0;
}

int countBits(int number) {
    int count = 0;
    while (number != 0) {
        count++;
        number = number & (number - 1);
    }
    return count;
}

bool setBit(int& number, int order){
    if(order>=31) return false;
    number = number | (1<<order);
    return true;
}

double mean(double array[], int numElements){
        if (numElements == 0) {
            return NAN;
        }
        double sum = 0;
        for (int i = 0; i < numElements; i++) {
            sum += array[i];
        }
        double average = sum / numElements;
        return average;
}

double stddev(double array[], int numElements) {
    if(numElements == 0) return NAN;
    double avg = mean(array,numElements);
    double diff1 = 0;
    double diff2;
    for(int i = 0; i < numElements;i++) {
        diff1 += (avg - array[i]) * (avg - array[i]);
    }
    diff2 = diff1/numElements;
    return sqrt(diff2);

}

pair<double, double> max2(double array[], int numElements) {

    pair<double,double> answer = {NAN,NAN};

    if(numElements < 2) {
        answer.first = array[0];
    }

    else {
        if(array[0] < array[1]) {
            answer.first = array[0];
            answer.second = array[1];
        }
        else {
            answer.first = array[1];
            answer.second = array[0];
        }

        for(int i = 2;i < numElements;i++) {
            if(array[i] > answer.second) {
                answer.first = answer.second;
                answer.second = array[i];
            }
            else {
                if(array[i] > answer.first){
                    answer.first = array[i];
                }
            }
        }

    }

    return answer;}
