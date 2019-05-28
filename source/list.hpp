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
  		//TO IMPLEMENT PROPERLY
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
  		////not implemented yet
    }

    /* ... */
    //TODO: member function insert
  	/* ... */
    //TODO: member function reverse

    /* ... */
    void push_front(T const& element) {
      
  		if (size() == 0){         // Wenn leer dann erstes gleich letztes element
        first_ = new ListNode<T>{element,nullptr,nullptr}; // init des neuen Elements entspr. ListNode Konstruktor
        last_ = first_;
      }
      else if (size() != 0){
        
        first_ = new ListNode<T>{element,nullptr, first_};
        first_->next->prev = first_;
      }
      ++size_;
    }

    /* ... */
    void push_back(T const& element) {
  		if (size() == 0){
        last_ = new ListNode<T> {element, nullptr, nullptr};
        first_ = last_;
      } else if (size() != 0){
        last_ = new ListNode<T> {element, first_, nullptr};
      }
      ++size_;
    }

    /* ... */
    void pop_front() {
    	assert(!empty());
  		//not implemented yet
    }

    /* ... */
    void pop_back() {
    	assert(!empty());
		//not implemented yet
    }

  	
    T& front() {
    assert(!empty());  //Original
  		//not implemented yet    	
   	return first_->value; //<- obviously wrong because of 
    				// returned reference to tmp-Object
    }

  
    T& back() {
    	assert(!empty());
    	//not implemented yet
    	return last_->value; //<- obviously wrong because of
    				// returned reference to tmp-Object
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

