#include <string>
class Account {
public:
	Account() = default;
	Account(const std::string& s, double d) : owner(s), amount(d) {}
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
private:
	static constexpr int period = 30; // period is a const expression
	double daily_tbl[period] = {0};
	std::string owner;
	double amount;
	static double interestRate;
};
void Account::rate(double d)
{
	interestRate = d;
}
constexpr int Account::period;
double Account::interestRate = 0.0;
int main()
{
	return 0;
}