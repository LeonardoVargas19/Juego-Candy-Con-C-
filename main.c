
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char m[9][6],p[3],mov='\0';
	int i,j,cont[4],band,aux,x,y,d,punt=0,k;
	int c,f;
	char a;

	srand(time(NULL));
	for (i=0;i<9;i++){
		for (j=0;j<6;j++){
			do{
				band=0;
				m[i][j]=rand()%4+35;
				if (j>1 && m[i][j]==m[i][j-1] && m[i][j]==m[i][j-2]){
					band=1;
				}else if (i>1 && m[i][j]==m[i-1][j] && m[i][j]==m[i-2][j]){
					band=1;
				}else if (j>1 && i>1 && m[i][j]==m[i-1][j-1] && m[i][j]==m[i-2][j-2]){
					band=1;
				}else if (j<4 && i>1 && m[i][j]==m[i-1][j+1] && m[i][j]==m[i-2][j+2]){
					band=1;
				}
			}while(band==1);
			cont[m[i][j]-35]++;
		}
	}
	do{
		printf("\n    ");
		for (j=0;j<6;j++){
			printf("%3c",j+65);
		}
		printf("\n\n");
		for (i=0;i<9;i++){
			printf("%d   ",i+1);
			for (j=0;j<6;j++){
				printf("%3c",m[i][j]);
			}
		printf("\n");
		}
		printf("\nPuntuacion: %d",punt);//////Implemetar el random
		do{
			band=0;///Deseeas mover los lugares po5
			printf("\nQue coordenada deseas mover (Ej. 1A): ");

			fflush(stdin);
			scanf("%s",p);
			y=p[0]-49;
			x=p[1]-65;
			if(x<0 || x>5 || y<0 || y>8){
				band=1;
			}
		}while(band==1);
		do{
			band=0;
			printf("\nHacia donde deseas moverla (w,a,s,d):\n ");
			printf(" o Deseeas Cambiar los caracteres (c)\n ");
			fflush(stdin);
			scanf("%c",&mov);
			switch(mov){
				case 'w':
					if (p[0]<=0){
						printf("\nSeleccion no valida");
						band=1;
					}else{
						aux=m[y][x];
						m[y][x]=m[y-1][x];
						m[y-1][x]=aux;
						y-=1;
					}
				break;
				case 'a':
					if (p[1]<=0){
						printf("\nSeleccion no valida");
						band=1;
					}else{
						aux=m[y][x];
						m[y][x]=m[y][x-1];
						m[y][x-1]=aux;
						x-=1;
					}
				break;
				case 's':
					if (p[0]<=8){
						printf("\nSeleccion no valida");
						band=1;
					}else{
						aux=m[y][x];
						m[y][x]=m[y+1][x];
						m[y+1][x]=aux;
						y+=1;
					}
				break;
				case 'd':
					if (p[1]<=5){
						printf("\nSeleccion no valida");
						band=1;
					}else{
						aux=m[y][x];
						m[y][x]=m[y][x+1];
						m[y][x+1]=aux;
						x+=1;
					}
				break;
				case 'c':
				for(c=0;c<6;c++){
	           	for(f=0;f<9;f++){
			      if (m[c][f]!='@'){
			      		a=rand()%4+35;
			      		if (a!='@'){
			      			m[c][f]=a;
						  }
				  }



		}
		printf("\n");
	}

					break;


				default:
					printf("\nSeleccion no valida");
					band=1;
				break;
			}
		}while(band==1);
		for (k=0;k<2;k++){
			band=0;
			for (i=0;i<9 && band==0;i++){
				for (j=0;j<6 && band==0;j++){
					if (j>1 && m[i][j]==m[i][j-1] && m[i][j]==m[i][j-2] && m[i][j]!='@'){
						band=1;
						d=1;
					}else if (i>1 && m[i][j]==m[i-1][j] && m[i][j]==m[i-2][j] && m[i][j]!='@'){
						band=1;
						d=2;
					}else if (j>1 && i>1 && m[i][j]==m[i-1][j-1] && m[i][j]==m[i-2][j-2] && m[i][j]!='@'){
						band=1;
						d=3;
					}else if (j<4 && i>1 && m[i][j]==m[i-1][j+1] && m[i][j]==m[i-2][j+2] && m[i][j]!='@'){
						band=1;
						d=4;
					}
				}
			}
			i--;
			j--;
			if (band==1){
				switch (d){
					case 1:
						cont[m[i][j]-35]-=3;
						m[i][j]=64;
						m[i][j-1]=64;
						m[i][j-2]=64;
						punt++;
					break;
					case 2:
						cont[m[i][j]-35]-=3;
						m[i][j]=64;
						m[i-1][j]=64;
						m[i-2][j]=64;
						punt++;
					break;
					case 3:
						cont[m[i][j]-35]-=3;
						m[i][j]=64;
						m[i-1][j-1]=64;
						m[i-2][j-2]=64;
						punt++;
					break;
					case 4:
						cont[m[i][j]-35]-=3;
						m[i][j]=64;
						m[i-1][j+1]=64;
						m[i-2][j+2]=64;
						punt++;
					break;
				}
			}else if (k==0){
				punt--;
			}
		}
	}while (cont[0]>=3 || cont[1]>=3 || cont[2]>=3 || cont[3]>=3);
	printf("\n    ");
		for (j=0;j<6;j++){
			printf("%3c",j+65);
		}
		printf("\n\n");
		for (i=0;i<9;i++){
			printf("%d   ",i+1);
			for (j=0;j<6;j++){
				printf("%3c",m[i][j]);
			}
		printf("\n");
		}
		printf("\nPuntuacion final: %d",punt);
	return 0;
}

