#pragma once
#include "ListenSource.hpp"
#include <SFML/Graphics.hpp>
/*
	- S�n�f �zelle�tirmesidir.
	- sfml sf::Event s�n�f�n� sisteme adapte eder.
	
	- bkz. IListenSource.hpp
*/
class RenderWindowListenSource : public ListenSource<sf::Event> {
public:
	using ListenSource<sf::Event>::ListenSource;
	void* getEventMemory()const;
	void* getDataMemory()const;
};

