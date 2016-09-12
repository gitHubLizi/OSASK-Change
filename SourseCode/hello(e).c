void api_putstr0(char *s);
void api_end(void);

void HariMain(void)
{
	//static char s[8] = {0xe0,0xe1,0xe2,0xe3,0xe4,0xe5,0xe6,0xe7}
	//api_putstr0(s);
	api_putstr0("Hello,World!");
	api_end();
}
