#include <stdio.h>
#include <omp.h>

int main(){

// c'est pas une bonne idee de faire ca en TD. Tu le feras demain ! -- C Bouillaguet

double pi=0;
int N=1000000000;
//parallel: paralleliser
//le for dit qu il vont se repartir la boucle
//+pi dit qu il y aura une valeur prive pour chaque processus
//et a la fin il somme tout les pi
//on aura un equilibrage de charges statique
//si je met pas le reduction la variable sera pas prive et chacun essayera de lire et d ecrire
#pragma omp parallel for reduction (+:pi)
  //1pragma omp parallel for
for (size_t i = 0; i < N; i++) {
  //1pragma omp atomic update
  //1pragma omp capture
  //1pragma omp critical
  pi += 4 / ( 1 + ( (i*1.0/N)*(i*1.0/N) ) ) ;
}

pi=pi/N;

printf("%lf\n",pi );
return 0;
}



/*
je n ai pas le droit d ecrire atomique devant un if
normalement on l ecrire devant une instruction binaire + * - /
lire ecrire


//1pragma omp capture
comme c je fais a=x; a+= je prend la valeur et je la changeD

//1pragma omp critical
On met un veroue pour les  autres processus qui ne pourront plus acceder a la variable du coup
c est pareille a un code sequentiel chacun va attendre son predecesseur

*/
