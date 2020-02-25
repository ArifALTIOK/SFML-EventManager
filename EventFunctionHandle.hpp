#pragma once
#include "FunctionHandle.hpp"
/*
	- S�n�f �zelle�tirmesidir
	  Event tiplerine g�re alaca�� Args ve
	  Retval tiplerini otomatik belirlenir.
	  Sadece Eventin tipi belirtilmesi yeterlidir.

	- Di�er kullan�mlar i�in bkz. FunctionHandle.hpp

*/
template<typename Event>
using EventFunctionHandle =
FunctionHandle<
	typename EventTraits<Event>::Args,
	typename EventTraits<Event>::Retval>;
