///////////////////////////////////////////////////////////////////////////////
// File Name:      Student.cpp
//
// Author:         Roz Stengle, Ben Chylla
// CS email:       roz@cs.wisc.edu, chylla@cs.wisc.edu
//
// Description:    The implementation of the Student class.
//
///////////////////////////////////////////////////////////////////////////////

#include "Student.hpp"
#include <iostream>

int Student::numStudents = 0;

int id;
std::string name;
std::vector<double> assignmentsScore;
double projectScore;

Student::Student(std::string name,
				  const std::vector<double> &assignmentsScore,
				  double projectScore) {
	this->name = name;
	this->id = numStudents;
	this->assignmentsScore = assignmentsScore;
	numStudents++;
}

    /**
     * @brief Getter for student's id.
     *
     * @return The id of the student.
     */
    int getId() {
		return id;
	}

    /**
     * @brief Getter for student's name.
     *
     * @return The name of the student.
     */
    std::string getName(){
		return name;
		}

    /**
     * @brief Getter for student's assignment scores.
     *
     * @return A const reference to the vector of student's assignment scores.
     */
    const std::vector<double> &getAssignmentsScore() {
		return assignmentsScore;
	}

    /**
     * @brief Getter for student's project score.
     *
     * @return The project score of the student.
     */
    double getProjectScore() {
		return projectScore;
	}

    /**
     * @brief Get the total number of students.
     *
     * @return The total number of students.
     */
    int Student::getNumStudents() {
		return numStudents;
	}

    /**
     * @brief Prints the details of the student.
     *
     * @example This method prints the following details of a student.
     * Id = 2
     * Name = Joe Dart
     * Assignments = [67, 78, 96, 91, 97, 96]
     * Project = 96
     * Total = 90.05
     * Grade = CR
     */
    void Student::printDetails() {
    	std::cout << "STUDENT DETAILS: " << std::endl;
    	std::cout << "Id = " << getId() << std::endl;
		std::cout << "Name = " << getName() << std::endl;
		std::cout << "Assignments = [";
		for (int i = 0; i < assignmentsScore.size(); i++) {
			std::cout << assignmentsScore[i] << ",";
			if (i < assignmentsScore.size()-1) {
				std::cout << " ";
			}
		}
		std::cout << "]" << std::endl;
		std::cout << "Project = " << getProjectScore() << std::endl;
		std::cout << "Total = " << getTotal() << std::endl;
		std::cout << "Grade = " << getGrade() << std::endl;
	}

    /**
     * @brief Get the total score of a student.
     *
     * @return The total score of the student.
     */
    /*double getTotal() {

    }*/

    /**
     * @brief Get the letter grade obtained by a student.
     *
     * @return The letter grade of the student. The possible letter grades are "CR" and "N".
     */
    /*std::string getGrade() {

    }*/

