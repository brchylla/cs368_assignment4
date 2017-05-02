///////////////////////////////////////////////////////////////////////////////
// File Name:      UndergradStudent.hpp
//
// Author:         Roz Stengle, Ben Chylla
// CS email:       roz@cs.wisc.edu, chylla@cs.wisc.edu
//
// Description:    The implementation of the UndergradStudent class.
// 
///////////////////////////////////////////////////////////////////////////////

#include "UndergradStudent.hpp"
#include <iostream>

int UndergradStudent::numUndergradStudents;

std::string residenceHall;
std::string yearInCollege;

UndergradStudent::UndergradStudent(std::string name,
									const std::vector<double> &assignmentsScore,
									double projectScore,
									std::string residenceHall,
									std::string yearInCollege) :
									Student(name, assignmentsScore,
											projectScore) {
	this->residenceHall = residenceHall;
	this->yearInCollege = yearInCollege;
	numUndergradStudents++;
}

    /**
     * @brief Getter for a student's residence hall.
     *
     * @return The residence hall in which the student resides.
     */
    std::string getResidenceHall() {
		return residenceHall;
	}

    /**
     * @brief Getter for a student's year in college.
     *
     * @return The year in college of the student.
     */
    std::string getYearInCollege(){
		return yearInCollege;
	}

    /**
     * @brief Get the total number of undergraduate students.
     *
     * @return The number of undergraduate students.
     */
    int UndergradStudent::getNumStudents() {
		return numUndergradStudents;
	}

    void UndergradStudent::printDetails() {
		Student::printDetails();
		std::cout << "Residence Hall = " << getResidenceHall() << std::endl;
		std::cout << "Year in College = " << getYearInCollege() << std::endl;
	}

    double UndergradStudent::getTotal(){
		double average;
		for (auto i : getAssignmentsScore()) {
			average += i;
		}
		average = average/((getAssignmentsScore().size()));
		double total = average * 0.7 + getProjectScore() * 0.3;
		return total;
	}

    std::string UndergradStudent::getGrade() {
		std::string grade;
		
		if (getTotal() >= 70) {
			grade = "CR";
		}
		else
			grade = "N";
		
		return grade;
	}
