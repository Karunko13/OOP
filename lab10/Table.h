#pragma once
#include <functional>
#include <iostream>

class Table
{
private:
	std::vector<Data> dataVec;
	
public:
	int minRow = -1;

	Table() = default;
	
	void operator+=(Data data)
	{
		dataVec.push_back(data);

		if (minRow < data.getNumbers().size())
		{
			minRow = minRow;
		}
		else
		{
			minRow = data.getNumbers().size();
		}
	}

	void print() const
	{
		std::for_each(dataVec.begin(), dataVec.end(), [](const Data& data) {data.print(); });
		std::cout << std::endl;
	}


	const Table& sort(unsigned column)
	{
		if (minRow <= column)
		{
			std::cout << "Indeks 3 nieprawidlowy!" << std::endl;
			return *this;
		}

		std::sort(dataVec.begin(), dataVec.end(), [column](const Data& a, const Data& b) {return a.getNumbers()[column] < b.getNumbers()[column]; });
		return *this;



		//return sortBy([column](const Data& a, const Data& b) {return a.getNumbers()[column] < b.getNumbers()[column]; });
		}
	const Table& sortBy(std::function<bool(const Data& a, const Data& b)> compare)
	{
		std::sort(dataVec.begin(), dataVec.end(), compare);
		return *this;
	}
};

