#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,

  /*
  * Macro definitions for custom keycodes
  */
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
};

enum voyager_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _NAV,
    _NUMERIC,
    _STUFF,
};

// Thumb keys
#define CK_LWR MO(_LOWER)
#define CK_RSE LT(_RAISE, KC_SPACE)

#define CK_LSPAC LT(_NAV, KC_TAB)
#define CK_RSPAC LT(_NAV, KC_ENTER)

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
#define CK_HYPR0 HYPR(KC_0)
#define MEH_TAP  MEH_T(KC_TAB)
#define CK_CL_EC MT(MOD_LCTL, KC_ESCAPE)
#define CK_HPRUM LALT(KC_U)
#define CK_NUM_F LT(_NUMERIC, KC_F)
#define CK_MSRCH LGUI(KC_F12)

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

// Combo Definitions
const uint16_t PROGMEM num_toggle[] = {KC_M, CK_NUM_F, COMBO_END};
combo_t key_combos[] = {
    COMBO(num_toggle, TG(_NUMERIC)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_voyager(
    CK_HYPR0 ,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,
    MEH_TAP,        KC_W,           KC_L,           KC_R,           KC_B,           KC_Z,                                           KC_SCLN,        KC_Q,           KC_U,           KC_D,           KC_J,           KC_BSLS,
    CK_CL_EC,       CK_HRS,         CK_HRH,         CK_HRN,         CK_HRT,         KC_COMMA,                                       KC_DOT,         CK_HRA,         CK_HRE,         CK_HRO,         CK_HRI,         MT(MOD_LCTL, KC_QUOTE),
    OSM(MOD_LSFT),  CK_NUM_F,       KC_M,           KC_V,           KC_C,           KC_SLASH,                                       KC_G,           KC_P,           KC_X,           KC_K,           KC_Y,           MT(MOD_LSFT, KC_ENTER),
                                                                    CK_LWR,         CK_LSPAC,                                       CK_RSPAC,       CK_RSE
  ),

  [_LOWER] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_BRID,        KC_BRIU,        KC_MCTL,        CK_MSRCH,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_MUTE,        KC_DELETE,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_PIPE,
    KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UNDS,        KC_PLUS,        KC_LCBR,        KC_RCBR,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_VOLD,                                        KC_VOLU,        KC_LBRC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_RBRC,        KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, TO(_STUFF)
  ),

  [_RAISE] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_DELETE,
    KC_TILD,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_PIPE,
    KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_INS,                                         KC_PSCR,        KC_MINUS,       KC_EQUAL,       KC_LBRC,        KC_RBRC,        KC_GRAVE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F11,                                         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                    TO(_STUFF),     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_NAV] = LAYOUT_voyager(
    KC_TRANSPARENT, CK_ACS_1,       CK_ACS_2,       CK_ACS_3,       CK_ACS_4,       CK_ACS_5,                                       CK_ACS_6,       CK_ACS_7,       CK_ACS_8,       CK_ACS_9,       CK_ACS_0,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LCBR,        KC_RCBR,        KC_TRANSPARENT,                                 LSFT(KC_TAB),   KC_TAB,         LALT(KC_BSPC),  KC_BSPC,        KC_DELETE,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_ESCAPE,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRC,        KC_RBRC,        KC_TRANSPARENT,                                 KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         ST_MACRO_4,     KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, LGUI(KC_SPACE),                                 LGUI(KC_SPACE), KC_TRANSPARENT
  ),

  [_NUMERIC] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_SLASH,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ASTR,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_COLN,        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_0,           KC_1,           KC_2,           KC_3,           KC_COMMA,       KC_ENTER,
                                                                    TO(_BASE),      TO(_BASE),                                      KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_STUFF] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
    RGB_SAD,        RGB_SAI,        KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,                                 KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,
    RGB_HUD,        RGB_HUI,        KC_TRANSPARENT, HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,                                KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                TO(_BASE), KC_TRANSPARENT,                                          KC_TRANSPARENT, TO(_BASE)
  ),

};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    //_BASE
    /* [0] = { */
    /*     {96,230,217}, {96,230,217},  {96,230,217},  {96,230,217},  {96,230,217},  {96,230,217}, */
    /*     {96,230,217}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, */
    /*     {96,230,217}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, */
    /*     {96,230,217}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, */
    /*                                                                 {96,230,217},  {96,230,217}, */
    /**/
    /*     {96,230,217},  {96,230,217},  {96,230,217},  {96,230,217},  {96,230,217},  {96,230,217}, */
    /*     {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {96,230,217}, */
    /*     {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {96,230,217}, */
    /*     {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {139,214,152}, {96,230,217}, */
    /*     {96,230,217},  {96,230,217} */
    /* }, */

    //_LOWER
    [1] = {
        {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255},
        {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255},
        {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255},
        {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255},
                                                                    {85,255,255}, {85,255,255},

        {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255},
        {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255},
        {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255},
        {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255},
        {85,255,255}, {85,255,255}
    },

    //_RAISE
    [2] = {
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

    //_NAV
    [3] = {
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

    //_NUMERIC
    [4] = {
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
    [5] = {
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
    /* case _BASE: */
    /*   set_layer_color(0); */
    /*   break; */
    case _LOWER:
      set_layer_color(1);
      break;
    case _RAISE:
      set_layer_color(2);
      break;
    case _NAV:
      set_layer_color(3);
      break;
    case _NUMERIC:
      set_layer_color(4);
      break;
    case _STUFF:
      set_layer_color(5);
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_LWR:
            return TAPPING_TERM -32;
        case CK_RSE:
            return TAPPING_TERM -32;
        case CK_LSPAC:
            return TAPPING_TERM -32;
        case CK_RSPAC:
            return TAPPING_TERM -32;

        case CK_HRT:
            return TAPPING_TERM -27;
        case CK_HRA:
            return TAPPING_TERM -27;

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

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_HRT:
        case CK_HRA:
            return 130;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_LWR:
        case CK_RSE:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_LWR:
        case CK_LSPAC:
        case CK_RSPAC:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
