#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
/*
	- Event S�n�flar�

	- Herbir s�n�f Event s�n�f�ndan t�rer. 
	  Fakat Event s�n�f� kendi ba��na olu�turulamaz.
	
	- Eventler Donan�m ve Yaz�l�m olarak iki kategoriye ayr�lm��t�r.
	
	- Her bir event, ger�ekle�mesi durumunda �al��acak 
	  fonksiyon i�in almas� gereken parametreyi Args olarak belirtir.
	
	- Retval de�eri fonksiyonun geri d�n�� de�erini belirtir.
	  Bu event s�n�f� i�in void olarak belirtilmi�tir. Ayr�ca belirtmek gerekmez.
	
	- Donan�msal eventlerin parametreleri i�i bo�tur. De�er i�ermez.
	
	- Kendi alt Event s�n�f�n�z� olu�turmak isterseniz
	  Event s�n�f�ndan kal�t�m al�p, kurucusunda tipini parametre
	  olarak g�nderin. Ayr�ca bu eventin ger�ekle�mesi durumunda
	  tetiklenecek fonksiyonun parametresini Args �eklinde belirtin. 

	- EventTraits s�n�f� Eventin Args,Retval,FunctionType,Function
	  �eklindeki �zelliklerini tespit eder.
	  Function tetiklenecek fonksiyonu,
	  FunctionType fonksiyonun geri d�n�� ve parametrelerini birli�ini,
	  Retval fonksiyonun geri d�n�� tipini,
	  Args fonksiyonun parametre tipini belirtir.


*/
class EventManager;
class Event{
protected:
	sf::Event::EventType type;
	Event(sf::Event::EventType);
	friend class EventManager;
public:
	using Retval = void;
};

struct Void {};

class HardwareEvent : public Event {
protected:
	using Event::Event;
public:
	using Args = Void;
};

class SoftwareEvent : public Event {
protected:
	using Event::Event;
};

struct ClosedEvent : HardwareEvent {
	ClosedEvent();
};

struct LostFocusEvent : HardwareEvent {
	LostFocusEvent();
};

struct GainedFocusEvent : HardwareEvent {
	GainedFocusEvent();
};

struct SizeEvent : SoftwareEvent {
	SizeEvent();
	using Args = sf::Event::SizeEvent;
};


struct MouseMoveEvent : SoftwareEvent {
	MouseMoveEvent();
	using Args = sf::Event::MouseMoveEvent;
};

struct MousePressedEvent : SoftwareEvent {
	MousePressedEvent();
	using Args = sf::Event::MouseButtonEvent;
};


struct MouseReleasedEvent : SoftwareEvent {
	MouseReleasedEvent();
	using Args = sf::Event::MouseButtonEvent;
};


struct KeyPressedEvent : SoftwareEvent {
	KeyPressedEvent();
	using Args = sf::Event::KeyEvent;
};

struct KeyReleasedEvent : SoftwareEvent {
	KeyReleasedEvent();
	using Args = sf::Event::KeyEvent;
};



// bu s�n�f� degistirmeyin args ve handle tespiti yapar
template<typename Event>
struct EventTraits {
	using Args = typename Event::Args;
	using Retval = void;
	using FunctionType = typename Retval(Args);
	using Function = typename std::function<FunctionType>;
};
