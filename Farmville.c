#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
void tab( int[]);
 
void tab( int plants[]){
  int z, x, y, d, c;
  x=lrand48()%10000;
  y=lrand48()%10000;
  if(x>=5000 && ((y>=1000 && y<=1010)||(y>=1020 && y<=1030))){
    z=1;
  }
  else{ z=0; }
  if(z==1){    
    for(c=0; c<=5000; c=(c+10)){
      if(y>=1000 && y<=1010){
        if(x>=(c+5000) && x<(c+5010)){
          plants[(c/10)]++;
        }
      }
      else{
        if(x>=(c+5000) && x<(c+5010)){
          plants[((c/10)+500)]++;
        }
      }
    }
  }
}
 
main(){
  int  i, g, plants[1000];
  float cont, y, d;
  FILE *fp;
  srand48(time(0));
  printf("Una grandine ha colpito il terreno dello Zio Tom! Fortunatamente, in 100 mq, lo Zio ha piantanto solo due file di fragole, ognuna da 500 piante ciascuna. \n");
  printf("Il programma cercherà di aiutare Tom a prevedere i danni che subiranno le piante al variare della quantità di grandine caduta.\n");
  printf("Inserisci quindi il numero di chicchi di grandine:\n g = ");
  scanf("%d", &g);
  while(g<0){
    printf("Non puoi mettere un numero negativo! Suvvia, aiutiamo lo Zio Tom!\n g = ");
    scanf("%d", &g);
  }
  for(i=0; i<1000; i++){
    plants[i]=0;
  }
  for(i=0; i<g; i++){
    tab( plants);
  }
  for(i=0; i<1000; i++){
    if(plants[i]>=3){
      cont++;
    }
  }
  printf("Le piante distrutte sono:\n %f %%", (float)cont/10);
  printf("\n");
  if((fp=fopen("fragole.dat", "w"))==NULL){
    printf("Errore nell'apertura del file fragole.dat\n");
    exit(EXIT_FAILURE);
  }
  fprintf(fp, "Le piante distrutte sono:\n");
  fprintf(fp, "\n");
  for(i=0; i<1000; i++){
    d=i;
    if(plants[i]>=3){
      if(i>=0 && i<501){
        y=10.0;
        fprintf(fp, "%d - ( %f , %f )\n", i, ((d/10)+50), y);
      }
      else{
        y=10.2;
        fprintf(fp, "%d - ( %f , %f )\n", i, (((d-501)/10)+50), y);
      }
    }
  }
}
