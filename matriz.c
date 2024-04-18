#include <stdio.h>
#define fore(i,l,r) for(int (i) = (l) ; (i) < (r) ; (i)++)
#define debug(x) printf(#x ": %d\n",x)

int main ()
{
char op;
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


printf("escribe el signo de la operación a realizar \n + para suma \n - para resta\n * para multiplicación\n / para division \n t para traspuesta \n x para salir\n");
scanf(" %c",&op);
// opciones 
switch (op)
{
	case '+':	
	
		if (m1==m2 && n1==n2)
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
		printf("las matrices no son de las mismas dimensiones");
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
		fore(l,0,m2){
		r+=a[i][l]*b[l][j];		
		}
		printf("%d ", r);
		}

		printf("\n");
		}
		}

		else
		{
		printf("no es posible con esas dimensiones");
		}
		break;
	case '/':

		if (m1==m2 & n1==n2)
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
		printf("las matrices no son de las mismas dimensiones");
		break;
		}
	case 't':

		break;
	case 'x':
		return 0;
	defaul:
	printf("no es una opción correcta");
		break;



}


return 0;
}
