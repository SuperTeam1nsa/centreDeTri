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
	UsineTraitement();
	UsineTraitement(UsineTraitement const& autre) : sequenceOperations(autre.sequenceOperations), depot(autre.depot) {
		camionVert = new CamionVert(*autre.camionVert);
		camionBleu = new CamionBleu(*autre.camionBleu);
		camionBrun = new CamionBrun(*autre.camionBrun);
		Compteur::ajouterConstructeurCopie();
	}
	virtual ~UsineTraitement();
	void chargerOperations(SequenceOperations* sequenceOperation);
	void demarrerTraitement(ChargementDechet* chargement);
	friend class OperationTraitement;
private:
	class Log
	{
	public:
		Log() {};
		~Log() {};
		void static i(string info);
		void static i(Dechet const& dechet);
		void static i(Depot const& depot);
	};

	SequenceOperations sequenceOperations;
	Depot depot;
	CamionBleu* camionBleu;
	CamionVert* camionVert;
	CamionBrun* camionBrun;

	void preOperation();
	void postOperation();
	void creerDechetTraiteRecyclable(Dechet* dechet);
	void creerDechetTraiteNonRecyclable(Dechet* dechet);
	void creerDechetTraiteCompostable(Dechet* dechet);
	void traiterDechet(Dechet* dechet);

};
