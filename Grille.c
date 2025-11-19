#include <stdio.h>
#include <stdlib.h>

#define N 8
#define BLACK 0
#define WHITE 1
#define EMPTY 2

// Initialisation du plateau avec la situation de départ
void initialiser_plateau(int *plateau[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            plateau[i][j] = EMPTY;
        }
    }
    // Situation de depart
    plateau[3][3] = WHITE;
    plateau[4][4] = WHITE;
    plateau[3][4] = BLACK;
    plateau[4][3] = BLACK;
}


// Place un pion de la couleur donnée à la position (i,j)
void placer_pion(int *plateau[],int i,int j,int couleur){
    plateau[i][j]=couleur;
}


// Vérifie si une position (i,j) est dans les limites du plateau
int est_dans_plateau(int i, int j) {
    return (i >= 0 && i < N && j >= 0 && j < N);
}


// Vérifie la légalité d'un coup pour la couleur donnée
int verifier_legalite(int *plateau[], int i, int j, int couleur) {
    if (!est_dans_plateau(i, j) || plateau[i][j] != EMPTY) { // arret immédiat si hors plateau ou case non vide 
        printf("coup illégal car en dehors du plateau ou case non vide\n");
        return 0;
    }

    int couleur_oppose = (couleur + 1) % 2; // recupere la valeur opposé a la couleur du joueur

    int directions[8][2] = { // Les 8 directions possible ( le vecteur de déplacement du prof quoi)
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

  
    for (int k = 0; k < 8; k++) { // test des 8 huits directions
        int direction_i = directions[k][0]; // déplacement ligne
        int direction_j = directions[k][1]; // déplacement colonne

        // On regarde la première case dans cette direction
        int x = i + direction_i; 
        int y = j + direction_j;
        int a_trouve_adversaire = 0;

        // TANT QUE on est sur le plateau ET qu'on voit des pions adverses
        while (est_dans_plateau(x, y) && plateau[x][y] == couleur_oppose) {
            x += direction_i;      // On continue d'avancer dans la même direction
            y += direction_j;
            a_trouve_adversaire = 1; // On a bien trouvé un adversaire
        }

        // SI on s'est arrêté sur un pion de NOTRE couleur, ET qu'on avait trouvé des adversaires avant
        if (a_trouve_adversaire && est_dans_plateau(x, y) && plateau[x][y] == couleur) { 
            return 1; // Le coup est légal (pas besoin de vérifier les autres directions)
        }
    }
    printf("coup illégal car aucune prise possible\n");
    return 0; // retourne coup illégal 
}


// Affiche le plateau
void affiche_othello(int *plateau[]){
    printf("    0    1    2    3    4    5    6    7\n");
    printf("  -----------------------------------------\n");
    for (int i = 0; i < N; i++) {
        printf("%d|", i);
        for (int j = 0; j < N; j++) {
            if (plateau[i][j] == BLACK) {
                printf("  B  ");
            } else if (plateau[i][j] == WHITE) {
                printf("  W  ");
            } else {
                printf(" ___ ");
            }
        }
        
        printf("|\n");
    }
    printf("  -----------------------------------------\n");
}


// Retourne les pions adverses capturés par le coup joué à (i,j)
void retourner_pions(int *plateau[], int i, int j, int couleur){
    int couleur_oppose = (couleur + 1) % 2; // recupere la valeur opposé a la couleur du joueur

    int directions[8][2] = { // Les 8 directions possible ( le vecteur de déplacement du prof quoi)
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

  
    for (int k = 0; k < 8; k++) { // test des 8 huits directions
        int direction_i = directions[k][0]; 
        int direction_j = directions[k][1]; 

        
        int x = i + direction_i; 
        int y = j + direction_j;
        int a_trouve_adversaire = 0;

        // TANT QUE on est sur le plateau ET qu'on voit des pions adverses
        while (est_dans_plateau(x, y) && plateau[x][y] == couleur_oppose) {
            x += direction_i;      // On continue d'avancer dans la même direction
            y += direction_j;
            a_trouve_adversaire = 1; // On a bien trouvé un adversaire
        }

        // SI on s'est arrêté sur un pion de NOTRE couleur, ET qu'on avait trouvé des adversaires avant
        if (a_trouve_adversaire && est_dans_plateau(x, y) && plateau[x][y] == couleur) { 
            // Retourner les pions adverses entre (i,j) et (x,y)
            int retour_i = i + direction_i;
            int retour_j = j + direction_j;
            while (retour_i != x || retour_j != y) {
                plateau[retour_i][retour_j] = couleur; // Retourne le pion
                retour_i += direction_i;
                retour_j += direction_j;
            }
        }
    }
}
void calcul_point_actuel(int *plateau[]){
    int blanc = 0;
    int noir = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
            if(plateau[i][j]== BLACK){
                noir++;
            }
            else if(plateau[i][j]== WHITE){
                blanc++;
            }
        }
    }
    printf(" W : %d  B : %d \n",blanc,noir); 
}
int main(){
    int i;
    int j;
    char Couleur_actuelle='B';
    int tour =0;
    int temp_tour=0;

    int *othello[N];
    for (int i = 0; i < N; i++) {
        othello[i] = (int *)malloc(N * sizeof(int));
    }

    initialiser_plateau(othello);
    while(1){ // oui ici il faut mettre une condition de fin de partie mais je l'ai pas encore faite 
    affiche_othello(othello);
    calcul_point_actuel(othello);
    printf("Pion %c veuillez entrer les coordonées i et j du coup que vous voulez jouer :\n", Couleur_actuelle);
    scanf("%d %d",&i,&j);
    if(Couleur_actuelle=='B' && tour == temp_tour){
        if (verifier_legalite(othello,i,j,BLACK)){
            placer_pion(othello,i,j,BLACK);
            retourner_pions(othello,i,j,BLACK);
            Couleur_actuelle='W';
            tour++;
            }
    } 
    else{
        if (verifier_legalite(othello,i,j,WHITE)){
            placer_pion(othello,i,j,WHITE);
            retourner_pions(othello,i,j,WHITE);
            Couleur_actuelle='B';
            tour++;
            }
        }
    temp_tour = tour;
    
    }

    

    for (int i = 0; i < N; i++) {
    free(othello[i]);
    }

return 0;
}