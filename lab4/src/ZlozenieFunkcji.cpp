#include "ZlozenieFunkcji.h"
	
	double ZlozenieFunkcji::wynik(double x)
	{
		ans.clear();
		x=_zlozenie[0](x);

		//push back czyli na koniec std::vector ans
		ans.push_back(x);
		//przejscie po całym vectorze _zlozenie i wypełnienie jego elementów następnymi "funkcjami"
		for(int i=1; i<_zlozenie.size(); i++)
		{
			x = _zlozenie[i](x);
			ans.push_back(x);

		}
		return ans.back();
	}

	double ZlozenieFunkcji::operator [](double id) 
	{
			return ans[id];
	}

	void ZlozenieFunkcji::insert(std::function<double(double)> funkcja)
	{
		_zlozenie.push_back(funkcja);
	}

	ZlozenieFunkcji::~ZlozenieFunkcji()
	{
		ans.clear();
		_zlozenie.clear();
	}