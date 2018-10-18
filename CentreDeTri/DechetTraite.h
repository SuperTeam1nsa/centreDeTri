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
	DechetTraite();
	~DechetTraite();
	const Dechet* getDechet() const { return dechet; };
};

