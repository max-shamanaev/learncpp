#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
	std::string name{};
	char grade{};
};

class GradeMap
{
public:
	char& operator[](const std::string& keyName)
	{
		auto exist = std::find_if(m_map.begin(), m_map.end(), 
			[&keyName](const StudentGrade& student)
			{
				return student.name == keyName;
			});

		if (exist != m_map.end())
			return exist->grade;
		
		m_map.push_back(StudentGrade{keyName});

		return m_map.back().grade;
	}

private:
	std::vector<StudentGrade> m_map{};
};

void q14_9()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';


	GradeMap grades2{};

	char& gradeJoe{ grades2["Joe"] }; // does a push_back
	gradeJoe = 'A';

	// vector resize after second push_back will lead to invalidation
	// gradeJoe ref
	//char& gradeFrank{ grades["Frank"] }; // does a push_back
	//gradeFrank = 'B';

	std::cout << "Joe has a grade of " << gradeJoe << '\n';
	//std::cout << "Frank has a grade of " << gradeFrank << '\n';
}