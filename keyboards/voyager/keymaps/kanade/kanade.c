bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
  // Follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;  // Bypass Achordion for thumb keys.
  }

  return 800;  // Otherwise use a timeout of 800 ms.
}

bool achordion_eager_mod(uint8_t mod) {
  return true;  // Eagerly apply all mods.
}

uint16_t achordion_streak_timeout(uint16_t tap_hold_keycode) {
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 20;  // A shorter streak timeout for layer-tap keys.
  }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & MOD_LSFT) != 0) {
    return 20;  // A shorter streak timeout for Shift mod-tap keys.
  } else if ((mod & MOD_RSFT) != 0) {
    return 20;  // A shorter streak timeout for Shift mod-tap keys.
  } else {
    return 120;  // A longer timeout otherwise.
  }
}

// Send `delete` when `shift` + `backspace` are pressed.
// Note that `backspace` is a layer1 layer-tap key.
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(2,KC_BSPC), KC_DEL);

// This globally defines all key overrides to be used.
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};
