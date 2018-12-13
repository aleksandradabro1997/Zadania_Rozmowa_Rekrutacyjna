/* r = (sin(x))^2
 * x E <0,2PI>
 * Dokładność 10^(-8)
 * Do obliczania pola pod wykresem wykorzystam metodę trapezów
 * 1. Podzielenie obszaru pod wykresem na mniejsze kawałki
 * 2. Zliczenie i dodanie ich pól - daje dobre przybliżenie całki
 *
 * Proste testy wykonane przy pomocy biblioteki cassert
 */

#include "function.h"
double f_sin(double x){return pow(sin(x),2);}

array<double,2> function(){
	const double krok = pow(10,-8); 	   			//definiuje konieczne stałe/zmienne
	double pole=0;
	double dlugosc=0;

	for(double i=0; i < M_PI ; i+=krok){			//pętla zliczająca

		pole += f_sin(i) + f_sin(i+krok);					//przyjęłam zakres do PI, poniewaz program zostanie szybciej wykonany
		double tmp = abs(f_sin(i+krok)-f_sin(i));			//a względem x=PI funkcja jest lustrzanym odbiciem
													//tmp obliczanie roznicy wysokosci(dluzsza przyprostokatna ) do wyznaczania dlugosci
	    dlugosc += sqrt(pow(krok,2) + pow(tmp,2));	//obliczanie dlugosci (tw. Pitagorasa)

	}
	assert(pole > 0);								//pole i dlugosc musza byc > 0
	assert(dlugosc > 0);

	pole = (pole * krok /2)*2; 						//ze wzgledu na podzial przedzialu
	dlugosc *=2;									//mnozymy wartosci *2
	//cout << setprecision(9) <<pole  <<"   "<< setprecision(9)<< dlugosc <<endl;
	array<double,2> tab = {pole, dlugosc};
	return tab;
}

int main(){

	array<double,2>  tab1 = function();

	for(double & i: tab1)				//wyswietlane sa kolejno pole , dlugosc
		cout<< setprecision(9) << i <<endl;

}



