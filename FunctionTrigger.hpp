#pragma once
/*
	- �ablon olarak olu�turulan tetikleyici s�n�f

	- Args fonksiyonlar�n parametre tipi

	- Fonksiyonlar sadece bir parametre al�r,
	  Fakat alacaklar� parametre class veya struct
	  �evirilerek parametre i�inde birle�tirilme yap�labilir

	  �rne�in : 
		struct Test{	int x,y;	}; 
		�eklindeki bir struct ile �oklu �ekilde parametre 
		g�nderilebilir. G�nderilen parametre tipi tektir.
		Fakat i�inde birden fazla arg�man olabilir.

	- Retval fonksiyonlar�n geri d�n�� tipidir.
	  geri de�er d�nd�rmek istenmeyen fonksiyonlarda 
	  void tipi se�ilmelidir.
	
*/

#include "Trigger.hpp"
#include "FunctionHandle.hpp"

template<typename Args, typename Retval>
class FunctionTrigger : public Trigger {
	using Function = FunctionHandle<Args, Retval>;
	using FunctionType = typename Function::FunctionType;
	using Functions = std::vector<Function*>;
	using Iterator = typename Functions::iterator;
	Functions functions;
	Args* args;
public:
	// Fonksiyonlar ayn� parametreyi g�zetledi�i i�in
	// parametrenin bellek adresi tetikleyicide kurucuda verilir.
	FunctionTrigger(Args* args);
	~FunctionTrigger();

	//Ekleme i�lemleri
	//override
	size_t add(Handle* handle);
	size_t add(FunctionType function);
	size_t add(Function* function);

	//silme i�lemi
	//override
	bool remove(size_t id);

	//fonksiyonlar�n hepsini ayn� anda tetikleme
	//override
	void triggered()const;
};


template<typename Args, typename Retval>
FunctionTrigger<Args,Retval>::FunctionTrigger(Args* args)
	: args(args)
{		}

template<typename Args, typename Retval>
FunctionTrigger<Args, Retval>::~FunctionTrigger() {
	for (Function* f : functions)
		remove(f->id);
}

template<typename Args, typename Retval>
size_t FunctionTrigger<Args, Retval>::add(Handle* handle) {
	Function* function = dynamic_cast<Function*>(handle);
	if (function)
		return add(function);
	else
		throw "Hatali Fonksiyon Ekleme";

}

template<typename Args, typename Retval>
size_t FunctionTrigger<Args, Retval>::add(FunctionType function) {
	return add(new Function(function));
}

template<typename Args, typename Retval>
size_t FunctionTrigger<Args, Retval>::add(Function* function) {
	functions.push_back(function);
	return function->id;
}

template<typename Args, typename Retval>
bool FunctionTrigger<Args, Retval>::remove(size_t id) {
	bool result = false;
	Iterator iter = functions.begin();
	Function* f = 0;
	while (iter != functions.end()) {
		f = *iter;
		if (f->id == id)
			break;
		iter++;
	}

	if (iter != functions.end()) {
		try {
			delete f;
			functions.erase(iter);
			result = true;
		}
		catch (...) {

		}
	}
	return result;
}

template<typename Args, typename Retval>
void FunctionTrigger<Args, Retval>::triggered()const {
	for (Function* f : functions) {
		(*f)(*args);
	}
}