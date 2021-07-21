/*Celem zadania jest przećwiczenia operatora () oraz std::function.

Należy zaimplementować klasy Sinus, PierwiastekKwadratowy oraz Liniowa -  te trzy proszę umieścić w nagłówku Funkcje.h. Powinny one posiadać operator () zwracający wartość funkcji w punkcie zadanym przez argument operatora.

Należy zaimplementować klasę ZlozenieFunkcji pozwalającą na wyznaczenie wartości złożenia funkcji (funkcjonałów). Dla przypomnienia: złożenie funkcji f1(x) oraz f2(x), f1(x) o f2(x), definiujemy jako f2( f1(x) ). Klasa powinna również posiadać zdefiniowany operator [ ] pozwalający na dostęp do pośrednich wyników złożenia funkcji (np. jeśli złożone mają zostać trzy funkcje f3(f2(f1(x))) to [1] powinien zwrócić f2(f1(x)); proszę wywnioskować o działaniu operatora na podstawie kodu main.cpp).

Można (zaleca się) używać std::vector. Co nie jest zabronione, jest dozwolone (proszę nie pytać "czy klasa X może mieć N pól prywatnych").
*/


#include "include/Funkcje.h"
#include "include/ZlozenieFunkcji.h"

#include <iostream>

double tylkododatnie(double x){
    return x>0 ? x : 0;
}

int main (){
    const Sinus sinus(M_PI, M_PI/2.); // f(x) = sin(a*x + b)
    const PierwiastekKwadratowy squareroot; // f(x) = x^0.5
    const Liniowa lin(-0.25, 1.0); // f(x) = ax + b, a=-0.25, b=1
    
    double x = 10;
    
    std::cout << "Wartosci funkcji dla argumentu x = " << x << std::endl;
    std::cout << "\tsinus(x) = " << sinus(x) << std::endl;
    std::cout << "\tsquareroot(x) = " << squareroot(x) << std::endl; 
    std::cout << "\tlin(x) = " << lin(x) << std::endl; 
    
    ZlozenieFunkcji fs;
    fs.insert(sinus);
    fs.insert(squareroot);
    fs.insert(lin);
    fs.insert(tylkododatnie);
    
    double result1 = fs.wynik(x);
    double result2 = tylkododatnie(lin(squareroot(sinus(x))));
    
    std::cout << "-> x = " << x << ":\t" << result1 << ", " << result2 << std::endl; 
    
    x=0.25;
    std::cout << "-> x = " << x << ":\t" << fs.wynik(x) << std::endl;
    
    std::cout << "Wyniki dzialan kolejnych zagniezdzen funkcji: " << std::endl;
    double sinx = sinus(x);
    std::cout << "\t" << sinx << ", " << fs[0] << std::endl; 
    std::cout << "\t" << squareroot(sinx) << ", " << fs[1] << std::endl; 
    std::cout << "\t" << lin(squareroot(sinx)) << ", " << fs[2] << std::endl; 
		
}

/* //Output:
Wartosci funkcji dla argumentu x = 10
    sinus(x) = 1
    squareroot(x) = 3.16228
    lin(x) = -1.5
-> x = 10:  0.75, 0.75
-> x = 0.25:    0.789776
Wyniki dzialan kolejnych zagniezdzen funkcji: 
    0.707107, 0.707107
    0.840896, 0.840896
    0.789776, 0.789776
*/
