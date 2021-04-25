/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BilletReduit.h
 * Author: dupuyrem
 *
 * Created on 9 mars 2020, 13:53
 */

#ifndef BILLETREDUIT_H
#define BILLETREDUIT_H

#include "Billet.h"
#include "Promotion.h"


class BilletReduit: public Billet {
public:
    BilletReduit(const Trajet & unTrajet, const Tarif & unTarif, const Promotion & unePromo, const Client& client); 
    float getPrix() const; 
    const Promotion & getPromotion() const;
    void afficher(std::ostream & cout = std::cout) const;
    
    
    BilletReduit(const BilletReduit& orig) = default;
    virtual ~BilletReduit() {}
private:
    const Promotion & m_promotion; 
    
    

};

#endif /* BILLETREDUIT_H */

