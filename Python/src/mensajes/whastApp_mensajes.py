import pywhatkit
import time
import keyboard
# Reemplaza con el número de teléfono al que deseas enviar el mensaje
## Lista de números de teléfono
numeros = ["+527711247516"]

# Lista de mensajes
mensajes = "Hola Alma buenas noches."

# Función para enviar mensajes
def enviar_mensaje(numero, mensaje, hora, minuto):
    pywhatkit.sendwhatmsg(numero, mensaje, hora, minuto, 10, True, True)
    # time.sleep(10)  # Espera 20 segundos
    # keyboard.press_and_release('ctrl+w')  # Cierra la ventana del navegador

# Hora actual
hora_actual = time.localtime().tm_hour
minuto_actual = time.localtime().tm_min

# Enviar mensajes
for i in range(len(numeros)):
    enviar_mensaje(numeros[i], mensajes, hora_actual, minuto_actual + 1)
    hora_actual = time.localtime().tm_hour
    minuto_actual = time.localtime().tm_min + 1