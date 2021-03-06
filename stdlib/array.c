#include"liml.h"

lvalue liml_array_make(lvalue size__, lvalue call__, lvalue f){
  lvalue size = (lvalue) size__ ;
  lvalue (*call)(lvalue, lvalue) = 
    (lvalue (*)(lvalue, lvalue)) call__ ;
  lvalue i ;
  lvalue* t = malloc(sizeof(lvalue) * (size + 1)) ;
  *t = size ;
  t++ ;
  
  for(i = 0 ; i < size ; i++){
    t[i] = call(f, i) ; 
  }

  return (lvalue)t ;
}

lvalue liml_array_ifmake(lvalue size, lvalue n){
  lvalue i ;
  lvalue* res = malloc(sizeof(lvalue) * (size + 1)) ;
  *res = size ;
  res++ ;
  for(i = 0 ; i < size ; i++){
    res[i] = n ;
  }

  return (lvalue)res ;
}

lvalue liml_array_length(lvalue t__){
  lvalue* t = (lvalue*) t__ ;
  return (lvalue)*(t-1) ; 
}

lvalue liml_array_release(lvalue call__, lvalue f, lvalue t__){
  lvalue* t = (lvalue*) t__ ;
  lvalue(*call)(lvalue, lvalue) = (lvalue(*)(lvalue,lvalue)) call__ ;
  lvalue i ;
  lvalue size = *(t-1) ;

  for(i = 0 ; i < size ; i++){
    call(f, t[i]) ;
  }
  free(t-1) ;
  return 0;
}

lvalue liml_array_ifrelease(lvalue t__){
  lvalue* t = (void*) t__;
  free(t-1) ;
  return 0;
}
