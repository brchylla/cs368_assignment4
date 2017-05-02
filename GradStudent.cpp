///////////////////////////////////////////////////////////////////////////////
// File Name:      GradStudent.hpp
//
// Author:         Roz Stengle, Ben Chylla
// CS email:       roz@cs.wisc.edu, chylla@cs.wisc.edu
//
// Description:    The implementation of the Grad Student class.
//
///////////////////////////////////////////////////////////////////////////////


#include "GradStudent.hpp"
#include <iostream>

std::string researchArea;
std::string advisor;

int GradStudent::numGradStudents;

GradStudent::GradStudent(std::string name,
						const std::vector<double> &assignmentsScore,
						double projectScore,
						std::string researchArea, std::string advisor) :
						Student(name, assignmentsScore, projectScore) {
	this->researchArea = researchArea;
	this->advisor = advisor;
}
    /**
     * @brief Getter for the student's research area.
     *
     * @return The research area of the student.
     */
    std::string getResearchArea() {
		return researchArea;
    }

    /**
     * @brief Getter for the student's advisor.
     *
     * @return The advisor of the student.
     */
    std::string getAdvisor() {
		return advisor;
	}

    /**
     * @brief Get the total number of graduate students.
     *
     * @return The number of graduate students.
     */
    int GradStudent::getNumStudents(){
		return numGradStudents;
	}

    void GradStudent::printDetails() {
		Student::printDetails();
		std::cout << "Research Area = " << getResearchArea() << std::endl;
		std::cout << "Advisor = " << getAdvisor() << std::endl;
	}

    double GradStudent::getTotal(){
		double average;
		for (auto i : getAssignmentsScore()) {
			average += i;
		}
		average = average/((getAssignmentsScore()).size());
		double total = average * 0.5 + getProjectScore() * 0.5;
		return total;
	}

    std::string GradStudent::getGrade() {
		std::string grade;
		if (getTotal() >= 80) {
			grade = "CR";
		}
		else
			grade = "N";
		
		return grade;
	}
