#ifndef _NES_MSG_MACROS_H_ // Maybe something like _Z64_MM_NES_MSG_H_ // and rename file accordingly
#define _NES_MSG_MACROS_H_

#include "ultra64.h"

// The size should be correct, but the signedness may not be
typedef struct {
    /* 0x00 */  u8 boxType;
    /* 0x01 */  u8 yPos;
    /* 0x02 */  u8 itemIcon;
    /* 0x03 */  u16 nextMsgId;
    /* 0x05 */  u16 itemPrice;
    /* 0x07 */  u16 itemPrice;
    /* 0x09 */  u16 itemPrice;
} MessageHeader; // size = 0x0B


// Majora's mask codes

#define MSGCODE_COLOR_DEFAULT                   "\x00"
#define MSGCODE_COLOR_RED                       "\x01"
#define MSGCODE_COLOR_GREEN                     "\x02"
#define MSGCODE_COLOR_BLUE                      "\x03"
#define MSGCODE_COLOR_YELLOW                    "\x04"
#define MSGCODE_COLOR_TURQUOISE                 "\x05"
#define MSGCODE_COLOR_PINK                      "\x06"
#define MSGCODE_COLOR_SILVER                    "\x07"
#define MSGCODE_COLOR_ORANGE                    "\x08"

#define MSGCODE_SLOWDOWNTEXT                    "\x0A"      // Slows down text (not used)
#define MSGCODE_PRINT_JUNGLECRUISEHITS          "\x0B"      // Print: Hits Required to Win Jungle Cruise Reward
#define MSGCODE_PRINT_STRAYFAIRIES              "\x0C"      // Print: Stray Fairies Collected in Current Dungeon
#define MSGCODE_PRINT_GOLD_SKULLTULAS           "\x0D"      // Print: Gold Skulltulas Collected in Current Spider House

#define MSGCODE_BOXBREAK                        "\x10"      // Used when four lines of text have been printed, but can technically be used anywhere.
#define MSGCODE_LINEBREAK                       "\x11"
#define MSGCODE_LINE_FEED                       "\x12"      // Used when three lines of text have been printed.
#define MSGCODE_CARRIAGE_RETURN                 "\x13"      // Reset Cursor Position to Start of Current Line.
#define MSGCODE_INDENT(x)                       "\x14" x    // Print: xx Spaces
#define MSGCODE_TEXTSKIP_OFF                    "\x15"      // Disable Text Skip I
#define MSGCODE_PLAYERNAME                      "\x16"      // Print: Player Name
#define MSGCODE_INSTANT_ON                      "\x17"      // Enable: Instantaneous Text
#define MSGCODE_INSTANT_OFF                     "\x18"      // Disable: Instantaneous Text
#define MSGCODE_TEXTSKIP_OFF_SOUND              "\x19"      // Disable Text Skip II
#define MSGCODE_KEEPOPEN                        "\x1A"      // Disable Text Box Close. Used for shop item descriptions.

#define MSGCODE_DELAY_(x, y)                    "\x1B" x y  // Delay for xxxx Before Printing Remaining Text
#define MSGCODE_KEPTTEXT(x, y)                  "\x1C" x y  // Keep Text on Screen for xxxx Before Closing
#define MSGCODE_DELAY_CONVERSATION_END(x, y)    "\x1D" x y  // Delay for xxxx Before Ending Conversation
#define MSGCODE_PLAYSOUND(x, y)                 "\x1E" x y  // Play Sound Effect xxxx
#define MSGCODE_DELAY_TEXTFLOW(x, y)            "\x1F" x y  // Delay for xxxx Before Resuming Text Flow

#define MSGCODE_ENDMARKER                       "\xBF"


// Special characters

#define MSGCODE_E_ACUTE_LOWERCASE               "\x9D"      // "é"

#define MSGCODE_A_BTN                           "\xB0"
#define MSGCODE_B_BTN                           "\xB1"
#define MSGCODE_C_BTN                           "\xB2"
#define MSGCODE_L_BTN                           "\xB3"
#define MSGCODE_R_BTN                           "\xB4"
#define MSGCODE_Z_BTN                           "\xB5"
#define MSGCODE_CUP_BTN                         "\xB6"
#define MSGCODE_CDOWN_BTN                       "\xB7"
#define MSGCODE_CLEFT_BTN                       "\xB8"
#define MSGCODE_CRIGHT_BTN                      "\xB9"
#define MSGCODE_TARGET_ICON                     "\xBA"
#define MSGCODE_STICK                           "\xBB"
//#define MSGCODE_DPAD                            "\x??"      // Unused.

#endif
