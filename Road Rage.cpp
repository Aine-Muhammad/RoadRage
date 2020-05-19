// Game: Road Rage COPYRIGHT;
// By the AAs (Abdullah Mehboob and Ain E Muhammad);
// Copying this game's code will result on extreme punishments due to the law of copyright;
#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

// macro funtions //
#define RANDOM (130 + (rand() % 460));

// helper //
int end = 0;
int score = 0;
char score1[10];
int x = 0; // speed increaser;

// car global variables //
int cx1 = 200, cy1 = 580, cx2 = 280, cy2 = 700;

// enemy global variables //
int e1x1 = RANDOM;
int e1y1 = -120;

int e2x1 = RANDOM;
int e2y1 = -480;

int e3x1 = RANDOM;
int e3y1 = -840;

int e1x2;
int e1y2;
	
int e2x2;
int e2y2;
	
int e3x2;
int e3y2;

// function prototypes //
void grass ();
void road ();
void car ();
void enemy ();
void collision();
void Endgame();

int main () {
	initwindow (800, 750, "ROAD");
	settextstyle(0,0,8);
	setcolor(WHITE);
	outtextxy(20,200,"Road Rage©");
	settextstyle(9,0,4);
	outtextxy(170,300,"PRESS S TO START");
	if(kbhit)
	{
		int key=getch();
		if(key==115 || key==83)		{
			road();
		}
		setvisualpage(2);
		Endgame();
	}
	
	while (!kbhit()) {
		delay (200);
	}
		
	return 0;
}

void collision() {
	if (((cx2 >= e1x1) && (cx1 <= e1x2) && (cy2 >= e1y1) && (cy1 <= e1y2))) {
		end = 5;
	}
	
	if(((cx2 >= e2x1) && (cx1 <= e2x2 ) && (cy2 >= e2y1) && (cy1 <= e2y2))) {
		end = 5;
	}
	
	if(((cx2 >= e3x1) && (cx1 <= e3x2 ) && (cy2 >= e3y1 ) && (cy1 <= e3y2))) {
		end = 5;
	}
	
	if (cx1 <= 120 || cx2 >= 680) {
		end = 5;
	}
}

void grass () {
	setfillstyle (CLOSE_DOT_FILL, GREEN);
	bar (0, 0, 120, 750); // left grass;
	bar (680, 0, 800, 750); // right grass;
}

void enemy () {
	setfillstyle(LINE_FILL, BROWN);
	if (e1y1 >= 750) {
		e1x1 = RANDOM;
		e1y1 = -380;
		score += 5;
	}
	
	if (e2y1 >= 750) {
		e2x1 = RANDOM;
		e2y1 = -380;
		score += 5;
	}
	
	if (e3y1 >= 750) {
		e3x1 = RANDOM;
		e3y1 = -380;
		score += 5;
	}
	
	e1y1 = e1y1 + x + 5;
	e2y1 = e2y1 + x + 5;
	e3y1 = e3y1 + x + 5;
	
	e1x2 = e1x1 + 80;
	e1y2 = e1y1 + 120;
	
	e2x2 = e2x1 + 80;
	e2y2 = e2y1 + 120;
	
	e3x2 = e3x1 + 80;
	e3y2 = e3y1 + 120;
	
	setcolor(GREEN);
	setfillstyle(1,GREEN);	
	bar(e1x1, e1y1, e1x2, e1y2);	
	floodfill(e1x1+20,e1y1+20,GREEN);// car;
	setcolor(8);
	setfillstyle(15,8);	
	ellipse(e1x1+40,e1y1+30,50,50,38,10);
	fillellipse(e1x1+40,e1y1+30,38, 10);
	rectangle(e1x1+10,e1y1+70,e1x2-10,e1y1+90);
	floodfill(e1x1+20,e1y1+80, 8);
	setcolor(RED);
	setfillstyle(1,RED);
	rectangle(e1x1,e1y1,e1x1+10,e1y1+10);
	floodfill(e1x1+3,e1y1+3, RED);
	rectangle(e1x2-10,e1y1,e1x2,e1y1+10);
	floodfill(e1x2-5,e1y1+3, RED); // enemy1;
    setcolor(BLUE);
	
	setfillstyle(1,BLUE);
	bar(e2x1, e2y1, e2x2, e2y2);
	floodfill(e2x1+20,e2y1+20,BLUE);// car;
	setcolor(8);
	setfillstyle(15,8);	
	ellipse(e2x1+40,e2y1+30,50,50,38,10);
	fillellipse(e2x1+40,e2y1+30, 38,10);
	rectangle(e2x1+10,e2y1+70,e2x2-10,e2y1+90);
	floodfill(e2x1+20,e2y1+80, 8);
	setcolor(RED);
	setfillstyle(1,RED);
	rectangle(e2x1,e2y1,e2x1+10,e2y1+10);
	floodfill(e2x1+3,e2y1+3, RED);
	rectangle(e2x2-10,e2y1,e2x2,e2y1+10);
	floodfill(e2x2-5,e2y1+3, RED); // enemy2;
	
	setcolor(YELLOW);
	setfillstyle(1,YELLOW);
	bar(e3x1, e3y1, e3x2, e3y2);
	floodfill(e3x1+20,e3y1+20,YELLOW);// car;
	setcolor(8);
	setfillstyle(15,8);	
	ellipse(e3x1+40,e3y1+30,50,50,38,10);
	floodfill(e3x1+40,e3y1+30, 8);
	rectangle(e3x1+10,e3y1+70,e3x2-10,e3y1+90);
	floodfill(e3x1+20,e3y1+80, 8);
	setcolor(RED);
	setfillstyle(1,RED);
	rectangle(e3x1,e3y1,e3x1+10,e3y1+10);
	floodfill(e3x1+3,e3y1+3, RED);
	rectangle(e3x2-10,e3y1,e3x2,e3y1+10);
	floodfill(e3x2-5,e3y1+3, RED); // enemy3;
	collision(); 
}

