#include <stdio.h>
#define fore(i, l, r) for (int(i) = (l); (i) < (r); (i)++)

void leer_mtrz(int m, int n, int matrix[m][n]) {
    fore(i, 0, m) {
        fore(j, 0, n) {
            scanf("%d", &matrix[i][j]);
        }
    }
}
void suma_mtrz(int m1, int n1, int a[m1][n1], int m2, int n2, int b[m2][n2]) {
    if (m1 == m2 && n1 == n2) {
        fore(i, 0, m1) {
            fore(j, 0, n1) {
                printf("%d ", a[i][j] + b[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("las matrices no son de las mismas dimensiones\n");
    }
}

void resta_mtrz(int m1, int n1, int a[m1][n1], int m2, int n2, int b[m2][n2]) {
    if (m1 == m2 && n1 == n2) {
        fore(i, 0, m1) {
            fore(j, 0, n1) {
                printf("%d ", a[i][j] - b[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("las matrices no son de las mismas dimensiones\n");
    }
}

void mult_matriz(int m1, int n1, int a[m1][n1], int m2, int n2, int b[m2][n2]) {
    if (n1 == m2) {
        fore(i, 0, m2) {
            fore(j, 0, n1) {
                int r = 0;
                fore(l, 0, m2) {
                    r += a[i][l] * b[l][j];
                }
                printf("%d ", r);
            }
            printf("\n");
        }
    } else {
        printf("no es posible con esas dimensiones, las filas de A deben ser igual a las columnas de B\n");
    }
}
void div_matriz(int m1, int n1, int a[m1][n1], int m2, int n2, int b[m2][n2]){
  //multiplicacion de matriz por inversa de otra matriz
}
void traspuesta(int m, int n, int a[m][n]){
  printf("la matriz resultante es \n");
  fore(i,0,n)
  {
    fore(j,0,m)
    {
      printf("%d ",a[j][i]);
    }
    printf("\n");
  }
}

int main() {
    while (1) {
        char op;
        printf("escribe el signo de la operación a realizar\n + para suma\n - para resta\n * para multiplicación\n / para división\n t para traspuesta\n x para salir\n");
        scanf(" %c", &op);
      
        int m1, n1, m2, n2;
        printf("ingresa el tamaño de tu matriz A\n ejemplo: 3 2\n");
        scanf("%d %d", &m1, &n1);

        int a[m1][n1];
        leer_mtrz(m1, n1, a);

        int b[0][0];
        if (op != 't') {
            printf("ingresa el tamaño de tu matriz B, como lo hiciste con A\n");
            scanf("%d %d", &m2, &n2);
            b[m2][n2];
            leer_mtrz(m2, n2, b);
        }

        switch (op) {
            case '+':
                suma_mtrz(m1, n1, a, m2, n2, b);
                break;
            case '-':
                resta_mtrz(m1, n1, a, m2, n2, b);
                break;
            case '*':
                mult_matriz(m1, n1, a, m2, n2, b);
                break;
            case '/':
                div_matriz(m1, n1, a, m2, n2, b);
                break;
            case 't':
              traspuesta(m1, n1, a);
                break;
            case 'x':
          return 0;
            default:
                printf("no es una opción válida\n");
        }
    }

    return 0;
}
