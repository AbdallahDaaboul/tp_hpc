unsigned char ima=malloc...

#pragma omp parallel for schedule(dynamic)
for(inr i=0, i<k,i++){
  double y = ymin + i*yinc;
  double x=xmin;
  for (size_t j = 0; j < w; j++) {
    ima[j+i*w]=xy2color(x,y);
    x+=xinc;
  }
  y+=yinc;
}


/*

#pragma omp parallel for schedule(dynamic)
maitre esclave
*/
