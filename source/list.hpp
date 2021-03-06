#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cassert>
#include <cstddef>  //ptrdiff_t
#include <iterator> //std::bidirectional_iterator_tag
#include <iostream>

#include <initializer_list>

template <typename T>  // Schablone für die Liste, als Klasse -soll diverse Methoden haben
class List;

template <typename T>  // als struct, weil Inhalt nur ein paar Daten keine Fkt.
struct ListNode {       // aehnlich wie rekursiv, da wiederum auf andere Listnodes zeigend
  T        value = T ();
  ListNode* prev = nullptr;
  ListNode* next = nullptr;
};

template <typename T>   // using -Fügt einen Namen ein, der an einer anderen Stelle in der 
struct ListIterator {  // deklarativen Region definiert ist, in der diese using-Deklaration angezeigt wird.
  using Self              = ListIterator<T>;
  using value_type        = T;
  using pointer           = T*;
  using reference         = T&;
  using difference_type   = ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;

  ListIterator(): //Default-konstr.
    node{nullptr}{}

  ListIterator(ListNode<T>* n): 
    node{n}{}  // Custom-konstr.--init mit einem neuen uebergeben Listnode

  // Der Stern-operator soll Dereferenzieren, Zugriff auf d Objekt/Wert ,auf welches der Iterator zeigt//
  T&  operator*()  const {
  	return node->value;
  } 

  // Rueckgabe der Referenz auf /Adresse des Objekt
  T* operator->() const {
  	  	return &(node->value);
  }

  // Iterator wird um eins nach vorne versetzt, sofern nicht schon auf Nullptr gewesen
  ListIterator<T>& operator++() {  // when no Parameter --PREINCREMENT !!
  	if (node) {
      node = node->next;
    }             // Zeigt nun auf naechsten Wert  PREINCREMENT
  	return *this;

  } 

  // Iterator wird um eins nach vorne versetzt, aber alte Wert noch zurückgegeben !!
  ListIterator<T> operator++(int) { // when int ---//POSTINCREMENT !! 
  	ListIterator<T> help = *this;  // save the old IT
    ++(*this);  // increment 
  	return help; // returns the old IT
  }  

  // Vergleich, ob beide Nodes identisch - true wenn gleich
  bool operator==(ListIterator<T> const& x) const {
  	return (node == x.node);
  }

  /// Vergleich, ob beide Nodes nicht identisch - true wenn ungleich
  bool operator!=(ListIterator<T> const& x) const {
  	return (node != x.node);
  }

 
  ListIterator<T> next() const {  // gibt nächsten Node zurück
    if (nullptr != node) {        // sofern nicht selbst schon der nullptr
      return ListIterator{node->next};
    } else {
      return ListIterator{nullptr};
    }
  }

  ListIterator<T> prev() const {  // gibt vorherigen Node zurück
    if (nullptr != node) {        // sofern nicht selbst schon der nullptr
      return ListIterator{node->prev};
    } else {
      return ListIterator{nullptr};
    }
  }

  ListNode <T>* node = nullptr;
};



template <typename T>
class List {
  public:
    using value_type      = T;
    using pointer         = T*;
    using const_pointer   = T const*;
    using reference       = T&;
    using const_reference = T const&;
    using iterator        = ListIterator<T>;

    //Aufg 4.2 //Default Constructor
    List(): 
    size_{0}, 
    first_{nullptr}, 
    last_{nullptr} {} 

    // Copy-Konstruktor using Deep-Copy semantics (Aufgabe 4.8)
    List(List<T> const& in_List):
    size_{0},
    first_{nullptr},    
    last_{nullptr} {      // elementweises uebertragen per loop
      for (ListIterator it = in_List.begin(); it != in_List.end(); ++it){
        push_back(*it);  // push_back bezieht sich auf das objekt auf dem die methode aufgerufen wurde
      }
    }
   
    //Move-Konstruktor (Aufgabe 4.13)
    List(List<T>&& in_list):
      size_{in_list.size_}, // der in klammern uebergebenen listwerden die daten entnommen
      first_{in_list.first_},   //  und auf die list auf d linken seite im aufruf uebertragen  
      last_{in_list.last_}
      {
      in_list.size_= 0;     // danach wird die alte liste zurueckgestzt
      in_list.first_= nullptr;
      in_list.last_= nullptr; 
    }
   
