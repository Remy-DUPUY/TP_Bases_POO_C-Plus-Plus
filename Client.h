/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Client.h
 * Author: dupuyrem
 *
 * Created on 11 mars 2020, 10:55
 */

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>

class Client {
public:
    Client(const std::string & nom = "Stevie Wonder");
    const std::string & getNom() const; 
    void afficher(std::ostream &cout = std::cout) const;
    
    
    Client(const Client& orig) = default;
    virtual ~Client() {} 
private:
    std::string m_nom; 
    
    

};

#endif /* CLIENT_H */

