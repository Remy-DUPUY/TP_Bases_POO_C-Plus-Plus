/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Promotion.cpp
 * Author: dupuyrem
 * 
 * Created on 9 mars 2020, 13:13
 */

#include "Promotion.h"
using namespace std; 

const float Promotion::TAUXMIN = 0.01; 
const float Promotion::TAUXMAX = 0.99;

Promotion::Promotion(const string & unLibelle, float unTaux)
: m_libelle(unLibelle), m_tauxReduction(unTaux,TAUXMIN,TAUXMAX){
    
}

const string & Promotion:: getLibelle() const{
    return this -> m_libelle; 
}

void Promotion:: setLibelle(const std::string& libelle){
    this -> m_libelle = libelle; 
}

float Promotion::calculePrixReduit(const float prix) const{
    
    return (1-m_tauxReduction.getVal())*prix; 
}

void Promotion:: saisir(std::istream & cin){
    
    string libelle; 
    float taux; 
    
    cout << "Saisir le libelle puis le taux de réduction de la promotion :" << endl; 
    
    cin >> libelle >> taux; 
    setLibelle(libelle); 
    m_tauxReduction.setVal(taux); 
    
} 

void Promotion:: afficher(std::ostream & cout) const{
    
    cout << "Libelle de la promotion : " << this -> getLibelle() << " - Taux de réduction : " << m_tauxReduction.getVal() << "%" <<endl; 
}




