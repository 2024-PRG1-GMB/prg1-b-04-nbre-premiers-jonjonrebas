#include <iostream>
#include <cstdlib>


using namespace std;

int main() {

    cout
            << "Bonjour bienvenue dans ce programme qui vous donnera tous les "
            << "nombre premiers dans la limite de l'intervalle que vous aurez choisi." << endl;

    int nombre_premier;
    int limite;
    int tableau = 0;
    char reponse;

    do {

        do { //Boucle pour s'assurer que la limite entrée par l'utilisateur est correcte

            cout << "Veuillez entrer une valeur limite comprise entre 2 et 1000 : " << endl;
            cin  >> limite;

            // Vérification que la limite est dans l'intervalle autorisé

            if (limite < 2 || limite > 1000) {
                cout << "Veuillez entrer une limite comprise 2 et 1000 " << endl;


            }
        } while (limite < 2 || limite > 1000);

        cout << "voici tous les nombres premiers jusqu'a la limite choisie : " << endl;

        // Boucle pour trouver tous les nombres premiers jusqu'à la limite

        for (nombre_premier = 2; nombre_premier <= limite; ++nombre_premier) {
            bool estPremier = true; //flag pour indiquer si le nombre est premier
            for (int i = 2;
                 i * i <= nombre_premier; ++i) { //diviser par tous les nombres de 2 jusqu'à sa racine carrée
                if (nombre_premier % i == 0) {
                    estPremier = false;
                    break; // Sortir de la boucle dès qu'on trouve un diviseur
                }
            }
            if (estPremier) {

                cout << nombre_premier << '\t';
                tableau++;

                if (tableau == 5) {
                    cout << endl;
                    tableau = 0;
                }
            }
        }
        cout << endl; // Sauter une ligne après l'affichage des nombres premiers

        // Demander à l'utilisateur s'il veut recommencer
        do {
            cout << "Voulez-vous recommencer ? [O/N] : ";
            cin  >> reponse;

            // Vérifier si l'entrée est invalide et redemander la question
            if (reponse != 'O' && reponse != 'o' && reponse != 'N' && reponse != 'n') {

            }
        } while (reponse != 'O' && reponse != 'o' && reponse != 'N' &&
                 reponse != 'n'); // Continue de demander tant que l'entrée est incorrecte

    } while (reponse == 'O' || reponse == 'o'); // Répéter si l'utilisateur entre 'O' ou 'o'

    cout << "Fin du programme." << endl;

    return EXIT_SUCCESS;

}

