/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reservation.cpp
 * Author: dupuyrem
 * 
 * Created on 11 mars 2020, 11:39
 */

#include "Reservation.h"
using namespace std;

const int Reservation::NBJOURMIN = 1; 
const int Reservation::NBJOURMAX = 365; 

const float Reservation::PRIXPARJOURMIN = 30.0; 
const float Reservation::PRIXPARJOURMAX = 1000; 

Reservation::Reservation(const string& nomHotel, int nbJour, float prixParJour, const Client& client)
: Produit(client), m_nomHotel(nomHotel), m_nbJour(nbJour,NBJOURMIN,NBJOURMAX), m_prixParJour(prixParJour,PRIXPARJOURMIN,PRIXPARJOURMAX){
    
}


float Reservation::getPrix() const {
    return (m_nbJour*m_prixParJour); 
}

void Reservation::afficher(std::ostream& cout) const {
    Produit::afficher(); // afficher le client 
    cout << "Nom de l'hotel :" << m_nomHotel << " , Nombre de jour :" << m_nbJour << " , Prix par jour :" << m_prixParJour << "€" << endl;
    cout << "Cout total de la réservation : " << this->getPrix() << "€" << endl; 
}










