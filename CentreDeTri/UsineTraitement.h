#pragma once
#include "SequenceOperations.h"
#include "ChargementDechet.h"
#include "Depot.h"
#include "Compteur.h"
#include "CreationDechetRecyclable.h"
#include "CreationDechetTraiteNonRecyclable.h"
#include "CreationDechetTraiteCompostable.h"

class UsineTraitement
{
public:
	UsineTraitement() :camionBleu(new CamionBleu()), camionBrun(new CamionBrun()), camionVert(new CamionVert()) { Compteur::ajouterConstructeur(); }
	UsineTraitement(UsineTraitement const& autre) : sequenceOperations(autre.sequenceOperations), depot(autre.depot) {
		camionVert = new CamionVert(*autre.camionVert);
		camionBleu = new CamionBleu(*autre.camionBleu);
		camionBrun = new CamionBrun(*autre.camionBrun);
		Compteur::ajouterConstructeurCopie();
	}
	virtual ~UsineTraitement();
	void chargerOperations(SequenceOperations* sequenceOperation);
	void demarrerTraitement(ChargementDechet* chargement) {/*à compléter ! */ }
	friend class OperationTraitement;
private:
	class Log
	{
	public:
		Log() { Compteur::ajouterConstructeur(); }
		~Log() { Compteur::ajouterDestructeur(); }
		void static i(string info) { std::cout << info << std::endl; }
		void static i(Dechet const& dechet) { dechet << std::cout << std::endl; }
		void static i(Depot const& depot) { depot << std::cout << std::endl; }
	};

	SequenceOperations sequenceOperations;
	Depot depot;
	CamionBleu* camionBleu;
	CamionVert* camionVert;
	CamionBrun* camionBrun;

	void preOperation() { Log::i("PREOPERATION"); }
	void postOperation() { Log::i("POSTOPERATION"); }
	void creerDechetTraiteRecyclable(Dechet* dechet);
	void creerDechetTraiteNonRecyclable(Dechet* dechet);
	void creerDechetTraiteCompostable(Dechet* dechet);
	void traiterDechet(Dechet* dechet);

};
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
