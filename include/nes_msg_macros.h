#ifndef _NES_MSG_MACROS_H_ // Maybe something like _Z64_NES_MSG_H_ // and rename file accordingly
#define _NES_MSG_MACROS_H_

// Majora's mask codes


#define MSGCODE_COLOR_DEFAULT           "\x00"
#define MSGCODE_COLOR_RED               "\x01"
#define MSGCODE_COLOR_GREEN             "\x02"
#define MSGCODE_COLOR_BLUE              "\x03"
#define MSGCODE_COLOR_YELLOW            "\x04"
#define MSGCODE_COLOR_TURQUOISE         "\x05"
#define MSGCODE_COLOR_PINK              "\x06"
#define MSGCODE_COLOR_SILVER            "\x07"
#define MSGCODE_COLOR_ORANGE            "\x08"

#define MSGCODE_BOXBREAK                "\x10" // Used when four lines of text have been printed, but can technically be used anywhere.
#define MSGCODE_LINEBREAK               "\x11"
#define MSGCODE_LINE_FEED               "\x12" // Used when three lines of text have been printed.
#define MSGCODE_CARRIAGE_RETURN         "\x13" // Reset Cursor Position to Start of Current Line.
#define MSGCODE_INDENT                  "\x14" // Print: xx Spaces
#define MSGCODE_INSTANT_ON              "\x17" // Enable: Instantaneous Text
#define MSGCODE_INSTANT_OFF             "\x18" // Disable: Instantaneous Text

#define MSGCODE_DELAY_                  "\x1B" // Delay for xxxx Before Printing Remaining Text
#define MSGCODE_KEPTTEXT                "\x1C" // Keep Text on Screen for xxxx Before Closing
#define MSGCODE_DELAY_CONVERSATION_END  "\x1D" // Delay for xxxx Before Ending Conversation
#define MSGCODE_PLAYSOUND               "\x1E" // Play Sound Effect xxxx
#define MSGCODE_DELAY_TEXTFLOW          "\x1F" // Delay for xxxx Before Resuming Text Flow

#define MSGCODE_ENDMARKER               "\xBF"


// Special characters

#define MSGCODE_E_ACUTE_LOWERCASE       "\x9D" // "é"

#define MSGCODE_A_BTN                   "\xB0"
#define MSGCODE_B_BTN                   "\xB1"
#define MSGCODE_C_BTN                   "\xB2"
#define MSGCODE_L_BTN                   "\xB3"
#define MSGCODE_R_BTN                   "\xB4"
#define MSGCODE_Z_BTN                   "\xB5"
#define MSGCODE_CUP_BTN                 "\xB6"
#define MSGCODE_CDOWN_BTN               "\xB7"
#define MSGCODE_CLEFT_BTN               "\xB8"
#define MSGCODE_CRIGHT_BTN              "\xB9"
#define MSGCODE_TARGET_ICON             "\xBA"
#define MSGCODE_STICK                   "\xBB"
// #define MSGCODE_DPAD "\x??" // Unused.

#endif
