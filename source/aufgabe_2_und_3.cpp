#include <list>
#include <iostream>
#include <set>
#include <map>


int main(int argc, char* argv[]){

    std::list<unsigned int>  defau;     // Initialisierung d list mit Groesse 0
    std::list<unsigned int>  empty{};   // Initialisierung d list mit Groesse 0
    std::list<unsigned int>  fifty(50); // Init -Große d list enspr Zahl in d runden Klammern, alle vom Wert 0
    std::list<unsigned int>  l{8,2,3,4,5}; // direkteingabe d elemente , also groesse 5 hier
    std::list<unsigned int>  rl{};

    std::cout << defau.size() << "\n" ;
    std::cout << fifty.size() << "\n" ;
    std::cout << empty.size() << "\n";
    std::cout << l.size() << "\n";
    std::cout << rl.size() << "\n\n";



    for (std::list<unsigned int>::iterator it = rl.begin(); (rl.size() < 100 ); it++){
       rl.push_back(rand()%100);  // Trick mit Restausgabe / kein Ober-/Untergrenzenoperator möglich ??   
    }
    std::cout << "Alle Zahlen in der Liste :";
    
    for (unsigned int i : rl){
        std::cout << i << ",";         // std::set  // erlaubt keine doppelten bzw mehrfachen Werte
    }                               // set --Schluessel und Wert identisch , collection of unique keys, sorted by keys 
    std::set<unsigned int> all_unikate(std::begin(rl), std::end(rl));  // set -container - keine duplikate mgl. ! 
    std::cout << "\nGesamtgroesse der rl-Liste : " << rl.size()<< std::endl;
    std::cout << "Anzahl d Unikate (also size Set-List): " << all_unikate.size()<<std::endl; 
    std::cout << "Nicht in der (Set-)Liste sind : \n";
    
    for(int i = 0 ; i < 100 ; i++) {
        if (all_unikate.count(i) != true) {      //Abfrage ob die Zahl (mit ihren Haufgikeiten in der Liste) existiert 
            std::cout << "[" << i << "]" ;
        }
    }
    std::cout << std::endl << std::endl;
    std::cout << "In der (set-)Liste sind (aufst. sotiert) : \n";
    
    for (unsigned int i : all_unikate){
        std::cout << i << ",";
    }
     std::cout << std::endl << std::endl;

                        //map-- collection of key-value pairs, sorted by keys, keys are unique   (in multimap keys must not be unique)
   
    std::map<unsigned int, unsigned int> map_1;     // map erstellen -iterrieren ueber die ganze list, 
                                                     // im rumpf Häufigkeit inkrementieren , ggfs. auch mehrfach.
    for (std::list<unsigned int>::iterator i = rl.begin(); i != rl.end(); ++i) {    // iterator hier kein einfacher int, sondern spe 
    map_1[*i]++;  // besonderheit bei map--wenn key noch nicht vorhanden , dann direkte erzeugung dieses Key, so direkte Inkrementierung mgl.                             
    }                                                                              

    std::cout << "Wert : Häufigkeit standard-for-schleife-(saved in map_1)" << std::endl;     
    for (int i = 0; i < 100; ++i) {
    std::cout << i << ":" << map_1[i] << ", ";   //Ausgabe d aktuellen schleifendurchlaufs und inhalt des zugehoerige feldes
    }
    std::cout << std::endl;


    std::cout <<"\nHäufigkeit direkt-map-schleife-(saved in map_1) auto Iteratorzuweisung begin u end  und first/second zugriff\n ";
    for (auto it_map = map_1.begin(); it_map != map_1.end(); ++it_map){
       std::cout << it_map->first << ":" << it_map->second << ", "; 
    }
    std::cout << std::endl;
} 
/*  
  //  alternativemit direktem zugriff auf das Pair des Iterators , so direkter Aufruf mit first und second möglich 

Associative
    Elements in associative containers are referenced by their key and not by their absolute position in the container.
Ordered
    The elements in the container follow a strict order at all times. All inserted elements are given a position in this order.
*/