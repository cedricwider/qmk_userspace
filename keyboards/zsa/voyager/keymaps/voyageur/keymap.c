#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
};
enum voyager_layers {
    _BASE,
    _DEVELOPER,
    _NUMPAD,
    _STUFF,
    _NAVIGATION,
};

/*
* Macro definitions for custom keycodes
*/

// Thumb keys
#define CK_LWR LT(_DEVELOPER, KC_MINUS)
#define CK_LSPAC LT(_NAVIGATION, KC_TAB)
#define CK_RSPAC LT(_NAVIGATION, KC_ENTER)
#define CK_RSE LT(_NUMPAD, KC_SPACE)

// Home Row Mods
#define CK_HRS MT(MOD_LGUI, KC_S)
#define CK_HRH MT(MOD_LALT, KC_H)
#define CK_HRN MT(MOD_LCTL, KC_N)
#define CK_HRT MT(MOD_LSFT, KC_T)

#define CK_HRA MT(MOD_RSFT, KC_A)
#define CK_HRE MT(MOD_RCTL, KC_E)
#define CK_HRO MT(MOD_RALT, KC_O)
#define CK_HRI MT(MOD_RGUI, KC_I)

// Special Keys
#define CK_HYPR0 LGUI(LCTL(RALT(LSFT(KC_0))))
#define HYPR_TAP ALL_T(KC_TAB)
#define CK_CL_EC MT(MOD_LCTL, KC_ESCAPE)

