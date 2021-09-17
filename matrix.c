#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int r, c, r2, c2, r3, c3;
int nasobeni = 0;
int error = 1;
char charakter[20];

int main()
{
	char znak;

	//cout << "zadejte velikost první matice (øádky, sloupce): ";
	scanf("%d%d", &r, &c);
	int m1[r][c];

	for (int i = 0; i<r; i++) {
		for (int j = 0; j<c; j++) {
			if (scanf("%d", &m1[i][j]) == 0)
			{
				error = 0;
			}
		}
	}
	
	//cout << "zadejte operaci (+,-,*): ";
	scanf("\n%c", &znak);

	//cout << "zadejte velikost druhé matice (øádky, sloupce): ";
	scanf("%d%d", &r2, &c2);
	int m2[r2][c2];

	for (int i = 0; i<r2; i++) {
		for (int j = 0; j < c2; j++) {
			if (scanf("%d", &m2[i][j]) == 0)
			{
				error = 0;
			}
		}
	}

	if(error == 0)
	{
		fprintf(stderr, "Error: Chybny vstup!\n");
		return 100;
	}

	switch (znak)
	{

	default: {
		fprintf(stderr, "Error: Chybny vstup!\n");
		return 100;
	}
	case '+': {
		if (r != r2 || c != c2) {
			fprintf(stderr, "Error: Chybny vstup!\n");
			return 100;
		}

		printf("%d %d\n", r, c);

		r2 = r;
		c2 = c;

		int v[r2][c2];

		for (int a = 0; a < r; a++) {
			for (int b = 0; b < c; b++) {
				v[a][b] = m1[a][b] + m2[a][b];
				if( b == c-1 )
					printf("%d", v[a][b]);
				else
					printf("%d ", v[a][b]);
			}
			printf("\n");
		}
		break;
	}

	case '-': {
		if (r != r2 || c != c2) {
			fprintf(stderr, "Error: Chybny vstup!\n");
			return 100;
		}

		printf("%d %d\n", r, c);

		r2 = r;
		c2 = c;

		int v2[r2][c2];

		for (int a = 0; a < r; a++) {
			for (int b = 0; b < c; b++) {
				v2[a][b] = m1[a][b] - m2[a][b];
				if( b == c-1 )
					printf("%d", v2[a][b]);
				else
					printf("%d ", v2[a][b]);
			}
			printf("\n");
		}
		break;}

	case '*': {
			if (c != r2) {
				fprintf(stderr, "Error: Chybny vstup!\n");
				return 100;
			}

			printf("%d %d\n", r, c2);

			int v3[r3 = r][c3 = c2];

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c2; j++) {
					for (int k = 0; k < r2; k++) {
						nasobeni = nasobeni + (m1[i][k] * m2[k][j]);
					}
						v3[i][j] = nasobeni;
						nasobeni = 0;
						//printf("%d ", v3[i][j]);
						if (j == c2 - 1)
							printf("%d", v3[i][j]);
						else
							printf("%d ", v3[i][j]);
				}
				  printf("\n");
	}
			}
	return 0;
	}

}
