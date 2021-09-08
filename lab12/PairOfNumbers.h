#pragma once

template<class VAL1, class VAL2>
class PairOfNumbers
{
private:

public:

	VAL1& first;
	VAL2& second;

	PairOfNumbers() = default;
	PairOfNumbers(VAL1& _val1,VAL2& _val2) : first(_val1), second(_val2) {}

	PairOfNumbers<VAL2, VAL1> Swapped() const
	{
		return PairOfNumbers<VAL2, VAL1>(this->second, this->first);
	}

	void Print() const
	{
		std::cout << "Print method: " << first << " " << second << std::endl;
	}

	void Add(VAL1 val)
	{
		first += val;
		second += val;
	}
	void Scale(VAL1 val)
	{
		first *= val;
		second *= val;
	}
	void Info()
	{
		std::cout << "This is NON-const pair of numbers " << std::endl;
	}

	void Info() const
	{
		std::cout << "This is const pair of numbers " << std::endl;
	}
};