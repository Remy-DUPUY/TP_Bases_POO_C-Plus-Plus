/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trajet.h
 * Author: dupuyrem
 *
 * Created on 4 mars 2020, 11:18
 */

#ifndef TRAJET_H
#define TRAJET_H

#include <string>
#include <iostream>
#include "NombreContraint.h"



class Trajet {
public:
    Trajet(const std::string & villeDep = "Grenoble", const std::string & villeArr = "Lyon", int dist = 100); 
    const std::string & getVilleDepart() const; 
    void setVilleDepart(const std::string & villeDep); 
    const std::string & getVilleArrivee() const; 
    void setVilleArrivee(const std::string & villeArri); 
    int getDistance() const; 
    void saisir(std::istream & cin = std::cin); 
    void afficher(std::ostream & cout = std::cout) const;
   
    
    
    Trajet(const Trajet& orig) = default;
    virtual ~Trajet() {} 
   
private:
    std::string m_villeDepart; 
    std::string m_villeArrivee; 
    NombreContraint<int> m_distance; 
    static const int DISTANCEMIN; 
    static const int DISTANCEMAX; 

};

#endif /* TRAJET_H */

