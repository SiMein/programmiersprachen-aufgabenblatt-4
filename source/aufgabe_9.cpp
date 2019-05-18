# include <cstdlib> // std :: rand ()   Standard General Utilities Library  This header defines several general purpose functions,
                            // including dynamic memory management, random number generation, communication with the environment, 
                            //integer arithmetics, searching, sorting and converting.
# include <vector> // std :: vector <>
# include <list> // std :: list <>
# include <iostream> // std :: cout
# include <iterator> // std :: ostream_iterator <>
# include <algorithm> // std :: reverse , std :: generate

int main (){

     std::cout << "---------------------------------------------------1\n";
    std :: vector <int> v_0 (10);    //Initialisierung eines int-Vektors der Größe 10  
    for ( auto & v : v_0) {         // Befüllung des Vektors mit zufaelligen int-Werten 
        v = std::rand ();
    }                                           //cbegin  Returns a const_iterator pointing to the first element in the container.
                                                // Copies the elements in the range [first,last) into the range beginning at result.
    std :: copy (std::cbegin (v_0), std::cend (v_0), //Kopie des zuvor ganzen erstellten Vectors (von begin bis end)
    std :: ostream_iterator <int>( std::cout , "\n")); // Ostream iterators are output iterators that write sequentially to an output stream (such as cout).
                                                // gibt die Elemente im Zwischenspeicher der reihe nach aus
    std::cout << "---------------------------------------------------2\n";

    std :: list <int> l_0(std::cbegin (v_0), std::cend ( v_0 ));  // Copies the elements of the vector (range first-last) into the list l_0
    std :: list <int> l_1(std::cbegin (l_0), std::cend ( l_0 ));  // Copies the elements of the list l_0 (range first-last) into the list l_1 
                            
    std :: reverse (std :: begin (l_1), std::end(l_1 ));  // Reverses the order of the elements in l_1 
                                                  // The function calls iter_swap to swap the elements to their new locations.
    std :: copy (std :: cbegin (l_1), std::cend (l_1),  // Copy in Zwischenspeicher
    std :: ostream_iterator <int >( std :: cout , "\n")); // Ausgabw der reversden liste 

    std::cout << "---------------------------------------------------3\n";

    l_1 . sort ();                          // Liste l_1 wird aufsteigend sortiert
    std :: copy (l_1. cbegin (), l_1. cend (),  // Copy in Zwischenspeicher
    std :: ostream_iterator <int >( std :: cout , "\n"));  // Ausgabw der sortierten liste 

    std::cout << "---------------------------------------------------4\n";

    std :: generate (std :: begin (v_0), std :: end(v_0), std :: rand ); //Generiert Sie Werte für d range /begin to last)
                         // mit der Funktion Weist den Wert zu, der von 
                         // aufeinanderfolgenden Aufrufen von gen() an die Elemente im Bereich [first, last] zurückgegeben wird.
    std :: copy (v_0. crbegin (), v_0. crend (), // Returns a const_reverse_iterator pointing to
                                                 // the last element in the container (i.e., its reverse beginning).
    std :: ostream_iterator <int >( std :: cout , "\n"));

    return 0;
}

 /* cbegin Returns a const_iterator pointing to the first element in the container.
 A const_iterator is an iterator that points to const content. 
 This iterator can be increased and decreased (unless it is itself also const), 
 just like the iterator returned by vector::begin, but it cannot be used to modify
  the contents it points to, even if the vector object is not itself const.
If the container is empty, the returned iterator value shall not be dereferenced.
*/