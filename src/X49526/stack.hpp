#include <iostream>
#include <cstdlib>

using namespace std;
// lines 26, 27, 135, 156, 212
template <typename T>
class Stack 
{

	private:

	////////////////////////////////////////////////////////
	// Dades i estructures de dades privades a la classe. //
	////////////////////////////////////////////////////////
	
	struct Item 
	{
		T value;
		Item* next;
	};


	int _size;
	Item* ptopitem;

	T _maxim;
	int _frequenciaMaxim;

	////////////////////////////////////////////////////////
	// Funcions auxiliars privades a la classe.           //
	////////////////////////////////////////////////////////
	
	Item* copyItems(Item *pitem) 
	{
		if (pitem == NULL) return NULL;
		Item *pfirstitem = new Item();
		Item *pcurrentitem = pfirstitem;
		while (pitem != NULL) 
		{
			pcurrentitem->value = pitem->value;
			if (pitem->next != NULL) pcurrentitem->next = new Item();
			else pcurrentitem->next = NULL;
			pcurrentitem = pcurrentitem->next;
			pitem = pitem->next;
		}
	
		return pfirstitem;
	}
	
	void deleteItems()
	{
		Item *pitem = ptopitem;
		while (pitem != NULL) 
		{
			Item *pitemaux = pitem;
			pitem = pitem->next;
			delete pitemaux;
		}

		_size = 0;
		return;
	}
	
	void printRec(ostream &os, const Item *pitem) const
	{
		if (pitem == NULL) return;
		printRec(os, pitem->next);
		if (pitem->next != NULL) os << " ";
		os << pitem->value;
		
		return;
	}
	
	public:

	////////////////////////////////////////////////////////
	// Constructors de la classe. 						  //
	////////////////////////////////////////////////////////

	Stack() 
	{
		ptopitem = NULL;
		_size = 0;
	}
	
	Stack(const Stack<T> &s) 
	{
		ptopitem = copyItems(s.ptopitem);
		_size = s._size;
	}
	
	~Stack() 
	{
		deleteItems();
	}

	////////////////////////////////////////////////////////
	// Operador d'assignació de la classe.				  //
	////////////////////////////////////////////////////////
	
	Stack<T> &operator=(const Stack<T> &s) 
	{
		if (this != &s) 
		{
			deleteItems();
			ptopitem = copyItems(s.ptopitem);
			_size = s._size;
		}
		
		return *this;
	}

	////////////////////////////////////////////////////////
	// Funcions estàndards de la classe.				  //
	////////////////////////////////////////////////////////
	
	int size() 
	{
		return _size;
	}

	bool empty() const 
	{
		return ptopitem == NULL;
	}

	void push(T value) 
	{
		Item *pnewitem = new Item();
		pnewitem->value = value;
		pnewitem->next = ptopitem;
		ptopitem = pnewitem;
		_size++;

		if (_size == 1) {
			_maxim = value;
			_frequenciaMaxim = 1;
		}
		else if (_maxim < value) {
			_maxim = value;
			_frequenciaMaxim = 1;
		}
		else if (_maxim == value) ++_frequenciaMaxim;
	}
	
	void pop() 
	{
		if (ptopitem == NULL) {
			cerr << "Error: pop on empty stack" << endl;
			exit(1);
		}
		
		Item *paux = ptopitem;
		ptopitem = ptopitem->next;

		if (_maxim == paux->value) {
			if (1 < _frequenciaMaxim) --_frequenciaMaxim;
			else if (_frequenciaMaxim == 1 and 1 < _size) {
				Item* current = ptopitem;
				_maxim = ptopitem->value;
				_frequenciaMaxim = 0;
				while (current != NULL) {
					if (_maxim == current->value) ++_frequenciaMaxim;
					else if (_maxim < current->value) {
						_maxim = current->value;
						_frequenciaMaxim = 1;
					}

					current = current->next;
				}
			}
		}

		delete paux;
		_size--;
		return;
	}
		
	T top() 
	{
		if (ptopitem == NULL) 
		{
			cerr << "Error: accessing top of empty stack" << endl;
			exit(1);
		}
		
		return ptopitem->value;
	}
		
	const T top() const 
	{
		if (ptopitem == NULL) 
		{
			cerr << "Error: accessing top of empty stack" << endl;
			exit(1);
		}
		
		return ptopitem->value;
	}

	////////////////////////////////////////////////////////
	// Mètode MÀXIM.                     				  //
	////////////////////////////////////////////////////////

	/*
	 * Pre:	Sigui [a1,...,an] el contingut actual de la pila des 
	 * del fons fins al top.
	 * Post: Retorna el màxim de a1+...+an.
	 * Descomenteu les següents dues linies i implementeu el mètode:
	 */

	T maxim() 
	{
		return _maxim;
	}


	////////////////////////////////////////////////////////
	// Entrada / Sortida de la classe.				      //
	////////////////////////////////////////////////////////
	
	template <typename U> 
	friend ostream &operator<<(ostream &os, const Stack<U> &s);
	
	template<typename U> 
	friend istream &operator>>(istream &is, Stack<U> &s);
	
};	/* ----------- FINAL DE LA CLASSE STACK ------------ */

	////////////////////////////////////////////////////////
	// Implementació de l'entrada/sortida.				  //
	////////////////////////////////////////////////////////

template <typename U> 
ostream &operator<<(ostream &os, const Stack<U> &s)
{
	//os << s._size;
	//if (s.ptopitem != NULL) os << " ";
	s.printRec(os, s.ptopitem);
	return os;
}

template <typename U> 
istream &operator>>(istream &is, Stack<U> &s)
{
	int n;
	is >> n;
	s = Stack<U> ();
	for (int i = 0; i < n; i++) 
	{
		U u;
		is >> u;
		s.push(u);
	}
	return is;
}

/* ------- FINAL DE LA IMPLEMENTACIÓ ENTRADA/SORTIDA -------- */

/* ------------------- FINAL DEL FITXER --------------------- */
