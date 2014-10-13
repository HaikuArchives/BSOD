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
 
#ifndef BSOD_H
#define BSOD_H

#include <ScreenSaver.h>
#include <Locker.h>

#define TYPE_CHANGED		'mTyp'
#define INTERVAL_CHANGED	'mInv'

class BSOD : public BScreenSaver, public BLocker {
 public:
	BSOD(BMessage *msg, image_id id);
	virtual ~BSOD();
	
	virtual void StartConfig(BView *view);
	virtual status_t StartSaver(BView *view, bool preview);
	virtual void StopSaver();
	virtual void Draw(BView *view, int32 frame);

	status_t SaveState(BMessage *msg) const;
	void RestoreState(BMessage *msg);

 private:
 	friend class BSODConfigView;
 
 	void Windows(BView *view, bool win9x, int32 frame);
	void SCO(BView *view, int32 frame);
	void SparcLinux(BView* view, int32 frame);
	void Amiga(BView* view, int32 frame);
	void Atari(BView *view, int32 frame);
	void Mac(BView *view, int32 frame);
	void MacsBug(BView *view, int32 frame);

	void draw_string (BView *view, BFont *font, int xoff, int yoff,
					  int win_width, int win_height, 
					  const char *string, int delay);

	int m_type, m_method;
	
	// used by random
	int32 m_interval;
	time_t m_last_reset;
	int32 m_starting_frame;	
	
	BBitmap *m_bitmap, *m_icon;
	image_id m_image;
	bool m_preview;	
};

class BSODConfigView : public BView 
{
 public:
	BSODConfigView(BRect frame, BSOD *s);
	virtual void AttachedToWindow(void);
	virtual void MessageReceived(BMessage *message);
	
 private:
 	void UpdateLabel();
 
	BSOD *m_screensaver;	
	BMenu *m_type_menu;
	BSlider	*m_delay_slider;
};

#endif // BSOD_H