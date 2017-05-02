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

using namespace std;

void fillStudents(std::istream &inFile,
		std::vector<GradStudent> &gstudents,
		std::vector<UndergradStudent> &ugstudents) {
	string line;
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
		string studentType = inputs[0];
		string name = inputs[1];
		double score1 = stod(inputs[2]);
		double score2 = stod(inputs[3]);
		double score3 = stod(inputs[4]);
		double score4 = stod(inputs[5]);
		double score5 = stod(inputs[6]);
		double score6 = stod(inputs[7]);
		double projectScore = stod(inputs[8]);
		string resHallOrResearchArea = inputs[9];
		string yearInSchoolOrAdvisor = inputs[10];

		vector<double> assignmentScore = {score1, score2, score3, score4, score5, score6};
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
		Student newStudent = students[i].get();
		newStudents.printDetails();
	}
}

void computeStatistics(std::vector<std::reference_wrapper<Student>> &students) {
	cout << "Number of students = " << students.size() << endl;
	double totalScore;
	for (int i = 0; i < students.size(); i++) {
		totalScore += students[i].getTotal();
	}
	cout << "The mean of the total score = " << totalScore/students.size() << endl;
	cout << "The sorted list of students (id, name, total, grade) in descending order: " << endl;
	struct less_than_key
	{
		inline bool operator() (Student student1, Student student2)
		{
			return (student1.getTotal() < student2.getTotal());
		}
	};
	sort(students.begin(), students.end(), less_than_key());
	for (int i = 0; i < students.size(); i++) {
		cout << students[i].getId() << ", " << students[i].getName() << ", " << students[i].getTotal() << ", " << students[i].getGrade() << endl;
	}
}
