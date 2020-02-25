#pragma once
/*
	- Olaylar� tek bir merkezden y�netir
	
	- IListener interface i�erisinde herhangi bir dinleyi konulabilir.
	
	- Takibi istenen event add methodlar�na �ablon olarak belirtilir ve
	  bu event ger�ekle�ti�inde tetiklenecek fonksiyon parametre olarak verilir.
	  geri d�n�� de�eri olarak olu�turulan fonksiyonun kimlik numaras� d�ner.
	  
	- Takibi kald�r�lmak istenen event remove methoduna �ablon parametresi
	  ile belirtilir ve ekleme i�leminde elde edilen kimlik numaras�
	  parametre olarak belirtilir.

	- Dinleme i�lemleri listen olarak ba�lat�l�r.
	  Dinleme esnas�nda herhangi bir event ger�ekle�mez ise hi�bir�ey yapmaz.
	  Ger�ekle�en event var ise ilgili takip�iler tetiklenir.

*/


#include "Event.hpp"
#include "EventFunctionHandle.hpp"
#include "EventFunctionTrigger.hpp"
#include "IListener.hpp"
#include <vector>

class EventManager {
	IListener* listener;
	struct Hash {
		Event event;
		Trigger* trigger;
		Hash(Event event, Trigger* trigger) :
			event(event), trigger(trigger)
		{	}
	};

	using Hashes = std::vector<Hash*>;
	using Iterator = typename Hashes::iterator;
	Hashes hashes;
public:

	EventManager(IListener* listener);

	template<typename Event, typename Function = typename EventTraits<Event>::Function>
	size_t add(Function function);

	template<typename Event>
	size_t add(Handle* handle);


	template<typename Event>
	void remove(size_t id);

	void remove(size_t id);

	void listen();
};




template<typename Event, typename Function>
size_t EventManager::add(Function function)
{
	Handle* handle = new EventFunctionHandle<Event>(function);
	return add<Event>(handle);
}



template<typename Event>
size_t EventManager::add(Handle* handle) {
	Event e;
	EventFunctionHandle<Event>* function = (EventFunctionHandle<Event>*)handle;
	for (Hash* hash : hashes) {
		if (hash->event.type == e.type) {
			return hash->trigger->add(function);
		}
	}

	typename Event::Args* args =
		static_cast<typename Event::Args*>
		(listener->getListenSource()->getDataMemory());

	Trigger* trigger = new EventFunctionTrigger<Event>(args);
	trigger->add(function);
	Hash* hash = new Hash(e, trigger);
	hashes.push_back(hash);
	return function->id;
}


template<typename Event>
void EventManager::remove(size_t id) {
	Event e;
	for (Hash* hash : hashes) {
		if (hash->event.type == e.type) {
			hash->trigger->remove(id);
			break;
		}
	}
}

