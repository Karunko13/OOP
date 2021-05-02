#include "W.h"

W::W()
	{
		_size=0;
		tab=nullptr;
	}

W::W(int size)
	{
		_size=size;
		tab=new int[_size];
		for(int i=0; i<_size;i++)
		{
			tab[i]=0;//domyślnie wypełniam wektor zerami
		}
	}
W::W(const W&org )
	{	
		_size=org._size;
		tab=new int[_size];
		for(int i=0; i<_size; i++)
		{
			tab[i]=org.tab[i];
		}


	}

int &W::at(int part) const
	{
		return tab[part];
	}

void W::print(const string &name) const
	{	
		cout<<name;
		cout<<"[";
		for(int i=0; i< _size; i++)
		{
			cout<<tab[i]<<", ";
		}
		
		cout<<"\b\b]";
		cout<<endl;
	}
	
	
double W::dot(const W& vec1,const W& vec2)
		{
			if(vec1._size==vec2._size)
			{	
				double x=0;
				for(int i=0; i<vec1._size; i++)
				{
					
					x+=(vec1.tab[i])*(vec2.tab[i]);
					return x;
				}
			}
			else
			{
				cout<<"Error, vectors of different dimensions!"<<endl;
				return 0;
			}
			return 0;
		}
W::operator double() const
		{
			int x=0;
			for(int i=0; i<_size;i++)
			{
				x+=tab[i]*tab[i];
			}
			double n= static_cast<double>(sqrt(x));
			return n;

		}

double W::norm() const
{
		int x=0;
			for(int i=0; i<_size;i++)
			{
				x+=tab[i]*tab[i];
			}
			double n= static_cast<double>(sqrt(x));
			return n;
}

void W::operator +=(const W org)
	{
		if(_size==org._size)
		{
			for(int i=0; i<_size; i++)
			{
				tab[i] +=org.tab[i];
			}
		}
		else
		{
			cout<<"inne rozmiary"<<endl;//zabezpieczenie niewykorzystane w programie,sprawdzam czy rozmiary wektorow sa takie same
		}
	}

W W::operator +=(const int plus)
{
	W obj(_size);
	for(int i=0; i<_size; i++)
	{
		obj.tab[i]=tab[i]+plus;
	}
	return obj;
}