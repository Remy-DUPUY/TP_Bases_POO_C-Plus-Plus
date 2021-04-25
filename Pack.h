/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pack.h
 * Author: Admin
 *
 * Created on 18 mars 2020, 11:37
 */

#ifndef PACK_H
#define PACK_H

#include "Produit.h"
#include <vector> 


class Pack: public Produit {
public:
    Pack(const Produit & mesProd); 
    float getPrix() const; 
    void afficher(std::ostream & cout = std::cout) const ;   
    void ajouter(const Produit * produit); 
    
   
    Pack(const Pack& orig) = default;
    virtual ~Pack() {}
private:
    std::vector<const Produit*> m_contenu;  

};

#endif /* PACK_H */

