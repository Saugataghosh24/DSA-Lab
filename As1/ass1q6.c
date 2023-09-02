#include <stdio.h>
#include <stdlib.h>
typedef struct term {
int c;
int e;
}term;
typedef struct poly {
term t[20];
int n;
}poly;
void print (poly *a, char var) {
int i;
for (i = 0; i < a->n; i++) {
if (i < a->n - 1)
printf ("%d*%c^%d + ", a->t[i].c, var, a->t[i].e);
else
printf ("%d*%c^%d", a->t[i].c, var, a->t[i].e);
}
printf ("\n");
}
void print_large(poly a) {
int i;
for (i = 0; i < a.n; i++)
printf ("%d", a.t[i].c);
}
void read (poly *a) {
int i;
printf ("Enter no. of terms: ");
scanf("%d", &a->n);
printf ("Enter the terms (coefficient and exponent): ");
for (i = 0; i < a->n; i++)
scanf ("%d %d", &a->t[i].c, &a->t[i].e);
}
void read_large (poly *a) {
        int i;
        printf ("Enter no. of digits: ");
        scanf("%d", &a->n);
        printf ("Enter the digits of the number (space-separated): ");
        for (i = 0; i < a->n; ) {
                scanf ("%d", &a->t[i].c);
if (a->t[i].c < 0 || a->t[i].c > 9) {
printf ("Invalid digit. Try again.");
continue;
}
a->t[i].e = a->n - 1 - i;
i += 1;
}
}
poly* add (poly a, poly b) {
poly *c = (poly *) malloc(sizeof(poly));   int i, j, k;
for (i = 0, j = 0, k = 0; i < a.n && j < b.n; k++) {
if (a.t[i].e == b.t[j].e) {
c->t[k].c = a.t[i].c + b.t[j].c;
c->t[k].e = a.t[i].e;
i++; j++;
}
else if (a.t[i].e > b.t[j].e) {
                        c->t[k].c = a.t[i].c;
                        c->t[k].e = a.t[i].e;
                        i++;
                }
else {
                        c->t[k].c = b.t[j].c;
                        c->t[k].e = b.t[j].e;
                        j++;
                }
}
while (i < a.n) {
c->t[k].c = a.t[i].c;
                c->t[k].e = a.t[i].e;
                i++;  k++;
}
while (j < b.n) {
c->t[k].c = b.t[j].c;
c->t[k].e = b.t[j].e;
                j++; k++;
}
c->n = k;
return c;
}
poly* add_large (poly a, poly b) {
poly *c = add(a, b);
int carry = 0, i;
for (i = c->n - 1; i >= 0; i--) {
c->t[i].c += carry;
carry = c->t[i].c/10;
c->t[i].c %= 10;
}
return c;
}
int main() {
poly a, b, *c;
read_large(&a); read_large(&b);
c = add_large(a, b);
printf ("A = ");  print_large(a);
printf (", B = ");  print_large(b);
printf ("\nA + B = ");
print_large(*c);
printf ("\n");
free(c);
return 0;
}

