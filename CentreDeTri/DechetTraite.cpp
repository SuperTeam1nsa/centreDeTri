#include "DechetTraite.h"

DechetTraite::DechetTraite(Dechet * dechet)
{
	this->dechet = dechet;
	Compteur::ajouterConstructeur();
}

DechetTraite::~DechetTraite()
{
	delete dechet;
	Compteur::ajouterDestructeur();
}
