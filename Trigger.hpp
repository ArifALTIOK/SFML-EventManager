#pragma once

/*
	Tutucular� (Handle nesnelerini) bir arada tutmak amac�yla
	ekleme, silme ve gerekti�inde tetikleme i�lemleri aray�z�d�r

*/
class Handle;
class Trigger {
public:
	
	virtual size_t add(Handle* handle) = 0;
	//Tutucu ekleme geri d�n�� de�eri tutucunun benzersiz kimli�idir

	virtual bool remove(size_t id) = 0;
	// parametresi tutucunun kimli�i olacak �ekilde silindiyse true
	// silinemedi veya bulunamadi false d�nd�rmesi ama�lan�r
	
	virtual void triggered()const = 0;
	//Nesne i�indeki t�m tutucular� ayn� anda tetikler
};

