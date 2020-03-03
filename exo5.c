double R= malloc
double T= malloc
int convergence=0

while(!convergence){
  #pragma omp parallel for
  for(int k=0, k<sigma,k++){
    int N=k*n*m;
    do-xy-plane(TRNnmsigmak)
  }
  <test conv>
  <echange T et R>
  t=t+dt;
}
