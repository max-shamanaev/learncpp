/*
	�������� ��������� ���������: �������� ���������, ���������� ��� �������� � ��� ������ 
	(�� ����� �� 0 �� 100). �������� ������������, ������� ��������� �� ����� ������. 
	�������� std::vector ��� �������� ������ ���� ���������. ����� ��������� � ������������ 
	������ ��� � ������. ����� ����, ��� ������������ ���� ��� ���� ���� � ������, ������������ 
	������ �� ������� (������� ����� �������). ����� �������� ��� ����� � ������ � ��������������� �������.

	�� ������ ������������, ��� ����� �� �������� �������� � ��� ���������� ������� ������ �� ����������� �������.
*/

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>

struct Student
{
	std::string firstName{};
	int grade{};
};

// ����� �������� studentsNum <= 0
size_t getNumberOfStudents()
{
	int studentsNum{ 0 };
	do
	{
		std::cout << "How many students you want to enter: ";
		std::cin >> studentsNum;
	} while (studentsNum <= 0);

	return studentsNum;
}

bool descending(const Student& a, const Student& b)
{
	return (a.grade > b.grade);
}

void question2()
{
	// �������� ������� � ��������� ��������� ������������� �����
	//std::vector<Student> students(getNumberOfStudents());

	std::cout << "How many students you want to enter: ";
	size_t studentsNum{};
	std::cin >> studentsNum;
	
	std::cout << "Enter their name/grade(0-100) pairs:\n";
	std::vector<Student> students(studentsNum);
	for (auto& student : students)
	{
		std::cin >> student.firstName >> student.grade;
		while (student.grade < 0 || student.grade > 100 || std::cin.fail())
		{
			std::cout << "Invalid grade! Please retry: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> student.grade;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::sort(students.begin(), students.end(), descending);

	for (const auto& student : students)
		std::cout << student.firstName << " got a grade of " << student.grade << '\n';
}
