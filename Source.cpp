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
int andis(int i) {
	if (i == 47)
		return 0;
	if (i == 118)
		return 1;
	if (i == 187)
		return 2;
	if (i == 260)
		return 3;
	if (i == 333)
		return 4;
	if (i == 405)
		return 5;
	if (i == 477)
		return 6;
	if (i == 548)
		return 7;
	if (i == 621)
		return 8;
	if (i == 688)
		return 9;
}

int setX(int x) {
	if (x > 0 && x < 83)
		return 47;
	if (x > 83 && x < 153)
		return 118;
	if (x > 153 && x < 224)
		return 187;
	if (x > 224 && x < 297)
		return 260;
	if (x > 297 && x < 369)
		return 333;
	if (x > 369 && x < 441)
		return 405;
	if (x > 441 && x < 513)
		return 477;
	if (x > 513 && x < 585)
		return 548;
	if (x > 585 && x < 655)
		return 621;
	if (x > 655 && x < 750)
		return 688;
}
int setY(int y) {
	if (y > 0 && y< 83)
		return 47;
	if (y > 83 && y < 153)
		return 118;
	if (y > 153 && y < 224)
		return 187;
	if (y > 224 && y < 297)
		return 260;
	if (y > 297 && y < 369)
		return 333;
	if (y > 369 && y < 441)
		return 405;
	if (y > 441 && y < 513)
		return 477;
	if (y > 513 && y < 585)
		return 548;
	if (y > 585 && y < 655)
		return 621;
	if (y > 655 && y < 750)
		return 688;

}
void arayPrint(int a[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

int main(int argc, char **argv) {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *image = NULL;
	ALLEGRO_DISPLAY_MODE   disp_data;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_MOUSE_CURSOR *mouseCursor = NULL;
	//	ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
	ALLEGRO_BITMAP *player1 = NULL;
	ALLEGRO_BITMAP *player2 = NULL;

	int boardhelp[10][10];
	for (int i1=0; i1 < 10; i1++)
		for (int i2=0; i2 < 10; i2++)
			boardhelp[i1][i2] = 0;

	const int komi = 6.5;
	char board[9][9];
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

	/*al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);
	al_set_new_display_flags(ALLEGRO_FULLSCREEN);*/
	display = al_create_display(750, 750);
	al_clear_to_color(al_map_rgb(192, 192, 192));
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


	image = al_load_bitmap("1.jpg");
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
	al_draw_bitmap(image, 45,45,0);
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
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (ev.mouse.button & 1) {
				if(checkNobat%2==0){
						mouseCursor = al_create_mouse_cursor(player2, 15, 15);
						al_set_mouse_cursor(display, mouseCursor);
						al_draw_filled_circle(setX(ev.mouse.x), setY(ev.mouse.y), 20, al_map_rgb(255, 255, 255));
						boardhelp[andis(setX(ev.mouse.y))][andis(setY(ev.mouse.x))] = 2;
					checkNobat++;
				}
				else {
						mouseCursor = al_create_mouse_cursor(player1, 15, 15);
						al_set_mouse_cursor(display, mouseCursor);
						al_draw_filled_circle(setX(ev.mouse.x), setY(ev.mouse.y), 20, al_map_rgb(0, 0, 0));
						boardhelp[andis(setX(ev.mouse.y))][andis(setY(ev.mouse.x))] = 1;
					checkNobat++;
				}
			}
			arayPrint(boardhelp);
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
