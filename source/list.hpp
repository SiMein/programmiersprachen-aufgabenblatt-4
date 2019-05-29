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
struct ListNode {
  T         value = T ();
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

  /* DESCRIPTION  operator*() */
  T&  operator*()  const {
  	//not implemented yet
  	return {};
  } 

  /* DESCRIPTION  operator->() */
  T* operator->() const {
  	//not implemented yet
  	return nullptr;
  }

  /* ... */
  ListIterator<T>& operator++() {
  	//not implemented yet
  	return {};
  } //PREINCREMENT

  /* ... */
  ListIterator<T> operator++(int) {
  	//not implemented yet
  	return {};
  } //POSTINCREMENT (signature distinguishes)

  /* ... */
  bool operator==(ListIterator<T> const& x) const {
  	//not implemented yet
  }

  /* ... */
  bool operator!=(ListIterator<T> const& x) const {
  	//not implemented yet
  }

  /* ... */
  ListIterator<T> next() const {  // gibt nächsten Node zurück
    if (nullptr != node) {
      return ListIterator{node->next};
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

    // not implemented yet
    // do not forget about the initialiser list !
  

    //Aufg 4.2 //Default Constructor
    List(): 
    size_{0}, 
    first_{nullptr}, 
    last_{nullptr} {} 

    /* ... */
    //TODO: Copy-Konstruktor using Deep-Copy semantics (Aufgabe 4.8)

  	/* ... */
    //TODO: Move-Konstruktor (Aufgabe 4.13)

    //TODO: Initializer-List Konstruktor (4.14)
  	/* ... */
    List(std::initializer_list<T> ini_list) {
  		//not implemented yet
    }

  	/* ... */
    //TODO: Assignment operator (Aufgabe 4.12)

  	/* ... */
    //TODO: operator== (Aufgabe 4.7)

  	/* ... */
    //TODO: operator!= (Aufgabe 4.7)

  	/* ... */
    ~List() {
  	   clear();
    }

  	/* ... */
    ListIterator<T> begin() {
    	assert(!empty());
  		////not implemented yet
    	return ListIterator<T>{};
    }

  	/* ... */
    ListIterator<T> end() {
    	assert(!empty());

  		////not implemented yet
    	return ListIterator<T>{};
    }

    /* ... */
    void clear() {
  		while (size() != 0){
        pop_front();
      }
    }

    /* ... */
    //TODO: member function insert
  	/* ... */
    //TODO: member function reverse

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

/* ... */
//TODO: Freie Funktion reverse

/* ... */
//TODO: Freie Funktion operator+ (4.14)

#endif // # define BUW_LIST_HPP

