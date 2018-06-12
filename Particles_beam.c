#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
void coordinate_N(double *, double *, int);
 
void coordinate_N(double x[], double y[], int N){
  int i;
  for(i=0; i<N; i++){
    x[i]=((double)lrand48()/RAND_MAX)*2-1.;
    y[i]=((double)lrand48()/RAND_MAX)*2-1.;
  }
}
 
 
main(){
  int N1, N2, R=1, cont=0, lim, i, j;
  double r, x1[1000], y1[1000], x2[1000], y2[1000], cento;
  FILE *fp;
  srand48(time(0));
  printf("Il programma simula una collisione tra due fasci di particelle pensati come cerchi di raggio uno, contenenti un certo numero di elementi\n");
  printf("Per fare questo, però, ho bisogno che tu inserisca il numero N1 di particelle del primo fascio, il numero N2 di particelle del secondo fascio e un numero r minore di 0,0625.\n");
  printf("\n");
  printf("Inserisci N1.\n N1 = ");
  scanf("%d", &N1);
  while( N1<0 || N1>=1000 ){
    printf("Il numero di N1 è negativo o troppo elevato. Riscrivilo, tenendo conto che 0<N1<1000!\n N1 = ");
  scanf("%d", &N1);
  }
  printf("Inserisci N2.\n N2 = ");
  scanf("%d", &N2);
  while( N2<0 || N2>=1000 ){
    printf("Il numero di N2 è negativo o troppo elevato. Riscrivilo, tenendo conto che 0<N1<1000!\n N2 = ");
    scanf("%d", &N2);
  }
  printf("Inserisci r.\n r = ");
  scanf("%lf", &r);
 while( r<0 || r>0.0625 ){
    printf("Il numero di r è negativo o troppo elevato. Riscrivilo, tenendo conto che 0<r<0,0625!\n r = ");
    scanf("%lf", &r);
  }
 
 coordinate_N(x1, y1, N1);
 coordinate_N(x2, y2, N2);
 
 for(i=0; i<N2; i++){
   lim=0;
   for(j=0; j<N1; j++){
      if(sqrt(fabs(pow((y2[i]-y1[j]),2)+pow((x2[i]-x1[j]),2)))<=r && lim<1){
       printf("La particella %d del fascio di particelle numero 2 ha effettuato una collisione contro la particella %d del primo fascio. \n", i,j);
       printf("\n");
       cont++;
       lim++;
     }
   }
 }
 printf("E' stato raggiunto il seguente numero di collisioni:\n %d\n", cont);
 cento=(cont*100.)/N2;
 printf("Il %g per cento di particelle del secondo fascio ha subito una collisione", cento);
 
 fp = fopen("beam1.dat", "w");
 if((fp=fopen("beam1.dat", "w"))==NULL){
   printf("Errore nell'apertura del file beam1.dat \n");
   exit(EXIT_FAILURE);
 }
 fprintf(fp, "Coordinate del primo fascio: \n" );
 for(i=0; i<N1; i++){
   fprintf(fp, " %d  x = %g                  y = %g \n", i,x1[i],y1[i]);
 }
 fprintf(fp, "\n");
 fprintf(fp, "Coordinate del secondo fascio: \n" );
 for(i=0; i<N1; i++){
   fprintf(fp, " %d  x = %g                  y = %g \n", i,x2[i], y2[i]);
 }
}
