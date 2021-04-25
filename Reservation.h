/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reservation.h
 * Author: dupuyrem
 *
 * Created on 11 mars 2020, 11:39
 */

#ifndef RESERVATION_H
#define RESERVATION_H

#include "Produit.h"
#include "NombreContraint.h"
#include <string>


class Reservation: public Produit {
public:
    Reservation(const std::string & nomHotel, int nbJour, float prixParJour, const Client & client); 
    float getPrix() const; 
    void afficher(std::ostream & cout = std::cout) const;   
    
    Reservation(const Reservation& orig) = default;
    virtual ~Reservation() {} 
private:
    std::string m_nomHotel; 
    NombreContraint<int> m_nbJour; 
    NombreContraint<float> m_prixParJour; 
    
    static const int NBJOURMIN;   
    static const int NBJOURMAX;
    
    static const float PRIXPARJOURMIN;   
    static const float PRIXPARJOURMAX;
    
    

};

#endif /* RESERVATION_H */

