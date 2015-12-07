#ifndef EXER17_11_QUIZ_H
#define EXER17_11_QUIZ_H
#include <cstddef>
#include <iostream>
#include <string>
#include <bitset>
#include <stdexcept>
template <std::size_t N> class Quiz;
// friend overloaded << operator
template <std::size_t N>
std::ostream& operator<<(std::ostream&os, const Quiz<N>&);
// friend to calculate grades
template <std::size_t N>
std::size_t grades(const Quiz<N>&, const Quiz<N>&);
template <std::size_t N>
class Quiz {
	friend std::ostream& operator<< <N>(std::ostream&, const Quiz<N>&);
	friend std::size_t grades<N>(const Quiz<N>&, const Quiz<N>&);
public:
	Quiz() = default;
	Quiz(const std::string &s) : q(s) {}
	void updataQuiz(std::size_t n, bool a) {
		if(n >= N)
			throw std::out_of_range("out of range!");
		q.set(n, a);
	}
private:
	std::bitset<N> q;
};
// friend overloaded << operator
template <std::size_t N>
std::ostream& operator<<(std::ostream& os, const Quiz<N> &quiz)
{
	os << quiz.q;
}
// friend to calculate grades
template <std::size_t N>
std::size_t grades(const Quiz<N> &ans, const Quiz<N> &test)
{
	std::size_t grd = 0;
	for(std::size_t i = 0; i != N; ++i)
	{
		if(ans.q[i] == test.q[i])
			++grd;
	}
	return grd;
}
#endif