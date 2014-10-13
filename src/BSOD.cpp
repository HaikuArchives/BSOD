/* 
 * BSOD - Blue Screen of Death screensaver
 * based on Jamie Zawinksi's xscreensaver BSOD
 * Rewritten for BeOS and copyright © 2000 by John Yanarella (yanarejm@muohio.edu)
 *
 * version 1.02 (April 16th, 2000)
 *    - by request, added random cycling option
 *    - added random cycle time interval slider
 *
 * version 1.01 (April 6th, 2000)
 *    - added BeOS R4.5 project file and binary
 *      (only change: links against _APP_ instead of libscreensaver.so)
 *
 * version 1.0 (April 5th, 2000)
 *    - original release
 *	  - rewrote the original BSOD to use BeOS graphic methods
 *	  	and to work with BeOS screensaver API
 *	  - added autoscaling of images and fonts
 *	  - fixed formatting of Win9x BSOD text to be more accurate
 *
 * Although the BeOS "port" involved a great deal of rewriting,
 * it's still covered by this license:
 * 
 * xscreensaver, Copyright (c) 1998 Jamie Zawinski <jwz@jwz.org>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  No representations are made about the suitability of this
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <Bitmap.h>
#include <TextView.h>
#include <Menu.h>
#include <MenuField.h>
#include <MenuItem.h>
#include <PopUpMenu.h>
#include <Slider.h>

#include <File.h>
#include <Node.h>
#include <NodeInfo.h>

#include "BSOD.h"

#include "amiga_hand.h"
#include "atari.h"
#include "mac.h"

static const char* TITLE =
	"Blue Screen Of Death for BeOS v1.02\n";
	
static const char* CREDITS = 
	"Simulating less stable Operating Systems\n"
	"\n\n\n\n\n\n\n"
	"\nRewritten for the BeOS by:\n"
	"  John Yanarella (yanarejm@muohio.edu)\n"
	"\nBased on the UNIX xscreensaver by:\n"
	"  Jamie Zawinski (jwz@jwz.org)\n\n";

extern "C" _EXPORT BScreenSaver *instantiate_screen_saver(BMessage *message, image_id image)
{
	return new BSOD(message, image);
}

BSOD::BSOD(BMessage *msg, image_id image)
 : BScreenSaver(msg, image)
{
	m_bitmap = NULL;
	m_icon = NULL;
	m_image = image;
	m_preview = false;
	
	m_method = 0;

	RestoreState(msg);

	if (m_type > 9)
		m_type = 0;
}

BSOD::~BSOD() {
}

void BSOD::StartConfig(BView *view)
{
	BSODConfigView* configView = new BSODConfigView(view->Bounds(), this);
	view->AddChild(configView);
}


status_t BSOD::StartSaver(BView * view, bool preview)
{
	if (preview) {
		image_info info;
		BFile addon_file;
		if ((get_image_info(m_image, &info) == B_OK ) &&
			(addon_file.SetTo(info.name, O_RDONLY ) == B_OK))
		{
			BNodeInfo addon_node_info((BNode*)&addon_file);
			m_icon = new BBitmap(BRect(0,0,31,31), B_CMAP8);
			if (addon_node_info.GetTrackerIcon(m_icon, B_LARGE_ICON) == B_OK) {
				SetTickSize(1000000);
				m_preview = true;
				return B_OK;
			} else {
				delete m_icon;
				m_icon = NULL;
				return B_ERROR;
			}
		} else {
			delete m_icon;
			m_icon = NULL;
			return B_ERROR;
		}
	}
	
	m_method = m_type;
	if (m_type == 8)
		m_method = rand() % 8;

	m_bitmap = NULL;

	// stuff for random cycling
	time_t now = real_time_clock();
	srand(now);
	m_last_reset = now;
	m_starting_frame = -1;

	SetTickSize(100000);

	return B_OK;
}

void BSOD::StopSaver() 
{
	if (m_icon)
		delete m_icon;
	if (m_bitmap)
		delete m_bitmap;
	m_icon = m_bitmap = NULL;
}

status_t BSOD::SaveState(BMessage *msg) const
{
	msg->AddInt32("type", m_type);
	msg->AddInt32("interval", m_interval);
	return B_OK;
}

void BSOD::RestoreState(BMessage *msg) {
	int32 type, interval;
	
	if (msg->FindInt32("type", &type) == B_OK)
		m_type = type;
	else
		m_type = 0;
		
	if (msg->FindInt32("interval", &interval) == B_OK)
		m_interval = interval;
	else
		m_interval = 30;
}

void BSOD::Draw(BView *view, int32 frame)
{
	// preview draw
	if (m_preview) {
		if (frame == 0) {
			rgb_color color = { 0, 0, 165, 0 };
			view->SetHighColor(color);
			view->FillRect(view->Bounds());
			view->SetDrawingMode(B_OP_OVER);
			BPoint pt(view->Bounds().Width()/2 - 16, view->Bounds().Height()/2 - 16);
			view->DrawBitmap(m_icon, pt);
		}		
		return;
	}
	else
	{
		if (m_type == 9) 
		{
			Lock();
			
			time_t now = real_time_clock();
						
			if (now > m_last_reset + m_interval) 
			{
				m_last_reset = now;
				m_starting_frame = frame;
			}
			
			if (m_starting_frame > 0) 
				frame = frame % m_starting_frame;
			
			if (frame == 0)
			{
				delete m_bitmap;
				m_bitmap = NULL;
				m_method = rand() % 8;
			}
			
			Unlock();
		}
			
		switch (m_method)
		{
			case 0:
				Windows(view, true, frame);
				break;
			case 1:
				Windows(view, false, frame);
				break;
			case 2:
				SCO(view, frame);
				break;
			case 3:
				SparcLinux(view, frame);
				break;
			case 4:
				Amiga(view, frame);
				break;
			case 5:
				Atari(view, frame);
				break;
			case 6:
				Mac(view, frame);
				break;
			case 7:
				MacsBug(view, frame);
				break;
			default:
				break;
		}
	}
}

void BSOD::draw_string (BView *view, BFont *font, int xoff, int yoff,
	 				    int win_width, int win_height, const char *string, int delay)
{
	int x, y;
	int width = 0, height = 0, cw = 0;
	int char_width, line_height;
	
	const char *s = string;
	const char *se = string;

	rgb_color foreground = view->HighColor();
	rgb_color background = view->LowColor();
	
	// this assumes fixed-width fonts
	char_width = (int) font->StringWidth("W");
	font_height info;
	font->GetHeight(&info);
	line_height = (int) (info.ascent + info.descent + 1);

	while (1)
    {
		if (*s == '\n' || !*s)
		{
			height++;
			if (cw > width) width = cw;
				cw = 0;
			if (!*s) break;
		}
		else
			cw++;
		s++;
	}

	x = (win_width - (width * char_width)) / 2;
	y = (win_height - (height * line_height)) / 2;

	if (x < 0) x = 2;
	if (y < 0) y = 2;

	x += xoff;
	y += yoff;

	se = s = string;
	while (1)
	{
		if (*s == '\n' || !*s)
		{
			int off = 0;
			bool flip = false;

			if (*se == '@' || *se == '_')
			{
				if (*se == '@') flip = true;
				se++;
				off = (char_width * (width - (s - se))) / 2;
			}

			if (flip)
			{
				view->SetHighColor(background);
				view->SetLowColor(foreground);
				
				view->FillRect(BRect(x+off-1, y+1, 
									 x+off+((s-se)*char_width), y+info.ascent+1),
							   B_SOLID_LOW);
			}
	
			if (s != se)
				view->DrawString(se, s-se, BPoint(x+off, y+info.ascent));

			if (flip)
			{
				view->SetHighColor(foreground);
				view->SetLowColor(background);
			}

			se = s;
			y += line_height;
			if (!*s) break;
			se = s+1;

			if (delay > 0)
			{
				view->Sync();
				snooze(delay);
			}

		}
		s++;
	}
	
	view->Sync();
}

void BSOD::Windows(BView *view, bool win95, int32 frame)
{
	if (frame == 0)
	{
		(win95 ? view->SetViewColor(0,0,165) : view->SetViewColor(0,0,128));
		view->Invalidate();
		SetTickSize(50000);
	}
	
	if (frame > 1) 
		return;
			
	const char *w95 = (
		"\n@ Windows \n\n"
 		"A fatal exception 0E has occured at 0028:C004D86F in VXD VFAT(01) +\n"
		"0000B897.  The current application will be terminated.\n"
		"\n"
		"* Press any key to terminate the current application.\n"
		"* Press CTRL+ALT+DELETE again to restart your computer.  You will\n"
		"  lose any unsaved information in all applications.\n"
		"\n"
		"_Press any key to continue _"
	);

	const char *wnt = ( /* from Jim Niemira <urmane@urmane.org> */
		"*** STOP: 0x0000001E (0x80000003,0x80106fc0,0x8025ea21,0xfd6829e8)\n"
		"Unhandled Kernel exception c0000047 from fa8418b4 (8025ea21,fd6829e8)\n"
		"\n"
		"Dll Base Date Stamp - Name             Dll Base Date Stamp - Name\n"
		"80100000 2be154c9 - ntoskrnl.exe       80400000 2bc153b0 - hal.dll\n"
		"80258000 2bd49628 - ncrc710.sys        8025c000 2bd49688 - SCSIPORT.SYS \n"
		"80267000 2bd49683 - scsidisk.sys       802a6000 2bd496b9 - Fastfat.sys\n"
		"fa800000 2bd49666 - Floppy.SYS         fa810000 2bd496db - Hpfs_Rec.SYS\n"
		"fa820000 2bd49676 - Null.SYS           fa830000 2bd4965a - Beep.SYS\n"
		"fa840000 2bdaab00 - i8042prt.SYS       fa850000 2bd5a020 - SERMOUSE.SYS\n"
		"fa860000 2bd4966f - kbdclass.SYS       fa870000 2bd49671 - MOUCLASS.SYS\n"
		"fa880000 2bd9c0be - Videoprt.SYS       fa890000 2bd49638 - NCC1701E.SYS\n"
		"fa8a0000 2bd4a4ce - Vga.SYS            fa8b0000 2bd496d0 - Msfs.SYS\n"
		"fa8c0000 2bd496c3 - Npfs.SYS           fa8e0000 2bd496c9 - Ntfs.SYS\n"
		"fa940000 2bd496df - NDIS.SYS           fa930000 2bd49707 - wdlan.sys\n"
		"fa970000 2bd49712 - TDI.SYS            fa950000 2bd5a7fb - nbf.sys\n"
		"fa980000 2bd72406 - streams.sys        fa9b0000 2bd4975f - ubnb.sys\n"
		"fa9c0000 2bd5bfd7 - usbser.sys         fa9d0000 2bd4971d - netbios.sys\n"
		"fa9e0000 2bd49678 - Parallel.sys       fa9f0000 2bd4969f - serial.SYS\n"
		"faa00000 2bd49739 - mup.sys            faa40000 2bd4971f - SMBTRSUP.SYS\n"
		"faa10000 2bd6f2a2 - srv.sys            faa50000 2bd4971a - afd.sys\n"
		"faa60000 2bd6fd80 - rdr.sys            faaa0000 2bd49735 - bowser.sys\n"
		"\n"
		"Address dword dump Dll Base                                      - Name\n"
		"801afc20 80106fc0 80106fc0 00000000 00000000 80149905 : "
		  "fa840000 - i8042prt.SYS\n"
		"801afc24 80149905 80149905 ff8e6b8c 80129c2c ff8e6b94 : "
		  "8025c000 - SCSIPORT.SYS\n"
		"801afc2c 80129c2c 80129c2c ff8e6b94 00000000 ff8e6b94 : "
		  "80100000 - ntoskrnl.exe\n"
		"801afc34 801240f2 80124f02 ff8e6df4 ff8e6f60 ff8e6c58 : "
		  "80100000 - ntoskrnl.exe\n"
		"801afc54 80124f16 80124f16 ff8e6f60 ff8e6c3c 8015ac7e : "
		  "80100000 - ntoskrnl.exe\n"
		"801afc64 8015ac7e 8015ac7e ff8e6df4 ff8e6f60 ff8e6c58 : "
		  "80100000 - ntoskrnl.exe\n"
		"801afc70 80129bda 80129bda 00000000 80088000 80106fc0 : "
		  "80100000 - ntoskrnl.exe\n"
		"\n"
		"Kernel Debugger Using: COM2 (Port 0x2f8, Baud Rate 19200)\n"
		"Restart and set the recovery options in the system control panel\n"
		"or the /CRASHDEBUG system start option. If this message reappears,\n"
		"contact your system administrator or technical support group."
	);
	
	BFont font(be_fixed_font);
	font.SetFlags(B_DISABLE_ANTIALIASING);

	if (win95)
	{
		font.SetSize(0.021875*view->Bounds().Width());

		view->SetFont(&font);
		view->SetLowColor(0,0,165);			// blue
		view->SetHighColor(255,255,255);	// white
		draw_string(view, &font, 0, 0, (int)view->Bounds().Width(), (int)view->Bounds().Height(), w95, 0);
	}
	else
	{
		font.SetSize(0.015625*view->Bounds().Width());
		
		font.SetFace(B_BOLD_FACE);
		font.SetSpacing(B_FIXED_SPACING);
		view->SetFont(&font);		
		view->SetLowColor(0,0,128);			// dark blue
		view->SetHighColor(192,192,192);	// white
    	draw_string(view, &font, 0, 0, 10, 10, wnt, 750);
	}
}

