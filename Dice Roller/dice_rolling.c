#include<reg51.h>

sbit alwaysoff = P2^7;
sbit flag = P3^0;

sbit a = P2^0;
sbit b = P2^1;
sbit c = P2^2;
sbit d = P2^3;
sbit e = P2^4;
sbit f = P2^5;
sbit g = P2^6;

int previous = 1;

void off() {
	a = 0; b = 0; c = 0; d = 0; e = 0; f = 0; g = 0;
	return;
}

void display(int num) {
	  off();
	  while (flag != 1) {}
		if (num == 1) {a = 0; b = 1; c = 1; d = 0; e = 0; f = 0; g = 0;}
		if (num == 2) {a = 1; b = 1; c = 0; d = 1; e = 1; f = 0; g = 1;}
		if (num == 3) {a = 1; b = 1; c = 1; d = 1; e = 0; f = 0; g = 1;}
		if (num == 4) {a = 0; b = 1; c = 1; d = 0; e = 0; f = 1; g = 1;}
		if (num == 5) {a = 1; b = 0; c = 1; d = 1; e = 0; f = 1; g = 1;}
		if (num == 6) {a = 1; b = 0; c = 1; d = 1; e = 1; f = 1; g = 1;}
		previous = num;
	  return;
}

void main() {
	flag = 1;
	alwaysoff = 0;
	off();
	while (1) {
		if (flag == 0 && previous != 1) display(1);
		if (flag == 0 && previous != 2) display(2);
		if (flag == 0 && previous != 3) display(3);
		if (flag == 0 && previous != 4) display(4);
		if (flag == 0 && previous != 5) display(5);
		if (flag == 0 && previous != 6) display(6);
	} 
	return;
}