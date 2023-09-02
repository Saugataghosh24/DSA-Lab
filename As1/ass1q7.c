#include<stdio.h>
#define MAX_TERMS 100

typedef struct
{
  int row;
  int col;
  int value;
}term;

term a[MAX_TERMS];
term b[MAX_TERMS];
term c[MAX_TERMS];

void read_sparse_matrix(term []);
void print_sparse_matrix(term []);
void add_sparse_matrix(term [], term [], term []);

int main()
{
  int m, n;

  printf("Enter the dimensions of the first matrix: ");
  scanf("%d%d", &m, &n);
  read_sparse_matrix(a);

  printf("Enter the dimensions of the second matrix: ");
  scanf("%d%d", &m, &n);
  read_sparse_matrix(b);

  add_sparse_matrix(a, b, c);

  printf("The sum of the two matrices is:\n");
  print_sparse_matrix(c);

  return 0;
}

void read_sparse_matrix(term t[])
{
  int i = 0, j, n, m, num;
  printf("Enter the number of non-zero elements: \n");
  scanf("%d", &n);
  printf("Enter the row, column, and value of each non-zero element:\n");
  for(j = 0; j < n; j++)
  {
    scanf("%d%d%d", &t[i].row, &t[i].col, &t[i].value);
    i++;
  }
  t[i].value = 0;
}

void print_sparse_matrix(term t[])
{
  int i;
  for(i = 0; t[i].value; i++)
  {
    printf("%d\t%d\t%d\n", t[i].row, t[i].col, t[i].value);
  }
}

void add_sparse_matrix(term a[], term b[], term c[])
{
  int i = 0, j = 0, k = 0;
  while(a[i].value && b[j].value)
  {
    if(a[i].row < b[j].row)
      c[k++] = a[i++];
    else if(a[i].row > b[j].row)
      c[k++] = b[j++];
    else
    {
      if(a[i].col < b[j].col)
        c[k++] = a[i++];
      else if(a[i].col > b[j].col)
        c[k++] = b[j++];
      else
      {
        c[k] = a[i];
        c[k++].value = a[i++].value + b[j++].value;
      }    }
  }
  while(a[i].value)
    c[k++] = a[i++];
  while(b[j].value)
    c[k++] = b[j++];
  c[k].value = 0;
}