void BSOD::SCO(BView* view, int32 frame)
{
	if (frame == 0)
	{
		view->SetViewColor(0,0,0);
		view->Invalidate();
		SetTickSize(100000);
	}
	
	int lines_1 = 0, lines_2 = 0, lines_3 = 0, lines_4 = 0;
	
	const char *s;
	
	const char *sco_panic_1 = (
		"Unexpected trap in kernel mode:\n"
		"\n"
		"cr0 0x80010013     cr2  0x00000014     cr3 0x00000000  tlb  0x00000000\n"
		"ss  0x00071054    uesp  0x00012055     efl 0x00080888  ipl  0x00000005\n"
		"cs  0x00092585     eip  0x00544a4b     err 0x004d4a47  trap 0x0000000E\n"
		"eax 0x0045474b     ecx  0x0042544b     edx 0x57687920  ebx  0x61726520\n"
		"esp 0x796f7520     ebp  0x72656164     esi 0x696e6720  edi  0x74686973\n"
		"ds  0x3f000000     es   0x43494c48     fs  0x43525343  gs   0x4f4d4b53\n"
		"\n"
		"PANIC: k_trap - kernel mode trap type 0x0000000E\n"
		"Trying to dump 5023 pages to dumpdev hd (1/41), 63 pages per '.'\n"
	);
	const char *sco_panic_2 = (
		"...............................................................................\n"
	);
	const char *sco_panic_3 = (
		"5023 pages dumped\n"
		"\n"
		"\n"
	);
	const char *sco_panic_4 = (
		"**   Safe to Power Off   **\n"
		"           - or -\n"
		"** Press Any Key to Reboot **\n"
	);

	if (frame > (int32)strlen(sco_panic_2) + 9) 
		return;


	for (s = sco_panic_1; *s; s++) if (*s == '\n') lines_1++;
	for (s = sco_panic_2; *s; s++) if (*s == '\n') lines_2++;
	for (s = sco_panic_3; *s; s++) if (*s == '\n') lines_3++;
	for (s = sco_panic_4; *s; s++) if (*s == '\n') lines_4++;

	BFont font(be_fixed_font);
	font.SetSize(0.015625*view->Bounds().Width());
	font.SetFlags(B_DISABLE_ANTIALIASING);
	font.SetFace(B_BOLD_FACE);
	font.SetSpacing(B_FIXED_SPACING);
	view->SetFont(&font);

	view->SetLowColor(0,0,0);			// black
	view->SetHighColor(255,255,255);	// white

	font_height info;
	font.GetHeight(&info);

	if (frame == 1) 
	{
		draw_string(view, &font,
					10, (int)(view->Bounds().Height() - ((lines_1 + lines_2 + lines_3 + lines_4 + 1) *
        	                           (info.ascent + info.descent + 1))),
					10, 10,
					sco_panic_1, 0);
		view->Sync();
		return;
	}
	
	if (frame > 1 && frame < (int32)strlen(sco_panic_2) + 1)
	{
		for (s = sco_panic_2; *s; s++)
	    {
			char *ss = strdup(sco_panic_2);
			ss[frame] = 0;
			draw_string(view, &font,
				10, (int)(view->Bounds().Height() - ((lines_2 + lines_3 + lines_4 + 1) *
					(info.ascent + info.descent + 1))),
				10, 10,
				ss, 0);
	      	view->Sync();
			free(ss);
		}
		return;
	}

	if (frame > (int32)strlen(sco_panic_2) + 2)
	{
		draw_string(view, &font,
			10, (int)(view->Bounds().Height() - ((lines_3 + lines_4 + 1) *
				(info.ascent + info.descent + 1))),
			10, 10,
			sco_panic_3, 0);
		view->Sync();
	}

	if (frame > (int32)strlen(sco_panic_2) + 8)
	{
		draw_string(view, &font,
			10, (int)(view->Bounds().Height() - ((lines_4 + 1) *
				(info.ascent + info.descent + 1))),
			10, 10,
			sco_panic_4, 0);
		view->Sync();	
	}
}

