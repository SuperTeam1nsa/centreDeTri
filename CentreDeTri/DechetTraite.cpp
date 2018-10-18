#include "DechetTraite.h"

DechetTraite::DechetTraite(Dechet * dechet)
{
	this->dechet = dechet;
	Compteur::ajouterConstructeur();
}

DechetTraite::DechetTraite()
{
	dechet = new Dechet();
	Compteur::ajouterConstructeurCopie();
}

DechetTraite::~DechetTraite()
{
	delete ;
	Compteur::ajouterDestructeur();
}
