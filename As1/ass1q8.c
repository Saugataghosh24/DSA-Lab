#include<stdio.h>
#define MAX_TERMS 100

typedef struct
{
  int row;
  int col;
  int value;
}term;

term a[MAX_TERMS];

void read_sparse_matrix(term []);
void print_non_zero_elements(term []);

int main()
{
  int m, n;

  printf("Enter the dimensions of the matrix: ");
  scanf("%d%d", &m, &n);
  printf("Enter the elements of the matrix:\n");
  read_sparse_matrix(a);

  print_non_zero_elements(a);

  return 0;
}

void read_sparse_matrix(term t[])
{
  int i = 0, j, n, m, num;
  printf("Enter the number of non-zero elements: ");
  scanf("%d", &n);
  printf("Enter the row, column, and value of each non-zero element:\n");
  for(j = 0; j < n; j++)
  {
    scanf("%d%d%d", &t[i].row, &t[i].col, &t[i].value);
    i++;
  }
  t[i].value = 0;
}

void print_non_zero_elements(term t[])
{
  int i, j, row_index, count[100] = {0};
  for(i = 0; t[i].value; i++)
  {
    row_index = t[i].row;
    count[row_index]++;
  }
  printf("Number of non-zero elements in each row:\n");
  for(j = 0; j < 100; j++)
  {
    if(count[j] != 0)
      printf("Row %d has %d non-zero elements\n", j, count[j]);
  }
}
