#define MASTER_LEFT

#define RGB_DI_PIN D0
#define RGBLIGHT_LED_COUNT 54
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LAYERS

// Habilitar soporte para iluminación RGB
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_LIMIT_VAL 120  // Ajusta el brillo máximo (0-255)
#define RGBLIGHT_SLEEP       // Apaga los LEDs al entrar en reposo
#define RGBLIGHT_HUE_STEP 8  // Ajusta la velocidad de cambio de tono
#define RGBLIGHT_SAT_STEP 8  // Ajusta la velocidad de cambio de saturación
#define RGBLIGHT_VAL_STEP 8  // Ajusta la velocidad de cambio de brillo

// mouse configs
#define OUSEKEY_DELAY 10 // Retraso entre presionar una tecla de movimiento y el movimiento del cursor
#define OUSEKEY_INTERVAL 10 // Tiempo entre movimientos del cursor en milisegundos
#define OUSEKEY_MOVE_DELTA 6 // Tamaño del paso
#define OUSEKEY_MAX_SPEED 10 // Velocidad máxima del cursor en la que se detiene la aceleración
#define OUSEKEY_TIME_TO_MAX 30 // Tiempo hasta que se alcanza la velocidad máxima del cursor
#define OUSEKEY_WHEEL_DELAY 10 // Retraso entre presionar una tecla de rueda y el movimiento de la rueda
#define OUSEKEY_WHEEL_INTERVAL 80 // Tiempo entre movimientos de las ruedas
#define OUSEKEY_WHEEL_DELTA 1 // Tamaño del paso del movimiento de la rueda
#define OUSEKEY_WHEEL_MAX_SPEED 8 // Número máximo de pasos de desplazamiento por acción de desplazamiento
#define OUSEKEY_WHEEL_TIME_TO_MAX 40 // Tiempo hasta que se alcanza la velocidad máxima de desplazamiento
