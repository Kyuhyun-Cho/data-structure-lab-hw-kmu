//조규현 20191669 Lab2-2

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Angle {
private:
    int type;

public :
    int width;
    int height;
    int round;

    Angle(int inputType) : type(inputType) {
        width = height = round = 0;
    }

    double calculate() {
        switch (type) {
            case 1 : // triangle
                return 0.5 * width * height;
            case 2 : // rectangle
                return width * height;
            case 3 : // circle
                return 3.14 * round * round;
        }
    }

    int get_type() {
        return type;
    }
};

int main()
{
    ifstream openfile("Lab2-2.txt");
    if (!openfile.is_open()) {
        cout << "not open";
        return 0;
    }

    vector<Angle> arr;
    int size{ 7 };

    for (int i = 0; i < size; i++) {
        string tmp, str_token;
        getline(openfile, tmp);
        stringstream ss(tmp);
        while (ss >> str_token) {
            //cout << str_token << endl;
            if (str_token == "triangle") {
                Angle* tmp_angle = new Angle(1);

                ss >> str_token;
                tmp_angle->width = stoi(str_token);
                ss >> str_token;
                tmp_angle->height = stoi(str_token);

                arr.push_back(*tmp_angle);
            }
            else if (str_token == "rectangle") {
                Angle* tmp_angle = new Angle(2);

                ss >> str_token;
                tmp_angle->width = stoi(str_token);
                ss >> str_token;
                tmp_angle->height = stoi(str_token);

                arr.push_back(*tmp_angle);
            }
            else if (str_token == "circle") {
                Angle* tmp_angle = new Angle(3);

                ss >> str_token;
                tmp_angle->round = stoi(str_token);

                arr.push_back(*tmp_angle);
            }
        }


    }
    cout << fixed;
    cout.precision(2);

    for (auto ang : arr) {
        switch (ang.get_type()) {
            case 1: // triangle
                cout << "triangle ";
                cout << (double)ang.width << ' ' << (double)ang.height << ' ';
                break;
            case 2: // rectangle
                cout << "rectangle ";
                cout << (double)ang.width << ' ' << (double)ang.height << ' ';
                break;
            case 3: // circle
                cout << "circle ";
                cout << (double)ang.round << ' ';
                break;
        }
        cout << ang.calculate() << endl;
    }
}