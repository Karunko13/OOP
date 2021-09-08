#pragma once
#include "Data.h"
class Sum
{
private:
	double _val;
public:

	Sum(double val) : _val(val) {}

	double value()
	{
		return _val;
	}

	void operator()(double val)
	{
		_val += val;
	}
};

Sum sumData(const Data& dat)
{
	double sum = 0;
	const std::vector<double>& numbers = dat.getNumbers();
	std::for_each(numbers.begin(), numbers.end(), [&sum](double number) {sum += number; });
	return Sum(sum);
}