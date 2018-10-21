﻿#include "UsineTraitement.h"
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
	delete sequenceOperations;
}

void UsineTraitement::demarrerTraitement(ChargementDechet * chargement)
{//à compléter
}

void UsineTraitement::chargerOperations(SequenceOperations * seqOpe)
{
	sequenceOperations = seqOpe;
}

void UsineTraitement::creerDechetTraiteRecyclable(Dechet * dechet)
{
	DechetTraiteRecyclable* dechetT = new DechetTraiteRecyclable(dechet);
	if (!(camionBleu->ajouterDechet(dechetT)))
	{
		depot.depotDechetsTraites(camionBleu);
		camionBleu->ajouterDechet(dechetT);
	}
}

void UsineTraitement::creerDechetTraiteNonRecyclable(Dechet* dechet)
{
	DechetTraiteNonRecyclable* dechetT = new DechetTraiteNonRecyclable(dechet);
	if (!(camionVert->ajouterDechet(dechetT)))
	{
		depot.depotDechetsTraites(camionVert);
		camionVert->ajouterDechet(dechetT);
	}
}

void UsineTraitement::creerDechetTraiteCompostable(Dechet* dechet)
{
	DechetTraiteCompostable* dechetT = new DechetTraiteCompostable(dechet);
	if (!(camionBrun->ajouterDechet(dechetT)))
	{
		depot.depotDechetsTraites(camionBrun);
		camionBrun->ajouterDechet(dechetT);
	}
}

void UsineTraitement::traiterDechet(Dechet * dechet)
{
	Operation* operationCourante = sequenceOperations->getOperationDemarrage();
	while (operationCourante != NULL)
	{
		preOperation();
		bool operationEffectuee = operationCourante->effectuerOperation(dechet);
		postOperation();
		operationCourante = operationCourante->getOperationSuivante(operationEffectuee);
	}
}
