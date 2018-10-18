#pragma once
#include "Dechet.h"
#include "Compteur.h"

class DechetTraite :
	public Dechet
{
protected:
	Dechet* dechet;

public:
	DechetTraite(Dechet* dechet);
	~DechetTraite();
	const Dechet* getDechet() const { return dechet; };
};

