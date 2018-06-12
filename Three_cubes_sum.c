        #include<stdio.h>
        #include<stdlib.h>
        #include<math.h>
       
        int functionC(int);
 
void min_max(int*, int);
 
void min_max( int *numeriC, int N){
          int *po, *pp;
          po=numeriC;
            while(*po==0){
              po++;
              numeriC[0]=*po;
            }
            pp=numeriC+N-1;
            while(*pp==0){
              pp--;
              numeriC[N-1]=*pp;
            }
            printf("Il minimo è %d \n", numeriC[0]);
            printf("Il massimo è %d \n", numeriC[N-1]);
        }
       
       
        int func_C(int n){
          int  x, a, b, c;
          for( a=1; a<n; a++){
            for( b=1; b<n; b++){
              for( c=1; c<n; c++){
                if(n==(pow(a,3)+pow(b,3)+pow(c,3))){
                  x=1;
                  return x;
                }
              }  
            }
          }
        x=0;
        return x;
        }
       
        main(){
          int N, i, numeriC[1000], x, n, a;
          printf("Questo programma trova i numeri interi minori di un numero  N costituiti da somma dei cubi di altri tre numeri  interi\n");
          printf("Per fare questo è necessario che te inserisca un N minore di 1000\n");
          scanf("%d", &N);
          for(n=0; n<N; n++){
            x=func_C(n);
            if(x==1){
              numeriC[n]=n;
            }
            else{ numeriC[n]=0;}
          }
          for(i=0; i<N; i++){
            if(numeriC[i]!=0){
            printf("%d ", numeriC[i]);
            }
          }
          printf("\n");
          min_max(numeriC, N);
         }     
