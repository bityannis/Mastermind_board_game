#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    //GENERATION ALEATOIRE DES 4 LETTRES
    srand(time(NULL));
    char LETTRES_POSSIBLE[5] = {'R', 'V', 'B', 'J', 'O'};
    char COMBINAISON[4] = {};
    
    for (int i = 0; i < 4; i++) {
        int random_index = (rand() % 4);
        COMBINAISON[i] = LETTRES_POSSIBLE[random_index];
        printf("RANDOM 🤫 %c\n", COMBINAISON[i]);
    }

    //CREATION DES VARIABLES
    char saisie_utilisateur[4] = {};
    const int MAX_TENTATIVES = 3;
    int tentatives_utilisateur = 0;
    int couleur_bien, couleur_mal = 0;

    //DEBUT DU JEU
    printf("Donnez un code de 4 couleurs differentes et sans espaces parmis : {'R', 'V', 'B', 'J', 'O'}\n");

    //MAX 3 TENTATIVES SINON ECHEC
    for (int i = 0; i < MAX_TENTATIVES; i++) {
        fflush(stdin); // Indispensable pour ne pas lire des restes d'entrees
        scanf("%c %c %c %c", &saisie_utilisateur[0], &saisie_utilisateur[1], &saisie_utilisateur[2], &saisie_utilisateur[3]);
        tentatives_utilisateur++;
        couleur_bien = couleur_mal = 0; //A chaque boucle on reinitialise les variables
        printf("Tentative %d/%d\n", tentatives_utilisateur, MAX_TENTATIVES);

        //Si le joueur a assez de tentatives restantes:
        if (tentatives_utilisateur <= MAX_TENTATIVES) {
            for (int i = 0; i < 4; i++) {
                if (saisie_utilisateur[i] == COMBINAISON[i]) {
                    couleur_bien++;
                } 
                else {
                    couleur_mal++;
                }
            }
        } 
        printf("Couleur(s) bien places: %d\n", couleur_bien);
        printf("Couleur(s) mal places: %d\n", couleur_mal);

        //Victoire en cas de couleurs bien places et en une 1 tentative
        if (couleur_bien == 4) {
            printf("FELICITATIONS!\n");
            break;
        } else if (tentatives_utilisateur == MAX_TENTATIVES) {
            printf("PLUS DE CHANCES2\n");
            break;
        }

        }

    return 0;
}