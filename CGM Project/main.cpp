#include <graphics.h>

void showCountdown() {
    char buffer[5];
    setbkcolor(BLACK);
    cleardevice();
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 6);
    
    outtextxy(600, 400, "Prepare for Launch!");
    delay(3000); 
    cleardevice(); 

    for (int i = 10; i >= 0; i--) {
        cleardevice(); 
        sprintf(buffer, "%d", i); 
        outtextxy(770, 400, buffer);
        delay(1000); 
    }

    cleardevice(); 
    outtextxy(750, 450, "Go!!");
    delay(1000); 
    cleardevice();
}


void drawStars() {
    for (int i = 0; i < 200; i++) {
        int x = rand() % 1600;
        int y = rand() % 1000;
        int brightness = rand() % 3;
        if (brightness == 0) {
            putpixel(x, y, WHITE);
        } else if (brightness == 1) {
            putpixel(x, y, LIGHTGRAY);
        } else {
            putpixel(x, y, YELLOW);
        }
    }
}


void drawNebula() {
    for (int i = 0; i < 2000; i++) {
        int x = rand() % 1600;
        int y = rand() % 1000;
        int color = rand() % 3;
        if (color == 0) {
            putpixel(x, y, RED);
        } else if (color == 1) {
            putpixel(x, y, MAGENTA);
        } else {
            putpixel(x, y, LIGHTMAGENTA);
        }
    }
}


void planet() {
    
   setcolor(LIGHTGRAY);
    circle(1100, 100, 90); 
    setfillstyle(SOLID_FILL, CYAN);
    floodfill(1105, 42, LIGHTGRAY); 

    //rings around the planet
    setcolor(LIGHTGRAY);
    ellipse(1100, 100, 0, 360, 110, 40); 
    setcolor(WHITE);
    ellipse(1100, 100, 0, 360, 115, 45);


    setcolor(LIGHTBLUE);
    arc(1100, 100, 20, 120, 70); 
    arc(1100, 100, 200, 290, 60); 
    line(1040, 70, 1120, 90); 

    //small circles on the planet
    setcolor(DARKGRAY);
    circle(1070, 80, 10); 
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(1070, 80, DARKGRAY);

    circle(1120, 120, 15); 
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(1120, 120, DARKGRAY);

    circle(1090, 140, 8); 
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(1090, 140, DARKGRAY);
    



    // White planet
    setcolor(WHITE);
    circle(1500, 600, 250);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(1500, 600, WHITE); 
    
    setcolor(DARKGRAY);
    circle(1350, 500, 60);
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(1350, 500, DARKGRAY);
    
    setcolor(DARKGRAY);
    circle(1400, 700, 30);
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(1400, 700, DARKGRAY);
    
    setcolor(DARKGRAY);
    circle(1500, 650, 20);
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(1500, 650, DARKGRAY);


}


void blinkingStars() {
    int x = rand() % 1600; 
    int y = rand() % 1000; 
    int size = rand() % 2 + 2; 
    
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x, y, size, size); 
    delay(100); 
}


void rocket(int rocketX, int rocketY) {
	
    // Body of the rocket
    setcolor(LIGHTGRAY);
    rectangle(rocketX - 35, rocketY, rocketX + 35, rocketY + 150);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(rocketX - 30, rocketY + 5, LIGHTGRAY);

    setcolor(LIGHTGRAY);
    rectangle(rocketX - 35, rocketY + 151, rocketX + 35, rocketY + 180);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(rocketX - 30, rocketY + 155, LIGHTGRAY);

    setcolor(BLACK);
    circle(rocketX, rocketY + 35, 20);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    floodfill(rocketX + 1, rocketY + 36, BLACK);

    // Pointer head of the rocket
    int points[] = {rocketX - 35, rocketY, rocketX + 35, rocketY, rocketX, rocketY - 50};
    setfillstyle(SOLID_FILL, RED);
    setcolor(LIGHTGRAY);
    fillpoly(3, points);

    // Wings of the rocket
    int points1[] = {rocketX + 35, rocketY + 150, rocketX + 55, rocketY + 150, rocketX + 35, rocketY + 100};
    setfillstyle(SOLID_FILL, RED);
    setcolor(LIGHTGRAY);
    fillpoly(3, points1);

    int points2[] = {rocketX - 35, rocketY + 150, rocketX - 55, rocketY + 150, rocketX - 35, rocketY + 100};
    setfillstyle(SOLID_FILL, RED);
    setcolor(LIGHTGRAY);
    fillpoly(3, points2);

    // Flame
    setcolor(DARKGRAY);
    rectangle(rocketX - 30, rocketY + 180, rocketX - 20, rocketY + 200);
    setfillstyle(SOLID_FILL, RED);
    floodfill(rocketX - 25, rocketY + 185, DARKGRAY);

    setcolor(DARKGRAY);
    rectangle(rocketX + 20, rocketY + 180, rocketX + 30, rocketY + 200);
    setfillstyle(SOLID_FILL, RED);
    floodfill(rocketX + 25, rocketY + 185, DARKGRAY);

    setcolor(DARKGRAY);
    rectangle(rocketX - 20, rocketY + 200, rocketX - 10, rocketY + 220);
    setfillstyle(SOLID_FILL, RED);
    floodfill(rocketX - 15, rocketY + 205, DARKGRAY);

    setcolor(DARKGRAY);
    rectangle(rocketX + 10, rocketY + 200, rocketX + 20, rocketY + 220);
    setfillstyle(SOLID_FILL, RED);
    floodfill(rocketX + 15, rocketY + 205, DARKGRAY);

    setcolor(DARKGRAY);
    rectangle(rocketX - 10, rocketY + 220, rocketX, rocketY + 240);
    setfillstyle(SOLID_FILL, RED);
    floodfill(rocketX - 5, rocketY + 225, DARKGRAY);

    setcolor(DARKGRAY);
    rectangle(rocketX, rocketY + 220, rocketX + 10, rocketY + 240);
    setfillstyle(SOLID_FILL, RED);
    floodfill(rocketX + 5, rocketY + 225, DARKGRAY);

    setcolor(DARKGRAY);
    rectangle(rocketX - 5, rocketY + 241, rocketX + 5, rocketY + 250);
    setfillstyle(SOLID_FILL, LIGHTRED);
    floodfill(rocketX, rocketY + 243, DARKGRAY);

    setcolor(DARKGRAY);
    rectangle(rocketX - 19, rocketY + 180, rocketX + 19, rocketY + 200);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(rocketX - 15, rocketY + 182, DARKGRAY);

    setcolor(DARKGRAY);
    rectangle(rocketX - 10, rocketY + 200, rocketX + 10, rocketY + 220);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(rocketX - 8, rocketY + 202, DARKGRAY);
}



void endingScene(){
	setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 6);
    outtextxy(400, 350, "Mission Accomplished");
    
    delay(4000); 
    cleardevice();
}




int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    setbkcolor(BLACK);
    cleardevice();
    showCountdown();



    int rocketX = 700;
    int rocketY = 1300;

    for (int i = 0; i < 1800; i += 35) {
        cleardevice();
        
        drawStars();
        drawNebula();
        planet();
        
        rocket(rocketX, rocketY - i);
        delay(150); 
        blinkingStars();
    }
    
    endingScene();

    getch();
    closegraph();
    return 0;
}
    


