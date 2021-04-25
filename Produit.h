/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Produit.h
 * Author: dupuyrem
 *
 * Created on 11 mars 2020, 11:11
 */

#ifndef PRODUIT_H
#define PRODUIT_H

#include "Client.h"
#include <iostream>


class Produit {
public:
    Produit(const Client & client);
    virtual float getPrix() const = 0; // équivalent du abstract : methode pas implémentée 
    virtual void afficher(std::ostream & cout = std::cout) const; 
    virtual void ajouter(const Produit * produit) {throw "opération interdite";};  // méthode abstract : on ne souhaite pas ajouter un produit à un produit
    
    const Client getClient() const;  
    
    Produit(const Produit& orig) = default;
    virtual ~Produit() {}
private:
    const Client & m_leClient; 
    

};

#endif /* PRODUIT_H */

