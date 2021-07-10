#include<reg51.h>

sbit a = P2^0;
sbit b = P2^1;
sbit c = P2^2;
sbit d = P2^3;
sbit e = P2^4;
sbit f = P2^5;
sbit g = P2^6;

sbit first = P2^7;
sbit second = P3^0;

long int time_for_delay = 30000;

void delay(long int sec) {
	while(sec--) {}
}

void display(int num) {
	  if (num == 0) {a = 1; b = 1; c = 1; d = 1; e = 1; f = 1; g = 0;}
		if (num == 1) {a = 0; b = 1; c = 1; d = 0; e = 0; f = 0; g = 0;}
		if (num == 2) {a = 1; b = 1; c = 0; d = 1; e = 1; f = 0; g = 1;}
		if (num == 3) {a = 1; b = 1; c = 1; d = 1; e = 0; f = 0; g = 1;}
		if (num == 4) {a = 0; b = 1; c = 1; d = 0; e = 0; f = 1; g = 1;}
		if (num == 5) {a = 1; b = 0; c = 1; d = 1; e = 0; f = 1; g = 1;}
		if (num == 6) {a = 1; b = 0; c = 1; d = 1; e = 1; f = 1; g = 1;}
		if (num == 7) {a = 1; b = 1; c = 1; d = 0; e = 0; f = 1; g = 0;}
		if (num == 8) {a = 1; b = 1; c = 1; d = 1; e = 1; f = 1; g = 1;}
		if (num == 9) {a = 1; b = 1; c = 1; d = 1; e = 0; f = 1; g = 1;}
	  return;
}

void show (int i, int j) {
		first = 0; second = 1;
		display(i);
		delay(2000);
		first = 1; second = 0;
		display(j);
		delay(1500);
}

void main() {
	int i, j;
	first = 0; second = 0;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			show(i, j);
		}
	}
}