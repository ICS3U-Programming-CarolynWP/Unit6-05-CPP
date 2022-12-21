// Copyright Carolyn
// Created by: Carolyn Webster Pless
// Created on: 22/12/19
// gets the user input for a list of marks the determines
// The average using a function.

#include <list>
#include <iostream>
#include <random>
#include <array>

// Function to calculate the average
int Calculate_Average(std::list<int> arrayOfMarks) {
    // Variables
    int sum = 0, number, numberAmount, average;
    // FOR IN to calculate the average
    for (int number : arrayOfMarks) {
        sum = sum + number;
    }
    numberAmount = arrayOfMarks.size();
    if (numberAmount == 0) {
        return -1;
    } else {
        // Returning it back to main()
        average = sum / numberAmount;
        return average;
    }
}

// main()
int main() {
    // Variables
    std::list<int> listOfMarks;
    std::string userMarksString;
    int userMarks, average;

    // To get the user inputs, make sure it's valid, and call the function
    while (true) {
        std::cout << "Please enter your grade (0-100, -1 to stop): ";
        std::cin >> userMarksString;
        // If the user enters -1 to stop the program
        if (userMarksString == "-1") {
            break;
        }
        // Try Catch
        try {
            userMarks = stoi(userMarksString);
            // To make sure the average is between 0 and 100
            if (userMarks < 0 || userMarks > 100) {
                std::cout << "Please enter a mark between 0 and 100!\n";
                continue;
            } else {
                listOfMarks.push_back(userMarks);
            }
        } catch(std::invalid_argument) {
            std::cout << "Please enter a valid integer!\n";
        }
    }
    // Calling the function
    average = Calculate_Average(listOfMarks);
    if (average == -1) {
        std::cout << "Please enter a valid integer! \n";
    } else {
        // Displaying the average to the user
        std::cout << "Your average mark is " << average << "%!\n";
    }
}
