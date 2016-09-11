OBJS_BOOTPACK = bootpack.obj naskfunc.obj hankaku.obj graphic.obj dsctbl.obj \
		int.obj fifo.obj keyboard.obj mouse.obj memory.obj sheet.obj timer.obj \
		mtask.obj window.obj console.obj file.obj

OBJS_API =	api001.obj api002.obj api003.obj api004.obj api005.obj api006.obj \
			api007.obj api008.obj api009.obj api010.obj api011.obj api012.obj \
			api013.obj api014.obj api015.obj api016.obj api017.obj api018.obj \
			api019.obj api020.obj

TOOLPATH = ../z_tools/
INCPATH  = ../z_tools/haribote/

MAKE     = $(TOOLPATH)make.exe -r
NASK     = $(TOOLPATH)nask.exe
CC1      = $(TOOLPATH)cc1.exe -I$(INCPATH) -Os -Wall -quiet
GAS2NASK = $(TOOLPATH)gas2nask.exe -a
OBJ2BIM  = $(TOOLPATH)obj2bim.exe
MAKEFONT = $(TOOLPATH)makefont.exe
BIN2OBJ  = $(TOOLPATH)bin2obj.exe
BIM2HRB  = $(TOOLPATH)bim2hrb.exe
RULEFILE = $(TOOLPATH)haribote/haribote.rul
EDIMG    = $(TOOLPATH)edimg.exe
IMGTOL   = $(TOOLPATH)imgtol.com
COPY     = copy
DEL      = del

# デフォルト動作

default :
	$(MAKE) img

# ファイル生成規則

ipl10.bin : ipl10.nas Makefile
	$(NASK) ipl10.nas ipl10.bin ipl10.lst

asmhead.bin : asmhead.nas Makefile
	$(NASK) asmhead.nas asmhead.bin asmhead.lst

hankaku.bin : hankaku.txt Makefile
	$(MAKEFONT) hankaku.txt hankaku.bin

hankaku.obj : hankaku.bin Makefile
	$(BIN2OBJ) hankaku.bin hankaku.obj _hankaku

bootpack.bim : $(OBJS_BOOTPACK) Makefile
	$(OBJ2BIM) @$(RULEFILE) out:bootpack.bim stack:3136k map:bootpack.map \
		$(OBJS_BOOTPACK)
# 3MB+64KB=3136KB

bootpack.hrb : bootpack.bim Makefile
	$(BIM2HRB) bootpack.bim bootpack.hrb 0

haribote.sys : asmhead.bin bootpack.hrb Makefile
	copy /B asmhead.bin+bootpack.hrb haribote.sys

hello(c).bim : hello(c).obj $(OBJS_API) Makefile
	$(OBJ2BIM) @$(RULEFILE) out:hello(c).bim map:hello(c).map hello(c).obj $(OBJS_API)

hello(c).hrb : hello(c).bim Makefile
	$(BIM2HRB) hello(c).bim hello(c).hrb 0

hello(e).bim : hello(e).obj $(OBJS_API) Makefile
	$(OBJ2BIM) @$(RULEFILE) out:hello(e).bim stack:1k map:hello(e).map \
		hello(e).obj $(OBJS_API)

hello(e).hrb : hello(e).bim Makefile
	$(BIM2HRB) hello(e).bim hello(e).hrb 0

lines.bim : lines.obj $(OBJS_API) Makefile
	$(OBJ2BIM) @$(RULEFILE) out:lines.bim stack:1k map:lines.map \
		lines.obj $(OBJS_API)

lines.hrb : lines.bim Makefile
	$(BIM2HRB) lines.bim lines.hrb 48k

noodle.bim : noodle.obj $(OBJS_API) Makefile
	$(OBJ2BIM) @$(RULEFILE) out:noodle.bim stack:1k map:noodle.map \
		noodle.obj $(OBJS_API)

noodle.hrb : noodle.bim Makefile
	$(BIM2HRB) noodle.bim noodle.hrb 40k

beepdown.bim : beepdown.obj $(OBJS_API) Makefile
	$(OBJ2BIM) @$(RULEFILE) out:beepdown.bim stack:1k map:beepdown.map \
		beepdown.obj $(OBJS_API)

beepdown.hrb : beepdown.bim Makefile
	$(BIM2HRB) beepdown.bim beepdown.hrb 40k

color.bim : color.obj $(OBJS_API) Makefile
	$(OBJ2BIM) @$(RULEFILE) out:color.bim stack:1k map:color.map \
		color.obj $(OBJS_API)

