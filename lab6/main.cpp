/*
Cwiczenie metod wirtualnych - w rozwiazaniu musi pojawic sie slowo kluczowe virtual.

Nalezy zaimplementowac klasy wykonujace dzialania matematyczne i wypisujace dzialanie, ktore wykonuja. Nalezy zastanowic sie nad odpowiednia hierarchia klas. 
*/


#include"include/Primitive.h"
#include"include/Product.h"
#include"include/Sum.h"
#include"include/Ratio.h"
#include<iostream>

void SumFormula ();
void RatioFormula ();
void ProductFormula ();

int main ()
{
  std::cout<<"SUM:\n";
  SumFormula();
  std::cout<<"\nRATIO:\n";
  RatioFormula();
  std::cout<<"\nPRODUCT:\n";
  ProductFormula();
  
  return 0;
}

void SumFormula ()
{
  // formula: ((((a*b)+(c+d))+(c+d))+(a/b))

  Primitive primA (4);
  Primitive primB (3);
  Primitive primC (2);
  Primitive primD (1); 

  // (a*b)
  Product prodAB (primA, primB);
  prodAB.PrintWithValue();
  
  // (c+d)
  Sum sumCD (primC, primD);
  sumCD.PrintWithValue();

  // (a/b)
  Ratio ratioAB (primA, primB);
  ratioAB.PrintWithValue();

  // (a*b)+(c+d)
  Sum sum1 (prodAB, sumCD);
  sum1.PrintWithValue();

  // ((a*b)+(c+d))+(c+d)
  Sum sum2 (sum1, sumCD);
  sum2.PrintWithValue();
  
  // (((a*b)+(c+d))+(c+d))+(a/b)
  Sum sum3 (sum2, ratioAB);
  sum3.PrintWithValue();

  primA.Set(1.4);
  primB.Set(0.3);
  primC.Set(1.2);
  primD.Set(0.1);

  sum3.PrintWithValue();
	
}

void RatioFormula ()
{
  // formula: ((((a*b)/(c+d))/(a*b))/(a/b))

  Primitive primA (1);
  Primitive primB (2);
  Primitive primC (3);
  Primitive primD (4); 

  // (a*b)
  Product prodAB (primA, primB);
  prodAB.PrintWithValue();
  
  // (c+d)
  Sum sumCD (primC, primD);
  sumCD.PrintWithValue();

  // (a/b)
  Ratio ratioAB (primA, primB);
  ratioAB.PrintWithValue();

  // (a*b)/(c+d)
  Ratio ratio1 (prodAB, sumCD);
  ratio1.PrintWithValue();

  // (((a*b)/(c+d))/(a*b)
  Ratio ratio2 (ratio1, prodAB);
  ratio2.PrintWithValue();
  
  // (((a*b)/(c+d))/(a*b))/(a/b)
  Ratio ratio3 (ratio2, ratioAB);
  ratio3.PrintWithValue();

  primA.Set(0.1);
  primB.Set(0.2);
  primC.Set(0.3);
  primD.Set(0.4);

  ratio3.PrintWithValue();
}

void ProductFormula ()
{
  // formula: ((((a*b)*(c+d))*(a*b))*(a/b))

  Primitive primA (4);
  Primitive primB (2);
  Primitive primC (1);
  Primitive primD (3); 

  // (a*b)
  Product prodAB (primA, primB);
  prodAB.PrintWithValue();
  
  // (c+d)
  Sum sumCD (primC, primD);
  sumCD.PrintWithValue();

  // (a/b)
  Ratio ratioAB (primA, primB);
  ratioAB.PrintWithValue();

  // (a*b)*(c+d)
  Product product1 (prodAB, sumCD);
  product1.PrintWithValue();

  // ((a*b)*(c+d))*(a*b)
  Product product2 (product1, prodAB);
  product2.PrintWithValue();
  
  // (((a*b)*(c+d))*(a*b))*(a/b)
  Product product3 (product2, ratioAB);
  product3.PrintWithValue();

  primA.Set(1);
  primB.Set(2);
  primC.Set(3);
  primD.Set(4);

  product3.PrintWithValue();

}


/* // OUTPUT:
SUM:
(4*3) = 12
(2+1) = 3
(4/3) = 1.33333
((4*3)+(2+1)) = 15
(((4*3)+(2+1))+(2+1)) = 18
((((4*3)+(2+1))+(2+1))+(4/3)) = 19.3333
((((1.4*0.3)+(1.2+0.1))+(1.2+0.1))+(1.4/0.3)) = 7.68667

RATIO:
(1*2) = 2
(3+4) = 7
(1/2) = 0.5
((1*2)/(3+4)) = 0.285714
(((1*2)/(3+4))/(1*2)) = 0.142857
((((1*2)/(3+4))/(1*2))/(1/2)) = 0.285714
((((0.1*0.2)/(0.3+0.4))/(0.1*0.2))/(0.1/0.2)) = 2.85714

PRODUCT:
(4*2) = 8
(1+3) = 4
(4/2) = 2
((4*2)*(1+3)) = 32
(((4*2)*(1+3))*(4*2)) = 256
((((4*2)*(1+3))*(4*2))*(4/2)) = 512
((((1*2)*(3+4))*(1*2))*(1/2)) = 14
*/
