/*
 * Celem zadania jest napisanie hierarchi klas opisujacej skladniki systemu plikow.
 * Skladnikami tymi sa miedzy innymi katalog (klasa Dir) i plik (klasa File).
 * Jaka jest hierarchia? Czy wystepuja w niej tylko te dwie klasy?
 * Nalezy przewidziec ze beda to jeszcze jakies inne obiekty. Np. Link?
 * Prosze uniemozliwic dziedziczenie po klasie Dir, bez tego (-2pkt).
 * Prosze napisaca w dokumentacji jak i dlaczego nie bedzie mozna po klasie Dir dziedziczyc.
 *
 *
 * UWAGA: Aby zapewnic ladne wypisywanie, klasy te powinny psiadac metode print z argumentem informujacym
 *        ile spacji potrzeba wypisac przed nazwa (indentacja). operator<< powinien wywolac te metode dla Dir a ona rekursywnie metody print dla skladowych zwiekszajac liczbe spacji.
 * UWAGA: W rozwiazaniu nalezy uzyc dynamicznego rozpoznania typow (wazne, upraszcza implementacje nieco!)
 * UWAGA: Prosze zauwazyc ze Dir zarzada pamiecia dla przechowywanych obiektow. To znaczy musi jes skasowac.
 *        W implementcji mozna uzyc czego sie chce. Jak ktos umie std::vector to b. prosze.
 *        Moze byc takze tablica na 10 elementow lub PArr z poprzedniego zadania.
 * UWAGA: W implementacji klasy Dir nie mozna uzyc dwoch "tablic" jedna na pliki a druga na katalogi bo jest to
 *        a) nierozszerzalne b) nie da sie zachowac kolejnosci dodawania do katalogu.


*/


#include "Dir.h"
#include "File.h"


int main() {

  Dir* top = new Dir(".");
  Dir* home = new Dir("home");
  *top += home; // dodajemy do kat TOP podkatalog
  *home += new Dir("rafal");
  *home += new File("proj.descr");
  *home += new File("proj.files.repo");
  *home += new Dir("adam");
  
  std::cout << (const Dir&)*top << std::endl;

  top->findDir("rafal")->add( new Dir("Desk") );

  Dir* rafal = home->findDir("rafal");  
  *rafal += new File("foto1.jpg");
  *rafal += new File("foto2.jpg");
  *rafal += new File("foto3.jpg");
  top->findDir("rafal")->add( new Dir("work") );


  std::cout << *top;
  std::cout << "--------------" << std::endl;
  std::cout << *(rafal->get("work"));
  std::cout << *(top->get("proj.descr"));

  delete top;
	
}

/* //OUTPUT 
. (DIR)
  home (DIR)
    rafal (DIR)
    proj.descr (FILE)
    proj.files.repo (FILE)
    adam (DIR)

. (DIR)
  home (DIR)
    rafal (DIR)
      Desk (DIR)
      foto1.jpg (FILE)
      foto2.jpg (FILE)
      foto3.jpg (FILE)
      work (DIR)
    proj.descr (FILE)
    proj.files.repo (FILE)
    adam (DIR)
--------------
work (DIR)
proj.descr (FILE)
Deleting Dir: .
About to delete home
Deleting Dir: home
About to delete rafal
Deleting Dir: rafal
About to delete Desk
Deleting Dir: Desk
About to delete foto1.jpg
About to delete foto2.jpg
About to delete foto3.jpg
About to delete work
Deleting Dir: work
About to delete proj.descr
About to delete proj.files.repo
About to delete adam
Deleting Dir: adam
 */
