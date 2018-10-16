#pragma once
#include "SequenceOperations.h"
#include "ChargementDechet.h"
#include "Depot.h"

class UsineTraitement
{
public:
	UsineTraitement();
	virtual ~UsineTraitement();
	void chargerOperations(SequenceOperations* sequenceOperation);
	void demarrerTraitement(ChargementDechet* chargement);
	
private:
	class Log
	{
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