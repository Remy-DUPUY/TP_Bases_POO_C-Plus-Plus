/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dupuyrem
 *
 * Created on 2 mars 2020, 14:39
 */

#include <cstdlib>

#include "Trajet.h"
#include "NombreContraint.h"
#include "Tarif.h"
#include "Promotion.h"
#include "Billet.h"
#include "BilletReduit.h"
#include "Client.h"
#include "Produit.h"
#include "Reservation.h"
#include "Pack.h"

#include "Conteneur.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    // ----   PARTIE 2 DU TP : Pattern Singleton  --- 
    
    // création des Conteneurs + ajout des éléments en dur
    
    // Les trajets :
    Trajet trajet1("Lyon","Grenoble",100); 
    Trajet trajet2("Paris","Marseille",800);
    
    // Les tarifs :
    Tarif tarif1("Lyon_Grenoble",0.5); 
    Tarif tarif2("Paris_Marseille",0.3); 
    
    // Les promotions :
    Promotion promo1("Promo_Lyon_Grenoble",0.2); 
    Promotion promo2("Promo_Paris_Marseille",0.5); 

    // les clients :
    Client client1("DUPUY Remy"); 
    Client client2("POMMATAU Romain");
    
    // les conteneurs : 
    Conteneur<Trajet> & CTrajet = Conteneur<Trajet>::getInstance(); 
    CTrajet.ajouter(trajet1);
    CTrajet.ajouter(trajet2); 
    
    
    Conteneur<Tarif> & CTarif = Conteneur<Tarif>::getInstance(); 
    CTarif.ajouter(tarif1); 
    CTarif.ajouter(tarif2); 
    
    Conteneur<Promotion> & CPromotion = Conteneur<Promotion>::getInstance();
    CPromotion.ajouter(promo1); 
    CPromotion.ajouter(promo2);

    Conteneur<Produit> & CProduit = Conteneur<Produit>::getInstance();
    
    Conteneur<Client> & CClient= Conteneur<Client>::getInstance();
    CClient.ajouter(client1); 
    CClient.ajouter(client2);

    
   // le menu utilisateur en lui même :
    
    bool lancement = true; 
    
    while(lancement){
        
    
    
    cout << "Bienvenue sur l'application SNCF " << endl; 
    cout << "********************************" << endl; 
    
    cout << "1-  Créer un billet " << endl; 
    cout << "2-  Créer un billet Réduit " << endl; 
    cout << "3-  Créer une réservation " << endl; 
    cout << "4-  Créer un pack " << endl; 
    cout << "5-  Afficher les produits " << endl; 
    cout << "6-  Quitter " << endl;
    
     cout << "********************************" << endl; 
     cout << "Veuillez faire un choix : " << endl; 
     
     int choix = 0; 
     
     cin >> choix; 
    
     // Créer un billet : 
     if(choix == 1){
         Client* client = new Client();
         *client = CClient.choisirElement(); 
         
         
         Trajet* trajet = new Trajet(); 
         *trajet  = CTrajet.choisirElement(); 
         
         Tarif* tarif = new Tarif(); 
         *tarif = CTarif.choisirElement(); 
         
         Billet* billet = new Billet(*trajet,*tarif,*client); 
         
         CProduit.ajouter(*billet); 
        
         CProduit.afficher(); 
         
         cout << "Billet crée ! " << endl; 
     }
     
     // Créer un billet réduit : 
     if(choix == 2){
         
         Client* client = new Client();
         *client = CClient.choisirElement();
         
         Trajet* trajet = new Trajet();
         *trajet = CTrajet.choisirElement();

         Tarif* tarif = new Tarif();
         *tarif = CTarif.choisirElement();

         Promotion* promo = new Promotion();
         *promo = CPromotion.choisirElement();
         
         BilletReduit* billetR = new BilletReduit(*trajet, *tarif, *promo, *client);
         CProduit.ajouter(*billetR);
                 
         CProduit.afficher(); 
         
         cout << "Billet réduit crée ! " << endl; 
     }
     
     
    // Créer une réservation : 
     if(choix == 3){
         
         Client* client = new Client();
         *client = CClient.choisirElement();

         string nomHotel;
         cout << "Nom de l'hotel :";
         cin >> nomHotel;

         int nombreJours;
         cout << "Nombre de jour à l'hotel :";
         cin >> nombreJours;

         int prixPJour;
         cout << "Prix par jour de l'hotel:";
         cin >> prixPJour;

         Reservation* reverservation = new Reservation(nomHotel, nombreJours, prixPJour,*client);
         CProduit.ajouter(*reverservation);

         cout << " \n" << endl; 
         CProduit.afficher(); 
         
         cout << "Réservation crée ! " << endl; 
         
     }
    
    // Créer un pack : 
     if(choix == 4){
         
         const Produit& produit = CProduit.choisirElement();
         
         Pack* pack = new Pack(produit);
         
         bool lancementPack = true;
                    while (lancementPack) {
                        cout << "Voulez vous ajouter un produit en plus ? " << endl;
                        cout << "   1 - oui" << endl;
                        cout << "   2 - non" << endl;

                        cout << "Votre choix : ";
                        int reponse_Pack = 0;
                        cin >> reponse_Pack;

                       switch (reponse_Pack) {
                            case 1:
                            {
                                const Produit& produit = CProduit.choisirElement();

                                pack->ajouter(&produit);
                            }
                                break;
                            default:
                            {
                                lancementPack = false;
                            }
                                break;
                        }
                  
                    }
         
                  CProduit.ajouter(*pack);
    
     }
     
     // Afficher la liste des produits :      
     if(choix == 5){
         CProduit.afficher(); 
     }
    
     // Tout arreter : 
     if (choix == 6){
         return 0; 
     }
     
    }
    
    
    
    
