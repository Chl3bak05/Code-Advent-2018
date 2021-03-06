// Code Advent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int leftp = 0, top = 0, x = 0, y = 0;
string sleft, stop, sx, sy;
int fab[1000][1000];



void rozdziel(string linia) {
	int first = linia.find('@') + 2;
	int second = linia.find(',') + 1;
	int third = linia.find(':') + 2;
	int fourth = linia.find('x') + 1;

	sleft = linia.substr(first, second - 2);
	stop = linia.substr(second, third - 2);
	sx = linia.substr(third, fourth - 2);
	sy = linia.substr(fourth);

	leftp = stoi(sleft.c_str());
	top = stoi(stop.c_str());
	x = stoi(sx.c_str());
	y = stoi(sy.c_str());
}

int main()
{
	
	string dane;
	int claim = 0;

	cout << "start" << endl;
	fstream plik;

	plik.open("elf.txt", std::ios::in); //Otwiera plik

	if (plik.good()) { //Czy plik otwarty poprawnie
		cout << "Good" << endl;
	}
	else {
		cout << "Bad" << endl;
	}
	
	while (getline(plik, dane)) {
		rozdziel(dane);
		for (int i = leftp; i < leftp + x; i++) {
			for (int j = top; j < top + y; j++) {
				if (fab[i][j] == NULL) {
					fab[i][j] = 1;
				}
				else {
					fab[i][j]++;
				}
			}
		}

	}

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (fab[i][j] >= 2) {
				claim++;
			}
		}
	}
	cout << claim;



	plik.close();
	getchar();
	getchar();


    return 4;
}

