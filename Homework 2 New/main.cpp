//
//  main.cpp
//  Homework 2 New
//
//  Created by Shayne Gill on 2/5/18.
//  Copyright © 2018 Shayne Gill. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string chooseOperation()
{
    string fileName;
    string fileNames[] = {"Vowels", "Consonants", "Digits", "Punctuation", "User Selection", "exit"};
    int choice = -1;
    cout << "What would you like to remove from the sentence?" << endl;
    cout << "1.) Vowels" << endl;
    cout << "2.) Consonants" << endl;
    cout << "3.) Digits" << endl;
    cout << "4.) Punctuation" << endl;
    cout << "5.) User Selection" << endl;
    cin >> choice;
    while (choice < 1 || choice > 6 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "That's not a valid choice. Please try again (1-5): ";
        cin >> choice;
    }
    
    return fileNames[choice - 1];
   
}

/*Rerun Program*/int restartProgram(int minValue, int maxValue)
{
    int response = 0;
    cout << endl;
    cout << "Would you like to run the test again? (1=Yes/0=No): ";
    cin >> response;
    while (cin.fail() || (response < minValue || response > maxValue))
    {
        cout << "Invalid input. Please try again." << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Would you like to run the test again? (1=Yes/0=No): ";
        cin >> response;
    }
    return response;
}

///*Get user string*/ string userString()
//{
//    char input[100];
//    cout << "Enter a string: \n";
//    cin.getline(input, 500);
//
//    return (input[cin.getline(input, 500)]);
//
//}

int isVowel(char ch){
    switch(ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        {
            return 1;
            break;
        }
        default:
            return 0;
    }
}
int isConsonant (char ch){
    switch (ch) {
        case 'b':
        case 'B':
        case 'c':
        case 'C':
        case 'd':
        case 'D':
        case 'f':
        case 'F':
        case 'g':
        case 'G':
        case 'h':
        case 'H':
        case 'j':
        case 'J':
        case 'k':
        case 'K':
        case 'l':
        case 'L':
        case 'm':
        case 'M':
        case 'n':
        case 'N':
        case 'p':
        case 'P':
        case 'q':
        case 'Q':
        case 'r':
        case 'R':
        case 's':
        case 'S':
        case 't':
        case 'T':
        case 'v':
        case 'V':
        case 'w':
        case 'W':
        case 'x':
        case 'X':
        case 'y':
        case 'Y':
        case 'z':
        case 'Z':
        {
            return 1;
            break;
            
        }
            
        default:
            return 0;
    }
}
int isDigit (char ch)
{
    switch (ch) {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
        {
            return 1;
            break;
            
        }
            
        default:
            return 0;
    }
    
}

void outputString (string userChoice, char input[100])
{
    char output[100];
    
    if (userChoice == "Vowels") {
        for (int i = 0, j = 0; input[i] != '\0'; i++) {
            if (!isVowel(input[i])) {
                output[j++] = input [i];
                output[j] = '\0';
            }
        }
        
        cout << "Input String: " << input << endl;
        cout << "String without Vowels: " << output;
    }
    else if (userChoice == "Consonants")
    {
        for (int i = 0, j = 0; input[i] != '\0'; i++) {
            if (!isConsonant(input[i])) {
                output[j++] = input [i];
                output[j] = '\0';
            }
        }
        
        cout << "Input String: " << input << endl;
        cout << "String without Consonants: " << output;
    }
    else if (userChoice == "Digits")
    {
        for (int i = 0, j = 0; input[i] != '\0'; i++) {
            if (!isDigit(input[i])) {
                output[j++] = input [i];
                output[j] = '\0';
            }
        }
        
        cout << "Input String: " << input << endl;
        cout << "String without Digits: " << output;
    }
    else if (userChoice == "Punctuation")
    {
        for (int i = 0, j = 0; input[i] != '\0'; i++) {
            if (!ispunct(input[i])) {
                output[j++] = input [i];
                output[j] = '\0';
            }
        }
        
        cout << "Input String: " << input << endl;
        cout << "String without Punctuation: " << output;
        
    }
    
}

int main(int argc, const char * argv[]) {
    bool done = false;
    
    
    do {
        char input[100];
        
        string userSelection = chooseOperation(); // User choice of which operation to conduct.
        cin.ignore(); // Needed to ignore new line, or it skips next operation.
        
        cout << "You chose operation: " << userSelection << endl; // Simply reiterates the users choice.
        
        cout << "Enter a string: ";
        cin.getline(input, 500);
        
        outputString(userSelection, input); // Converts string to user request.
        
        int response = restartProgram(0, 1); // User restart request
        if (response == 0) { done = true; } // Closes program if requested by user.
    } while (!done);
    
//    system("pause");
    return 0;
}
