#ifndef _JPN_MSG_MACROS_H_ // Maybe something like _Z64_JPN_MSG_H_ // and rename file accordingly
#define _JPN_MSG_MACROS_H_

// Majora's mask codes


#define MSGCODE_COLOR_DEFAULT                   "\x20\x00"
#define MSGCODE_COLOR_RED                       "\x20\x01"
#define MSGCODE_COLOR_GREEN                     "\x20\x02"
#define MSGCODE_COLOR_BLUE                      "\x20\x03"
#define MSGCODE_COLOR_YELLOW                    "\x20\x04"
#define MSGCODE_COLOR_TURQUOISE                 "\x20\x05"
#define MSGCODE_COLOR_PINK                      "\x20\x06"
#define MSGCODE_COLOR_SILVER                    "\x20\x07"
#define MSGCODE_COLOR_ORANGE                    "\x20\x08"

//#define MSGCODE_SLOWDOWNTEXT                    "\x??\x??"      // Slows down text (not used)
#define MSGCODE_PRINT_JUNGLECRUISEHITS          "\x03\x10"      // Print: Hits Required to Win Jungle Cruise Reward
#define MSGCODE_PRINT_STRAYFAIRIES              "\x02\x1C"      // Print: Stray Fairies Collected in Current Dungeon
#define MSGCODE_PRINT_GOLD_SKULLTULAS           "\x02\x1D"      // Print: Gold Skulltulas Collected in Current Spider House

#define MSGCODE_BOXBREAK                        "\x00\x09"      // Used when four lines of text have been printed, but can technically be used anywhere.
#define MSGCODE_LINEBREAK                       "\x00\x0A"
#define MSGCODE_LINE_FEED                       "\x00\x0B"      // Used when three lines of text have been printed.
#define MSGCODE_CARRIAGE_RETURN                 "\x00\x0C"      // Reset Cursor Position to Start of Current Line.
#define MSGCODE_INDENT(x)                       "\x00\x1F""\0" x// Print: xx Spaces
#define MSGCODE_TEXTSKIP_OFF                    "\x02\x40"      // Disable Text Skip I
#define MSGCODE_PLAYERNAME                      "\x01\x00"      // Print: Player Name
#define MSGCODE_INSTANT_ON                      "\x01\x01"      // Enable: Instantaneous Text
#define MSGCODE_INSTANT_OFF                     "\x01\x02"      // Disable: Instantaneous Text
#define MSGCODE_TEXTSKIP_OFF_SOUND              "\x01\x03"      // Disable Text Skip II
#define MSGCODE_KEEPOPEN                        "\x01\x04"      // Disable Text Box Close. Used for shop item descriptions.

#define MSGCODE_DELAY_(x, y)                    "\x01\x10" x y  // Delay for xxxx Before Printing Remaining Text
#define MSGCODE_KEPTTEXT(x, y)                  "\x01\x11" x y  // Keep Text on Screen for xxxx Before Closing
#define MSGCODE_DELAY_CONVERSATION_END(x, y)    "\x01\x12" x y  // Delay for xxxx Before Ending Conversation
#define MSGCODE_PLAYSOUND(x, y)                 "\x01\x20" x y  // Play Sound Effect xxxx
#define MSGCODE_DELAY_TEXTFLOW(x, y)            "\x01\x28" x y  // Delay for xxxx Before Resuming Text Flow

#define MSGCODE_ENDMARKER                       "\x05\x00"


// Special characters

#define MSGCODE_A_BTN                           "\x89\x9F"
#define MSGCODE_B_BTN                           "\x89\xA0"
#define MSGCODE_C_BTN                           "\x89\xA1"
#define MSGCODE_L_BTN                           "\x89\xA2"
#define MSGCODE_R_BTN                           "\x89\xA3"
#define MSGCODE_Z_BTN                           "\x89\xA4"
#define MSGCODE_CUP_BTN                         "\x89\xA5"
#define MSGCODE_CDOWN_BTN                       "\x89\xA6"
#define MSGCODE_CLEFT_BTN                       "\x89\xA7"
#define MSGCODE_CRIGHT_BTN                      "\x89\xA8"
#define MSGCODE_TARGET_ICON                     "\x89\xA9"
#define MSGCODE_STICK                           "\x89\xAA"
#define MSGCODE_DPAD                            "\x89\xAB"

#endif
