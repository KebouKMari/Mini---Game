#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int main()
{
 int MAX=0;
 const int MIN=1;
 short int niveau;
 int nombreMystere,nombre,compteur=1;
 short int continuerPartie=1;
 short int rejouer=1;

 do{

      printf("|-------------------------------------------------------------|\n");
      printf("|*************************JEU PLUS/MOINS *********************|\n");
      printf("|-------------------------------------------------------------|\n\n");
      printf("1.Entre 1 et 100\n");
      printf("2.Entre 1 et 1000\n");
      printf("3.Entre 1 et 10000\n\n");
      printf("Choissisez votre niveau ::");
      scanf("%d",&niveau);     // Choix du niveau de jeu
        switch(niveau){
        case 1:
            MAX=100;
            break;
        case 2:
            MAX=1000;
            break;
        case 3:
            MAX=10000;
            break;
        default:
            printf("\nEntrez votre niveau de jeu soit 1,2 ou 3\n");
          }

         while(niveau==1 || niveau==2 || niveau==3){        // On continue le jeu si on entre un niveau valide
         short int choix;
         printf("\n");
         printf("1.Mode monojoeur\n");
         printf("2.Mode deux joueurs\n\n");
         printf("Entrez le mode qui vous convient::");
         scanf("%d",&choix);     // choix du mode
         printf("\n");

         switch(choix){
            case 1:  // mode monojoueur
                  do{
                     srand(time(NULL));
                     nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
                     printf("Quel est le nombre:: ");
                     scanf("%d",&nombre);
                 while(nombre<1 || nombre>MAX){         // si le nombre n 'est pas la marge du niveau choisi,il reessaie encore
                    printf("Le mot mystere est compris entre 1 et %d\n",MAX);
                    compteur=compteur+1;               // on augment le nombre de tours
                    printf("Quel est le nombre:: ");
                    scanf("%d",&nombre);
                    }

                 if(nombre==nombreMystere){            // S'il trouve le mot mystere un seul essai
                    printf("Bravo, tu as devine le mot mystere !!! en %d nombre d'essais. Tu es un Genie :)\n\n",compteur);
                    compteur=1;
                 }
                 else{            //sinon

                    do{

                        if(nombreMystere>nombre){
                            printf("C'est plus\n");
                        }
                        if (nombreMystere<nombre){
                            printf("C'est moins\n");
                        }

                        compteur=compteur+1;
                        printf("Quel est le nombre:: ");
                        scanf("%d",&nombre);
                        while(nombre<1 || nombre>MAX){
                            printf("le mot mystere est compris entre 1 et %d\n",MAX);
                            compteur=compteur+1;
                            printf("Quel est le nombre:: ");
                            scanf("%d",&nombre);
                        }

                    }while(nombre!=nombreMystere);

                     if(nombre==nombreMystere){
                        printf("Bravo, tu as devine le mot mystere !!! en %d nombre d'essais\n",compteur);
                        compteur=1;
                      }
                    }
                   //demande a l'utilisatuer s'il  continue la partie.
                  printf("\nVeux- tu continuer cette partie ? (1(Oui)/0(Non))::");
                  scanf("%d",&continuerPartie);


          }while(continuerPartie==1);

         // si l'utilisatuer ne continue pas la partie
         if(continuerPartie!=1){
            printf("\n");
            printf("Merci d'avoir jouer avec nous.\n");
             niveau=-1;
         }
         break;
        case 2: // mode deux joueurs
            do{
                 char strNum[5];
                 printf("Entrez le nombre mystere ::");
                 sprintf(strNum, "%d", nombreMystere);
                 int p=0;
                    //boucle qui masque le nombre entre par le second joueur
                    do{
                        strNum[p]=getch();
                        if(strNum[p]!='\r'){
                            printf("*");
                        }
                        p++;
                    }while(strNum[p-1]!='\r');
                    strNum[p-1]='\0';
                     nombreMystere = atoi(strNum);   // transforme une chaine en entier
                     printf("\n");
                     printf(" Quel est le nombre:: ");
                     scanf("%d",&nombre);
                     while(nombre<1 || nombre>MAX){   // si le nombre n 'est pas la marge du niveau choisi,il reessaie encore
                        printf("Le mot mystere est compris entre 1 et %d\n",MAX);
                        compteur++;
                        printf("Quel est le nombre:: ");
                        scanf("%d",&nombre);
                     }

                 if(nombre==nombreMystere){             // S'il trouve le mot mystere un seul essai
                     printf("\nBravo, tu as devine le mot mystere !!! en %d nombre d'essais. Tu es un Genie :)\n",compteur);
                     compteur=1;
                 }

                 else{

                     do{

                            if(nombreMystere>nombre){
                                printf("C'est plus\n");
                                compteur=compteur+1;
                            }
                            if (nombreMystere<nombre){
                                printf("C'est moins\n");
                                compteur=compteur+1;
                            }

                             printf("Quel est le nombre:: ");
                             scanf("%d",&nombre);
                            while(nombre<1 || nombre>MAX){
                                printf("le mot mystere est compris entre 1 et %d\n",MAX);
                                compteur=compteur+1;
                                printf("Quel est le nombre:: ");
                                scanf("%d",&nombre);
                            }

                     }while(nombre!=nombreMystere);

                        if(nombre==nombreMystere){
                            printf("\nBravo, tu as devine le mot mystere !!! en %d nombre d'essais\n",compteur);
                            compteur=1;
                        }
                    }
                  printf("\nVeux-tu continuer cette partie ? (1(Oui)/0(Non))::");
                  scanf("%d",&continuerPartie);
                  printf("\n");


            }while(continuerPartie==1);

             if(continuerPartie!=1){
                printf("Merci d'avoir jouer\n");
                niveau=-1;
             }
                break;
                // si l'utilisateur n'entre ni 1 ou 2 pour le mode de jeu
             default:
                printf("\nEntrez soit 1 ou 2 pour Jouer \n");
         }

        }
        // Demande a l'utilisateur de relancer le jeu
        printf("\nVoulez-vous Rejouer ??? Tapez 1 pour Oui et 0 pour Non ::");
        scanf("%d",&rejouer);
    }while(rejouer==1);

    if(rejouer!=1){   // l'utilisateur refuse de jouer encore.
        printf("\nAurevoir Amigo !!!\n");
    }

    return 0;
 }
