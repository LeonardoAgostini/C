#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
void distanza(double[][3], double[]);
 
void distanza(double pos[][3], double distance[]){
  int i;
  FILE *fp;
  if((fp=fopen("distanza.dat", "w"))==NULL){
    printf("Errore nell'apertura di distanza.dat");
    exit(EXIT_FAILURE);
  }
  fp=fopen("distanza.dat", "w");
  fprintf(fp,"Distanze degli atomi\n");
  fprintf(fp,"\n");
  for(i=0; i<500; i++){
    distance[i]=sqrt(pow(pos[i][0],2)+pow(pos[i][1],2)+pow(pos[i][2],2));
    fprintf(fp,"%d - x = %lf                y =%lf                 z=%lf\n", i,pos[i][0],pos[i][1],pos[i][2]);
  }
}
 
 
main(){
  int R=1, i, j, cont=0;
  double R1, R2, pos[500][3], distance[500], data[500], temp;
  srand(time(0));
  printf("Dato un gas perfetto composto da 500 atomi racchiusi in una sfera di raggio R = 1, vogliamo calcolare quanti atomi sono racchiusi in due sfere di raggio R1 e R2 entrambi minori di R.\n");
  printf("Per fare questo ho bisogno che tu inserisca i valori di R1 e R2. Attenzione deve valere questa affermazione : R1 < R2 < R.\n");
  printf("Inserisci R1.\n R1 = ");
  scanf("%lf", &R1);
  printf("\n");
  printf("Inserisci R2.\n R2 = ");
  scanf("%lf", &R2);
  printf("\n");
  while(R1>R2 || R1>R || R2>R){
    printf("Hai sbagliato i valori dei raggi! Reinseriscili!\n");
    printf("R1 = ");
    scanf("%lf", &R1);
    printf("R2 = ");
    scanf("%lf", &R2);
  }
  for(i=0; i<500; i++){
    for(j=0; j<3; j++){
      pos[i][j]=(double)lrand48()/RAND_MAX;
      while(pos[i][j]>=1){
        pos[i][j]=(double)lrand48()/RAND_MAX;
      }
    }
  }
  distanza(pos, distance);
  for(i=0; i<500; i++){
    data[i]=distance[i];
  }
  for( i=0; i<499; i++ ){
    for( j=499; j<i; j--){
      if(data[j-1]>data[j]){
        temp=data[j-1];
        data[j-1]=data[j];
        data[j]=temp;
      }
    }
  }
 
  for(i=0; i<500; i++){
    if(data[0]==distance[i]){
      printf("L'atomo con distanza minore è quello di cordinate:\n x = %g\n y = %g\n z = %g\n", pos[i][0], pos[i][1], pos[i][2]);
    }
   if(data[499]==distance[i]){
      printf("L'atomo con distanza maggiore è quello di cordinate:\n x = %g\n y = %g\n z = %g\n", pos[i][0], pos[i][1], pos[i][2]);
    }
   if(distance[i]>=R1 && distance[i]<=R2){
     cont++;
   }
  }
 
  printf("Gli atomi che hanno distanza compresa tra R1 = %g e R2=%g sono %f del totale.\n", R1, R2, (float)cont/500);  
}
