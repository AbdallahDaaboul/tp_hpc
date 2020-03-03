int * MultMat(int *A,int *B,int n){
  int C[n][n];
  int tmp,i,j,k=0;

  #pragma omp parallel for
  for(i = 0; i < 3; ++i) {
    for(j = 0; j < 3; ++j) {
      C[i][j] = 0;
      //#pragma omp parallel for reduce (+: C[i][j])
      for(k = 0; k < 3; ++k) {
        C[i][j] = C[i][j] + A[i][k] * B[k][j];
      }
    }
   }

  return C;
}


/*
#pragma omp parallel for reduce (+: C[i][j])
pire maniere car le mettre dans la boucle plus interne va creer et synchroniser les threads pour qu elle les
retur apres la barriere pour les recreer a la deuxieme iteration de for

#pragma omp parallel for
on a pas besoin de synchroniser ni de reduce car il partage C mais chacun va traiter une ligne de cette matrice
donc nous aurons pas de conflits de lire et ecrire


*/