#define CK_ACS_0 LALT(LCTL(LSFT(KC_0)))
#define CK_ACS_1 LALT(LCTL(LSFT(KC_1)))
#define CK_ACS_2 LALT(LCTL(LSFT(KC_2)))
#define CK_ACS_3 LALT(LCTL(LSFT(KC_3)))
#define CK_ACS_4 LALT(LCTL(LSFT(KC_4)))
#define CK_ACS_5 LALT(LCTL(LSFT(KC_5)))
#define CK_ACS_6 LALT(LCTL(LSFT(KC_6)))
#define CK_ACS_7 LALT(LCTL(LSFT(KC_7)))
#define CK_ACS_8 LALT(LCTL(LSFT(KC_8)))
#define CK_ACS_9 LALT(LCTL(LSFT(KC_9)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_voyager(
    LALT(KC_U),     KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,
    HYPR_TAP,       KC_W,           KC_L,           KC_R,           KC_B,           KC_Z,                                           KC_SCLN,        KC_Q,           KC_U,           KC_D,           KC_J,           KC_BSLS,
    CK_CL_EC,       CK_HRS,         CK_HRH,         CK_HRN,         CK_HRT,         KC_COMMA,                                       KC_DOT,         CK_HRA,         CK_HRE,         CK_HRO,         CK_HRI,         MT(MOD_LCTL, KC_QUOTE),
    CK_HYPR0,       KC_F,           KC_M,           KC_V,           KC_C,           KC_SLASH,                                       KC_G,           KC_P,           KC_X,           KC_K,           KC_Y,           MT(MOD_LSFT, KC_ENTER),
                                                                    CK_LWR,         CK_LSPAC,                                       CK_RSPAC, CK_RSE
  ),

  [_DEVELOPER] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_EXLM,        KC_PLUS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LCBR,        KC_HASH,        KC_EQUAL,       KC_RCBR,        KC_PIPE,
    KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LABK,                                        KC_RABK,        KC_LPRN,        KC_DLR,         KC_MINUS,       KC_RPRN,        KC_GRAVE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLS,                                        KC_TRANSPARENT, KC_LBRC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_RBRC,        KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 TO(_NUMPAD),          KC_TRANSPARENT
  ),

  [_NUMPAD] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_SLASH,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ASTR,        KC_TRANSPARENT,
    KC_GRAVE,       KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,                                         KC_COLN,        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_TRANSPARENT,
    KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F11,                                         KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,                                         KC_0,           KC_1,           KC_2,           KC_3,           KC_COMMA,       KC_ENTER,
                                                                    KC_TRANSPARENT, TO(_BASE),                                      TO(_STUFF),     KC_TRANSPARENT
  ),

  [_STUFF] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
    RGB_SAD,        RGB_SAI,        KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,                                 KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,
    RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,                                KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                KC_TRANSPARENT, TO(_BASE),                                          KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_NAVIGATION] = LAYOUT_voyager(
    KC_TRANSPARENT, CK_ACS_1,       CK_ACS_2,       CK_ACS_3,       CK_ACS_4,       CK_ACS_5,                                       CK_ACS_6,       CK_ACS_7,       CK_ACS_8,       CK_ACS_9,       CK_ACS_0,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TILD,        ST_MACRO_0,     ST_MACRO_1,     KC_TRANSPARENT, KC_TRANSPARENT,                                 LSFT(KC_TAB),   KC_TAB,         LALT(KC_BSPC),  KC_BSPC,        KC_DELETE,      KC_TRANSPARENT,
    KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_ESCAPE,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_2,     ST_MACRO_3,     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         ST_MACRO_4,     KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_LWR:
            return TAPPING_TERM -62;
        case CK_RSE:
            return TAPPING_TERM -62;
        case CK_LSPAC:
            return TAPPING_TERM -62;
        case CK_RSPAC:
            return TAPPING_TERM -62;

        case CK_HRT:
            return TAPPING_TERM -62;
        case CK_HRA:
            return TAPPING_TERM -62;

        case CK_HRS:
            return TAPPING_TERM +62;
        case CK_HRH:
            return TAPPING_TERM +62;
        case CK_HRO:
            return TAPPING_TERM +62;
        case CK_HRI:
            return TAPPING_TERM +62;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    //_BASE
    [0] = {
        {96,230,217}, {96,230,217},  {96,230,217},  {96,230,217},  {96,230,217},  {96,230,217},
        {96,230,217}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152},
        {96,230,217}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152},
        {96,230,217}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152},
                                                                    {96,230,217},  {96,230,217},

        {96,230,217},  {96,230,217},  {96,230,217},  {96,230,217},  {96,230,217},  {96,230,217},
        {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {96,230,217},
        {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {96,230,217},
        {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {96,230,217},
        {96,230,217},  {96,230,217}
    },

    //_DEVELOPER
    [1] = {
        {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255},
        {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255},
        {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255},
        {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255},
                                                                    {169,255,255}, {169,255,255},

        {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255},
        {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255},
        {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255},
        {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255},
        {169,255,255}, {169,255,255}
    },

    //_NUMPAD
    [2] = {
        {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},
        {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},
        {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},
        {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},
                                                                    {0,245,245},   {0,245,245},

        {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},
        {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},
        {0,245,245},   {0,245,245},   {41,255,255},  {0,245,245},   {0,245,245},   {0,245,245},
        {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},   {0,245,245},
        {0,245,245},   {0,245,245}
    },

    //_STUFF
    [3] = {
        {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},
        {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},
        {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},
        {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},
                                                                    {131,255,255}, {131,255,255},

        {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},
        {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},
        {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},
        {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},
        {131,255,255}, {131,255,255}
    },

    //_NAVIGATION
    [4] = {
        {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},
        {169,255,84},  {169,255,84},  {131,255,255}, {131,255,255}, {169,255,84},  {169,255,84},
        {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},
        {169,255,84},  {169,255,84},  {131,255,255}, {131,255,255}, {169,255,84},  {169,255,84},
                                                                    {169,255,84},  {169,255,84},

        {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},
        {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},
        {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {169,255,84},  {169,255,84},
        {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},  {169,255,84},
        {169,255,84},  {169,255,84}
    },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case _BASE:
      set_layer_color(0);
      break;
    case _DEVELOPER:
      set_layer_color(1);
      break;
    case _NUMPAD:
      set_layer_color(2);
      break;
    case _STUFF:
      set_layer_color(3);
      break;
    case _NAVIGATION:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(100) SS_TAP(X_B));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRC) SS_DELAY(100) SS_TAP(X_B));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(100) SS_TAP(X_T));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRC) SS_DELAY(100) SS_TAP(X_T));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_BSLS)) SS_DELAY(100) SS_LCTL(SS_TAP(X_N)));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
  }
  return true;
}



