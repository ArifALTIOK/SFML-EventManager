#pragma once
#include "IListenTarget.hpp"
/*
	- S�n�f �zelle�tirmeleri i�in kullan�labilir template s�n�f

	- bkz. IListenTarget.hpp
*/

template<typename Target>
class ListenTarget : public IListenTarget {
protected:
	Target& target;
public:
	using TargetType = Target;
	ListenTarget(Target& target) : target(target)
	{	}
	virtual bool listen() const = 0;
	virtual IListenSource* getListenSource() const = 0;
};



