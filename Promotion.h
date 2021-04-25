/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Promotion.h
 * Author: dupuyrem
 *
 * Created on 9 mars 2020, 13:13
 */

#ifndef PROMOTION_H
#define PROMOTION_H
#include <iostream>
#include "NombreContraint.h"

class Promotion {
public:
    Promotion(const std::string & unLibelle = "Promo_etudiante",float unTaux = 0.5); 
    const std::string & getLibelle() const; 
    void setLibelle(const std::string & libelle);
    float calculePrixReduit(const float prix) const; 
    void saisir(std::istream & cin = std::cin); 
    void afficher(std::ostream & cout = std::cout) const;
    
    
    Promotion(const Promotion& orig) = default;
    virtual ~Promotion() {} 
private:
    std::string m_libelle; 
    NombreContraint<float> m_tauxReduction;  
    static const float TAUXMIN;   
    static const float TAUXMAX; 
    
};

#endif /* PROMOTION_H */

