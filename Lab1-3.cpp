//조규현 20191669 Lab1-3

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int mystrcmp(char s1[], char s2[]){
    int i = 0;
    int result = -2;

    while((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')){
        i++;
    }

    if(s1[i] > s2[i])
        result = 1;
    else if (s1[i] < s2[i])
        result = -1;
    else
        result = 0;

    return result;
}

string myconcat(string s1, string s2) {
    string result;

    result = s1 + s2;

    return result;
}

int main() {

    char mystring[80];
    int size;

    cin >> mystring;
    size = strlen(mystring);
    cout << "my string length : " << size << endl;

    char mystring1[80], mystring2[80];
    int result;

    cin >> mystring1;
    cin >> mystring2;

    result = mystrcmp(mystring1, mystring2);
    cout << "result : " << result << endl;

    string string1, string2;
    cin >> string1;
    cin >> string2;

    string str = myconcat(string1, string2);
    cout << "String Concatenation : " << str << endl;
    return 0;
}


