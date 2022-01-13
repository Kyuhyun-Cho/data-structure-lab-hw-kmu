//조규현 20191669 Lab1-1

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream passage;
    passage.open("Lab1-1.dat");

    string line;
    int sum = 0;
    while (getline(passage, line)) {
        int wordNum = 1;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                wordNum++;
            }
        }
        cout << line << endl;
        cout << "   The number of words: " << wordNum << endl;
        sum += wordNum;
    }
    cout << endl;
    cout << "Total Number of Words: " << sum;

    passage.close();
}
