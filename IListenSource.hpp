#pragma once

/*
	Dinleme hedeflerinin kaynak aray�z�d�r.
	Yani hedef dinleyerek sonu�lar�n� kayna��na yazar

*/
class IListenSource {
public:
	virtual void* getEventMemory()const = 0;
	// bellek �zerinde event datalar� kar��la�t�rmak i�in
	
	virtual void* getDataMemory()const = 0;
	// bellek �zerinden beklenen event ile ilgili args alabilmek i�in
};