    // Initializer-List Konstruktor (4.14)

    List(std::initializer_list<T> ini_list) {
      for(auto& n : ini_list){
        push_back(n);
      }
    }

  	// Zuweisungsoperator wie in vorlesung vorgestellt --worauf bezieht sich das ??
    //TODO: Assignment operator (Aufgabe 4.12)

  	// Vergleichsoperator speziell für Listenvergleich- true wenn gleich  (aufg 4.7)
    bool operator==(List<T>const& rhs) const{
      if(size() == 0 && rhs.size() == 0){
        return true;
      }
      if(size() != rhs.size()){
        return false;
      }
      ListIterator help1 = rhs.begin();
      ListIterator help2 = first_ ;   //  Hier mit auto als Zuweisung Fehler --Warum ????

      while(help1 != nullptr){
        if (*help1 != *help2){
          return false;
        }
        help1 = help1.next() ;
        help2 = help2.next();
      } 
      return true;
    }
    //   elegante Version --Liste, auf der der != operator aufgerufen wird, das geht mit dem *this-Pointer. 
    bool operator!=(List<T>const& rhs) const{   // vgl mit Input parameter /liste - dann result negieren 
      return(!(*this==rhs));
    }
    
    /*
    bool operator!=(List<T>const& rhs) const{  // negierte == Loesung als vollcodecopy 
      if(size() == 0 && rhs.size() == 0){    
        return false;                         
      }
      if(size() != rhs.size()){
        return true;
      }
      ListIterator help1 = rhs.begin();
      ListIterator help2 = first_ ;  

      while(help1 != nullptr){
        if (*help1 != *help2){
          return true;
        }
        help1 = help1.next() ;
        help2 = help2.next();
      } 
      return false;
    } 
    */ 
  
  	/* Dekonstruktor entfern alle elemente mittels clear-methode*/
    // direkter aufruf mgl, oder eben meist als" garbage-collector 
    // als letztes ausgeführt bevor element geschlossen wird 
    ~List() {
  	   clear();
    }
    iterator begin() const {
      if (empty()) {
        return iterator();
      }else {
      return iterator{first_};
      }
    }
    iterator end() const {
      return iterator();
    }


    /* alle elemente der reihe nach entfernen*/ 
    void clear() {
  		while (size() != 0){
        pop_front();
      }
    }

    //TODO: member function insert
    ListIterator<T> insert(ListIterator<T> const& in_it, T const& in_value){
      if((size() == 0)){
        push_front(in_value);  // in List deklaration auch aufruf von membermethoden direkt mgl. ohne Instanz bzw punkt davor ??
        last_ = first_;
        ListNode<T>* outIt = first_;
        return first_;
      }
      if (in_it == end()) {
        push_back(in_value);
        return last_->prev;
      }
      if (in_it == begin()) {
        push_front(in_value);
        return first_;
      } 
      
      
      ListNode<T>*helper = in_it.node; // zunächst nodes aus dem iterator rausgefiltert
      auto helper_pre = helper->prev ;  // auto hier ebenfalls ListNode 
                        // neuer Knoten mit parametern (wert (T), vorgaenger listnode, nachfolger  listnode) 
      ListNode<T>* n_insert = new ListNode<T>{in_value, helper_pre, helper};  // also genau vorm iterator einfuegen
      helper_pre->next = n_insert;          // Vorgänger zeigt vorwaerts auf neues element
      helper->prev = n_insert;                // nachfolger zeigt rueckwaerts auf neues element
      ++size_; 
      return n_insert; 

      /* 
      /home/simon/Documents/CPP/programmiersprachen-aufgabenblatt-4/source/list.hpp:239:64: error:
      request for member ‘prev’ in ‘*(& in_it)->ListIterator<int>::operator->()’, which is of non-class type ‘int’
      ListNode<T>* n_insert = new ListNode<T>{in_value, in_it->prev, in_it};
      */                                                  
    }

  	/* Memberreverse dreht liste um durch vertauschung der next und prevzeiger*/
    void reverse(){
      //last_ = first_;
      auto one = first_->prev;  // one als neues element anlegen ??
      auto two = first_;
       
      while (two != nullptr){   // Abbruch wenn listenende erreicht
        one = two->prev;        // init. one vorm first elemt //  bzw um eins weiter rücken
        two->prev = two->next;  // Zeiger tausch auch 
        two->next = one;        //  -""_
        two = two->prev;        // weiter zum nächsten element bereits zeiger getausch, daher prev
      }
      first_ = one; // one steht auf altem last , wird nun first
    }

