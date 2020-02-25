#pragma once
#include "Handle.hpp";

/*
	- Handle s�n�f�n� geni�letir.
	
	- Fonksiyonlar� tutmak i�in kullan�l�r.
	
	- Tutulacak fonksiyonun parametre tipi Args olarak,
	  geri d�n�� tipi Retval olarak belirtilir.

	- bkz. Handle.hpp
    - Kullan�mlar i�in bak�n�z FunctionTrigger.hpp
*/

template<typename Args, typename Retval>
class FunctionHandle : public Handle {
public:
	using FunctionType = Retval(Args);
	using Function = std::function<FunctionType>;
	FunctionHandle(FunctionType function);
	const Function function;
	Retval operator()(Args args);
};

template<typename Args, typename Retval>
FunctionHandle<Args, Retval>::FunctionHandle(
		FunctionHandle<Args,Retval>::FunctionType function)
	: function(function)
{	}

template<typename Args, typename Retval>
Retval FunctionHandle<Args,Retval>::operator()(Args args) {
	return function(args);
}