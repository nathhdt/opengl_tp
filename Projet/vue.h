#pragma once
#include <string>
#include "observateur.h"


class Vue : public Observateur
{
private:
	std::string titre;
public:
	Vue(const std::string& _titre);
	void clear() const;
	virtual void afficher() const;
};