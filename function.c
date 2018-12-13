
/*
 * KRZYWE DANE:
 * y1 = sqrt3st(x) = x^(1/3)
 * y2 = (1-x^4)^(1/4) v y2 = -(1-x^4)^(1/4)
 * Poniewaz pierwiastek stopnia 3 to funkcja majaca wartosci w I ćwiartce układu współrzędnych
 * Zatem badamy tylko wartosci w I cwiartce, biorąc pod uwagę drugie ograniczenie x E <0,1>
 *
 * Testy jednostkowe wykonałam przy pomocy biblioteki assert.h
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define krok 0.00000001;											//definicja kroku

double* function(double tab[]){


	double prec = pow(10,-8);										//definiuję potrzebne zmienne
	double i = 0;   												//typ double - dokladność 15-16 cyfr po przecinku
	int j = 0;
	double y1 = 0.0;
	double y2 = 0.0;

	while (i <= 1){
		y1 = cbrt(i);												//obliczam pierwiastek st. 3
		y2 = pow(1-pow(i,4.0),1/(4.0));								//obliczam

		assert(y1 >= 0);
		assert(y2 >= 0);

		double diff = (abs(y1*(pow(10,8)) - y2*pow(10,8)))/(pow(10,8));//aby nie utracić precyzji mnożę * 10^8

		//Dzielimy obszar na małe kawałki, proste będą się przecinały wówczas gdy (x1,y1)=(x2,y2), zatem przyjmując
		// x1=x2 obliczamy kolejno wartości y1,y2, jeżeli ich różnica < precyzji to przyjmujemy, że dany punkt spelnia warunek

		assert(diff <= 1); //roznica nie moze byc wieksza od 1 poniewaz obydwie funkcja mają zb. wartosci <0,1>
		if(diff < prec && j<6 ){
			//printf("diff: %.10f \n y1:%.8f y2:%.8f x: %.8f \n", diff,y1,y2,i);
			tab[j] = y1;
			tab[j+1] = y2;
			tab[j+2] = i;
			j += 3;
		}

		i = i + krok;

	}
	return tab;
	free(tab);

}
int main(){
	double tab1[6];
	assert(tab1!=NULL);
	double *tab = function(tab1);
	assert(tab!=NULL);
	int i;
	for(i=0 ; i<6;i++){				//mamy wyswietlane kolejno Y1, Y2, X 
		assert(tab[i]!='/0');			//rozmiar tablicy został wyznaczony doswiadczalnie
		printf("%.8f\n",tab[i]);
	}

}

