//  Created by Anna Myshlyakova on 2/1/18.
//  Copyright © 2018 IVC. All rights reserved.


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

#define N 5 // number of students

struct Student {
    string first_name;
    string last_name;
    int hwk1, hwk2, hwk3;
    int exam1, exam2;
    char grade;
    double percentage;
    int totalHwk, totalExam;
};

// Prototypes
vector<string> split(string line);
void retreiveStudentData(struct Student s[], int n);

int main() {
    
    Student students[N];
    
    retreiveStudentData(students, N);
    
    // Prints the retrieved data to make sure
    for (int i = 0; i < N; i++) {
        cout << students[i].first_name << " "
        << students[i].last_name << " "
        << students[i].hwk1 << " "
        << students[i].hwk2 << " "
        << students[i].hwk3 << " "
        << students[i].exam1 << " "
        << students[i].exam2 << endl;
    }
    
    return 0;
}

//Splits a string line into words (tokens)
vector<string> split(string line) {
    istringstream iss(line);
    vector<string> tokens;
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(tokens));
    
    return tokens;
}

// retrieves student data from a text file and loads it into the array of structures
void retreiveStudentData(struct Student s[], int n) {
    string line;
    ifstream studentFile;
    studentFile.open("./Students.txt", ios::out);
    
    if (!studentFile) {
        cout << "Unable to open file" << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            getline(studentFile, line);
            
            vector<string> tokens = split(line);
            
            s[i].last_name = tokens[0];
            s[i].first_name = tokens[1];
            s[i].hwk1 = stoi(tokens[2]);
            s[i].hwk2 = stoi(tokens[3]);
            s[i].hwk3 = stoi(tokens[4]);
            s[i].exam1 = stoi(tokens[5]);
            s[i].exam2 = stoi(tokens[6]);
            }
    }
    studentFile.close();
}



