#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Deadline 
{
int jour;
int mois;
int année;
}
Deadline;
 
typedef struct 
{
    int identifiant ;
    char titre[100];
    char discription[100];
    char status[100];
    struct Deadline deadline;
}tache;
tache t[100];
int number=0;
int choix;
char status[30];


 void ajouter_tache(int nu){
   
    for (int i=0;i<nu ; i++)
    { 
    int id;
    int exist =0;
    
    
    printf("entrer l edentifiant ");
    scanf("%d", &id);
    for(int j=0;j<number;j++){
    if(t[j].identifiant== id){
        printf("cette tache déjà ajoutée");
        exist = 1;
        break;
    }
    }
    if(exist){
        i--;
        continue;
    }
    
    
    t[number].identifiant = id;
    printf("titre\n");
    scanf("%s",t[number].titre);
    printf("discription \n");
    scanf("%s",t[number].discription); printf("Status (réaliser,  réalisation, finalisée) : ");
            scanf(" %s", t[number].status);

   /*int valid_status = 0;
        while (!valid_status) {
           
            scanf(" %s", status);
            if (strcmp(status,"réaliser") == 0 ||
                strcmp(status,"réalisation") == 0 ||
                strcmp(status,"finalisée") == 0) {
                valid_status = 1;
                strcpy(t[number].status, status);
            } else {
                printf("Statut invalide. Veuillez réessayer.\n");
            }
            
        }*/
    printf("entre le jour de deadline  \n");
    scanf("%d",&t[number].deadline.jour);
    printf("entre le mois de deadline  \n");
    scanf("%d",&t[number].deadline.mois);
    printf("entre l'annee de deadline  \n");
    scanf("%d",&t[number].deadline.année);
    number++;
    }
    }



void trier_affi() {
    tache temp;
    for (int i = 0; i < number - 1; i++) {
        for (int j = 0; j < number - i - 1; j++) {
            if (strcmp(t[j].titre, t[j + 1].titre) > 0) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
} 
void Afficher()
{
    for (int i = 0;i<number ;i++){
    printf("les taches nmr %d \n",i+1);
    printf("%d,%s,%s,%s,%d,%d,%d\n",t[i].identifiant,t[i].titre,t[i].discription,t[i].status,
    t[i].deadline.jour,t[i].deadline.mois,t[i].deadline.année);
    }
}    
void modification(){
    int ID ;
    int ch;
    tache modific [100];
    printf("entre l'identifiant que vous avez modifier");
    scanf("%d \n",&ID);
    for(int j=0 ;j<number ;j++){
    for(int j=0 ;j<number ;j++){
        if(t[j].identifiant,ID  == 0){
            printf("si tu peux modifier la discription tapper 1\n");
            printf("si tu peux modifier la discription tapper 2\n");
            printf("si tu peux modifier la discription tapper 3\n");
            scanf("%d",&ch);
            if(ch==1){
                printf("donne la nouvelle modification");
                scanf("%s",modific);
                
            }
        }
    }
    }


}

 int main(){
    

  do {
        printf("\nMenu:\n");
        printf("1. Ajouter une tâche\n");
        printf("2. Afficher les tâches\n");
        printf("3. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
            int n;
            printf("donner moi le nombre de les taches");
            scanf("%d",&n);
                ajouter_tache(n);
                break;
            case 2:

           
            trier_affi();
                Afficher();
                break;
                 case 3:
                modification();
                break;
            case 4:
                printf("Quitter le programme.\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 3);

    
 }


 