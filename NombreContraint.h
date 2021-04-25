/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NombreContraint.h
 * Author: dupuyrem
 *
 * Created on 2 mars 2020, 13:32
 */

#ifndef NOMBRECONTRAINT_H
#define NOMBRECONTRAINT_H
#include <iostream>
#include <string>

template <class TypeNumerique> 
class NombreContraint {
public:
    NombreContraint(TypeNumerique valeur = 0, const TypeNumerique min = 0, const TypeNumerique max = 100);
    const TypeNumerique getMin() const; 
    const TypeNumerique getMax() const; 
    const TypeNumerique getVal() const; 
    void setVal(TypeNumerique val); 
    void saisir(std::istream & entree = std::cin); 
    void afficher(std::ostream & sortie = std::cout) const; 
    operator int() const; 
    
    
    
private:
    TypeNumerique m_min; 
    TypeNumerique m_max; 
    TypeNumerique m_val; 
};

/* Ce ne sont pas de méthodes -> ce sont des fonctions donc elles sont hors de ma classe ! */

template <class TypeNumerique> 
    std::ostream& operator << (std::ostream& sortie, const NombreContraint<TypeNumerique> & n);
template <class TypeNumerique> 
    std::istream& operator >> (std::istream& entree, NombreContraint<TypeNumerique> & n);




/* ---------------- Mon code .cpp du template, pour compiler le template, il faut le code du .cpp (du template) qu'il faut inclure dans le .h --- */
/* ---------------- !!  Bien faire attention aux types devant les méthodes !  --- */

template <class TypeNumerique> 
NombreContraint<TypeNumerique>::NombreContraint(TypeNumerique valeur, const TypeNumerique min, const TypeNumerique max)
: m_val(valeur), m_min(min),m_max(max){
    
    setVal(valeur); 
    
}

template <class TypeNumerique> 
 const TypeNumerique NombreContraint<TypeNumerique>::getMin() const{
   return m_min; 
            
}


template <class TypeNumerique> 
 const TypeNumerique NombreContraint<TypeNumerique>::getMax() const{
    
    return m_max; 
    
}

template <class TypeNumerique> 
 const TypeNumerique NombreContraint<TypeNumerique>::getVal() const{
    
    return m_val; 
    
}

template <class TypeNumerique> 
 void NombreContraint<TypeNumerique>::setVal(TypeNumerique val){
    
    if(m_min <= val && val <= m_max){
        this -> m_val = val; 
    } else{
        throw "Erreur : la valeur dépasse les contraintes fixées"; 
    }
    
    
}

template <class TypeNumerique> 
 void  NombreContraint<TypeNumerique>::saisir(std::istream & entree){
    
    int val; 
    
    entree >> val; 
    setVal(val); 
   
}

template <class TypeNumerique> 
void NombreContraint<TypeNumerique>::afficher(std::ostream & sortie) const{
    
    sortie << getVal(); 
    
    
}

template <class TypeNumerique> 
NombreContraint<TypeNumerique>::operator int() const{
    return getVal(); 
}

template <class TypeNumerique> 
std::ostream& operator << (std::ostream& sortie, const NombreContraint<TypeNumerique> & n){
    n.afficher(sortie); 
    return sortie; 
}


template <class TypeNumerique> 
std::istream& operator >> (std::istream& entree, NombreContraint<TypeNumerique> & n){
    n.saisir(entree); 
     return entree;  
    
}


#endif /* NOMBRECONTRAINT_H */

