#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
int incrocio(double, double, double);
 
void media_pi(double [], double []);
 
int incrocio(double O, double x, double l){
  int y;
  if(x<=((l/2)*sin(O))){
    return y=1;
  }
  else{
    return y=0;
  }
}
 
void media_pi(double pi[], double media[]){
  int i;
  double med;
  FILE *fp;
  fp=fopen("pi.dat", "w");
  if((fp=fopen("pi.dat","w"))==NULL){
    printf("Errore nell'apertura del file pi.dat.\n");
    exit(EXIT_FAILURE);
  }
  fprintf(fp, " I valori di pi greco calcolati come pi = (2*l*n)/(t*h), sono:\n ");
  fprintf(fp, "\n");
  for(i=0; i<10; i++){
    media[i]=pi[i];
    fprintf(fp, "%lf ", pi[i]);
  }
  fprintf(fp, "\n");
  fprintf(fp, "La media dei valori è:\n");
  fprintf(fp, "\n");
  for(i=0; i<9; i++){
    media[9]+=media[i];
  }
  med=media[9]/10;
  fprintf(fp, "%lf \n", med);
}
 
main(){
  double l, t, x, O, y, pi[10], media[10];
  int n, h, i, j;
  srand48(time(0));
  printf("Il programma prende come argomento l'ago di Buffon, ovvero, dato un ago di lungezza l e un piano percorso da linee parallele a distanza t>l, si vuole calcolare la probabiltà che l'ago tocchi una di queste rette.\n");
  printf("Per fare questo ho bisogno che tu inserisca i valori di t e l - che vanno espressi in cm e devono essere minori di 3.0 - e anche n, il numero di lanci, minore di 3000.\n");
  printf("Inserisci la lunghezza dell'ago l:\n l = ");
  scanf("%lf", &l);
  while(l<0 || l>=2.9999999 ){
    printf("Il valore di l è sbagliato! Ricorda l deve essere positivo e minore di 3 cm.\n");
    printf("Reinserisci la lunghezza dell'ago l:\n l = ");
    scanf("%lf", &l);
}
  printf("Inserisci la distanza tra le rette t:\n t = ");
  scanf("%lf", &t);
  while(t<0 || t<=l || t>=3){
    printf("Il valore di t è sbagliato! Ricorda t deve essere positivo, minore di 3 cm e maggiore di l.\n");
    printf("Reinserisci la distanza tra le rette t:\n t = ");
    scanf("%lf", &t);
  }
  printf("Inserisci il numero di lanci n:\n n = ");
  scanf("%d", &n);
  while(n<0 || n>=3000){
    printf("Il valore di n è sbagliato! Ricorda n deve essere positivo e minore di 3000.\n");
    printf("Reinserisci il numero di lanci n:\n n = ");
    scanf("%d", &n);
  }
  for(j=0; j<10; j++){
    h=0;
    for(i=0; i<n; i++){
      O=((double)lrand48()/RAND_MAX)*1.74;
      x=((double)lrand48()/RAND_MAX)*t;
      y=incrocio( O, x, l);
      if(y==1){
        h++;
      }
    }
    printf("h = %d \n", h);
    pi[j]=(2*l*(double)n)/(t*(double)h);
  }
  media_pi(pi, media);
  printf("E' stato appena creato un file pi.dat nel quale viene calcolato pi greco come pi=(2*l*n)/(t*h)!\n");
}
