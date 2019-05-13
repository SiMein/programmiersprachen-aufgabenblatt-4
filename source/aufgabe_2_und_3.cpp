#include <list>
#include <iostream>

list<unsigned int>   defau;
list<unsigned int>   empty{};
list<unsigned int>   l{1,2,3,4,5};
list<unsigned int>::iterator  i=l.begin();

std::cout << defau.size ;
std::cout << empty.size ;
std::cout << l.size ;

//int main(int argc, char* argv[]){

//}

//std::set  // erlaubt keine doppelten bzw mehrfachen Werte


// Alternativ:

// auto i = l.begin();


/*
std::list   unsigned int
namespace list {
    template <typename T>
}

Instanziieren Sie eine std::list mit unsigned int und füllen Sie diese mit
100 Zufallszahlen von 0 bis 100. Bestimmen Sie, wieviele unterschiedliche Zahlen
in der std::list aus sind und geben Sie die Zahlen von 0 bis 100 aus, die nicht
in der Liste sind. Verwenden Sie std::set für ihre Lösung.
*/