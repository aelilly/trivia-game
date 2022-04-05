// trivia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

bool getAnswer(int);

int main()
{
    //define constants, and arrays
    int const size = 4;
    string question[size];
    bool answer[size];

    //build the quiz
    cout << "Let's build a trivia game of true or false questions" << endl;
    for (int i = 0; i < size; i++) {        //loop to run through each iteration of array
        cout << endl << "Input question " << i + 1 << ": " << endl;
        getline(cin, question[i]);
        if (i != 0)
            getline(cin, question[i]);
        answer[i] = getAnswer(i);         //calls getAnswer function to define each answer in the array
    }
    
    //take the quiz
    cout << endl << "Quiz" << endl;
    int score = 0;
    for (int i = 0; i < size; i++) {        //outputs each question and asks for answer
        cout << endl << "Question " << i + 1 << ": " << endl;
        cout << question[i] << endl;

        if (answer[i] == getAnswer(i))      //calls getAnswer function to verify each correct answer
            score++;
    }
    cout << endl << "You answered " << score << " out of " << size << " questions correctly";
}


bool getAnswer(int i) {
    string ans;
    static int count;
        do {        //basic validation loop
            if (count <= i)
                cout << "Input answer " << i + 1 << ": " << endl;
            else
                cout << "True or False?" << endl;
            cin >> ans;
            if (ans != "t" && ans != "T" && ans != "f" && ans != "F" && ans != "true" && ans != "True" && ans != "false" && ans != "False") {
                cout << "Invalid Input, Try Again" << endl; 
            }
        } while (ans != "t" && ans != "T" && ans != "f" && ans != "F" && ans != "true" && ans != "True" && ans != "false" && ans != "False");
        
        bool answer = ans == "t" || ans == "T" || ans == "true" || ans == "True";       //converts user input into bool value
        count++;
        return answer;
}


/*
Let's build a trivia game of true or false questions

Input question 1:
The sky is blue
Input answer 1:
True

Input question 2:
The sun is bright
Input answer 2:
t

Input question 3:
Fire is very hot
Input answer 3:
true

Input question 4:
A square is round
Input answer 4:
Yes
Invalid Input, Try Again
Input answer 4:
F

Quiz

Question 1:
The sky is blue
True or False?
true

Question 2:
The sun is bright
True or False?
t

Question 3:
Fire is very hot
True or False?
False

Question 4:
A square is round
True or False?
F

You answered 3 out of 4 questions correctly
*/