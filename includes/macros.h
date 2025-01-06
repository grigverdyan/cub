#ifndef MACROS_H
# define MACROS_H

//  GAME
# define WIN_WIDTH			960
# define WIN_HEIGHT			600
# define SENSITIVITY		0.05
# define MOVEMENT_SPEED		0.1
# define ANIM_CHANGE_FRAME	50

// ERROR_CODES
# define BAD_INPUT_FILE		1
# define BAD_ARGUMENT		2
# define UNRECOGNIZED_LINE	3
# define BAD_MAP			4
# define TEXTURE_MISSING	5
# define COULD_NOT_INIT		6
# define WRONG_NUM_ARGS		7
# define WRONG_FILE_EXT		8
# define BAD_ARG_FILE		9

// minimap
# define MAP_OFFSET			32
# define MINI_SCALE			6
# define MINI_SIZE			12

// minimap colors
# define MINIMAP_OUTER		0x433BDE
# define MINIMAP_ZERO		0x433BDE
# define MINIMAP_ONE		0xDEDEDE
# define MINIMAP_TWO		0xFF00FF
# define MINIMAP_PLAYER		0x00FF00

// boolean
# define TRUE				1
# define FALSE				0

// textures
# define TEXT_WIDTH			64
# define TEXT_HIGHT			64
# define TEXTURES_COUNT		4
# define SPRITES_COUNT		1
# define ENEMY_INDEX		0

// map
# define MAP_CHARS			"0123456789NEWS "
# define MAP_CHARS_WN		"0123456789NEWS \n"
# define WALL				'1'
# define ENEMY				'2'
# define DOOR				'3'
# define GROUND				'0'
# define NORTH				'N'
# define EAST				'E'
# define WEST				'W'
# define SOUTH				'S'
# define EMPTY				' '

// colors
# define BLACK_TERM			"\033[0;30m"
# define RED_TERM			"\033[1;31m"
# define WHITE_TERM			"\033[0;37m"
# define GREEN_TERM			"\033[1;32m"
# define SEP_TERM			"\033[1;36m"

// directions
# define _NORTH				0
# define _EAST				1
# define _WEST				2
# define _SOUTH				3

// keys
# define KEY_ESC			53

# define UP_ARROW			126
# define DOWN_ARROW		125
# define LEFT_ARROW		123
# define RIGHT_ARROW		124

# define KEYPAD_ZERO		82

# define KEY_ONE			18
# define KEY_TWO			19
# define KEY_THREE			20
# define KEY_FOUR			21
# define KEY_FIVE			23
# define KEY_SIX			22
# define KEY_SEVEN			26
# define KEY_EIGHT			28
# define KEY_NINE			25
# define KEY_ZERO			29

# define KEY_Q				12
# define KEY_W				13
# define KEY_E				14
# define KEY_R				15
# define KEY_T				17
# define KEY_Y				16

# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_F				3
# define KEY_G				5
# define KEY_H				4

# define KEY_L				37

# define MOUSE_LEFT_CLK	1
# define MOUSE_SCRL_CLK	3
# define MOUSE_RIGHT_CLK	2
# define MOUSE_SCRL_UP		5
# define MOUSE_SCRL_DOWN	4

#endif
