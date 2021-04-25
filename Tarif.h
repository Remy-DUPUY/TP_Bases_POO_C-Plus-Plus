/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tarif.h
 * Author: dupuyrem
 *
 * Created on 2 mars 2020, 14:49
 */

#ifndef TARIF_H
#define TARIF_H

#include <string>
#include <iostream>


#include "NombreContraint.h"


class Tarif {
public:
    Tarif(const std::string & unLibelle = "tarif_classique", float unPrixKilo = 0.3);
    const std::string & getLibelle() const ; 
    void setLibelle(const std::string & libelle); 
    float getPrixAuKm() const ; 
    void saisir(std::istream & cin = std::cin); 
    void afficher(std::ostream & cout = std::cout) const; 
            
    Tarif(const Tarif& orig) = default;
    
    virtual ~Tarif() {}
private:
    std::string m_libelle;
    NombreContraint<float> m_prixAuKm; 
    static const float PRIXMIN; 
    static const float PRIXMAX; 


};

#endif /* TARIF_H */

