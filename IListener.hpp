#pragma once
#include "IListenSource.hpp";

class IListener {
public:
	virtual bool listen() = 0;
	// dinleyici dinleme kurallar�n� belirler
	// de�i�iklik durumunda true de�er d�nd�rmesi beklenir

	virtual IListenSource* getListenSource()const = 0;
	// dinlemenin kayna��n� d�nd�r�r -> (bellek �zerinde i�lemler)
	// bkz. IListenSource.hpp
};