color.hrb : color.bim Makefile
	$(BIM2HRB) color.bim color.hrb 56k

color2.bim : color2.obj $(OBJS_API) Makefile
	$(OBJ2BIM) @$(RULEFILE) out:color2.bim stack:1k map:color2.map \
		color2.obj $(OBJS_API)

color2.hrb : color2.bim Makefile
	$(BIM2HRB) color2.bim color2.hrb 56k

color3.bim : color3.obj $(OBJS_API) Makefile
	$(OBJ2BIM) @$(RULEFILE) out:color3.bim stack:1k map:color3.map \
		color3.obj $(OBJS_API)

color3.hrb : color3.bim Makefile
	$(BIM2HRB) color3.bim color3.hrb 56k
	
color4.bim : color4.obj $(OBJS_API) Makefile
	$(OBJ2BIM) @$(RULEFILE) out:color4.bim stack:1k map:color4.map \
		color4.obj $(OBJS_API)

color4.hrb : color4.bim Makefile
	$(BIM2HRB) color4.bim color4.hrb 56k
	
color5.bim : color5.obj $(OBJS_API) Makefile
	$(OBJ2BIM) @$(RULEFILE) out:color5.bim stack:1k map:color5.map \
		color5.obj $(OBJS_API)

color5.hrb : color5.bim Makefile
	$(BIM2HRB) color5.bim color5.hrb 56k
	
color6.bim : color6.obj $(OBJS_API) Makefile
	$(OBJ2BIM) @$(RULEFILE) out:color6.bim stack:1k map:color6.map \
		color6.obj $(OBJS_API)

color6.hrb : color6.bim Makefile
	$(BIM2HRB) color6.bim color6.hrb 56k
	
color7.bim : color7.obj $(OBJS_API) Makefile
	$(OBJ2BIM) @$(RULEFILE) out:color7.bim stack:1k map:color7.map \
		color7.obj $(OBJS_API)

color7.hrb : color7.bim Makefile
	$(BIM2HRB) color7.bim color7.hrb 56k
	
	
crack7.bim : crack7.obj Makefile
	$(OBJ2BIM) @$(RULEFILE) out:crack7.bim stack:1k map:crack7.map crack7.obj

crack7.hrb : crack7.bim Makefile
	$(BIM2HRB) crack7.bim crack7.hrb 0k

haribote.img : ipl10.bin haribote.sys Makefile \
		hello(c).hrb hello(e).hrb  \
		lines.hrb noodle.hrb beepdown.hrb color.hrb color2.hrb color3.hrb color4.hrb color5.hrb color6.hrb color7.hrb\
		crack7.hrb
	$(EDIMG)   imgin:../z_tools/fdimg0at.tek \
		wbinimg src:ipl10.bin len:512 from:0 to:0 \
		copy from:haribote.sys to:@: \
		copy from:ipl10.nas to:@: \
		copy from:make.bat to:@: \
		copy from:hello(c).hrb to:@: \
		copy from:hello(e).hrb to:@: \
		copy from:lines.hrb to:@: \
		copy from:noodle.hrb to:@: \
		copy from:beepdown.hrb to:@: \
		copy from:color.hrb to:@: \
		copy from:color2.hrb to:@: \
		copy from:color3.hrb to:@: \
		copy from:color4.hrb to:@: \
		copy from:color5.hrb to:@: \
		copy from:color6.hrb to:@: \
		copy from:color7.hrb to:@: \
		copy from:crack7.hrb to:@: \
		imgout:haribote.img

# 一般規則

%.gas : %.c bootpack.h Makefile
	$(CC1) -o $*.gas $*.c

%.nas : %.gas Makefile
	$(GAS2NASK) $*.gas $*.nas

%.obj : %.nas Makefile
	$(NASK) $*.nas $*.obj $*.lst

# コマンド

img :
	$(MAKE) haribote.img

run :
	$(MAKE) img
	$(COPY) haribote.img ..\z_tools\qemu\fdimage0.bin
	$(MAKE) -C ../z_tools/qemu

install :
	$(MAKE) img
	$(IMGTOL) w a: haribote.img

clean :
	-$(DEL) *.bin
	-$(DEL) *.lst
	-$(DEL) *.obj
	-$(DEL) *.map
	-$(DEL) *.bim
	-$(DEL) *.hrb
	-$(DEL) haribote.sys

src_only :
	$(MAKE) clean
	-$(DEL) haribote.img
