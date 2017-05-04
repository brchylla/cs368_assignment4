///////////////////////////////////////////////////////////////////////////////
// File Name:      processStudent.cpp
//
// Author:         Ben Chylla, Roz Stengle
// CS email:       chylla@cs.wisc.edu, roz@cs.wisc.edu
//
// Description:    Methods to perform some processing on student objects.
//
// Sources:        <Sources, if any>
//
// URL(s) of sources:
//                 <URLs of your sources, if any>
///////////////////////////////////////////////////////////////////////////////

#include "processStudent.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

void fillStudents(std::istream &inFile,
		std::vector<GradStudent> &gstudents,
		std::vector<UndergradStudent> &ugstudents) {
	std::string line;
	while(getline(inFile, line)) {
		std::vector<std::string> inputs;
		for (int i = 0; i < 11; i++) {
			size_t found = line.find(',');
			if (found != std::string::npos) {
				inputs.push_back(line.substr(0, found));
				line.erase(0, found);
			}
			else {
				inputs.push_back(line);
			}
		}
		std::string studentType = inputs[0];
		std::string name = inputs[1];
		double score1 = std::stod(inputs[2]);
		double score2 = std::stod(inputs[3]);
		double score3 = std::stod(inputs[4]);
		double score4 = std::stod(inputs[5]);
		double score5 = std::stod(inputs[6]);
		double score6 = std::stod(inputs[7]);
		double projectScore = std::stod(inputs[8]);
		std::string resHallOrResearchArea = inputs[9];
		std::string yearInSchoolOrAdvisor = inputs[10];

		std::vector<double> assignmentScore = {score1, score2, score3, score4, score5, score6};
		if (studentType.compare("U") == 0) {
			//Student* aUGStudent = new UndergradStudent(name, assignmentScore, projectScore, resHallOrResearchArea, yearInSchoolOrAdvisor);
			ugstudents.push_back(UndergradStudent(name, assignmentScore, projectScore, resHallOrResearchArea, yearInSchoolOrAdvisor));
		}
		else {
			//Student* aGStudent = new GradStudent(name, assignmentScore, projectScore, resHallOrResearchArea, yearInSchoolOrAdvisor);
			gstudents.push_back(GradStudent(name, assignmentScore, projectScore, resHallOrResearchArea, yearInSchoolOrAdvisor));
		}
	}
}

void printStudents(const std::vector<std::reference_wrapper<Student>> &students) {
	std::sort(students.begin(), students.end(), [](Student &a, Student &b)
			{
		return a.getTotal() > b.getTotal();
			});
	for (int i = 0; i < students.size(); i++) {
		students[i].Student::printDetails();
		//newStudent.printDetails();
	}
}

void computeStatistics(std::vector<std::reference_wrapper<Student>> &students) {
	std::cout << "Number of students = " << students.size() << std::endl;
	double totalScore;
	for (int i = 0; i < students.size(); i++) {
		totalScore += students[i].getTotal();
	}
	std::cout << "The mean of the total score = " << totalScore/students.size() << std::endl;
	std::cout << "The sorted list of students (id, name, total, grade) in descending order: " << std::endl;
	struct less_than_key
	{
		inline bool operator() (Student student1, Student student2)
		{
			return (student1.getTotal() < student2.getTotal());
		}
	};
	std::sort(students.begin(), students.end(), less_than_key());
	for (int i = 0; i < students.size(); i++) {
		std::cout << students[i].getId() << ", " << students[i].getName() << ", " << students[i].getTotal() << ", " << students[i].getGrade() << std::endl;
	}
}
