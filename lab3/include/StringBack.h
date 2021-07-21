#pragma once
#include <iostream>
#include <utility>
#include <cstring>

using namespace std;

class StringBack{
	
		private:
		//rozmiar listy
		int _size=0;
		
		char* _data=nullptr;
		//wskaznik na poprzedni element z listy
		StringBack* _next=nullptr;
		
		public:
		//konstruktor domyslny
		StringBack()=default;
		//konstruktor jednoargumentowy
		StringBack(const char* str);
		//konstruktor kopiujacy
		StringBack(const StringBack& org);
		//konstruktor przenoszacy
		StringBack(StringBack&& org);

		void operator-=(StringBack* next);

		void operator-=(const char* string);

		void operator-=(StringBack&& next);

	  void operator=(StringBack&& str);

		int size() const;

		const char* str() const;

		int fragments() const;

    friend std::ostream& operator<<(std::ostream& out,const StringBack& str);

		const StringBack& fragment(unsigned index) const;
		//destruktor
		~StringBack();
};

