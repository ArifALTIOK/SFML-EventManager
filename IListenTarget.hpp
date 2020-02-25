#pragma once
class IListenSource;
class IListenTarget {
public:
	virtual ~IListenTarget() {	}

	virtual bool listen() const = 0;
	// Dinlenen yerde de�i�iklik varsa true d�ner
	// T�m alt s�n�flar nas�l dinleme yapmak isterse override eder
	
	virtual IListenSource* getListenSource() const = 0;
	// dinlemenin kayna��n� d�nd�r�r -> (bellek �zerinde i�lemler)
	// bkz. IListenSource.hpp
};



