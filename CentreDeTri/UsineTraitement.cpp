#include "UsineTraitement.h"

UsineTraitement::UsineTraitement()
{
	Compteur::ajouterConstructeur();
}


UsineTraitement::~UsineTraitement()
{
	Compteur::ajouterDestructeur();
	delete camionBleu;
	delete camionVert;
	delete camionBrun;
}

void UsineTraitement::chargerOperations(SequenceOperations * _sequenceOperation)
{
	sequenceOperations.definirOperationDemarrage(_sequenceOperation->getOperationDemarrage());
	while (_sequenceOperation->getOperationDemarrage() != NULL)
	{
		sequenceOperations.ajouterOperation(_sequenceOperation->getOperationDemarrage());
	}
}

void UsineTraitement::demarrerTraitement(ChargementDechet * chargement)
{
	
}

void UsineTraitement::Log::i(string info)
{
	cout << info << endl;
}

void UsineTraitement::Log::i(Dechet const & dechet)
{
	dechet << cout << endl;
}

void UsineTraitement::Log::i(Depot const & depot)
{
	depot << cout << endl;
}

void UsineTraitement::preOperation()
{
	UsineTraitement::Log::i("PREOPERATION");
}

void UsineTraitement::postOperation()
{
	UsineTraitement::Log::i("POSTOPERATION");
}

void UsineTraitement::creerDechetTraiteRecyclable(Dechet * dechet)
{
	DechetTraiteRecyclable* dechetTraite = new DechetTraiteRecyclable(dechet);
	if (!(camionBleu->ajouterDechet(dechetTraite)))
	{
		depot.depotDechetsTraites(camionBleu);
		camionBleu->ajouterDechet(dechetTraite);
	}
}

void UsineTraitement::creerDechetTraiteNonRecyclable(Dechet* dechet)
{
	DechetTraiteNonRecyclable* dechetTraite = new DechetTraiteNonRecyclable(dechet);
	if (!(camionVert->ajouterDechet(dechetTraite)))
	{
		depot.depotDechetsTraites(camionVert);
		camionVert->ajouterDechet(dechetTraite);
	}
}

void UsineTraitement::creerDechetTraiteCompostable(Dechet* dechet)
{
	DechetTraiteCompostable* dechetTraite = new DechetTraiteCompostable(dechet);
	if (!(camionBrun->ajouterDechet(dechetTraite)))
	{
		depot.depotDechetsTraites(camionBrun);
		camionBrun->ajouterDechet(dechetTraite);
	}
}

void UsineTraitement::traiterDechet(Dechet * dechet)
{
	Operation* operationCourante = sequenceOperations.getOperationDemarrage();
	while (operationCourante != NULL)
	{
		preOperation();
		bool operationEffectuee = operationCourante->effectuerOperation(dechet);
		postOperation();
		operationCourante = operationCourante->getOperationSuivante(operationEffectuee);
	}
}