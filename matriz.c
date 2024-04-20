#include <stdio.h>
#define fore(i, l, r) for (int(i) = (l); (i) < (r); (i)++)
#define debug(x) printf(#x ": %d\n", x)


int main() {
  while(1){

    char op;
    printf("escribe el signo de la operación a realizar \n + para suma \n - para resta\n * para multiplicación\n / para division \n t para traspuesta \n x para salir\n");
    scanf(" %c",&op);
    if (op=='x')
      return 0;
    if (op != 't' && op != 'x')
    {
      int m1,m2,n1,n2;
      //recolectar matriz A
      printf("ingresa el tamaño de tu matriz A \n  ejemplo: 3 2\n");
      scanf("%d %d",&m1,&n1);

      int a[m1][n1];
      fore(i,0,m1)
      {
      fore(j,0,n1)
      {
      scanf("%d",&a[i][j]);
      }
      }
      //recolectar matriz B
      printf("ingresa el tamaño de tu matriz B, como lo hiciste con A \n");
      scanf("%d %d",&m2,&n2);
      int b[m2][n2];
      fore(i,0,m2)
      {
      fore(j,0,n2)
      {
      scanf("%d",&b[i][j]);
      }
      }
      // opciones 
      switch (op)
      {
        case '+':	

          if (m1 ==m2 && n1==n2)
          {
            printf("la matriz resultante es \n");
            fore (i,0,m1)
            {
              fore(j,0,n1)
                {
                printf("%d ",(a[i][j]+b[i][j]));
                }
              printf("\n");
            }
          }

          else
          {
            printf("las matrices no son de las mismas dimensiones\n");
          }
          break;
        case '-':

          if (m1==m2 && n1==n2)
          {
            printf("la matriz resultante es \n");
            fore (i,0,m1)
            {
              fore(j,0,n1)
              {
                printf("%d ",(a[i][j]-b[i][j]));
              }
              printf("\n");
            }
          }

          else
          {
            printf("las matrices no son de las mismas dimensiones");
          }
          break;
        case '*':

          if (n1==m2)
          {
            printf("la matriz resultante es \n");
            fore (i,0,m2)
            {
              fore(j,0,n1)
              {

                int r=0;
                fore(l,0,m2)
                {
                  r+=a[i][l]*b[l][j];		
                }
                printf("%d ", r);
              }

              printf("\n");
            }
          }

          else
          {
            printf("no es posible con esas dimensiones, las filas de A deben ser igual a las columnas de B\n");
          }
          break;
        case '/':

          if (m2==n2)
          {
              //calcular determinante

              //fin de determinante
              printf("la matriz resultante es \n");
          }
          else
          {
              printf("las matrices no son de las mismas dimensiones\n");
          break;
          }
        default:
        printf("no es una opción válida\n");
      }
    }
    else{
      int m,n;
      //recolectar matriz A
        printf("ingresa el tamaño de tu matriz  \n  ejemplo: 3 2\n");
        scanf("%d %d",&m,&n);

        int a[m][n];
        fore(i,0,m)
        {
        fore(j,0,n)
        {
        scanf("%d",&a[i][j]);
        }
        }
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
  }
}
