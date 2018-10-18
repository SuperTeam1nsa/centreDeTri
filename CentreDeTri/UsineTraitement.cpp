#include "UsineTraitement.h"

UsineTraitement::UsineTraitement()
{
	Compteur::ajouterConstructeur();
}


UsineTraitement::~UsineTraitement()
{
	Compteur::ajouterDestructeur();
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
		depot.depotDechetsTraites(camionBleu);
		camionBleu = depot.getCamionBleu();
		camionBleu->ajouterDechet(dechet);
	}
}

void UsineTraitement::creerDechetTraiteNonRecyclable(Dechet* dechet)
{
	if (!(camionVert->ajouterDechet(dechet)))
	{
		depot.depotDechetsTraites(camionVert);
		camionVert = depot.getCamionVert();
		camionVert->ajouterDechet(dechet);
	}
}

void UsineTraitement::creerDechetTraiteCompostable(Dechet* dechet)
{
	if (!(camionBrun->ajouterDechet(dechet)))
	{
		depot.depotDechetsTraites(camionBrun);
		camionBrun = depot.getCamionBrun();
		camionBrun->ajouterDechet(dechet);
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

void UsineTraitement::Log::i(string info)
{
	cout << info << endl;
}

void UsineTraitement::Log::i(Dechet const & dechet)
{
	cout << dechet << endl;
}

void UsineTraitement::Log::i(Depot const & depot)
{
	depot << cout << endl;
}