/////////// --- A partir d'ici :  Test des classes précédentes - Correspond à la première partie du TP ----     ////////////////////////////
     
     
    /*
     
    // création du client 
    
    Client remy("Rémy Dupuy"); 
    
    // création d'un trajet :
    
    Trajet trajet_LYON_Gre("Lyon","Grenoble",100);
    
    trajet_LYON_Gre.afficher();  
    
    // creation du tarif :
    
    Tarif tarif_lyon_gre("lyon_grenoble",2.2); 
    
    tarif_lyon_gre.afficher(); 
    
    // creation d'une promotion:
    
    Promotion promo_lyon_gre("Promo_lyon_grenoble",0.5); 
    
    promo_lyon_gre.afficher(); 
    
    // cration d'un billet et d'un billet réduit : 
    
    Billet billet_LY_GRE(trajet_LYON_Gre,tarif_lyon_gre,remy); 
    
    billet_LY_GRE.afficher(); 
    
    BilletReduit billetRed_LY_GRE(trajet_LYON_Gre,tarif_lyon_gre,promo_lyon_gre,remy); 
    
    billetRed_LY_GRE.afficher(); 
   
    cout << " ///////// " << endl; 
   
 */
    // création d'un trajet, tarif, promotion, billet et billet réduit avec la méthode saisir()
    
    /*
    Trajet trajet_Paris_Marseille("VilleDep","VillArri",50); 
    
    trajet_Paris_Marseille.saisir(); 
    trajet_Paris_Marseille.afficher(); 
    
     Tarif tarif_Paris_Marseille("villeDep_Arri",1); 
     
     
     tarif_Paris_Marseille.saisir(); 
     tarif_Paris_Marseille.afficher(); 
     
     
     Promotion promo_paris_mars("Promo_villeDep_villeArri",0.5); 
    
     promo_paris_mars.saisir(); 
     promo_paris_mars.afficher(); 
     
     Billet billet_Paris_Mars(trajet_Paris_Marseille,tarif_Paris_Marseille,remy); 
     
     billet_Paris_Mars.afficher(); 
     
     BilletReduit billetRed_Paris_Mars(trajet_Paris_Marseille,tarif_Paris_Marseille,promo_paris_mars,remy);
     
     billetRed_Paris_Mars.afficher(); 
     */
 
    
    /*
    Client Stevie("Stevie W"); 
    
    // Stevie veut un billet de Nantes à Grenoble : 
    Trajet trajet_Nantes_Gre("Nantes","Grenoble",800);
    
    Tarif tarif_Nantes_Gre("nantes_gre",0.5); 
    
    Billet billet_NT_GRE(trajet_Nantes_Gre,tarif_Nantes_Gre,Stevie); 
    
    Pack pack_Stevie(billet_NT_GRE); // ajout du billet au pack
    
    // Stevie veut une réservation d'hotel en plus : 
    
    Reservation resa_stevie("Trivago",15,100,Stevie); 
    
    pack_Stevie.ajouter(&resa_stevie); 
    
    
    // affichage du pack :
    
    pack_Stevie.afficher(); 
     
    */
    
   
}

