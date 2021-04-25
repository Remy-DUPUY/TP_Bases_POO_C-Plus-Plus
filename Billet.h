/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Billet.h
 * Author: dupuyrem
 *
 * Created on 9 mars 2020, 12:25
 */

#ifndef BILLET_H
#define BILLET_H

#include "Trajet.h"
#include "Tarif.h"
#include <iostream>
#include "NombreContraint.h"
#include "Produit.h"


class Billet: public Produit {
public:
    Billet(const Trajet & unTrajet,const Tarif & unTarif, const Client& client); 
   const Trajet & getTrajet() const; 
   const Tarif & getTarif() const; 
    virtual float getPrix() const; 
    virtual void afficher(std::ostream & cout = std::cout) const;
    
    
    Billet(const Billet& orig) = default;
    virtual ~Billet(){}
private:
    const Trajet & m_trajet;
    const Tarif & m_tarif; 
    
    
    

};

#endif /* BILLET_H */