void car () {
	setfillstyle (1, WHITE);
	setcolor(WHITE);
	if (GetAsyncKeyState(VK_RIGHT)) {
		cx1 = cx1 + 5;
		cx2 = cx2 + 5;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		cx1 = cx1 - 5;
		cx2 = cx2 - 5;
	}
	bar (cx1, cy1, cx2, cy2); 
	floodfill(cx1+20,cy1+20,WHITE);// car;
	setcolor(8);
	setfillstyle(15,8);	
	ellipse(cx1+40,cy1+30,50,50,38,10);
	floodfill(cx1+40,cy1+30, 8);
	rectangle(cx1+10,cy1+70,cx2-10,cy1+90);
	floodfill(cx1+20,cy1+80, 8);
	setcolor(RED);
	setfillstyle(1,RED);
	rectangle(cx1,cy1,cx1+10,cy1+10);
	floodfill(cx1+3,cy1+3, RED);
	rectangle(cx2-10,cy1,cx2,cy1+10);
	floodfill(cx2-5,cy1+3, RED);
	collision();
	if (cx1 == 120 || cx2== 680) {
		end = 5;
	
	}
	
}

void road () {
	int i = 0;
	int page = 0;
	
	while (end == 0) {
		while (i <= 890 && end == 0) { // DONT TOUCH THIS!!;
			setvisualpage (1 - page);
			setactivepage (page);
			cleardevice();
			
			grass();
			car();
			enemy();
			itoa(score, score1, 10);
			
			// score text //
			settextstyle(0,0,2);
			setcolor(WHITE);
			outtextxy(550,20,"SCORE: ");
			
			settextstyle(0,0,2);
			setcolor(WHITE);
		outtextxy(650,20, score1);
			
			// road lines //
			setfillstyle(SOLID_FILL, WHITE);
			bar(400, -1040 + i, 405, -990 + i);
			bar(400, -890 + i, 405, -840 + i);
			bar(400, -740 + i, 405, -690 + i);
			bar(400, -590 + i, 405, -540 + i);
	
			bar(400, -440 + i, 405, -390 + i);
			bar(400, -290 + i, 405, -240 + i);
			bar(400, -140 + i, 405, -90 + i);
			bar(400, 10 + i, 405, 60 + i);
			bar(400, 160 + i, 405, 210 + i);
			bar(400, 310 + i, 405, 360 + i);
			bar(400, 460 + i, 405, 510 + i);
			bar(400, 610 + i, 405, 660 + i);
			
			delay(5);
			
			page = 1 - page;
			
			i += 3;
		}
		x++;
		i = 0;
	}
}

void Endgame() {
	setactivepage (2);
	setbkcolor(WHITE);
	settextstyle(0,0,8);
	setcolor(BLACK);
	outtextxy(100,200,"GAME OVER!");
	Beep(10,100);
	
	if(kbhit)
	{
		getch();
		delay(5000);
	}
	
}


