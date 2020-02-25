#pragma once
#include "IListener.hpp"
class IListenTarget;
/*
	Dinleme Hedefi ile kayna�� aras�nda ba� kurulup dinleme i�lemi yap�l�r

	bkz. IListener.hpp
*/

class Listener : public IListener {
	IListenTarget* target;
public:
	Listener(IListenTarget* target);

	//override
	bool listen();
	//override
	IListenSource* getListenSource()const;
};
