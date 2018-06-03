#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int passo_rana(int);

int passo_rana(int pace){
  int x, step;
  x = lrand48()%2;
  if( x==0 ){
    step=2;}
  else{
    step=-1;
  }
  printf("La rana si trova al gradino %d. \n", pace);
  return step;
}

main(){
  int N, tempo, pace, new, x, jumped[1000], not_jumped[1000], i, c;
  srand48(time(0));
  printf("Questo programma calcola il tempo che una rana impiega a salire una scala a chiocciola di N gradini\n");
  printf("Immetti il numero di gradini, tenendo conto che questi devono essere maggiori o uguali di 100 e minori e uguali di 1000.\n N = ");
  scanf("%d", &N);
  while( (N<100) || (N>1000) ){
    printf("Il numero inserito e' errato! Reinserisci N.\n N = ");
    scanf("%d", &N);}
  for( i=0; i<1000; i++){
    *(not_jumped+i)=0;
    *(jumped+i)=0;
  }
  pace=0;
  for( tempo=0; pace<N; tempo++){
    x = passo_rana(pace);
    new=pace+x;
    if(new<0)
      {}
    else{
      pace=new;}
    (*(not_jumped+pace))++;
  }
  printf("\n");
  printf("La rana impiega %d istanti a salire la scala.\n", tempo);
  c=0;
  for(i=0; i<N; i++){
    if( *(not_jumped+i)==0){
      *(jumped+i)=1;
    }
  } 
  for(i=0; i<N; i++){
    if(*(jumped+i)==1){
      printf("%d ", i);}
  }
  printf("\n");
}

