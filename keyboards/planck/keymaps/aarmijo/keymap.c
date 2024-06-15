/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
	_QWERTY,
	_COLEMAK,
	_DVORAK,
	_PLOVER,
	_NUMBERS,
	_LOWER,
	_RAISE,
	_ADJUST,
	_FUNCTION
};

enum planck_keycodes {
	QWERTY = SAFE_RANGE,
	COLEMAK,
	DVORAK,
	PLOVER,
	EXT_PLV,
	NUMBERS,
	RUT,
	EMAIL,
	PHONE,
	CC,
	USR,
	PWD,
	GMT
};

#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define FUNCTION MO(_FUNCTION)
#define LOW_TAB  LT(LOWER, KC_TAB)
#define LS_CAPS  LSFT_T(KC_CAPS)
#define RS_END   RSFT_T(KC_END)
#define RA_LEFT  RALT_T(KC_LEFT)
#define RALT_N	 RALT(KC_N)
#define RC_RGHT  RCTL_T(KC_RGHT)
#define RS_ENT   RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Qwerty
		* ,-----------------------------------------------------------------------------------.
		* | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
		* |------+------+------+------+------+------+------+------+------+------+------+------|
		* | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
		* |------+------+------+------+------+------+------+------+------+------+------+------|
		* | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
		* |------+------+------+------+------+------+------+------+------+------+------+------|
		* | Ctrl | Func | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
		* `-----------------------------------------------------------------------------------'
	*/
	[_QWERTY] = LAYOUT_planck_grid(
		QK_GESC, KC_Q,     KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
		LOW_TAB, KC_A,     KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		LS_CAPS, KC_Z,     KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, RS_ENT,
		KC_LCTL, FUNCTION, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, RA_LEFT, KC_DOWN, KC_UP,   RC_RGHT
	),

	/* Colemak
		* ,-----------------------------------------------------------------------------------.
		* | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
		* |------+------+------+------+------+------+------+------+------+------+------+------|
		* | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
		* |------+------+------+------+------+------+------+------+------+------+------+------|
		* | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
		* |------+------+------+------+------+------+------+------+------+------+------+------|
		* | Ctrl | Func | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
		* `-----------------------------------------------------------------------------------'
	*/
	[_COLEMAK] = LAYOUT_planck_grid(
		KC_TAB,  KC_Q,     KC_W,    KC_F,    KC_P,  KC_G,   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
		KC_ESC,  KC_A,     KC_R,    KC_S,    KC_T,  KC_D,   KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    KC_QUOT,
		KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,  KC_B,   KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
		KC_LCTL, FUNCTION, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
	),

	/* Dvorak
		* ,-----------------------------------------------------------------------------------.
		* | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
		* |------+------+------+------+------+------+------+------+------+------+------+------|
		* | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
		* |------+------+------+------+------+------+------+------+------+------+------+------|
		* | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
		* |------+------+------+------+------+------+------+------+------+------+------+------|
		* | Ctrl | Func | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
		* `-----------------------------------------------------------------------------------'
	*/
	[_DVORAK] = LAYOUT_planck_grid(
		KC_TAB,  KC_QUOT,  KC_COMM, KC_DOT,  KC_P,  KC_Y,   KC_F,   KC_G,  KC_C,    KC_R,    KC_L,    KC_BSPC,
		KC_ESC,  KC_A,     KC_O,    KC_E,    KC_U,  KC_I,   KC_D,   KC_H,  KC_T,    KC_N,    KC_S,    KC_SLSH,
		KC_LSFT, KC_SCLN,  KC_Q,    KC_J,    KC_K,  KC_X,   KC_B,   KC_M,  KC_W,    KC_V,    KC_Z,    KC_ENT ,
		KC_LCTL, FUNCTION, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
	),

	/* Plover layer (http://opensteno.org)
		* ,-----------------------------------------------------------------------------------.
		* |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
		* |------+------+------+------+------+------+------+------+------+------+------+------|
		* |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
		* |------+------+------+------+------+------+------+------+------+------+------+------|
		* |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
		* |------+------+------+------+------+------+------+------+------+------+------+------|
		* | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
		* `-----------------------------------------------------------------------------------'
	*/
	[_PLOVER] = LAYOUT_planck_grid(
		KC_1,    KC_1,     KC_1,    KC_1,    KC_1,  KC_1,   KC_1,   KC_1,  KC_1,    KC_1,    KC_1,    KC_1,
		KC_NO,   KC_Q,     KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC,
		KC_NO,   KC_A,     KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		EXT_PLV, KC_NO,    KC_NO,   KC_C,    KC_V,  KC_NO,  KC_NO,  KC_N,  KC_M,    KC_NO,   KC_NO,   KC_NO
	),

		/* Numbers */
	[_NUMBERS] = LAYOUT_planck_grid(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7, KC_P8,   KC_P9,   KC_PSLS, KC_BSPC,
		LOWER,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P4, KC_P5,   KC_P6,   KC_PAST, KC_NUM,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1, KC_P2,   KC_P3,   KC_PMNS, KC_ENT,
		QWERTY,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PCMM, KC_PDOT, KC_PPLS, KC_PEQL
	),

	/* Lower */
	[_LOWER] = LAYOUT_planck_grid(
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,       KC_9,     KC_0,    KC_DEL,
		KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,      KC_RIGHT, KC_TRNS, KC_GRV,
		KC_TRNS, KC_MPRV, KC_VOLD, KC_MPLY, KC_VOLU, KC_MNXT, RALT_N,  KC_MUTE, S(KC_NUBS), KC_TRNS,  KC_HOME, RS_END,
		KC_TRNS, NUMBERS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT,    KC_RGUI,  KC_APP,  KC_RCTL
	), 

	/* Raise */
	[_RAISE] = LAYOUT_planck_grid(
		KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
		KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
		KC_LSFT, KC_MPRV, KC_VOLD, KC_MPLY, KC_VOLU, KC_MNXT, KC_TRNS,  KC_MUTE, KC_NUBS, KC_TRNS, KC_TRNS, KC_RSFT,
		KC_TRNS, NUMBERS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_RALT, KC_RGUI, KC_APP,  KC_RCTL
	),

	/* Adjust (Lower + Raise) */
	[_ADJUST] = LAYOUT_planck_grid(
		QK_BOOT, RGB_TOG, RGB_M_P, RGB_M_B, RGB_MOD, RGB_RMOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI,
		AU_PREV, AU_TOGG, AU_NEXT, CK_DOWN, CK_TOGG, CK_UP,    KC_TRNS, QWERTY,  COLEMAK, DVORAK,  KC_TRNS, PLOVER,
		KC_TRNS, MU_TOGG, MU_NEXT, KC_TRNS, CK_RST,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EE_CLR
	),

	/* Function */
	[_FUNCTION] = LAYOUT_planck_grid(
		KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
		KC_TRNS, RUT,     EMAIL,   PHONE,   CC,      GMT,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
		KC_TRNS, USR,     PWD,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS
	)

};

