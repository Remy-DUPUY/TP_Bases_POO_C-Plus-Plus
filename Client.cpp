/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Client.cpp
 * Author: dupuyrem
 * 
 * Created on 11 mars 2020, 10:55
 */

#include "Client.h"
using namespace std; 

Client::Client(const string & nom)
: m_nom(nom){
    
}

const string & Client:: getNom() const{
    return this -> m_nom; 
}  

void Client::afficher(std::ostream &cout) const {
    cout << "Données du client : " << endl; 
    cout << " Nom : " << getNom() << endl; 
}



        


