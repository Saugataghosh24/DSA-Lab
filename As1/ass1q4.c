#include <stdio.h>
#include <math.h>

struct Term {
  int coeff;  
  int exp;    
};

int main() {
  struct Term terms[100];  
  int num_terms;           
  int x;                   
  int i;                   
  int result = 0;          

  printf("Enter the number of terms: ");
  scanf("%d", &num_terms);
  printf("Enter the value of x: ");
  scanf("%d", &x);

  printf("Enter the coefficients and exponents: \n");
  for (i = 0; i < num_terms; i++) {
    scanf("%d %d", &terms[i].coeff, &terms[i].exp);
  }

  for (i = 0; i < num_terms; i++) {
    result += terms[i].coeff * pow(x, terms[i].exp);
  }

  printf("Result = %d\n", result);

  return 0;
}
