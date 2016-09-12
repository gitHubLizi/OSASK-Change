int api_openwin(char *buf, int xsiz, int ysiz, int col_inv, char *title);
void api_initmalloc(void);
char *api_malloc(int size);
void api_refreshwin(int win, int x0, int y0, int x1, int y1);
void api_linewin(int win, int x0, int y0, int x1, int y1, int col);
int api_getkey(int mode);
void api_end(void);

void HariMain(void)
{
	char *buf;
	int win, x, y, r, g, b;
	int size_x = 144;
	int size_y = size_x + 20;
	int size = 8;
	api_initmalloc();
	buf = api_malloc(size_x * size_y);
	win = api_openwin(buf, size_x, size_y, -1, "color5");
	for (y = 0; y < size_x - 16; y++) {
		for (x = 0; x < size_x - 16; x++) {
			r = x * 2;
			g = y * 2;
			b = 0;
			buf[(x + size) + (y + size + 20) * size_x] = 36 * 3 + (r / 43) + (g / 43) * 6 + (b / 43) * 36;
		}
	}
	api_refreshwin(win, size, size + 20, size_x - size, size_y - size);
	api_getkey(1); 
	api_end();
}