void BSOD::SparcLinux(BView* view, int32 frame)
{
	if (frame == 0)
	{
		view->SetViewColor(0,0,0);
		view->Invalidate();
	}
	
	if (frame > 1) 
		return;		// Go away, kid.  You bother me.

	int lines = 1;
	const char *s;
	
	const char *linux_panic = (
		"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		"Unable to handle kernel paging request at virtual address f0d4a000\n"
		"tsk->mm->context = 00000014\n"
		"tsk->mm->pgd = f26b0000\n"
		"              \\|/ ____ \\|/\n"
		"              \"@'/ ,. \\`@\"\n"
		"              /_| \\__/ |_\\\n"
		"                 \\__U_/\n"
		"gawk(22827): Oops\n"
		"PSR: 044010c1 PC: f001c2cc NPC: f001c2d0 Y: 00000000\n"
		"g0: 00001000 g1: fffffff7 g2: 04401086 g3: 0001eaa0\n"
		"g4: 000207dc g5: f0130400 g6: f0d4a018 g7: 00000001\n"
		"o0: 00000000 o1: f0d4a298 o2: 00000040 o3: f1380718\n"
		"o4: f1380718 o5: 00000200 sp: f1b13f08 ret_pc: f001c2a0\n"
		"l0: efffd880 l1: 00000001 l2: f0d4a230 l3: 00000014\n"
		"l4: 0000ffff l5: f0131550 l6: f012c000 l7: f0130400\n"
		"i0: f1b13fb0 i1: 00000001 i2: 00000002 i3: 0007c000\n"
		"i4: f01457c0 i5: 00000004 i6: f1b13f70 i7: f0015360\n"
		"Instruction DUMP:\n"
	);
	
	for (s = linux_panic; *s; s++) if (*s == '\n') lines++;

	BFont font(be_fixed_font);
	font.SetSize(0.015625*view->Bounds().Width());
	font.SetFlags(B_DISABLE_ANTIALIASING);
	font.SetFace(B_BOLD_FACE);
	font.SetSpacing(B_FIXED_SPACING);
	view->SetFont(&font);

	view->SetLowColor(0,0,0);			// black
	view->SetHighColor(255,255,255);	// white

	font_height info;
	font.GetHeight(&info);

	draw_string(view, &font,
				10, (int)(view->Bounds().Height() - 
					(lines * (info.ascent + info.descent + 1))),
				10, 10,
				linux_panic, 0);
}

