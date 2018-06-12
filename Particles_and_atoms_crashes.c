#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
int crash(double, double, double, int, double[], int[]);
 
int crash(double k, double x, double P, int i, double cento[], int cento_particles[]){
  int tof;
  double l=(x/k), y;
  y=l;
  for(l=(x/k); l<x; l=l+y){
    if(((double)lrand48()/RAND_MAX)<P){
      if(l<100){
        cento[i]=1;
      }
      cento_particles[i]=1;
      return tof=1;
    }
  }
  return tof=0;
}
 
main(){
  int N, i, tof, cont=0, cont_cento=0, cento_particles[10000], cont_cp=0;
  double x, k, P, cento[10000];
  FILE *fp;
  srand48(time(0));
  printf("Dato un mezzo i cui atomi sono distanti l'uno dall'altro in media l=x/k, e dove x è la larghezza del mezzo, e dato un fascio di particelle che attraversa il suddetto mezzo, sappiamo che ogni singola particella ha una certa probabilità di passare attraverso l'oggetto.\n");
  printf("Questo discorso può essere esteso a tutto il fascio e si avranno particelle che continuano il loro percorso e particelle che urtano elasticamente gli atomi e che quindi tornano indietro.\n");
  printf("Il programma calcolerà la frazione di particelle che riesce a continuare il proprio percorso, e per farlo è necessario che tu inserisca i seguenti valori:\n");
  printf("Inserisci il numero N di particelle del fascio strettamente compreso tra 0 e 10000:\n N = ");
  scanf("%d", &N);
  while(N<=0 || N>=10000){
    printf("Il valore di N è sbagliato! Reimmettilo!\n N = ");
    scanf("%d", &N);
  }
  printf("Inserisci lo spessore x del mezzo strettamente compreso tra 0 e 3:\n x = ");
  scanf("%lf", &x);
  while(x<=0 || x>=3){
    printf("Il valore di x è sbagliato! Reimmettilo!\n x = ");
    scanf("%lf", &x);
  }
  printf("Inserisci il fattore k compreso positivo e minore uguale a 10000:\n k = ");
  scanf("%lf", &k);
  while(k<=0 || k>10000){
    printf("Il valore di k è sbagliato! Reimmettilo!\n k = ");
    scanf("%lf",&k);
  }
  printf("Inserisci la probabilità d'urto P strettamente compresa tra 0 e 0.15:\n P = ");
  scanf("%lf", &P);
  while(P<=0 || P>=0.15){
    printf("Il valore di P è sbagliato! Reimmettilo!\n P = ");
    scanf("%lf", &P);
  }
  for(i=0; i<N; i++){
    cento[i]=0;
    cento_particles[i]=0;
  }
 
  for(i=0; i<N; i++){
    tof=crash(k, x, P, i, cento, cento_particles);
    if(tof==0){
      cont++;
    }
    if(cento[i]==0){
      cont_cento++;
    }
  }
  if((fp=fopen("particles.dat", "w"))==NULL){
    printf("Errore nell'apretura del file particles.dat\n");
    exit(EXIT_FAILURE);
  }
  fp=fopen("particles.dat", "w");
  fprintf(fp, "Le prime 100 particelle che hanno rimbalzato sono:\n");
  for(i=0; i<N; i++){
    if(cont_cp<=100){
      if(cento_particles[i]==1){
        fprintf(fp, "%d \n", i);
      }
    }
    cont_cp++;
  }
  printf("Sono riuscite a passare %d particelle, cioè %g di N.\n", cont, ((double)cont/N));
  printf("\n");
  printf("Sono riuscite a superare i primi 100 passi %d particelle, cioè %g di N.\n", cont_cento, ((double)cont_cento/N));
  printf("\n");
}
