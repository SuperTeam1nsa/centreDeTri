#pragma once
#include "SequenceOPerations.h"
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

	class Log 
	{
		Log();
		~Log();
		void i(string info);
		void i(Dechet const& dechet);
		void i(Depot const& depot);
	};
};