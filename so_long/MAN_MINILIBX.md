# mlx_init

**Descripción:** Inicializa MiniLibX.

**Uso:** `void *mlx_init();`

**Devuelve:** Un puntero que se utiliza como identificador para las futuras operaciones MiniLibX.

---

# mlx_new_window

**Descripción:** Crea una nueva ventana.

**Uso:** `void *mlx_new_window(void *mlx_ptr, int width, int height, char *title);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.
- `width`, `height`: Tamaño de la ventana.
- `title`: Título de la ventana.

**Devuelve:** Un puntero que representa la nueva ventana.

---

# mlx_pixel_put

**Descripción:** Dibuja un píxel en una ventana.

**Uso:** `void mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.
- `win_ptr`: Puntero a la ventana donde se dibujará el píxel.
- `x`, `y`: Coordenadas del píxel.
- `color`: Color del píxel en formato hexadecimal RGB.

---

# mlx_new_image

**Descripción:** Crea una nueva imagen.

**Uso:** `void *mlx_new_image(void *mlx_ptr, int width, int height);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.
- `width`, `height`: Tamaño de la imagen.

**Devuelve:** Un puntero que representa la nueva imagen.

---

# mlx_get_data_addr

**Descripción:** Obtiene la dirección del primer byte del primer canal de una imagen.

**Uso:** `char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);`

**Argumentos:**
- `img_ptr`: Puntero a la imagen.
- `bits_per_pixel`: Puntero para almacenar el número de bits por píxel.
- `size_line`: Puntero para almacenar el tamaño de una línea de la imagen en bytes.
- `endian`: Puntero para almacenar el formato de orden de bytes (0 para little-endian, 1 para big-endian).

**Devuelve:** La dirección del primer byte del primer canal de la imagen.

---

# mlx_clear_window

**Descripción:** Limpia una ventana y la pone en color negro.

**Uso:** `void mlx_clear_window(void *mlx_ptr, void *win_ptr);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.
- `win_ptr`: Puntero a la ventana que se va a limpiar.

---

# mlx_destroy_window

**Descripción:** Cierra y libera los recursos asociados a una ventana.

**Uso:** `void mlx_destroy_window(void *mlx_ptr, void *win_ptr);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.
- `win_ptr`: Puntero a la ventana que se va a destruir.

---

# mlx_destroy_image

**Descripción:** Libera los recursos asociados a una imagen.

**Uso:** `void mlx_destroy_image(void *mlx_ptr, void *img_ptr);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.
- `img_ptr`: Puntero a la imagen que se va a destruir.

---

# mlx_hook

**Descripción:** Establece una función de callback para manejar eventos específicos.

**Uso:** `int mlx_hook(void *win_ptr, int event, int (*funct_ptr)(), void *param);`

**Argumentos:**
- `win_ptr`: Puntero a la ventana.
- `event`: Tipo de evento.
- `funct_ptr`: Puntero a la función de callback.
- `param`: Parámetro que se pasa a la función de callback.
---

# mlx_loop

**Descripción:** Inicia el bucle de eventos MiniLibX y espera a que ocurra un evento en cualquiera de las ventanas.

**Uso:** `int mlx_loop(void *mlx_ptr);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.

---

# mlx_string_put

**Descripción:** Muestra un texto en una ventana.

**Uso:** `int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *str);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.
- `win_ptr`: Puntero a la ventana.
- `x`, `y`: Coordenadas donde se colocará el texto.
- `color`: Color del texto en formato hexadecimal RGB.
- `str`: Cadena de texto que se mostrará.

---

# mlx_key_hook

**Descripción:** Establece una función de callback para manejar eventos de teclado.

**Uso:** `int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);`

**Argumentos:**
- `win_ptr`: Puntero a la ventana.
- `funct_ptr`: Puntero a la función de callback.
- `param`: Parámetro que se pasa a la función de callback.

---

# mlx_mouse_hook

**Descripción:** Establece una función de callback para manejar eventos de ratón.

**Uso:** `int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);`

**Argumentos:**
- `win_ptr`: Puntero a la ventana.
- `funct_ptr`: Puntero a la función de callback.
- `param`: Parámetro que se pasa a la función de callback.

---

# mlx_expose_hook

**Descripción:** Establece una función de callback para manejar eventos de exposición de la ventana.

**Uso:** `int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);`

**Argumentos:**
- `win_ptr`: Puntero a la ventana.
- `funct_ptr`: Puntero a la función de callback.
- `param`: Parámetro que se pasa a la función de callback.

---

# mlx_loop_hook

**Descripción:** Establece una función de callback que se llama repetidamente mientras MiniLibX está en el bucle de eventos.

**Uso:** `int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.
- `funct_ptr`: Puntero a la función de callback.
- `param`: Parámetro que se pasa a la función de callback.

---

# mlx_new_image_from_file

**Descripción:** Crea una nueva imagen cargada desde un archivo.

**Uso:** `void *mlx_new_image_from_file(void *mlx_ptr, char *filename, int *width, int *height);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.
- `filename`: Nombre del archivo de la imagen.
- `width`, `height`: Punteros para almacenar el ancho y alto de la imagen cargada.

**Devuelve:** Un puntero que representa la nueva imagen.

---

# mlx_put_image_to_window

**Descripción:** Muestra una imagen en una ventana.

**Uso:** `int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.
- `win_ptr`: Puntero a la ventana.
- `img_ptr`: Puntero a la imagen que se va a mostrar.
- `x`, `y`: Coordenadas donde se colocará la imagen.

---

# mlx_get_color_value

**Descripción:** Convierte un color en formato hexadecimal RGB en un valor que puede ser utilizado por MiniLibX.

**Uso:** `int mlx_get_color_value(void *mlx_ptr, int color);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.
- `color`: Color en formato hexadecimal RGB.

**Devuelve:** El valor del color que puede ser utilizado por MiniLibX.

---

# mlx_flush_event

**Descripción:** Forza el envío de eventos pendientes a la ventana.

**Uso:** `int mlx_flush_event(void *mlx_ptr);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.

---

# mlx_loop_hook_remove

**Descripción:** Elimina una función de callback del bucle de eventos MiniLibX.

**Uso:** `int mlx_loop_hook_remove(void *mlx_ptr, int (*funct_ptr)(), void *param);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.
- `funct_ptr`: Puntero a la función de callback.
- `param`: Parámetro que se pasa a la función de callback.

---

# mlx_do_sync

**Descripción:** Espera a que todos los eventos pendientes en la ventana se completen.

**Uso:** `int mlx_do_sync(void *mlx_ptr);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.

---

# mlx_sync

**Descripción:** Espera a que se completen todos los eventos pendientes en la ventana.

**Uso:** `int mlx_sync(void *mlx_ptr);`

**Argumentos:**
- `mlx_ptr`: Puntero devuelto por `mlx_init()`.

