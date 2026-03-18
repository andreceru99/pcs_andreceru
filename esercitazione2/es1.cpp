# include <iostream>


int main()
{
	int ai[3] = {0, 1, 2};	
	double ad[4] = {0.0, 1.1, 2.2, 3.3};
	float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	int x = 1;
	float y = 1.1;

	
	(&y)[1] = 0; 


	for (int i = 0; i < 3; i += 1) {	
		std::cout << "ai indirizzo " << i << " " << &ai[i] << "\n";
	}
	for (int i = 0; i < 4; i += 1) {	
		std::cout << "ad indirizzo " << i << " " << &ad[i] << "\n";
	}
	
	for (int i = 0; i < 8; i += 1) {	
		std::cout << "af indirizzo " << i << " " << &af[i] << "\n";
	}


	std::cout << "indirizzo x "<< &x << "\n";
	std::cout << "indirizzo y "<< &y << "\n";
	
	std::cout << x << "\n";
	std::cout << y << "\n";
	
	/*
	Output:
	ai indirizzo 0 0xffffef6d1538
	ai indirizzo 1 0xffffef6d153c
	ai indirizzo 2 0xffffef6d1540
	ad indirizzo 0 0xffffef6d1518
	ad indirizzo 1 0xffffef6d1520
	ad indirizzo 2 0xffffef6d1528
	ad indirizzo 3 0xffffef6d1530
	af indirizzo 0 0xffffef6d14f8
	af indirizzo 1 0xffffef6d14fc
	af indirizzo 2 0xffffef6d1500
	af indirizzo 3 0xffffef6d1504
	af indirizzo 4 0xffffef6d1508
	af indirizzo 5 0xffffef6d150c
	af indirizzo 6 0xffffef6d1510
	af indirizzo 7 0xffffef6d1514
	indirizzo x 0xffffef6d14f4
	indirizzo y 0xffffef6d14f0
	0
	1.1

	Si può notare che gli indirizzi degli elementi di ai distano di 4 byte (poiché ogni int occupa tipicamente 4 byte), 
	quelli di ad distano di 8 byte (poiché ogni double occupa tipicamente 8 byte), 
	mentre quelli di af distano di 4 byte (poiché ogni float occupa tipicamente 4 byte)
	Notiamo inoltre che gli elementi x e y distano di 4 byte, quindi sono adiacenti in memoria.
	Scrivere 
	(&y)[1] = 0; 
	significa dire alla macchina di accedere alla locazione di memoria successiva (considerando che y è un float) e scrivere 0 in quella posizione
	Ecco perché nell'output se stampiamo la x dopo questo comando appare il valore 0 anche se non è stata toccata direttamente

	Tuttavia, questo comportamento è indefinito (undefined behavior): non è garantito
	che x venga modificata, poiché la disposizione in memoria delle variabili dipende
	dal compilatore e dalle sue scelte di ottimizzazione; infatti ad inizio esercitazione avevo per sbaglio scritto nel codice
	float y = 1.1;
	int x = 1;
	e il fenomeno non si era verificato
	*/



	
	return 0;
}