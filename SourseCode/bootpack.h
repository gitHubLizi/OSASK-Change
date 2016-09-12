/* asmhead.nas */
struct BOOTINFO { /* 0x0ff0-0x0fff */
	char cyls; /* ブートセクタはどこまでディスクを読んだのか */
	char leds; /* ブート時のキーボードのLEDの状態 */
	char vmode; /* ビデオモード  何ビットカラーか */
	char reserve;
	short scrnx, scrny; /* 画面解像度 */
	char *vram;
};
#define ADR_BOOTINFO	0x00000ff0
#define ADR_DISKIMG		0x00100000

/* naskfunc.nas */
void io_hlt(void);
void io_cli(void);
void io_sti(void);
void io_stihlt(void);
int io_in8(int port);
void io_out8(int port, int data);
int io_load_eflags(void);
void io_store_eflags(int eflags);
void load_gdtr(int limit, int addr);
void load_idtr(int limit, int addr);
int load_cr0(void);
void store_cr0(int cr0);
void load_tr(int tr);
void asm_inthandler0c(void);
void asm_inthandler0d(void);
void asm_inthandler20(void);
void asm_inthandler21(void);
void asm_inthandler2c(void);
unsigned int memtest_sub(unsigned int start, unsigned int end);
void farjmp(int eip, int cs);
void farcall(int eip, int cs);
void asm_hrb_api(void);
void start_app(int eip, int cs, int esp, int ds, int *tss_esp0);
void asm_end_app(void);

/* fifo.c */
struct FIFO32 {
	int *buf;
	int p, q, size, free, flags;
	struct TASK *task;
};
void fifo32_init(struct FIFO32 *fifo, int size, int *buf, struct TASK *task);
int fifo32_put(struct FIFO32 *fifo, int data);
int fifo32_get(struct FIFO32 *fifo);
int fifo32_status(struct FIFO32 *fifo);

/* music.c */
void api_end(void);
int api_getkey(int mode);
int api_alloctimer(void);
void api_inittimer(int timer, int data);
void api_settimer(int timer, int time);
void api_beep(int tone);

#define C  1308100
#define Db 1385900
#define D  1468300
#define Eb 1555600
#define E  1648100
#define F  1746100
#define Gb 1850100
#define G  1960000
#define Ab 2076500
#define A  2200000
#define Bb 2330840
#define B  2469400

/* graphic.c */
void init_palette(void);
void set_palette(int start, int end, unsigned char *rgb);
void boxfill8(unsigned char *vram, int xsize, unsigned char c, int x0, int y0, int x1, int y1);
void init_screen8(char *vram, int x, int y);
void putfont8(char *vram, int xsize, int x, int y, char c, char *font);
void putfonts8_asc(char *vram, int xsize, int x, int y, char c, unsigned char *s);
void init_mouse_cursor8(char *mouse, char bc);
void putblock8_8(char *vram, int vxsize, int pxsize,
int pysize, int px0, int py0, char *buf, int bxsize);

