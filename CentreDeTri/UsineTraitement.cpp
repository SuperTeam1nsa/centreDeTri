#include "UsineTraitement.h"
#include "OperationTraitement.h"
//UsineTraitemetn =Storage
//OperationTraitement= StorageHistory
UsineTraitement::UsineTraitement() :camionBleu(new CamionBleu()), camionBrun(new CamionBrun()), camionVert(new CamionVert())
{
	Compteur::ajouterConstructeur();
}
UsineTraitement::UsineTraitement(UsineTraitement const& autre) : sequenceOperations(autre.sequenceOperations), depot(autre.depot) {
	camionVert = new CamionVert(*autre.camionVert);
	camionBleu = new CamionBleu(*autre.camionBleu);
	camionBrun = new CamionBrun(*autre.camionBrun);
	Compteur::ajouterConstructeurCopie();
}
UsineTraitement::~UsineTraitement()
{
	Compteur::ajouterDestructeur();
	delete camionBleu;
	delete camionVert;
	delete camionBrun;
}

void UsineTraitement::demarrerTraitement(ChargementDechet * chargement)
{//à compléter
}

void UsineTraitement::chargerOperations(SequenceOperations * seqOpe)
{
	sequenceOperations.definirOperationDemarrage(seqOpe->getOperationDemarrage());
	while (seqOpe->getOperationDemarrage() != NULL)
	{
		sequenceOperations.ajouterOperation(seqOpe->getOperationDemarrage());
	}
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
