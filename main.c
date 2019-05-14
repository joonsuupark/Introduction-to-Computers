/*
 * File: main.c
 * File Created: Monday, 6th May 2019 11:51:50 am
 * Author: joonsuupark (parkjoonsuu@gmail.com)
 * -----
 * Last Modified: Tuesday, 14th May 2019 7:26:15 pm
 * Modified By: joonsuupark (parkjoonsuu@kmu.ac.kr)
 * -----
 * Copyright 2019 Dept. of Computer Engineering, Keimyung University
 */

#include "colors.h"
#include "values.h"
#include "graph.h"

errno_t system_setting()
{
	errno_t err = errno;
	if (err = system("mode con:cols=200 lines=30")) {
		fprintf(stderr, "screen clear error, ERROR_CODE: %d", err);
		return errno;
	}
	return errno;
}

void clear_buff(FILE* in)
{
	int c;
	while ((c = fgetc(in)) != EOF && c != '\n');
}

void show_menu() {
	printf("=====0. QUIT\n");
	printf("=====1. sin\n");
	printf("=====2. cos\n");
	printf("=====3. tan\n");
	printf("=====4. cos(x) + sin(x)\n");
	printf("=====5. x^2\n");
	printf("select a menu: ");
}

int main(void)
{
	HWND hwnd = GetForegroundWindow();
	HDC hdc = GetWindowDC(hwnd);
	typedef double (*FunctionCallback)(double);
	FunctionCallback functions[] = { NULL, &sin, &cos, &tan, &sumof_cos_sin, &square };
	errno_t err = errno;
	if (err = system_setting()) {
		exit(EXIT_FAILURE);
	}

	int menu;
	do {
		system("cls");
		show_menu();
		menu = getchar() - '0';
		clear_buff(stdin);
		if (menu > 0 && menu <= 5) {
			system("cls");
#if !DEBUG_MODE
			SelectObject(hdc, GetStockObject(DC_PEN));
			SetDCPenColor(hdc, RGB(255, 255, 255));
			/* Draw the x axes  */
			MoveToEx(hdc, 0, OFFSET_Y, 0);
			LineTo(hdc, MAX_X_AXES, OFFSET_Y);

			/* Draw the y axes  */
			MoveToEx(hdc, OFFSET_X, MAX_Y_AXES, 0);
			LineTo(hdc, OFFSET_X, 100);
#endif // DEBUG_MODE
			draw_graph_console(hdc, functions[menu], RGB_GREEN);
		}
		printf("Press enter to continue...\n");
		system("pause");

	} while (menu != 0);
	return EXIT_SUCCESS;
}