#pragma once
#define _USE_MATH_DEFINES /* FOR M_PI */
#include <math.h>         /* FOR trigonometric function and M_PI   */
#include <windows.h> /* FOR draw graphs in console WIN32API */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "colors.h"
#include "values.h"

/* FLAG */
#define ON true
#define OFF false

 /* Running mode */
#define SLEEP_MODE ON
#define DEBUG_MODE OFF

void draw_graph_console(HDC hdc, double (*func)(double), int rgb);
double calculate_radian(double degree);
double sumof_cos_sin(double x);
double square(double x);
