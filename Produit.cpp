/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Produit.cpp
 * Author: dupuyrem
 * 
 * Created on 11 mars 2020, 11:11
 */

#include "Produit.h"
using namespace std; 


Produit::Produit(const Client & client)
: m_leClient(client){
    
}


const Client Produit:: getClient() const{
    return m_leClient; 
}

void Produit::afficher(std::ostream& cout) const{
    cout << "Nom du client associé :" << m_leClient.getNom() << endl; 
}