#ifdef AUDIO_ENABLE
	float plover_song[][2] = SONG(PLOVER_SOUND);
	float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
	float planck_song[][2] = SONG(PLANCK_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case QWERTY:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_QWERTY);
			}
			return false;
			break;
		case COLEMAK:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_COLEMAK);
			}
			return false;
			break;
		case DVORAK:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_DVORAK);
			}
			return false;
			break;
		case PLOVER:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					stop_all_notes();
					PLAY_SONG(plover_song);
				#endif
				layer_off(_RAISE);
				layer_off(_LOWER);
				layer_off(_ADJUST);
				layer_on(_PLOVER);
				if (!eeconfig_is_enabled()) {
						eeconfig_init();
				}
				keymap_config.raw = eeconfig_read_keymap();
				keymap_config.nkro = 1;
				eeconfig_update_keymap(keymap_config.raw);
			}
			return false;
			break;
		case EXT_PLV:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					PLAY_SONG(plover_gb_song);
				#endif
				layer_off(_PLOVER);
			}
			return false;
			break;
		case NUMBERS:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_NUMBERS);
				PLAY_SONG(planck_song);
			}
			return false;
			break;
		case RUT:
			if (record->event.pressed) {
				SEND_STRING("13658100-7");
			}
			break;
		case EMAIL:
			if (record->event.pressed) {
				SEND_STRING("arielarmijo@yahoo.es");
			}
			break;
		case PHONE:
		if (record->event.pressed) {
			SEND_STRING("949931219");
		}
		break;
		case CC:
			if (record->event.pressed) {
				SEND_STRING("4345591123200648");
			}
			break;
		case GMT:
			if (record->event.pressed) {
				SEND_STRING("Good morning team!");
			}
			break;
		case USR:
			if (record->event.pressed) {
				SEND_STRING("aarmijo\n");
			}
			break;
		case PWD:
			if (record->event.pressed) {
				SEND_STRING("cg331x\n");
			}
			break;
	}
	return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
	if (muse_mode) {
		if (IS_LAYER_ON(_RAISE)) {
			if (clockwise) {
				muse_offset++;
			} else {
				muse_offset--;
			}
		} else {
			if (clockwise) {
				muse_tempo+=1;
			} else {
				muse_tempo-=1;
			}
		}
	} else {
		if (clockwise) {
			#ifdef MOUSEKEY_ENABLE
				tap_code(KC_MS_WH_DOWN);
			#else
				tap_code(KC_PGDN);
			#endif
		} else {
			#ifdef MOUSEKEY_ENABLE
				tap_code(KC_MS_WH_UP);
			#else
				tap_code(KC_PGUP);
			#endif
		}
	}
		return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
	switch (index) {
		case 0: {
			#ifdef AUDIO_ENABLE
				static bool play_sound = false;
			#endif
				if (active) {
					#ifdef AUDIO_ENABLE
						if (play_sound) { PLAY_SONG(plover_song); }
					#endif
						layer_on(_ADJUST);
				} else {
					#ifdef AUDIO_ENABLE
						if (play_sound) { PLAY_SONG(plover_gb_song); }
					#endif
						layer_off(_ADJUST);
				}
				#ifdef AUDIO_ENABLE
					play_sound = true;
				#endif
			break;
		}
		case 1:
			if (active) {
				muse_mode = true;
			} else {
				muse_mode = false;
			}
	}
	return true;
}

void matrix_scan_user(void) {
	#ifdef AUDIO_ENABLE
		if (muse_mode) {
			if (muse_counter == 0) {
				uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
				if (muse_note != last_muse_note) {
					stop_note(compute_freq_for_midi_note(last_muse_note));
					play_note(compute_freq_for_midi_note(muse_note), 0xF);
					last_muse_note = muse_note;
				}
			}
			muse_counter = (muse_counter + 1) % muse_tempo;
		} else {
			if (muse_counter) {
				stop_all_notes();
				muse_counter = 0;
			}
		}
	#endif
}

bool music_mask_user(uint16_t keycode) {
	switch (keycode) {
		case RAISE:
		case LOWER:
			return false;
		default:
			return true;
	}
}
