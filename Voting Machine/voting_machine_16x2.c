#include<reg51.h>
#define port P2

sbit rs = P3^0;
sbit rw = P3^1;
sbit enable = P3^2;
sbit bjp = P3^3;
sbit tmc = P3^4;
sbit cng = P3^5;
sbit svh = P3^6;
sbit tot = P3^7;
sbit res = P1^7;

int bjpVote = 0, cngVote = 0, svhVote = 0, tmcVote = 0;

void delay(long int ms) {
	while(ms--);
}

void command(char cmd) {
	enable = 1; // For setting value;
	rs = 0;
	rw = 0;
	port = cmd;
	enable = 0;	// For displaying setted value;
	delay(1000);
	return;
}

void display(char ch) {
	enable = 1;
	rs = 1;
	rw = 0;
	port = ch;
	enable = 0;
	return;
}

void displayNum(int n) {
	if (n == 0) display('0');
	if (n == 1) display('1');
	if (n == 2) display('2');
	if (n == 3) display('3');
	if (n == 4) display('4');
	if (n == 5) display('5');
	if (n == 6) display('6');
	if (n == 7) display('7');
	if (n == 8) display('8');
	if (n == 9) display('9');
	return;
}

void displayRes() {
	char arr[16] = "BJP TMC CNG SHV";
	int i, first = 0, second = 0;
	command(0x01);
	
	for (i = 0; i < 16; i++) {
		display(arr[i]);
		delay(0);
	}
	
	command(0xC0);
	second = bjpVote % 10;
	first = bjpVote / 10;
	displayNum(first);
	displayNum(second);
	
	display(' ');
	display(' ');
	
	second = tmcVote % 10;
	first = tmcVote / 10;
	displayNum(first);
	displayNum(second);
	
	
	display(' ');
	display(' ');
	
	second = cngVote % 10;
	first = cngVote / 10;
	displayNum(first);
	displayNum(second);
	
	display(' ');
	display(' ');
	
	second = svhVote % 10;
	first = svhVote / 10;
	displayNum(first);
	displayNum(second);
	return;
}

void displayTotal() {
	int total = bjpVote + cngVote + svhVote + tmcVote;
	char arr[16] = "Total : ";
	int i, first = 0, second = 0;
	command(0x01);
	command(0x80);
	for (i = 0; i < 16; i++) {
		display(arr[i]);
		delay(1);
	}
	command(0xC0);
	second =total % 10;
	first = total/ 10;
	displayNum(first);
	displayNum(second);
	
	
	return;
}


void displayWelcome() {
	int i;
	char startArr[16] = "Welcome to ";
	char arr[16] = "Elect Commission";
	command(0x38);
	command(0x0C);
	command(0x01);
	command(0x80);
  for (i = 0; i < 16;i++) {
		display(startArr[i]);
		delay(400);
	}
	command(0xC0);
	for (i = 0; i < 16;i++) {
		display(arr[i]);
		delay(400);
	}
	return;
}

void displayAfterVote(char ch[3]) {
	int i;
	char startArr[16] = "Thanks For Vote";
	command(0x38);
	command(0x0C);
	command(0x01);
	command(0x80);
  for (i = 0; i < 16;i++) {
		display(startArr[i]);
		delay(400);
	}
	command(0xC0);
	for (i = 0; i < 3;i++) {
		display(ch[i]);
		delay(1000);
	}
	displayWelcome();
	return;
}

void main() {
	
	displayWelcome();
	
	while (1) {
		if (bjp == 0) {while(bjp != 1){} bjpVote++; displayAfterVote("BJP");}
		if (tmc == 0) {while(tmc != 1){} tmcVote++; displayAfterVote("TMC");}
		if (cng == 0) {while(cng != 1){} cngVote++; displayAfterVote("CNG");}
		if (svh == 0) {while(svh != 1){} svhVote++; displayAfterVote("SHV");}
		if (tot == 0) {displayTotal(); while(tot != 1){}}
		if (res == 0) {displayRes(); while(res != 1) {}}
	}
	
	return;
}