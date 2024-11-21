#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string Result(const string& s) {
    string result;
    bool inside = false;

    size_t i = 0;
    while (i < s.length() && s[i] == ' ') {
        i++;
    }

    for (; i < s.length(); i++) {
        if (s[i] != ' ') {
            result += s[i];
            inside = true;
        }
        else if (inside) {
            result += ' ';
            inside = false;
        }
    }

    // Remove trailing space, if there is one
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

int main() {
    ifstream inputFile("t.txt");  // Open file for reading
    if (!inputFile) {
        cout << "File not opened!" << endl;
        return 0;
    }

    ofstream outputFile("t2.txt");  // Open file for writing
    if (!outputFile) {
        cout << "Failed to create file t2.txt!" << endl;
        return 0;
    }

    string line;
    cout << "t.txt: " << endl;
    while (getline(inputFile, line)) {
        cout << line << endl;  
        string result = Result(line);  
        outputFile << result << endl;  
    }

    inputFile.close();
    outputFile.close();

    ifstream resultFile("t2.txt");
    if (!resultFile) {
        cout << "Failed to open file t2.txt!" << endl;
        return 0;
    }

    cout << "t2.txt:" << endl;
    while (getline(resultFile, line)) {
        cout << line << endl; 
    }

    resultFile.close();

    return 0;
}
