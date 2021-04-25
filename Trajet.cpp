/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trajet.cpp
 * Author: dupuyrem
 * 
 * Created on 4 mars 2020, 11:18
 */

#include "Trajet.h"
#include "NombreContraint.h"
using namespace std; 

const int Trajet::DISTANCEMIN = 1; 
const int Trajet::DISTANCEMAX = 2000;

Trajet::Trajet(const string & villeDep, const string & villeArr, int dist)
: m_villeDepart(villeDep), m_villeArrivee(villeArr), m_distance(dist,DISTANCEMIN,DISTANCEMAX){
    
}
    
const string & Trajet:: getVilleDepart() const{
    return m_villeDepart; 
   
}

void Trajet:: setVilleDepart(const  string & villeDep){
    this -> m_villeDepart = villeDep; 
}

const string & Trajet:: getVilleArrivee() const{
    return m_villeArrivee; 
}


void Trajet:: setVilleArrivee(const string & villeArri){
    this -> m_villeArrivee = villeArri; 
}

int Trajet:: getDistance() const{
    return m_distance.getVal(); 
}

void Trajet:: saisir(std::istream& cin){
    string villeDepart; 
    string villeArr; 
    int distance; 
    
    cout << "Saisir la ville de départ puis la ville d'arrivée et la distance en km" << endl; 
    
    cin >> villeDepart >> villeArr >> distance;
    setVilleDepart(villeDepart); 
    setVilleArrivee(villeArr); 
    m_distance.setVal(distance); 
   
}

void Trajet:: afficher(std::ostream& cout) const{
    
cout << "Trajet - Ville de départ : " << this -> getVilleDepart() << " - Ville d'arrivée : " << this -> getVilleArrivee() 
     << " - Distance : " << this -> getDistance() << "km" <<endl; 
    
}








