const int32 mac_width = 75;
const int32 mac_height = 100;

const unsigned char mac_bits [] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f
};
