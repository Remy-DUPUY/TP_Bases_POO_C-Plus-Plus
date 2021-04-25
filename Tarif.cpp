/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tarif.cpp
 * Author: dupuyrem
 * 
 * Created on 2 mars 2020, 14:49
 */

#include "Tarif.h"
using namespace std; 

 const float Tarif::PRIXMIN = 0.01; 
 const float Tarif::PRIXMAX = 10.00; 

Tarif::Tarif(const string & unLibelle, float unPrixKilo)
: m_libelle(unLibelle), m_prixAuKm(unPrixKilo,PRIXMIN,PRIXMAX){
   
}

const string & Tarif:: getLibelle() const{
    return m_libelle; 
}

void Tarif:: setLibelle(const string & libelle){
    this -> m_libelle = libelle; 
}

float Tarif:: getPrixAuKm() const{
    return m_prixAuKm.getVal(); 
}

void Tarif:: saisir(std::istream& cin){
    
    string libelle; 
    float prixAuKiloMetre; 
    
    cout << "Saisir le libelle puis le prix au KM :" << endl; 
    
    cin >> libelle >> prixAuKiloMetre; 
    setLibelle(libelle);
    m_prixAuKm.setVal(prixAuKiloMetre); 
    
}

void Tarif:: afficher(std::ostream& cout) const{
    
    cout << "Libellé du tarif :" << this -> getLibelle() << " - Prix au KM : "  << this -> getPrixAuKm() << "€" << endl; 
    
}