void BSOD::Amiga (BView *view, int32 frame)
{
	if (frame == 0)
	{
		if (!m_bitmap)
		{	
			BRect bounds(0,0,amiga_hand_width-1,amiga_hand_height-1);
			m_bitmap = new BBitmap(bounds, B_CMAP8);
			int32 length = ((int32(bounds.right-bounds.left+1)+3)&0xFFFFFFFC)*int32(bounds.bottom-bounds.top+1);
			m_bitmap->SetBits(amiga_hand_bits, length, 0, B_CMAP8);
		}

		view->SetViewColor(255,255,255);
		view->Invalidate();
		
		SetTickSize(300000);
	}

	int height;

	const char *string = (
		"_Software failure.  Press left mouse button to continue.\n"
		"_Guru Meditation #00000003.00C01570"
	);

	BFont font(be_fixed_font);
	font.SetSize(0.01875 * view->Bounds().Width());
	font.SetFlags(B_DISABLE_ANTIALIASING);
	font.SetFace(B_BOLD_FACE);
	font.SetSpacing(B_FIXED_SPACING);
	view->SetFont(&font);
	
	font_height info;
	font.GetHeight(&info);
	height = (int)(info.ascent + info.descent) * 6;

	int pix_w = (int)((amiga_hand_width/640.0) * view->Bounds().Width());
	int pix_h = (int)((amiga_hand_height/480.0) * view->Bounds().Height());

	if (m_bitmap)
	{		
		int x = (int)((view->Bounds().Width() - pix_w) / 2);
		int y = (int)((view->Bounds().Height() - pix_h) / 2);
	
		if (frame == 1) 
		{
			view->DrawBitmap(m_bitmap, m_bitmap->Bounds(), BRect(x, y, x + pix_w, y + pix_h));
		}
		if (frame == 4)
		{
			view->SetHighColor(255,255,255);
			view->FillRect(BRect(x, y, x + pix_w, y + pix_h), B_SOLID_HIGH);
			view->DrawBitmap(m_bitmap, m_bitmap->Bounds(),
					BRect(x, y + height, x + pix_w, y + height + pix_h));
		}
		view->Sync();
	}

	view->SetLowColor(0,0,0);			// black
	view->SetHighColor(255,0,0);		// red
	
	if (frame == 4) 
	{
		view->FillRect(BRect(0,0,view->Bounds().Width(), height), B_SOLID_LOW);
		draw_string(view, &font, 0, 0, (int)view->Bounds().Width(), height, string, 0);
	}
	if (frame > 3) 
	{
		pattern aPattern = (frame % 2 == 0) ? B_SOLID_HIGH : B_SOLID_LOW;
		view->FillRect(BRect(0,0,view->Bounds().Width(), info.ascent), aPattern);
		view->FillRect(BRect(0,0,info.ascent, height), aPattern);
		view->FillRect(BRect(view->Bounds().Width()-info.ascent, 0, view->Bounds().Width(), height), aPattern);
		view->FillRect(BRect(0,height-info.ascent,view->Bounds().Width(), height), aPattern);
	}
}

