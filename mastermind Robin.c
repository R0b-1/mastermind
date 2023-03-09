#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int valeur(int couleur)
{
    if (couleur == 1)
    {
        printf("rouge");
    }
    else if (couleur == 2)
    {
        printf("bleu");
    }
    else if (couleur == 3)
    {
        printf("vert");
    }
    else if (couleur == 4)
    {
        printf("jaune");
    }
    else if (couleur == 5)
    {
        printf("orange");
    }
    else if (couleur == 6)
    {
        printf("violet");
    }
    else
    {
        printf("couleur invalide");
    }
}

int main()
{
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

   int code[4];
    printf("Code secret : ");
    for (int i = 0; i < 4; i++)
    {
    int couleur;
    do
    {
        couleur = rand() % 6 + 1;
    } while (couleur == code[0] || couleur == code[1] || couleur == code[2] || couleur == code[3]);
    code[i] = couleur;
    printf("%d ", code[i]);
    }
    printf("\n");


    // Début du jeu
    int tentatives = 0;
    while (tentatives < 10)
    {
        // Lecture de la tentative de l'utilisateur
        int tentative[4];
        printf("Entrez votre tentative (4 chiffres de 1 a 6) : ");
        scanf("%d%d%d%d", &tentative[0], &tentative[1], &tentative[2], &tentative[3]);
        while (getchar() != '\n');


        // Vérification de la tentative
        int correctes = 0;
        int proches = 0;
        int codeCount[6] = {0};
        int nbrTentatives[6] = {0};
        for (int i = 0; i < 4; i++)
        
        {
            for (int j = 0; i < 4; j++){

            
            if (tentative[i] == code[j])
            {
                correctes++;
            }
            else
            {
                codeCount[code[i] - 1]++;
                nbrTentatives[tentative[i] - 1]++;
            }
        }}
        for (int i = 0; i < 6; i++)
        {
            proches += (codeCount[i] < nbrTentatives[i]) ? codeCount[i] : nbrTentatives[i];
        }
        proches -= correctes;

        // Affichage des résultats de la tentative
        for (int i = 0; i < correctes; i++)
        {
            printf("w");
        }
        for (int i = 0; i < proches; i++)
        {
            printf("r");
        }
        for (int i = 0; i < 4 - correctes - proches; i++)
        {
            printf(".");
        }
        printf("\n");

        // Vérification de la victoire
        if (correctes == 4)
        {
            printf("Bravo, vous avez trouvé le code secret en %d tentatives !\n", tentatives + 1);
            return 0;
        }

        // Incrément du nombre de tentatives
        tentatives++;
    }

    // Affichage de la défaite
    printf("Perdu,\nLe code secret était : ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", code[i]);
    }
    printf("\n");

    return 0;
}


// void rangementator(int tab[4]){
//     int i;
//     srand( time( NULL ) );
//     i = rand() %4;
//     for(int i=0; i<4; i++){
//         tab[i] = 5;
//     }
//     printf("Saisissez 1 chiffre compris entre 0 et 2\n ");
//     scanf("%d", &tab[i]);
//     printf("Voici le tableau avec la valeur :\n");
//     for(int i=0; i<4; i++){
//         if(tab[i] == 5){
//         printf("|--|");
//         }
//         else{
//             printf("%d ", tab[i]);
//         }
//     }
//     printf("\n");
// }


// void validator(int tab[4], int tab2[4]){
//     printf("Tableau de saisie :\n");
//     for (int i = 0; i < 4; i++) {
//         printf("%d ", tab[i]);
//     }
//     printf("\n");

//     printf("Tableau de rangementator :\n");
//     for (int i = 0; i < 4; i++) {
//         printf("%d ", tab2[i]);
//     }
//     printf("\n");
// }

