/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conteneur.h
 * Author: Admin
 *
 * Created on 20 mars 2020, 09:59
 */

#ifndef CONTENEUR_H
#define CONTENEUR_H

#include <vector>
#include <iostream>

#include "NombreContraint.h"


template <class T>
class Conteneur{
    public:
         void ajouter(const T & element); 
          void afficher() const; 
         const T & choisirElement() const;
         static Conteneur<T>& getInstance();

        
   protected:
            Conteneur() {} 
   private:
       std::vector<const T*> m_contenu; 
       static Conteneur<T>* m_instance; 
};


template <class T> 
 Conteneur<T> & Conteneur<T>::getInstance() {
    if(m_instance == nullptr){
        m_instance = new Conteneur<T>();
    }
    
    return *m_instance; 
}

template <class T>
Conteneur<T>* Conteneur<T>::m_instance = nullptr; 


template <class T>
void Conteneur<T>::ajouter(const T& element){
    m_contenu.push_back(&element); 
}

template <class T>
void Conteneur<T>::afficher() const {
    for(int i = 0; i < m_contenu.size(); i++){
        std::cout << i+1 << " - "; 
        m_contenu[i]-> afficher(std::cout); 
        std::cout << std::endl; 
        
    }
}

template <class T>
const T & Conteneur<T>::choisirElement() const{
    NombreContraint<int> n(1,1,m_contenu.size()); 
    bool ok; 
    do{
        try{
            afficher();
            std::cout << std::endl << "Votre choix :"; 
            n.saisir(std::cin);
            ok = true; 
            
        } catch(const char * e){
            std::cout << " Choix entre 1 et "
                    << m_contenu.size() << std::endl; 
            ok = false; 
        }
    } while(!ok); 
    return *m_contenu[n.getVal()-1]; 
   
    
}






#endif /* CONTENEUR_H */