/* Atari ST, by Marcus Herbert <rhoenie@nobiscum.de>
   Marcus had this to say:

	Though I still have my Atari somewhere, I hardly remember
	the meaning of the bombs. I think 9 bombs was "bus error" or
	something like that.  And you often had a few bombs displayed
	quickly and then the next few ones coming up step by step.
	Perhaps somebody else can tell you more about it..  its just
	a quick hack :-}
 */
void BSOD::Atari(BView *view, int32 frame)
{
	if (frame == 0)
	{
		if (!m_bitmap)
		{	
			BRect bounds(0,0,atari_width-1,atari_height-1);
			m_bitmap = new BBitmap(bounds, B_CMAP8);
			int32 length = ((int32(bounds.right-bounds.left+1)+3)&0xFFFFFFFC)*int32(bounds.bottom-bounds.top+1);
			m_bitmap->SetBits(atari_bits, length, 0, B_CMAP8);
		}

		view->SetViewColor(255,255,255);
		view->Invalidate();
		
		SetTickSize(100000);
	}

	if (frame > 10)
		return;

	int pix_w = (int)((atari_width/640.0) * view->Bounds().Width());
	int pix_h = (int)((atari_height/480.0) * view->Bounds().Height());
	
	int offset = pix_w + 2;

	int i, x, y;

	view->SetHighColor(0,0,0);
	view->SetLowColor(255,255,255);

	x = 5;
	y = (int)(view->Bounds().Height() - (view->Bounds().Height() / 5));
	
	if (y < 0) y = 0;
	
	if (frame == 1)
	{
		for (i = 0; i < 7; i++) 
		{
			view->DrawBitmap(m_bitmap, m_bitmap->Bounds(), 
				 BRect((x + (i*offset)), y, (x + (i*offset)) + pix_w, y + pix_h));
		}
	}

	if (frame >= 7 && frame < 11)
	{
		SetTickSize(400000);
		for (i = 7; i < frame; i++)
			view->DrawBitmap(m_bitmap, m_bitmap->Bounds(), 
				 BRect((x + (i*offset)), y, (x + (i*offset)) + pix_w, y + pix_h));
	}
	view->Sync();
}

