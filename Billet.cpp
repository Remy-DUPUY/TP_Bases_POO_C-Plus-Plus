/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Billet.cpp
 * Author: dupuyrem
 * 
 * Created on 9 mars 2020, 12:25
 */

#include "Billet.h"
using namespace std; 


Billet::Billet(const Trajet & unTrajet, const Tarif & unTarif, const Client& client)
: Produit(client),m_trajet(unTrajet), m_tarif(unTarif){
    
}

const Trajet & Billet::getTrajet() const{
    return m_trajet; 
}

const Tarif & Billet::getTarif() const{
    return m_tarif; 
}

 float Billet::getPrix() const{
    return (this -> m_tarif.getPrixAuKm()* this-> m_trajet.getDistance()); 
}


void Billet::afficher(std::ostream & cout) const{
    cout << "Billet classique / Le Trajet de " << this -> getTrajet().getVilleDepart() << " a " << this -> getTrajet().getVilleArrivee() << " coute " << this -> getPrix() << "€" << endl; 
}


