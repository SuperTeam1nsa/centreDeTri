#include "UsineTraitement.h"
#include "OperationTraitement.h"
//UsineTraitemetn =Storage
//OperationTraitement= StorageHistory
UsineTraitement::UsineTraitement() :camionBleu(new CamionBleu()), camionBrun(new CamionBrun()),
camionVert(new CamionVert()), sequenceOperations(NULL)
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

	/*
	détruits dans depotDechetsTraités
	delete camionBleu;
	delete camionVert;
	delete camionBrun;*/
	delete sequenceOperations;
}

void UsineTraitement::demarrerTraitement(ChargementDechet * chargement)
{
	Dechet* dechet = chargement->getDechet();
	while (dechet != NULL)
	{
		Log::i(*dechet);
		traiterDechet(dechet);
		dechet = chargement->getDechet();
	}
	//on amène les déchets restants (dans les camions) au depot même si les camions ne sont pas 
	//pleins (pour traiter tout le chargement) (facultatif)(ne change rien au fonctionnement du programme
	//si ce n'est qu'on ne détruit pas les camions dans le destructeur de l'usine si on fait ça)
	depot.depotDechetsTraites(camionBleu);
	depot.depotDechetsTraites(camionVert);
	depot.depotDechetsTraites(camionBrun);
	delete chargement;
	Log::i(depot);
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
		camionBleu = depot.getCamionBleu();
		camionBleu->ajouterDechet(dechetT);
	}
	Log::i("AJOUT DTR : " + to_string(dechet->getId()));
}

void UsineTraitement::creerDechetTraiteNonRecyclable(Dechet* dechet)
{
	DechetTraiteNonRecyclable* dechetT = new DechetTraiteNonRecyclable(dechet);
	if (!(camionVert->ajouterDechet(dechetT)))
	{
		depot.depotDechetsTraites(camionVert);
		camionVert = depot.getCamionVert();
		camionVert->ajouterDechet(dechetT);

	}
	Log::i("AJOUT DTNR : " + to_string(dechet->getId()));
}

void UsineTraitement::creerDechetTraiteCompostable(Dechet* dechet)
{
	DechetTraiteCompostable* dechetT = new DechetTraiteCompostable(dechet);
	if (!(camionBrun->ajouterDechet(dechetT)))
	{
		depot.depotDechetsTraites(camionBrun);
		camionBrun = depot.getCamionBrun();
		camionBrun->ajouterDechet(dechetT);
	}
	Log::i("AJOUT DTC : " + to_string(dechet->getId()));
}

//on a un déchet on le fait passer par les operations #test rigide etc, qui nous donne selon la valeur du test
	// vrai/faux l'operation suivante à effectuer #programmé dans la sequence #pas au hasard
	//permet d'aboutir à la création du bon type de dechet (la classe création hérite de opération) # c'est juste l'op finale
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
