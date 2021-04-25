/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pack.cpp
 * Author: Admin
 * 
 * Created on 18 mars 2020, 11:37
 */

#include <algorithm>

#include "Pack.h"


using namespace std; 

Pack::Pack(const Produit& mesProd)
: Produit(mesProd.getClient()), m_contenu(){  // vecteur initialisé à vide pour le moment 
    m_contenu.push_back(&mesProd);    // on ajoute au moins un élément au vecteur (cardinalité oblige) 
}         


float Pack::getPrix() const {
    float resultat; 
    
    for (int i =0; i < m_contenu.size(); i++){
        resultat += m_contenu[i]->getPrix(); 
    }
    
    return resultat; 

    
}


void Pack::afficher(std::ostream& cout) const{
    
    cout << " Liste des differents élements du pack :" << endl; 
    cout << " ------------" << endl; 
    
    for(int i = 0; i < m_contenu.size(); i++){
        m_contenu[i]->afficher(); 
    }
   
    cout << "Le prix total du pack est : " << this->getPrix() << "€" << endl; 
    cout << "------------" << endl; 
}

void Pack::ajouter(const Produit* produit){
    m_contenu.push_back(produit); 
}