#define COL8_FFFFFF 0
#define COL8_FFFFCC 1
#define COL8_FFFF99 2
#define COL8_FFFF66 3
#define COL8_FFFF33 4
#define COL8_FFFF00 5
#define COL8_FFCCFF 6
#define COL8_FFCCCC 7
#define COL8_FFCC99 8
#define COL8_FFCC66 9
#define COL8_FFCC33 10
#define COL8_FFCC00 11
#define COL8_FF99FF 12
#define COL8_FF99CC 13
#define COL8_FF9999 14
#define COL8_FF9966 15
#define COL8_FF9933 16
#define COL8_FF9900 17
#define COL8_FF66FF 18
#define COL8_FF66CC 19
#define COL8_FF6699 20
#define COL8_FF6666 21
#define COL8_FF6633 22
#define COL8_FF6600 23
#define COL8_FF33FF 24
#define COL8_FF33CC 25
#define COL8_FF3399 26
#define COL8_FF3366 27
#define COL8_FF3333 28
#define COL8_FF3300 29
#define COL8_FF00FF 30
#define COL8_FF00CC 31
#define COL8_FF0099 32
#define COL8_FF0066 33
#define COL8_FF0033 34
#define COL8_FF0000 35
#define COL8_66FFFF 36
#define COL8_66FFCC 37
#define COL8_66FF99 38
#define COL8_66FF66 39
#define COL8_66FF33 40
#define COL8_66FF00 41
#define COL8_66CCFF 42
#define COL8_66CCCC 43
#define COL8_66CC99 44
#define COL8_66CC66 45
#define COL8_66CC33 46
#define COL8_66CC00 47
#define COL8_6699FF 48
#define COL8_6699CC 49
#define COL8_669999 50
#define COL8_669966 51
#define COL8_669933 52
#define COL8_669900 53
#define COL8_6666FF 54
#define COL8_6666CC 55
#define COL8_666699 56
#define COL8_666666 57
#define COL8_666633 58
#define COL8_666600 59
#define COL8_6633FF 60
#define COL8_6633CC 61
#define COL8_663399 62
#define COL8_663366 63
#define COL8_663333 64
#define COL8_663300 65
#define COL8_6600FF 66
#define COL8_6600CC 67
#define COL8_660099 68
#define COL8_660066 69
#define COL8_660033 70
#define COL8_660000 71
#define COL8_CCFFFF 72
#define COL8_CCFFCC 73
#define COL8_CCFF99 74
#define COL8_CCFF66 75
#define COL8_CCFF33 76
#define COL8_CCFF00 77
#define COL8_CCCCFF 78
#define COL8_CCCCCC 79
#define COL8_CCCC99 80
#define COL8_CCCC66 81
#define COL8_CCCC33 82
#define COL8_CCCC00 83
#define COL8_CC99FF 84
#define COL8_CC99CC 85
#define COL8_CC9999 86
#define COL8_CC9966 87
#define COL8_CC9933 88
#define COL8_CC9900 89
#define COL8_CC66FF 90
#define COL8_CC66CC 91
#define COL8_CC6699 92
#define COL8_CC6666 93
#define COL8_CC6633 94
#define COL8_CC6600 95
#define COL8_CC33FF 96
#define COL8_CC33CC 97
#define COL8_CC3399 98
#define COL8_CC3366 99
#define COL8_CC3333 100
#define COL8_CC3300 101
#define COL8_CC00FF 102
#define COL8_CC00CC 103
#define COL8_CC0099 104
#define COL8_CC0066 105
#define COL8_CC0033 106
#define COL8_CC0000 107
#define COL8_33FFFF 108
#define COL8_33FFCC 109
#define COL8_33FF99 110
#define COL8_33FF66 111
#define COL8_33FF33 112
#define COL8_33FF00 113
#define COL8_33CCFF 114
#define COL8_33CCCC 115
#define COL8_33CC99 116
#define COL8_33CC66 117
#define COL8_33CC33 118
#define COL8_33CC00 119
#define COL8_3399FF 120
#define COL8_3399CC 121
#define COL8_339999 122
#define COL8_339966 123
#define COL8_339933 124
#define COL8_339900 125
#define COL8_3366FF 126
#define COL8_3366CC 127
#define COL8_336699 128
#define COL8_336666 129
#define COL8_336633 130
#define COL8_336600 131
#define COL8_3333FF 132
#define COL8_3333CC 133
#define COL8_333399 134
#define COL8_333366 135
#define COL8_333333 136
#define COL8_333300 137
#define COL8_3300FF 138
#define COL8_3300CC 139
#define COL8_330099 140
#define COL8_330066 141
#define COL8_330033 142
#define COL8_330000 143
#define COL8_99FFFF 144
#define COL8_99FFCC 145
#define COL8_99FF99 146
#define COL8_99FF66 147
#define COL8_99FF33 148
#define COL8_99FF00 149
#define COL8_99CCFF 150
#define COL8_99CCCC 151
#define COL8_99CC99 152
#define COL8_99CC66 153
#define COL8_99CC33 154
#define COL8_99CC00 155
#define COL8_9999FF 156
#define COL8_9999CC 157
#define COL8_999999 158
#define COL8_999966 159
#define COL8_999933 160
#define COL8_999900 161
#define COL8_9966FF 162
#define COL8_9966CC 163
#define COL8_996699 164
#define COL8_996666 165
#define COL8_996633 166
#define COL8_996600 167
#define COL8_9933FF 168
#define COL8_9933CC 169
#define COL8_993399 170
#define COL8_993366 171
#define COL8_993333 172
#define COL8_993300 173
#define COL8_9900FF 174
#define COL8_9900CC 175
#define COL8_990099 176
#define COL8_990066 177
#define COL8_990033 178
#define COL8_990000 179
#define COL8_00FFFF 180
#define COL8_00FFCC 181
#define COL8_00FF99 182
#define COL8_00FF66 183
#define COL8_00FF33 184
#define COL8_00FF00 185
#define COL8_00CCFF 186
#define COL8_00CCCC 187
#define COL8_00CC99 188
#define COL8_00CC66 189
#define COL8_00CC33 190
#define COL8_00CC00 191
#define COL8_0099FF 192
#define COL8_0099CC 193
#define COL8_009999 194
#define COL8_009966 195
#define COL8_009933 196
#define COL8_009900 197
#define COL8_0066FF 198
#define COL8_0066CC 199
#define COL8_006699 200
#define COL8_006666 201
#define COL8_006633 202
#define COL8_006600 203
#define COL8_0033FF 204
#define COL8_0033CC 205
#define COL8_003399 206
#define COL8_003366 207
#define COL8_003333 208
#define COL8_003300 209
#define COL8_0000FF 210
#define COL8_0000CC 212
#define COL8_000099 213
#define COL8_000066 214
#define COL8_000033 215
#define COL8_000000 216


