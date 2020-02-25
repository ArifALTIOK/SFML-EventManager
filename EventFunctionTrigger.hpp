#pragma once
#include "FunctionTrigger.hpp"
#include "EventFunctionHandle.hpp"

/*
	- S�n�f �zelle�tirmesidir
	  Event tiplerine g�re alaca�� Args ve 
	  Retval tiplerini otomatik belirlenir. 
	  Sadece Eventin tipi belirtilmesi yeterlidir.
	  
	- Di�er kullan�mlar i�in bkz. FunctionTrigger.hpp

*/
template<typename Event>
using EventFunctionTrigger =
FunctionTrigger<
	typename EventTraits<Event>::Args,
	typename EventTraits<Event>::Retval>;

