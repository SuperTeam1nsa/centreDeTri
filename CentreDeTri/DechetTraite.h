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
	DechetTraite(DechetTraite const& autre) { 
		dechet = new Dechet(*autre.dechet); 
		Compteur::ajouterConstructeurCopie();
	}
	~DechetTraite();
	const Dechet* getDechet() const { return dechet; };
};

