#pragma once
#include "Dechet.h"
#include "Compteur.h"

class DechetTraite :
	public Dechet
{
protected:
	Dechet* dechet;

public:
	DechetTraite(Dechet* dechet) {
		this->dechet = dechet;
		Compteur::ajouterConstructeur();
	}
	DechetTraite(DechetTraite const& autre) { 
		dechet = new Dechet(*autre.dechet); 
		Compteur::ajouterConstructeurCopie();
	}
	virtual ~DechetTraite() {
		delete dechet;
		Compteur::ajouterDestructeur();
	}
	const Dechet* getDechet() const { return dechet; };
};