/* dsctbl.c */
struct SEGMENT_DESCRIPTOR {
	short limit_low, base_low;
	char base_mid, access_right;
	char limit_high, base_high;
};
struct GATE_DESCRIPTOR {
	short offset_low, selector;
	char dw_count, access_right;
	short offset_high;
};
void init_gdtidt(void);
void set_segmdesc(struct SEGMENT_DESCRIPTOR *sd, unsigned int limit, int base, int ar);
void set_gatedesc(struct GATE_DESCRIPTOR *gd, int offset, int selector, int ar);
#define ADR_IDT			0x0026f800
#define LIMIT_IDT		0x000007ff
#define ADR_GDT			0x00270000
#define LIMIT_GDT		0x0000ffff
#define ADR_BOTPAK		0x00280000
#define LIMIT_BOTPAK	0x0007ffff
#define AR_DATA32_RW	0x4092
#define AR_CODE32_ER	0x409a
#define AR_LDT			0x0082
#define AR_TSS32		0x0089
#define AR_INTGATE32	0x008e

/* int.c */
void init_pic(void);
#define PIC0_ICW1		0x0020
#define PIC0_OCW2		0x0020
#define PIC0_IMR		0x0021
#define PIC0_ICW2		0x0021
#define PIC0_ICW3		0x0021
#define PIC0_ICW4		0x0021
#define PIC1_ICW1		0x00a0
#define PIC1_OCW2		0x00a0
#define PIC1_IMR		0x00a1
#define PIC1_ICW2		0x00a1
#define PIC1_ICW3		0x00a1
#define PIC1_ICW4		0x00a1

/* keyboard.c */
void inthandler21(int *esp);
void wait_KBC_sendready(void);
void init_keyboard(struct FIFO32 *fifo, int data0);
#define PORT_KEYDAT		0x0060
#define PORT_KEYCMD		0x0064

/* mouse.c */
struct MOUSE_DEC {
	unsigned char buf[3], phase;
	int x, y, btn;
};
void inthandler2c(int *esp);
void enable_mouse(struct FIFO32 *fifo, int data0, struct MOUSE_DEC *mdec);
int mouse_decode(struct MOUSE_DEC *mdec, unsigned char dat);

/* memory.c */
#define MEMMAN_FREES		4090	/* これで約32KB */
#define MEMMAN_ADDR			0x003c0000
struct FREEINFO {	/* あき情報 */
	unsigned int addr, size;
};
struct MEMMAN {		/* メモリ管理 */
	int frees, maxfrees, lostsize, losts;
	struct FREEINFO free[MEMMAN_FREES];
};
unsigned int memtest(unsigned int start, unsigned int end);
void memman_init(struct MEMMAN *man);
unsigned int memman_total(struct MEMMAN *man);
unsigned int memman_alloc(struct MEMMAN *man, unsigned int size);
int memman_free(struct MEMMAN *man, unsigned int addr, unsigned int size);
unsigned int memman_alloc_4k(struct MEMMAN *man, unsigned int size);
int memman_free_4k(struct MEMMAN *man, unsigned int addr, unsigned int size);

/* sheet.c */
#define MAX_SHEETS		256
struct SHEET {
	unsigned char *buf;
	int bxsize, bysize, vx0, vy0, col_inv, height, flags;
	struct SHTCTL *ctl;
	struct TASK *task;
};
struct SHTCTL {
	unsigned char *vram, *map;
	int xsize, ysize, top;
	struct SHEET *sheets[MAX_SHEETS];
	struct SHEET sheets0[MAX_SHEETS];
};
struct SHTCTL *shtctl_init(struct MEMMAN *memman, unsigned char *vram, int xsize, int ysize);
struct SHEET *sheet_alloc(struct SHTCTL *ctl);
void sheet_setbuf(struct SHEET *sht, unsigned char *buf, int xsize, int ysize, int col_inv);
void sheet_updown(struct SHEET *sht, int height);
void sheet_refresh(struct SHEET *sht, int bx0, int by0, int bx1, int by1);
void sheet_slide(struct SHEET *sht, int vx0, int vy0);
void sheet_free(struct SHEET *sht);