void BSOD::Mac(BView* view, int32 frame)
{
	if (frame == 0)
	{
		if (!m_bitmap)
		{	
			BRect bounds(0,0,mac_width-1,mac_height-1);
			m_bitmap = new BBitmap(bounds, B_CMAP8);
			int32 length = ((int32(bounds.right-bounds.left+1)+3)&0xFFFFFFFC)*int32(bounds.bottom-bounds.top+1);
			m_bitmap->SetBits(mac_bits, length, 0, B_CMAP8);
		}

		view->SetViewColor(0,0,0);
		view->Invalidate();	
	}

	if (frame > 1) 
		return;		// Go away, kid.  You bother me.

	const char *string = (
		"0 0 0 0 0 0 0 F\n"
		"0 0 0 0 0 0 0 3"
	);
	
	view->SetHighColor(187, 255, 255); // PaleTurquoise1
	view->SetLowColor(0, 0, 0);

	BFont font(be_fixed_font);
	font.SetSize(0.015625 * view->Bounds().Width());
	font.SetFlags(B_DISABLE_ANTIALIASING);
	font.SetFace(B_BOLD_FACE);
	font.SetSpacing(B_FIXED_SPACING);
	view->SetFont(&font);
	
	font_height info;
	font.GetHeight(&info);

	int pix_w = (int)((mac_width/640.0) * view->Bounds().Width());
	int pix_h = (int)((mac_height/480.0) * view->Bounds().Height());
		
	int x = (int)(view->Bounds().Width() - pix_w) / 2;
    int y = (int)(((view->Bounds().Height() + pix_h) / 2) 
    		- pix_h - (info.ascent + info.descent) * 2);
	if (y < 0) y = 0;

	view->DrawBitmap(m_bitmap, m_bitmap->Bounds(), BRect(x, y, x+pix_w, y+pix_h));

	draw_string(view, &font, 0, 0, view->Bounds().Width(), 
				view->Bounds().Height() + pix_h, string, 0);
}

