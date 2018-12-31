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


ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT ev;
ALLEGRO_BITMAP *player1 = NULL;
ALLEGRO_BITMAP *player2 = NULL;

int boardhelp[10][10] , mark[10][10] ;
int free1 =0 ;

void ini() {
	for (int i1 = 0; i1 < 10; i1++)
		for (int i2 = 0; i2 < 10; i2++)
			boardhelp[i1][i2] = 0;
}

void inimark() {
	for (int i1 = 0; i1 < 10; i1++)
		for (int i2 = 0; i2 < 10; i2++)
			mark[i1][i2] = 0;
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
	if (i == 810 )
		return 1;
	if (i == 918 )
		return 2;
	if (i == 1026 )
		return 3;
	if (i == 1134 )
		return 4;
	if (i == 1242 )
		return 5;
	if (i == 1350 )
		return 6;
	if (i == 1458)
		return 7;
	if (i == 1566)
		return 8;
	if (i == 1674 )
		return 9;
}
int setX(int x) {
	if (x > 680 && x < 1700 ){
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
	else {
		al_show_native_message_box(display, "Error", "Error", "Invalied Position",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -2;
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
		al_show_native_message_box(display, "Error", "Error", "Invalied Position",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -3;

	}

}

void arayPrint(int a[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

bool check(int i, int j) {
	if (i < 10 && j < 10 && i >= 0 && j >= 0) return 1;
	return 0 ;
}

void dfs(int i , int j , int sw) {
	int sw2 = 0 ; 
	mark[i][j] = 1;

//	printf("i = %d j = %d \n", i, j);
//	printf("118\n");

	if (check(i + 1, j) && !mark[i+1][j] && boardhelp[i + 1][j] == sw) dfs(i + 1 , j , sw) ;
	if (check(i - 1, j) && !mark[i-1][j] && boardhelp[i - 1][j] == sw) dfs(i - 1 , j , sw) ;
	if (check(i, j + 1) && !mark[i][j+1] && boardhelp[i][j + 1] == sw) dfs(i , j + 1 , sw) ;
	if (check(i, j - 1) && !mark[i][j-1] && boardhelp[i][j - 1] == sw) dfs(i , j - 1 , sw) ;

	if (check(i + 1, j) && !boardhelp[i + 1][j]) sw2 = 1 ;
	if (check(i - 1, j) && !boardhelp[i - 1][j]) sw2 = 1 ;
	if (check(i, j + 1) && !boardhelp[i][j + 1]) sw2 = 1 ;
	if (check(i, j - 1) && !boardhelp[i][j - 1]) sw2 = 1 ;

//	printf("sw2 = %d \n" , sw2);
	if (sw2) free1 = 0 ; 
}

void dfs2(int i, int j, int sw) {
//	printf("i = %d j = %d \n", i, j);
//	printf("125\n") ;
	mark[i][j] = 1;
	boardhelp[i][j] = 0;
	if (check(i + 1, j) && !mark[i+1][j] && boardhelp[i + 1][j] == sw) boardhelp[i + 1][j] = 0 , dfs2(i + 1, j, sw) ;
	if (check(i - 1, j) && !mark[i-1][j] && boardhelp[i - 1][j] == sw) boardhelp[i - 1][j] = 0 , dfs2(i - 1, j, sw) ;
	if (check(i, j + 1) && !mark[i][j+1] && boardhelp[i][j + 1] == sw) boardhelp[i][j + 1] = 0 , dfs2(i, j + 1, sw) ;
	if (check(i, j - 1) && !mark[i][j-1] && boardhelp[i][j - 1] == sw) boardhelp[i][j - 1] = 0 , dfs2(i, j - 1, sw) ;
}

bool alowStone() {
	if (setX(ev.mouse.x)!= -2 && setY(ev.mouse.y)!= -3)
		return true;



	return false;
}


int main(int argc, char **argv) {
	
	ALLEGRO_BITMAP  *image = NULL;
	ALLEGRO_DISPLAY_MODE   disp_data;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_MOUSE_CURSOR *mouseCursor = NULL;
	//	ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
	

	ini() ;
	
	const int komi = 6.5;
//	char board[9][9];
	bool redraw = false;
	bool doexit = false;
	int checkNobat = 1;


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
	al_clear_to_color(al_map_rgb(255,203,98));
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

	mouseCursor = al_create_mouse_cursor(player1, 15, 15);
	if (!mouseCursor) {
		return 50;
	}
	al_set_mouse_cursor(display, mouseCursor);
	//al_register_event_source(event_queue,al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_draw_bitmap(image, 0,0,0);
	al_flip_display();



	while (!doexit) {        //MAIN GAME LOOP
		
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
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (ev.mouse.button & 1) {
				if(checkNobat%2==0) {
					if (alowStone()) {
						mouseCursor = al_create_mouse_cursor(player2, 15, 15);
						al_set_mouse_cursor(display, mouseCursor);
						al_draw_filled_circle(setX(ev.mouse.x), setY(ev.mouse.y), 30, al_map_rgb(255, 255, 255));
							boardhelp[andisY(setY(ev.mouse.y))][andisX(setX(ev.mouse.x))] = 2;
						checkNobat++;
						//printf("%f  %f \n", setX(ev.mouse.x), setY(ev.mouse.y));
						//printf("%d  %d \n", andisY(setY(ev.mouse.y)), andisX(setX(ev.mouse.x)));
						int yy = andisX(setX(ev.mouse.x)) ;
						int xx = andisY(setY(ev.mouse.y)) ;
						free1 = 1 ;

						inimark() ;
						dfs(xx, yy, boardhelp[xx][yy]);
						if (free1) {
							inimark();
							dfs2(xx, yy, 2);
						}
						free1 = 0;
						inimark();
						if (check(xx + 1, yy) && boardhelp[xx + 1][yy]) free1=1 , dfs(xx + 1, yy, boardhelp[xx + 1][yy]);
						if (free1) {
							inimark();
							dfs2(xx+1, yy, boardhelp[xx + 1][yy]);
						}
						free1 = 0;
						inimark();
						if (check(xx - 1, yy) && boardhelp[xx - 1][yy]) free1=1 , dfs(xx - 1, yy, boardhelp[xx - 1][yy]);
						if (free1) {
							inimark();
							dfs2(xx-1, yy, boardhelp[xx - 1][yy]);
						}
						free1 = 0;
						inimark();
						if (check(xx, yy + 1) && boardhelp[xx][yy + 1]) free1=1 , dfs(xx, yy + 1, boardhelp[xx][yy + 1]);
						if (free1) {
							inimark();
							dfs2(xx, yy+1, boardhelp[xx][yy + 1]);
						}
						free1 = 0;
						inimark();
						if (check(xx, yy - 1) && boardhelp[xx][yy - 1]) free1=1 , dfs(xx, yy - 1, boardhelp[xx][yy - 1]);
						if (free1) {
							inimark();
							dfs2(xx, yy-1, boardhelp[xx][yy - 1]);
						}
					}
					else {
						al_show_native_message_box(display, "Error", "Error", "Move Is invalied!",
							NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}

				}
				else {
					if (alowStone()) {
						mouseCursor = al_create_mouse_cursor(player1, 15, 15);
						al_set_mouse_cursor(display, mouseCursor);
						al_draw_filled_circle(setX(ev.mouse.x), setY(ev.mouse.y), 30, al_map_rgb(0, 0, 0));
						boardhelp[andisY(setY(ev.mouse.y))][andisX(setX(ev.mouse.x))] = 1;
						checkNobat++;
						printf("%d  %d \n", setX(ev.mouse.x), setY(ev.mouse.y));
						//printf("%d  %d \n", andisY(setY(ev.mouse.y)), andisX(setX(ev.mouse.x)));
						int yy = andisX(setX(ev.mouse.x));
						int xx = andisY(setY(ev.mouse.y));
						free1 = 1;

						inimark();
						dfs(xx, yy, boardhelp[xx][yy]);
					//	printf("free1 = %d", free1);
						if (free1) {
							inimark();
							dfs2(xx, yy, 1);
						}
						free1 = 0;
						inimark();
						if (check(xx + 1, yy) && boardhelp[xx + 1][yy]) free1 = 1 , dfs(xx + 1, yy, boardhelp[xx + 1][yy]);
						if (free1) {
							inimark();
							dfs2(xx+1, yy, boardhelp[xx + 1][yy]);
						}
						free1 = 0;
						inimark();
						if (check(xx - 1, yy) && boardhelp[xx - 1][yy]) free1 = 1 , dfs(xx - 1, yy, boardhelp[xx - 1][yy]);
						if (free1) {
							inimark();
							dfs2(xx-1, yy, boardhelp[xx - 1][yy]);
						}
						free1 = 0;
						inimark();
						if (check(xx, yy + 1) && boardhelp[xx][yy + 1]) free1=1 , dfs(xx, yy + 1, boardhelp[xx][yy + 1]);
						if (free1) {
							inimark();
							dfs2(xx, yy+1, boardhelp[xx][yy + 1]);
						}
						free1 = 0;
						inimark();
						if (check(xx, yy - 1) && boardhelp[xx][yy - 1]) free1=1 , dfs(xx, yy - 1, boardhelp[xx][yy - 1]);
						if (free1) {
							inimark();
							dfs2(xx, yy-1, boardhelp[xx][yy - 1]);
						}
					}
					else {
						al_show_native_message_box(display, "Error", "Error", "Move Is invalied!",
							NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
				}
			}
			arayPrint(boardhelp);
			printf("\n\n\n\n\n\n");
			al_flip_display();
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (ev.mouse.button & 1) {
				if (checkNobat % 2 == 0) {
					mouseCursor = al_create_mouse_cursor(player2, 15, 15);
					al_set_mouse_cursor(display, mouseCursor);		
				}
				else {
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