/* timer.c */
#define MAX_TIMER		500
struct TIMER {
	struct TIMER *next;
	unsigned int timeout;
	char flags, flags2;
	struct FIFO32 *fifo;
	int data;
};
struct TIMERCTL {
	unsigned int count, next;
	struct TIMER *t0;
	struct TIMER timers0[MAX_TIMER];
};
extern struct TIMERCTL timerctl;
void init_pit(void);
struct TIMER *timer_alloc(void);
void timer_free(struct TIMER *timer);
void timer_init(struct TIMER *timer, struct FIFO32 *fifo, int data);
void timer_settime(struct TIMER *timer, unsigned int timeout);
void inthandler20(int *esp);
int timer_cancel(struct TIMER *timer);
void timer_cancelall(struct FIFO32 *fifo);

/* mtask.c */
#define MAX_TASKS		1000	/* 最大タスク数 */
#define TASK_GDT0		3		/* TSSをGDTの何番から割り当てるのか */
#define MAX_TASKS_LV	100
#define MAX_TASKLEVELS	10
struct TSS32 {
	int backlink, esp0, ss0, esp1, ss1, esp2, ss2, cr3;
	int eip, eflags, eax, ecx, edx, ebx, esp, ebp, esi, edi;
	int es, cs, ss, ds, fs, gs;
	int ldtr, iomap;
};
struct TASK {
	int sel, flags; /* selはGDTの番号のこと */
	int level, priority;
	struct FIFO32 fifo;
	struct TSS32 tss;
	struct SEGMENT_DESCRIPTOR ldt[2];
	struct CONSOLE *cons;
	int ds_base, cons_stack;
};
struct TASKLEVEL {
	int running; /* 動作しているタスクの数 */
	int now; /* 現在動作しているタスクがどれだか分かるようにするための変数 */
	struct TASK *tasks[MAX_TASKS_LV];
};
struct TASKCTL {
	int now_lv; /* 現在動作中のレベル */
	char lv_change; /* 次回タスクスイッチのときに、レベルも変えたほうがいいかどうか */
	struct TASKLEVEL level[MAX_TASKLEVELS];
	struct TASK tasks0[MAX_TASKS];
};
extern struct TASKCTL *taskctl;
extern struct TIMER *task_timer;
struct TASK *task_now(void);
struct TASK *task_init(struct MEMMAN *memman);
struct TASK *task_alloc(void);
void task_run(struct TASK *task, int level, int priority);
void task_switch(void);
void task_sleep(struct TASK *task);

/* window.c */
void make_window8(unsigned char *buf, int xsize, int ysize, char *title, char act);
void putfonts8_asc_sht(struct SHEET *sht, int x, int y, int c, int b, char *s, int l);
void make_textbox8(struct SHEET *sht, int x0, int y0, int sx, int sy, int c);
void make_wtitle8(unsigned char *buf, int xsize, char *title, char act);
void change_wtitle8(struct SHEET *sht, char act);

/* console.c */
struct CONSOLE {
	struct SHEET *sht;
	int cur_x, cur_y, cur_c;
	struct TIMER *timer;
};
void console_task(struct SHEET *sheet, int memtotal);
void cons_putchar(struct CONSOLE *cons, int chr, char move);
void cons_newline(struct CONSOLE *cons);
void cons_putstr0(struct CONSOLE *cons, char *s);
void cons_putstr1(struct CONSOLE *cons, char *s, int l);
void cons_runcmd(char *cmdline, struct CONSOLE *cons, int *fat, int memtotal);
void cmd_mem(struct CONSOLE *cons, int memtotal);
void cmd_cls(struct CONSOLE *cons);
void cmd_dir(struct CONSOLE *cons);
void cmd_type(struct CONSOLE *cons, int *fat, char *cmdline);
void cmd_exit(struct CONSOLE *cons, int *fat);
void cmd_start(struct CONSOLE *cons, char *cmdline, int memtotal);
void cmd_ncst(struct CONSOLE *cons, char *cmdline, int memtotal);
int cmd_app(struct CONSOLE *cons, int *fat, char *cmdline);
int *hrb_api(int edi, int esi, int ebp, int esp, int ebx, int edx, int ecx, int eax);
int *inthandler0d(int *esp);
int *inthandler0c(int *esp);
void hrb_api_linewin(struct SHEET *sht, int x0, int y0, int x1, int y1, int col);

/* file.c */
struct FILEINFO {
	unsigned char name[8], ext[3], type;
	char reserve[10];
	unsigned short time, date, clustno;
	unsigned int size;
};
void file_readfat(int *fat, unsigned char *img);
void file_loadfile(int clustno, int size, char *buf, int *fat, char *img);
struct FILEINFO *file_search(char *name, struct FILEINFO *finfo, int max);

/* bootpack.c */
struct TASK *open_constask(struct SHEET *sht, unsigned int memtotal);
struct SHEET *open_console(struct SHTCTL *shtctl, unsigned int memtotal);