    // Ein Element wird am Anfang der Liste eingefuegt
    void push_front(T const& element) {
      
  		if (size() == 0){         // Wenn leer dann erstes gleich letztes element
        first_ = new ListNode<T>{element,nullptr,nullptr}; // init des neuen Elements entspr. ListNode Konstruktor
        last_ = first_;
      }  else {        
        first_ = new ListNode<T>{element,nullptr, first_}; // Trick- zunächst next-Zeiger auf altes first-element (in im Konstruktor) 
                                                  // dann Zuweisung des neuen first-elements
        first_->next->prev = first_;    // zugriff auf altes first element wo vorgänger (neues First-element )verknüpft wird    
      }
      ++size_;
    }

    // Ein Element wird am Ende der Liste eingefuegt
    void push_back(T const& element) {      // analog zu push_front, von der anderen Seite
  		if (size() == 0){
        last_ = new ListNode<T> {element, nullptr, nullptr};
        first_ = last_;
      } else {
        last_ = new ListNode<T> {element, last_, nullptr};
        last_->prev->next = last_;
      }
      ++size_;
    }

    // Ein Element wird am Anfang der Liste entfernt
    void pop_front() {
    //	assert(!empty());  // wie genau verwendet man das ?
      if (size() == 0){
        std::cout << "Die Liste war bereits leer, entfernen mit pop_front nicht möglich \n";
      } else {

          if (size() == 1){
          delete first_;
          first_ = nullptr;
          size_ = 0;
        } else {
            auto help = first_->next;  // Hilfszeiger auf zweites Element
            delete first_;    // altes first loeschen
            first_ = help;    // neues first ist altes zweites Element 
            first_->prev = nullptr; // prevzeiger aktuallisieren
            --size_;        // ?? Frage -Zeiger müssen nicht deleted werden ?? Nur konkrete Objekte ??
        }
      }
    }

    // Ein Element wird am Ende der Liste entfernt
    void pop_back() {
    	//assert(!empty());
      if (size() == 0){
        std::cout << "Die Liste war bereits leer, entfernen mit pop_back nicht möglich \n";
      }
      else {
  
        if (size() == 1){
          delete last_;
          last_ = nullptr;
          size_ = 0;
        }else {
          auto help = last_->prev;
          delete last_; 
          last_ = help;    
          last_->next = nullptr; 
          --size_;
        } 
      }
    }

  	  // Gibt das Frontelement zurueck per Referenz
    T& front() {
      assert(!empty());  
  	  return first_->value;     				
    }

      // Gibt das Backelement zurueck per Referenz
    T& back() {
    	assert(!empty());
    	
    	return last_->value; 
    				
    }

  	//(4.2) function says true when list empty else false
    bool empty() const {
      return (size() ==  0);  
    };

    //(4.2)  standard getter function for the size of list
    std::size_t size() const {    // Datentyp   Methodenname  Wert wird nicht manipuiert
      return size_;
      //return std::numeric_limits<std::size_t>::max(); // 
      //Returns the maximum finite value representable by the numeric type T.
  };


  private:                // first (default)-Init of the Membervar.
    std::size_t size_ = 0;   // Bibliotheksfunktionen, die Größen annehmen, erwarten, dass sie
    ListNode<T>* first_ = nullptr;  //den Typ size_t haben, und der Operator sizeof ergibt size_t.
    ListNode<T>* last_ = nullptr;   // aehnlich aber nicht identisch mit unsigned int
};


//Freie Funktion reverse
template <typename T>
List<T> reverse(List<T> const& li)
{
    List<T> rev_li; 

    for (auto xx : li){
        rev_li.push_front(xx);
    }
    return rev_li; 
}

//Freie Funktion operator+ (4.14)
auto operator+( auto const& li1, auto const& li2){   //  Freie Funktion (in .cpp mit Konstr)

  auto list5 = li1;
    for(auto& ita : li2){
      list5.push_back(ita);
    }
  return list5;
}

#endif // # define BUW_LIST_HPP

