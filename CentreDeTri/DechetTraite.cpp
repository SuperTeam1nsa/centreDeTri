#include "DechetTraite.h"

DechetTraite::DechetTraite(Dechet * dechet)
{
	this->dechet = dechet;
}

DechetTraite::DechetTraite()
{
	dechet = new Dechet();
}

DechetTraite::~DechetTraite()
{
	delete ;
}