void BSOD::MacsBug(BView* view, int32 frame)
{
	if (frame == 0)
	{
		view->SetViewColor(170,170,170);
		view->Invalidate();
		
		SetTickSize(200000);
	}

	int char_width, line_height;
	int col_right, row_top, row_bottom, page_right, page_bottom, body_top;
	int xoff, yoff;

	const char *left = (
		"    SP     \n"
		" 04EB0A58  \n"
		"58 00010000\n"
		"5C 00010000\n"
		"   ........\n"
		"60 00000000\n"
		"64 000004EB\n"
		"   ........\n"
		"68 0000027F\n"
		"6C 2D980035\n"
		"   ....-..5\n"
		"70 00000054\n"
		"74 0173003E\n"
		"   ...T.s.>\n"
		"78 04EBDA76\n"
		"7C 04EBDA8E\n"
		"   .S.L.a.U\n"
		"80 00000000\n"
		"84 000004EB\n"
		"   ........\n"
		"88 00010000\n"
		"8C 00010000\n"
		"   ...{3..S\n"
		"\n"
		"\n"
		" CurApName \n"
		"  Finder   \n"
		"\n"
		" 32-bit VM \n"
		"SR Smxnzvc0\n"
		"D0 04EC0062\n"
		"D1 00000053\n"
		"D2 FFFF0100\n"
		"D3 00010000\n"
		"D4 00010000\n"
		"D5 04EBDA76\n"
		"D6 04EBDA8E\n"
		"D7 00000001\n"
		"\n"
		"A0 04EBDA76\n"
		"A1 04EBDA8E\n"
		"A2 A0A00060\n"
		"A3 027F2D98\n"
		"A4 027F2E58\n"
		"A5 04EC04F0\n"
		"A6 04EB0A86\n"
		"A7 04EB0A58"
	);
	
	const char *bottom = (
		"  _A09D\n"
		"     +00884    40843714     #$0700,SR         "
		"                  ; A973        | A973\n"
		"     +00886    40843765     *+$0400           "
		"                                | 4A1F\n"
		"     +00888    40843718     $0004(A7),([0,A7[)"
		"                  ; 04E8D0AE    | 66B8"
	);

/*
	const char *body = (
		"Bus Error at 4BF6D6CC\n"
		"while reading word from 4BF6D6CC in User data space\n"
		" Unable to access that address\n"
		"  PC: 2A0DE3E6\n"
		"  Frame Type: B008"
	);
*/
	const char * body = (
		"PowerPC unmapped memory exception at 003AFDAC "
		"BowelsOfTheMemoryMgr+04F9C\n"
		" Calling chain using A6/R1 links\n"
		"  Back chain  ISA  Caller\n"
		"  00000000    PPC  28C5353C  __start+00054\n"
		"  24DB03C0    PPC  28B9258C  main+0039C\n"
		"  24DB0350    PPC  28B9210C  MainEvent+00494\n"
		"  24DB02B0    PPC  28B91B40  HandleEvent+00278\n"
		"  24DB0250    PPC  28B83DAC  DoAppleEvent+00020\n"
		"  24DB0210    PPC  FFD3E5D0  "
		"AEProcessAppleEvent+00020\n"
		"  24DB0132    68K  00589468\n"
		"  24DAFF8C    68K  00589582\n"
		"  24DAFF26    68K  00588F70\n"
		"  24DAFEB3    PPC  00307098  "
		"EmToNatEndMoveParams+00014\n"
		"  24DAFE40    PPC  28B9D0B0  DoScript+001C4\n"
		"  24DAFDD0    PPC  28B9C35C  RunScript+00390\n"
		"  24DAFC60    PPC  28BA36D4  run_perl+000E0\n"
		"  24DAFC10    PPC  28BC2904  perl_run+002CC\n"
		"  24DAFA80    PPC  28C18490  Perl_runops+00068\n"
		"  24DAFA30    PPC  28BE6CC0  Perl_pp_backtick+000FC\n"
		"  24DAF9D0    PPC  28BA48B8  Perl_my_popen+00158\n"
		"  24DAF980    PPC  28C5395C  sfclose+00378\n"
		"  24DAF930    PPC  28BA568C  free+0000C\n"
		"  24DAF8F0    PPC  28BA6254  pool_free+001D0\n"
		"  24DAF8A0    PPC  FFD48F14  DisposePtr+00028\n"
		"  24DAF7C9    PPC  00307098  "
		"EmToNatEndMoveParams+00014\n"
		"  24DAF780    PPC  003AA180  __DisposePtr+00010"
	);

	const char *s;
	int body_lines = 1;

	for (s = body; *s; s++) if (*s == '\n') body_lines++;

	BFont font(be_fixed_font);

	font.SetSize(0.0125 * view->Bounds().Width());

	font.SetFlags(B_DISABLE_ANTIALIASING);
	font.SetFace(B_BOLD_FACE);
	font.SetSpacing(B_FIXED_SPACING);
	view->SetFont(&font);
	
	font_height info;
	font.GetHeight(&info);

	char_width = (int)font.StringWidth("W") + 1;

	line_height = (int)(info.ascent + info.descent + 1);

	col_right = char_width * 12;
	page_bottom = line_height * 47;

	if (page_bottom > view->Bounds().Height()) 
		page_bottom = (int)view->Bounds().Height();

	row_bottom = page_bottom - line_height;
	row_top = row_bottom - (line_height * 4);
	page_right = col_right + (char_width * 88);
	body_top = row_top - (line_height * body_lines);

	page_bottom += 2;
	row_bottom += 2;
	body_top -= 4;

	xoff = (int)(view->Bounds().Width() - page_right) / 2;
	yoff = (int)(view->Bounds().Height() - page_bottom) / 2;
	if (xoff < 0) xoff = 0;
	if (yoff < 0) yoff = 0;

	if (frame == 1)
	{
		view->SetHighColor(0,0,0);
		view->SetLowColor(255,255,255);
	
		view->FillRect(BRect(xoff, yoff, xoff+page_right, yoff+page_bottom), B_SOLID_LOW);	
	
		draw_string(view, &font, xoff, yoff, 10, 10, left, 0);
		draw_string(view, &font, xoff+col_right, yoff+row_top, 10, 10, bottom, 0);
	
		view->FillRect(BRect(xoff + col_right, yoff, 
							 xoff + col_right + 2, yoff+page_bottom), 
					   B_SOLID_HIGH);
	
		view->StrokeLine(BPoint(xoff+col_right, yoff+row_top), 
						 BPoint(xoff+page_right, yoff+row_top),
						 B_SOLID_HIGH);
		view->StrokeLine(BPoint(xoff+col_right, yoff+row_bottom), 
						 BPoint(xoff+page_right, yoff+row_bottom),
						 B_SOLID_HIGH);
						 
		view->StrokeRect(BRect(xoff, yoff, xoff+page_right, yoff+page_bottom), B_SOLID_HIGH);
	
		if (body_top > 4)
			body_top = 4;
	
		draw_string(view, &font, xoff + col_right + char_width, yoff + body_top, 10, 10, body, 500);
	}

	// blinking cursor
	view->StrokeLine(BPoint(xoff+col_right+(char_width/2)+2, yoff+row_bottom+3), 
					 BPoint(xoff+col_right+(char_width/2)+2, yoff+page_bottom-3),
					 B_SOLID_HIGH);
	view->Sync();

	if (frame % 2 == 0)
	{		
		view->StrokeLine(BPoint(xoff+col_right+(char_width/2)+2, yoff+row_bottom+3), 
						 BPoint(xoff+col_right+(char_width/2)+2, yoff+page_bottom-3),
						 B_SOLID_LOW);
		view->Sync();
    }
}

