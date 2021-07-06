/*Nalezy zaimplementowac klase StringBack pozwalajacą na wysoko zoptymalizowana konkatenacje (poprzez operator -=).

Oobiekty StringBack poza tablica znakow musza posiadac wskaznik na kolejny (a w zasadzie poprzedni) obiektStringBack (jak w liscie polaczonej). Wowczas konkatenacja polega na dolozeniu kolejnego (poprzedzajacego) StringBacka na poczatku listy. Zasadnicza optymalizacja zachodzi przy przesuwaniu gdzie nie potrzebna jest zadna alokacja.

Oczekiwane funkcjonalnosci klasy StringBack nalezy wywnioskowac z pliku main.cpp. Kilka glownych to:
StringBack::size - zwraca liczbe znakow w napisie (lacznie z dlugoscia w "podinkowanych" napisach),
StringBack::fragments - zwraca liczbe fragmentow (dlugosc listy),
StringBack::fragment(i) - zwraca i-ty StringBack z listy polaczonej (0 to jej koniec),
StringBack::str() - zwraca znaki (const char*) przechowywane w danym fragmencie.
W implementacji tej klasy musi byc uzyta zwyczajna tablica char i ew. mona zapisac rozmiar. Liste prosze zaimplementowac w najlprostszy mozliwy sposob (jednokierunkowa). Prosze pamietac o konwersjach, to duza oszczednosc na kodzie do napisania.

TIP: Klase mozna (nalezy) traktowac jak najprostsza mozliwa liste jednokierunkowa przechowujaca const char *, a odwrocona kolejnosc listy wystarczy zrealizowac w metodzie(operatorze) odpowiedzialnej(ym) za wyswietlanie tekstu.

*/


#include <iostream>
#include <utility>

#include "include/StringBack.h"

int main() {
    StringBack m(" am");
    m -= " I";
    m -= " as";
    m -= " bored";
    m -= " as";
    m -= " you";
    m -= " are";
    m -= " ?";
		
	
    std::cout << "size " << m.size() << " " << m.fragments() <<  " " << m << std::endl;
	
    StringBack mm(std::move(m));
    std::cout << "m (after move) size " << m.size() <<  " " << m << std::endl;
    std::cout << "mm size " << mm.size() << " " << mm.fragments() <<  " " << mm << std::endl;

    StringBack n(" ???");
    n -= std::move(mm);
    std::cout << "n: " << n << std::endl;

    StringBack k;
    k = std::move(n);
    std::cout << "n (after move): " << n << std::endl;
    std::cout << "k: " << k << std::endl;
    const StringBack kk(std::move(k));
    std::cout << "kk: " << kk.fragments() << std::endl;
    std::cout << kk.fragment(4).str() << std::endl;
		
}

/* //Output:
size 27 8  ? are you as bored as I am
m (after move) size 0 
mm size 27 8  ? are you as bored as I am
n:  ? are you as bored as I am ???
n (after move): 
k:  ? are you as bored as I am ???
kk: 9
 bored
*/
