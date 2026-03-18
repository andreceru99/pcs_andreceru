# include <iostream>
#include <cmath>
#include <algorithm>


int main()
{
	static const int N = 10;
	double arr[N] = {3.2, 7.0, 1.5, 9.8, 4.1, 6.3, 2.7, 8.6, 0.9, 5.4}; // inizializzo l'array
	double min_val = arr[0]; // inizializzo le variabili con il primo elemento
	double max_val = arr[0];
	double sum = 0.0; //ricorda di definire lo 0 come decimale con un double
	double var = 0.0;

	for (int i = 0; i < N; i += 1) {
		min_val = std::min(min_val, arr[i]); // compara i due valori forniti e restituisce il minimo 
		max_val = std::max(max_val, arr[i]); // compara i due valori forniti e restituisce il massimo
		sum += arr[i];
	}
	double media = sum/N;
	std::cout << "Valore minimo: " << min_val << "\n";
	std::cout << "Valore massimo: " << max_val << "\n";
	std::cout << "Media: " << media << "\n";
	
	// ciclo per calcolare la varianza
	for (int i = 0; i < N; i += 1) {
		var += (arr[i] - media)*(arr[i] - media);
	}
	var /= N;
	std::cout << "Deviazione Standard: " << std::sqrt(var) << "\n";




	
	return 0;
}