BSODConfigView::BSODConfigView(BRect frame, BSOD *s)
	: BView(frame, "", B_FOLLOW_NONE, B_WILL_DRAW)
{
	m_screensaver = s;
	
	BTextView* creditsView = new BTextView(frame, "credits", frame.InsetBySelf(5.0,0.0), B_FOLLOW_NONE, B_WILL_DRAW);
	
	creditsView->MakeEditable(false);
	creditsView->SetStylable(true);
	creditsView->MakeSelectable(false);	
	creditsView->SetAlignment(B_ALIGN_LEFT);
	creditsView->SetViewColor(216,216,216,0);
	
	BFont font(be_bold_font);
	font.SetSize(12.0);
	creditsView->SetFontAndColor(&font);
	creditsView->Insert(TITLE,strlen(TITLE));
	
	BFont font2(be_plain_font);
	font2.SetSize(10.0);
	creditsView->SetFontAndColor(&font2);	
	creditsView->Insert(CREDITS, strlen(CREDITS));

	AddChild(creditsView);

	m_type_menu = new BPopUpMenu("");
	BMenuItem *item[10];

	item[0] = new BMenuItem("Microsoft Windows 9x", new BMessage(TYPE_CHANGED));
	m_type_menu->AddItem(item[0]);
	item[1] = new BMenuItem("Microsoft Windows NT", new BMessage(TYPE_CHANGED));
	m_type_menu->AddItem(item[1]);
	item[2] = new BMenuItem("SCO UNIX", new BMessage(TYPE_CHANGED));
	m_type_menu->AddItem(item[2]);
	item[3] = new BMenuItem("SPARC Linux", new BMessage(TYPE_CHANGED));
	m_type_menu->AddItem(item[3]);
	item[4] = new BMenuItem("Commodore-Amiga AmigaDOS 1.3", new BMessage(TYPE_CHANGED));
	m_type_menu->AddItem(item[4]);
	item[5] = new BMenuItem("Atari ST", new BMessage(TYPE_CHANGED));
	m_type_menu->AddItem(item[5]);
	item[6] = new BMenuItem("Apple Mac OS (\"Sad Mac\")", new BMessage(TYPE_CHANGED));
	m_type_menu->AddItem(item[6]);
	item[7] = new BMenuItem("Apple Mac OS (debugger)", new BMessage(TYPE_CHANGED));
	m_type_menu->AddItem(item[7]);	
	item[8] = new BMenuItem("random", new BMessage(TYPE_CHANGED));
	m_type_menu->AddItem(item[8]);
	item[9] = new BMenuItem("random (cycle)", new BMessage(TYPE_CHANGED));
	m_type_menu->AddItem(item[9]);	

	if (m_screensaver->m_type > -1 && m_screensaver->m_type < 10)
		item[m_screensaver->m_type]->SetMarked(true);
	
	BMenuField *popup = new BMenuField(BRect(3, 40, 250, 55), "", "Crash type:", m_type_menu);
	popup->SetDivider(60);
	creditsView->AddChild(popup);
	
	BRect slideRect(frame);
	slideRect.left = 4;
	slideRect.top = 70;
	slideRect.bottom = 120;
	m_delay_slider = new BSlider(slideRect, "", "",
	                           new BMessage(INTERVAL_CHANGED), 1, 30, B_TRIANGLE_THUMB,
	                           B_FOLLOW_LEFT_RIGHT, B_WILL_DRAW|B_NAVIGABLE);
	m_delay_slider->SetLimitLabels("10 seconds", "5 minutes");
	rgb_color fill = { 0, 0, 165, 255 };
	m_delay_slider->UseFillColor(true, &fill);
	m_delay_slider->SetValue(m_screensaver->m_interval/10);
	m_delay_slider->SetEnabled(m_screensaver->m_type == 9);	
	creditsView->AddChild(m_delay_slider);
	UpdateLabel();
}

void BSODConfigView::AttachedToWindow()
{
	rgb_color view_color(Parent()->ViewColor());
	SetViewColor(view_color);
	m_type_menu->SetTargetForItems(this);
	m_delay_slider->SetTarget(this);
}

void BSODConfigView::MessageReceived(BMessage *msg)
{
	BMenuItem *item;
	
	switch (msg->what) {
		case TYPE_CHANGED:
			m_screensaver->Lock();
			msg->FindPointer("source", (void **)&item);
			m_screensaver->m_type = m_type_menu->IndexOf(item);
			m_delay_slider->SetEnabled(m_screensaver->m_type == 9);	
			m_screensaver->Unlock();
			break;
		
		case INTERVAL_CHANGED:
			m_screensaver->Lock();
			UpdateLabel();		
			m_screensaver->m_interval = m_delay_slider->Value() * 10;
			m_screensaver->Unlock();
			break;	
			
		default:
			BView::MessageReceived(msg);
			break;
	}
}

void BSODConfigView::UpdateLabel() 
{
	char *label = new char[200];
	int delay = m_delay_slider->Value() * 10;
	int minutes = delay / 60;
	int seconds = delay % 60;

	if (minutes == 0)
		sprintf(label, "Random cycling interval:  %i seconds", seconds);
	else if (seconds == 0)
		sprintf(label, "Random cycling interval:  %i %s", 
						minutes, (minutes == 1 ? "minute" : "minutes"));
	else
		sprintf(label, "Random cycling interval:  %i %s, %i %s", 
				minutes, (minutes == 1 ? "minute" : "minutes"),
				seconds, (seconds == 1 ? "second" : "seconds"));

	m_delay_slider->SetLabel(label);
	delete label;
}
