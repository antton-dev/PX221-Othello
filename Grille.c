#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h> 
#include <errno.h>

#define N 8 
#define BLACK 0 
#define WHITE 1 
#define EMPTY 2 
#define ILLEGAL -1

void intitialiser_plateau(*plateau[]) {
    for (int i=0; i<=7; i++) {
        for (int j=0; j=7; j++) {
            plateau[i][j] = EMPTY;
        }
    }

    // init situation de depart

    plateau[3][3] = WHITE;
    plateau[4][4] = WHITE;

    plateau[4][3] = BLACK;
    plateau[3][4] = BLACK;
}


int statut_case(int *plateau[],int i,int j) {
    for(int i=0; i<2; i++){
        if (plateau[i][j] == i) {
            return i; // retourne ce qu'il y a dans la case
        }
    }
}

void placer_pion(int *plateau[],int i,int j,int couleur){
    plateau[i][j]=couleur;
}

int adjacents(*plateau[], int i, int j) {
    int t_adjacents[2][2];
    int m, n;
    m=0;
    for(int k=i-1; k<=i+2; k++) {
        n=0;

        for(int l=j-1; l<=j+2; l++){
            t_adjacents[m][n] = plateau[k][l];
            n++;
        }
        m++;
    }

    return t_adjacents;
}

/* int verifier_legalite(int *plateau[],int i,int j,int couleur){
    int couleur_oppose = (couleur+1)%2; // inverser la couleur
    int couleur_adjacente_oppose = 0; // si y'a une couleur opposé à coté mettre à 1
    int position_adjacente[8] = [0,0,0,0,0,0,0,0,0]; // savoir quel vecteur faire mais ignorer l'indice 4 
    int valide = 0; // si on peut manger 
    if((i >= 0 && i <= 7) && (j >= 0 && j <= 7)){ // si on est sur le plateau 
        if(statut_case( plateau[], i, j)== EMPTY){ //si la case est vide 
            int t_adjacents[2][2] = adjacents(plateau[], i, j); // on recupere le tableau d'adjacence
            for(int m=0; m<=2; m++){ // on le parcourt
                for(int n=0; n<=2; n++){
                    if(t_adjacents[m][n]==couleur_oppose){ 
                        couleur_adjacente_oppose =1 ;
                        position_adjacente[m+n]=1;
                        if()


                    }
                }
            }
            if(couleur_adjacente_oppose){


            }
                    
        }
    } */



return valide;
}





int main(){
    int * othello[N][N];


return 0;
}