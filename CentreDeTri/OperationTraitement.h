#pragma once
//#include "UsineTraitement.h"
#include "Operation.h"
#include "Compteur.h"
class UsineTraitement;
class OperationTraitement :
	public Operation
{

public:
	OperationTraitement(UsineTraitement* usineT);
	//OperationTraitement(OperationTraitement const& autre);
	~OperationTraitement();

	bool effectuerOperation(Dechet* dechet) override { return false; }
protected:
	void creerDechetTraiteRecyclable(Dechet* dechet);//inside via friend
	void creerDechetTraiteNonRecyclable(Dechet* dechet);
	void creerDechetTraiteCompostable(Dechet* dechet);
	OperationTraitement(OperationTraitement const& autre);
private:
	UsineTraitement *usineTraitement;

};
