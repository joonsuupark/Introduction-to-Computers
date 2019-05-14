#include "graph.h"

void draw_graph_console(HDC hdc, double (*func)(double), int rgb)
{
	int degree, x, y;
	double radian, result;
	for (degree = MIN_X; degree <= MAX_X; degree++)
	{
		result = func(calculate_radian((double)degree));
		x = OFFSET_X + degree;
		y = OFFSET_Y - (int)(100.0 * result);
#if DEBUG_MODE
		fprintf(stdout, "%s, %d, %d.\n", "draw_graph_console", x, y);
#else
		SetPixel(hdc, x, y, rgb);
#endif // DEBUG_MODE
#if SLEEP_MODE
		Sleep(5);
#endif
	}
}

double calculate_radian(double degree)
{
	return M_PI * degree / 180.0;
}

double sumof_cos_sin(double x)
{
	return cos(x) + sin(x);
}

double square(double x)
{
	return x * x;
}