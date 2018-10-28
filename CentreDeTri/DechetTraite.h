#pragma once
#include "Dechet.h"
#include "Compteur.h"

class DechetTraite
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
		static int cpt = 0; ///matter tous les déchets créés passent pas par là => pas tous détruits...
		cpt++;
		printf("Nb: %d \n ", cpt);
		delete dechet;
		Compteur::ajouterDestructeur();
	}
	const Dechet* getDechet() const { return dechet; }
};
