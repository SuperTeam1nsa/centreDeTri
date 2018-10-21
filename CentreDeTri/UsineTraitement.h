#pragma once
#include "OperationTraitement.h"
#include "SequenceOperations.h"
#include "ChargementDechet.h"
#include "Depot.h"
#include "Compteur.h"

class OperationTraitement;
class UsineTraitement
{
public:
	UsineTraitement();
	UsineTraitement(UsineTraitement const& autre);


	void demarrerTraitement(ChargementDechet* chargement);
	void chargerOperations(SequenceOperations* sequenceOperation);
	~UsineTraitement();

private:
	friend class OperationTraitement;
	class Log
	{
	public:
		Log() { Compteur::ajouterConstructeur(); }
		~Log() { Compteur::ajouterDestructeur(); }
		void static i(string info) { std::cout << info << std::endl; }
		void static i(Dechet const& dechet) { dechet << std::cout << std::endl; }
		void static i(Depot const& depot) { depot << std::cout << std::endl; }
	};

	SequenceOperations* sequenceOperations;
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
