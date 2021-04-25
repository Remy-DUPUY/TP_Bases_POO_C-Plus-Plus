/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BilletReduit.cpp
 * Author: dupuyrem
 * 
 * Created on 9 mars 2020, 13:53
 */

#include "BilletReduit.h"
using namespace std; 


BilletReduit::BilletReduit(const Trajet & unTrajet, const Tarif & unTarif, const Promotion & unePromo, const Client& client): 
    Billet(unTrajet,unTarif,client),m_promotion(unePromo){
    
}

float BilletReduit:: getPrix() const{
   
    return m_promotion.calculePrixReduit(Billet::getPrix()); 
}

 const Promotion & BilletReduit:: getPromotion() const{
     return this -> m_promotion; 
 }
 
 
 void BilletReduit::afficher(std::ostream & cout) const{
     cout << "Billet réduit / Le Trajet de " << this -> getTrajet().getVilleDepart() << " a " << this -> getTrajet().getVilleArrivee() << " coute après réduction " << this -> getPrix() << "€" << endl; 
 }






    
