// midtermPJ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "allegro5/allegro.h"
#include<allegro5/allegro.h>
#include<stdio.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_primitives.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include<math.h>

ALLEGRO_DISPLAY *display = NULL;

ALLEGRO_BITMAP *mouseCursor1 = NULL;
ALLEGRO_BITMAP *player1 = NULL;
ALLEGRO_BITMAP *player2 = NULL;
ALLEGRO_BITMAP  *image = NULL;
int boardhelp[10][10], mark[10][10];
int free1 = 0;

void ini() {
	for (int i1 = 0; i1 < 10; i1++)
		for (int i2 = 0; i2 < 10; i2++)
			boardhelp[i1][i2] = 0;
}

void arayPrint(int a[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

void pass1() {
	int x1 = 1682;
	int x2 = 1894;
	int y1 = 491;
	int y2 = 562;
}
void menu() {
	int x1 = 18;
	int x2 = 309;
	int y1 = 140;
	int y11 = 276;
	int y2 = 329;
	int y22 = 470;
	int y3 = 527;
	int y33 = 670;
	int y4 = 734;
	int y44 = 871;
}

int andisY(int j) {
	if (j == 54)
		return 0;
	if (j == 162)
		return 1;
	if (j == 270)
		return 2;
	if (j == 378)
		return 3;
	if (j == 485)
		return 4;
	if (j == 594)
		return 5;
	if (j == 702)
		return 6;
	if (j == 809)
		return 7;
	if (j == 918)
		return 8;
	if (j == 1025)
		return 9;
}
int andisX(int i) {
	if (i == 701)
		return 0;
	if (i == 810)
		return 1;
	if (i == 918)
		return 2;
	if (i == 1026)
		return 3;
	if (i == 1134)
		return 4;
	if (i == 1242)
		return 5;
	if (i == 1350)
		return 6;
	if (i == 1458)
		return 7;
	if (i == 1566)
		return 8;
	if (i == 1674)
		return 9;
}
int setX(int x) {
	if (x > 680 && x < 1700) {
		if (x > 680 && x < 755)
			return 701;
		if (x > 755 && x < 866)
			return 810;
		if (x > 866 && x < 973)
			return 918;
		if (x > 973 && x < 1080)
			return 1026;
		if (x > 1080 && x < 1191)
			return 1134;
		if (x > 1191 && x < 1297)
			return 1242;
		if (x > 1297 && x < 1407)
			return 1350;
		if (x > 1407 && x < 1513)
			return 1458;
		if (x > 1513 && x < 1623)
			return 1566;
		if (x > 1623 && x < 1700)
			return 1674;
	}
	else if (x > 18 && x < 309) {
		return 2;
	}
	else if (x > 1682 && x < 1894) {
		return 3;
	}
	else {
		/*al_show_native_message_box(display, "Error", "Error", "Invalied Move!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);*/
		return -1;
	}

}
int setY(int y) {
	if (y > 36 && y < 1056) {
		if (y > 36 && y < 107)
			return 54;
		if (y > 107 && y < 217)
			return 162;
		if (y > 217 && y < 324)
			return 270;
		if (y > 324 && y < 433)
			return 378;
		if (y > 433 && y < 540)
			return 485;
		if (y > 540 && y < 646)
			return 594;
		if (y > 646 && y < 756)
			return 702;
		if (y > 756 && y < 863)
			return 809;
		if (y > 863 && y < 970)
			return 918;
		if (y > 970 && y < 1056)
			return 1025;
	}

	else {
		/*al_show_native_message_box(display, "Error", "Error", "Invalied Move!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);*/
		return -1;
	}

}
int setButton(int x, int y) {
	if (x == 2 || x == 3) {
		if (y > 140 && y < 276) {
			return 2;
		}
		else if (y > 329 && y < 470) {
			return 2;
		}
		else if (y > 491 && y < 562) {
			return 2;
		}

		else if (y > 527 && y < 670) {
			return 2;
		}
		else if (y > 734 && y < 871) {
			return 2;
		}
	}
	return -100;
}



void inimark() {
	for (int i1 = 0; i1 < 10; i1++)
		for (int i2 = 0; i2 < 10; i2++)
			mark[i1][i2] = 0;
}

bool check(int i, int j) {
	if (i < 10 && j < 10 && i >= 0 && j >= 0) return 1;
	return 0;
}

void dfs(int i, int j, int sw) {
	int sw2 = 0;
	mark[i][j] = 1;

	//	printf("i = %d j = %d \n", i, j);
	//	printf("118\n");

	if (check(i + 1, j) && !mark[i + 1][j] && boardhelp[i + 1][j] == sw) dfs(i + 1, j, sw);
	if (check(i - 1, j) && !mark[i - 1][j] && boardhelp[i - 1][j] == sw) dfs(i - 1, j, sw);
	if (check(i, j + 1) && !mark[i][j + 1] && boardhelp[i][j + 1] == sw) dfs(i, j + 1, sw);
	if (check(i, j - 1) && !mark[i][j - 1] && boardhelp[i][j - 1] == sw) dfs(i, j - 1, sw);

	if (check(i + 1, j) && !boardhelp[i + 1][j]) sw2 = 1;
	if (check(i - 1, j) && !boardhelp[i - 1][j]) sw2 = 1;
	if (check(i, j + 1) && !boardhelp[i][j + 1]) sw2 = 1;
	if (check(i, j - 1) && !boardhelp[i][j - 1]) sw2 = 1;

	//	printf("sw2 = %d \n" , sw2);
	if (sw2) free1 = 0;
}

void dfs2(int i, int j, int sw) {
	//	printf("i = %d j = %d \n", i, j);
	//	printf("125\n") ;
	mark[i][j] = 1;
	boardhelp[i][j] = 0;
	if (check(i + 1, j) && !mark[i + 1][j] && boardhelp[i + 1][j] == sw) boardhelp[i + 1][j] = 0, dfs2(i + 1, j, sw);
	if (check(i - 1, j) && !mark[i - 1][j] && boardhelp[i - 1][j] == sw) boardhelp[i - 1][j] = 0, dfs2(i - 1, j, sw);
	if (check(i, j + 1) && !mark[i][j + 1] && boardhelp[i][j + 1] == sw) boardhelp[i][j + 1] = 0, dfs2(i, j + 1, sw);
	if (check(i, j - 1) && !mark[i][j - 1] && boardhelp[i][j - 1] == sw) boardhelp[i][j - 1] = 0, dfs2(i, j - 1, sw);
}


void refresh() {
	int pixcelX[10] = { 701,810,918,1026,1134,1242,1350,1458,1566,1674 };
	int pixcelY[10] = { 54,162,270,378,485,594,702,809,918,1025 };


	al_shutdown_primitives_addon();

	al_init_primitives_addon();
	image = al_load_bitmap("mainIMG.jpg");
	al_draw_bitmap(image, 0, 0, 0);
	al_flip_display();

	for (int i3 = 0; i3 < 10; i3++) {
		for (int j3 = 0; j3 < 10; j3++) {
			if (boardhelp[i3][j3] == 1) {
				al_draw_filled_circle(pixcelX[j3], pixcelY[i3], 30, al_map_rgb(0, 0, 0));
			}
			else if (boardhelp[i3][j3] == 2) {
				al_draw_filled_circle(pixcelX[j3], pixcelY[i3], 30, al_map_rgb(255, 255, 255));
			}
		}
	}
}
bool suicide(int x, int y, bool exit) {
	if (x - 1 > 0 && x + 1 < 10 && y - 1 > 0 && y + 1 < 10) {
		if (boardhelp[y - 1][x] != 0 && boardhelp[y + 1][x] != 0 && boardhelp[y][x - 1] != 0 && boardhelp[y][x + 1] != 0) {
			exit = false;
			return false;

		}
	}
	return true;


}
bool alowStone(int chekA, int chekB, int passCountA, int passCountB, int button, bool suicide) {
	if (!suicide) {
		return false;
	}
	if (button != -100) {
		return false;
	}
	if (chekA > 41 || chekB > 40) {
		return false;
	}
	if (passCountA == 2 && passCountB == 2) {
		return false;
	}

	return true;


}


int main(int argc, char **argv) {


	ALLEGRO_DISPLAY_MODE   disp_data;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_MOUSE_CURSOR *mouseCursor = NULL;
	//	ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);

//	char board[9][9];
	bool redraw = false;
	bool doexit = false;
	int checkNobat = 1;
	const int player1No = 41;
	const int player2No = 40;
	const int komi = 6.5;

	int nutA = 0;
	int nutB = 0;
	int passCounterA = 0, passCounterB = 0;
	bool pass = false;
	ini();

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	al_init_primitives_addon();
	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}
	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}
	if (!al_install_mouse()) {
		return 100;
	}
	al_install_mouse();

	al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);
	//al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	display = al_create_display(disp_data.width, disp_data.height);
	al_clear_to_color(al_map_rgb(255, 203, 98));
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		return -1;
	}

	image = al_load_bitmap("mainIMG.jpg");
	if (!image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	player1 = al_load_bitmap("1.png");
	if (!player1) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}
	player2 = al_load_bitmap("2.png");
	if (!player2) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}
	mouseCursor1 = al_load_bitmap("click.png");
	if (!mouseCursor1) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}
	mouseCursor = al_create_mouse_cursor(player1, 15, 15);
	if (!mouseCursor) {
		return 50;
	}
	al_set_mouse_cursor(display, mouseCursor);
	//al_register_event_source(event_queue,al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_draw_bitmap(image, 0, 0, 0);
	al_flip_display();



	while (!doexit) {        //MAIN GAME LOOP
		ALLEGRO_EVENT ev;

		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			doexit = true;
		}
		else if (ev.type == ALLEGRO_KEY_ESCAPE) {
			al_destroy_event_queue(event_queue);
			al_destroy_display(display);
			doexit = true;
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
			redraw = true;
			while (redraw) {
				if (ev.mouse.x > 18 && ev.mouse.x < 309) {
					redraw = false;
					if (ev.mouse.y > 140 && ev.mouse.y < 276) {
						redraw = false;
						mouseCursor = al_create_mouse_cursor(mouseCursor1, 0, 0);
						al_set_mouse_cursor(display, mouseCursor);
					}
					else if (ev.mouse.y > 329 && ev.mouse.y < 470) {
						redraw = false;
						mouseCursor = al_create_mouse_cursor(mouseCursor1, 0, 0);
						al_set_mouse_cursor(display, mouseCursor);
					}
					else if (ev.mouse.y > 527 && ev.mouse.y < 670) {
						redraw = false;
						mouseCursor = al_create_mouse_cursor(mouseCursor1, 0, 0);
						al_set_mouse_cursor(display, mouseCursor);
					}
					else if (ev.mouse.y > 734 && ev.mouse.y < 871) {
						redraw = false;
						mouseCursor = al_create_mouse_cursor(mouseCursor1, 0, 0);
						al_set_mouse_cursor(display, mouseCursor);
					}
					else {
						if (checkNobat % 2 == 0) {
							mouseCursor = al_create_mouse_cursor(player2, 15, 15);
							al_set_mouse_cursor(display, mouseCursor);
						}
						if (checkNobat % 2 != 0) {
							mouseCursor = al_create_mouse_cursor(player1, 15, 15);
							al_set_mouse_cursor(display, mouseCursor);
						}
						break;
					}

				}
				else if (ev.mouse.x > 1682 && ev.mouse.x < 1894) {
					redraw = false;
					if (ev.mouse.y > 491 && ev.mouse.y < 562) {
						redraw = false;
						mouseCursor = al_create_mouse_cursor(mouseCursor1, 0, 0);
						al_set_mouse_cursor(display, mouseCursor);
						/*	if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ) {
								if(ev.mouse.button & 1){
									if (checkNobat % 2 == 0) {
										passCounterB++;
									}
									else {
										passCounterA++;
									}
								checkNobat++;
								}
							}*/
					}
					else {
						if (checkNobat % 2 == 0) {
							mouseCursor = al_create_mouse_cursor(player2, 15, 15);
							al_set_mouse_cursor(display, mouseCursor);
						}
						if (checkNobat % 2 != 0) {
							mouseCursor = al_create_mouse_cursor(player1, 15, 15);
							al_set_mouse_cursor(display, mouseCursor);
						}
						break;
					}
				}
				else {
					if (checkNobat % 2 == 0) {
						mouseCursor = al_create_mouse_cursor(player2, 15, 15);
						al_set_mouse_cursor(display, mouseCursor);
					}
					if (checkNobat % 2 != 0) {
						mouseCursor = al_create_mouse_cursor(player1, 15, 15);
						al_set_mouse_cursor(display, mouseCursor);
					}
					break;
				}
			}
		}

		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {


			if (ev.mouse.button & 1) {


				if (checkNobat % 2 == 0) {

					mouseCursor = al_create_mouse_cursor(player2, 15, 15);
					al_set_mouse_cursor(display, mouseCursor);
					al_draw_filled_circle(setX(ev.mouse.x), setY(ev.mouse.y), 30, al_map_rgb(255, 255, 255));
					printf("%d  %d  %d\n", setX(ev.mouse.x), setY(ev.mouse.y), passCounterB);
					printf("%d  %d \n", andisY(setY(ev.mouse.y)), andisX(setX(ev.mouse.x)));

					if (alowStone(nutA, nutB, passCounterA, passCounterB, setButton(setX(ev.mouse.x), ev.mouse.y), suicide(andisY(setY(ev.mouse.y)), andisX(setX(ev.mouse.x)), doexit))) {

						printf("%d  %d  %d\n", setX(ev.mouse.x), setY(ev.mouse.y), passCounterB);
						passCounterB = 0;
						boardhelp[andisY(setY(ev.mouse.y))][andisX(setX(ev.mouse.x))] = 2;
						nutB++;
						checkNobat++;
						int yy = andisX(setX(ev.mouse.x));
						int xx = andisY(setY(ev.mouse.y));
						free1 = 1;
						inimark();
						dfs(xx, yy, boardhelp[xx][yy]);
						if (free1) {
							inimark();
							dfs2(xx, yy, 2);
							refresh();
						}
						free1 = 0;
						inimark();
						if (check(xx + 1, yy) && boardhelp[xx + 1][yy]) free1 = 1, dfs(xx + 1, yy, boardhelp[xx + 1][yy]);
						if (free1) {
							inimark();
							dfs2(xx + 1, yy, boardhelp[xx + 1][yy]);
							refresh();
						}
						free1 = 0;
						inimark();
						if (check(xx - 1, yy) && boardhelp[xx - 1][yy]) free1 = 1, dfs(xx - 1, yy, boardhelp[xx - 1][yy]);
						if (free1) {
							inimark();
							dfs2(xx - 1, yy, boardhelp[xx - 1][yy]);
							refresh();
						}
						free1 = 0;
						inimark();
						if (check(xx, yy + 1) && boardhelp[xx][yy + 1]) free1 = 1, dfs(xx, yy + 1, boardhelp[xx][yy + 1]);
						if (free1) {
							inimark();
							dfs2(xx, yy + 1, boardhelp[xx][yy + 1]);
							refresh();
						}
						free1 = 0;
						inimark();
						if (check(xx, yy - 1) && boardhelp[xx][yy - 1]) free1 = 1, dfs(xx, yy - 1, boardhelp[xx][yy - 1]);
						if (free1) {
							inimark();
							dfs2(xx, yy - 1, boardhelp[xx][yy - 1]);
							refresh();
						}

					}
					else if (setX(ev.mouse.x) == 3) {

						checkNobat++;
						passCounterB++;
					}
				}
				else {

					mouseCursor = al_create_mouse_cursor(player1, 15, 15);
					al_set_mouse_cursor(display, mouseCursor);

					al_draw_filled_circle(setX(ev.mouse.x), setY(ev.mouse.y), 30, al_map_rgb(0, 0, 0));

					printf("%d  %d \n", andisY(setY(ev.mouse.y)), andisX(setX(ev.mouse.x)));
					if (alowStone(nutA, nutB, passCounterA, passCounterB, setButton(setX(ev.mouse.x), ev.mouse.y), suicide(andisY(setY(ev.mouse.y)), andisX(setX(ev.mouse.x)), doexit))) {
						passCounterA = 0;
						printf("%d  %d  %d\n", setX(ev.mouse.x), setY(ev.mouse.y), passCounterB);
						boardhelp[andisY(setY(ev.mouse.y))][andisX(setX(ev.mouse.x))] = 1;
						nutA++;
						checkNobat++;

						int yy = andisX(setX(ev.mouse.x));
						int xx = andisY(setY(ev.mouse.y));
						free1 = 1;

						inimark();
						dfs(xx, yy, boardhelp[xx][yy]);
						//	printf("free1 = %d", free1);
						if (free1) {
							inimark();
							dfs2(xx, yy, 1);
							refresh();
						}
						free1 = 0;
						inimark();
						if (check(xx + 1, yy) && boardhelp[xx + 1][yy]) free1 = 1, dfs(xx + 1, yy, boardhelp[xx + 1][yy]);
						if (free1) {
							inimark();
							dfs2(xx + 1, yy, boardhelp[xx + 1][yy]);
							refresh();
						}
						free1 = 0;
						inimark();
						if (check(xx - 1, yy) && boardhelp[xx - 1][yy]) free1 = 1, dfs(xx - 1, yy, boardhelp[xx - 1][yy]);
						if (free1) {
							inimark();
							dfs2(xx - 1, yy, boardhelp[xx - 1][yy]);
							refresh();
						}
						free1 = 0;
						inimark();
						if (check(xx, yy + 1) && boardhelp[xx][yy + 1]) free1 = 1, dfs(xx, yy + 1, boardhelp[xx][yy + 1]);
						if (free1) {
							inimark();
							dfs2(xx, yy + 1, boardhelp[xx][yy + 1]);
							refresh();
						}
						free1 = 0;
						inimark();
						if (check(xx, yy - 1) && boardhelp[xx][yy - 1]) free1 = 1, dfs(xx, yy - 1, boardhelp[xx][yy - 1]);
						if (free1) {
							inimark();
							dfs2(xx, yy - 1, boardhelp[xx][yy - 1]);
							refresh();
						}
					}
					else if (setX(ev.mouse.x) == 3) {

						checkNobat++;
						passCounterA++;
					}
				}

				arayPrint(boardhelp);
				printf("\n\n\n\n\n\n");
				al_flip_display();
			}

		}

		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (ev.mouse.button & 1) {
				if (checkNobat % 2 == 0) {
					if (passCounterB == 2 || passCounterA == 2) {
						doexit = true;
					}

					mouseCursor = al_create_mouse_cursor(player2, 15, 15);
					al_set_mouse_cursor(display, mouseCursor);
				}
				else {
					if (passCounterB == 2 || passCounterA == 2) {
						doexit = true;
					}
					mouseCursor = al_create_mouse_cursor(player1, 15, 15);
					al_set_mouse_cursor(display, mouseCursor);
				}
			}
		}

	}

	al_destroy_bitmap(player2);
	al_destroy_bitmap(player1);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
	al_destroy_bitmap(image);
	return 0;
}
