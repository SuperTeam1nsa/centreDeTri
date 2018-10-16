#include "UsineTraitement.h"


UsineTraitement::UsineTraitement()
{
}


UsineTraitement::~UsineTraitement()
{
}

void UsineTraitement::demarrerTraitement(ChargementDechet * chargement)
{

}

void UsineTraitement::preOperation()
{
	Log::i("PREOPERATION");
}

void UsineTraitement::postOperation()
{
	Log::i("POSTOPERATION");
}

void UsineTraitement::creerDechetTraiteRecyclable(Dechet * dechet)
{
	if (!(camionBleu->ajouterDechet(dechet)))
	{

	}
}

