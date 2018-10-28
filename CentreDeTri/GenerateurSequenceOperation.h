#pragma once
#include "UsineTraitement.h"
#include "SequenceOperations.h"
#include "CreationDechetRecyclable.h"
#include "CreationDechetTraiteCompostable.h"
#include "CreationDechetTraiteNonRecyclable.h"
#include"Operation1.h"
#include"Operation2.h"
#include"Operation3.h"
#include"Operation4.h"
#include"Operation5.h"
#include"Operation6.h"
#include "Compteur.h"

class GenerateurSequenceOperation
{
public:
	GenerateurSequenceOperation() { Compteur::ajouterConstructeur(); };
	~GenerateurSequenceOperation() { Compteur::ajouterDestructeur(); };
	SequenceOperations* genererSequence(int id, UsineTraitement* usineTraitement) const {
		return id == 0 ? genererSequence0(usineTraitement) :
			genererSequence1(usineTraitement);
	};
private:
	SequenceOperations* genererSequence0(UsineTraitement* usineTraitement) const;
	SequenceOperations* genererSequence1(UsineTraitement* usineTraitement) const { return NULL; }
};



SequenceOperations* GenerateurSequenceOperation::genererSequence0(UsineTraitement* usineTraitement) const
{
	//on crée la séquence 0
	SequenceOperations* seq = new SequenceOperations();
	//double chainage création ?=non cf schéma
	//Operation *op = new Operation1(new Operation1(new Operation2(new Operation3(new Operation4(new Operation5(NULL, NULL), NULL), NULL), NULL), NULL), NULL);
	Operation *op = new Operation1(new CreationDechetTraiteNonRecyclable(usineTraitement),
		new Operation2(new Operation6(new CreationDechetTraiteRecyclable(usineTraitement),
			new CreationDechetTraiteNonRecyclable(usineTraitement)),
			new Operation3(new CreationDechetTraiteRecyclable(usineTraitement),
				new Operation4(new CreationDechetTraiteCompostable(usineTraitement),
					new Operation5(new CreationDechetTraiteCompostable(usineTraitement),
						new CreationDechetTraiteNonRecyclable(usineTraitement))))));
	//Operation1* op = new Operation1(new CreationDechetTraiteNonRecyclable(usineTraitement), NULL);
	seq->ajouterOperation(op);
	return seq;
}
