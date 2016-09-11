void api_putchar(int c);
void api_end(void);

void HariMain(void)
{
	api_putchar(0xe0);
	api_putchar(0xe1);
	api_putchar(0xe2);
	api_putchar(0xe3);
	api_putchar(0xe4);
	api_putchar(0xe5);
	api_putchar(0xe6);
	api_putchar(0xe7);
	api_end();
}
