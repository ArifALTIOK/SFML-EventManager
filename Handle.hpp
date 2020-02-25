#pragma once
/*
	- Tutucu olarak kullan�lacak taban s�n�f
	- Nesnelerine otomatik benzersiz ve de�i�mez 
	  kimlendirme yapar

	- Kal�t�m ile t�retilerek Fonksiyon tutucu, 
	  nesne tutucu gibi herhangi bir s�n�fta 
	  kullan�labilir. Yine benzersiz ve de�i�mez 
	  kimlendirmeyi otomatik yapar
	
*/
class Handle {
	static size_t identifer;
public:
	virtual ~Handle();
	const size_t id;
	Handle();
};

