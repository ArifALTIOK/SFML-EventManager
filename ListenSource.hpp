#pragma once
#include "IListenSource.hpp"
/*
	- S�n�f �zelle�tirmeleri i�in kullan�labilir template s�n�f

	- bkz. IListenSource.hpp
*/
template<typename Source>
class ListenSource : public IListenSource {
protected:
	Source& source;
public:
	ListenSource(Source& source) : source(source) {}
	virtual void* getEventMemory() const = 0;
	virtual void* getDataMemory() const = 0;
};