# Importar módulos
import tkinter as tk
from datetime import datetime

# Crear ventana principal
ventana = tk.Tk()
ventana.title("Reloj digital")

# Crear variable para mostrar la hora
hora = tk.StringVar()

# Crear etiqueta para mostrar la hora
etiqueta = tk.Label(ventana, textvariable=hora, font=("Arial", 50))
etiqueta.pack()

# Función para actualizar la hora
def actualizar_hora():
    # Obtener la hora actual
    ahora = datetime.now()
    # Formatear la hora como HH:MM:SS
    formato = ahora.strftime("%H:%M:%S")
    # Asignar la hora formateada a la variable
    hora.set(formato)
    # Invocar a la función después de 1000 milisegundos (1 segundo)
    ventana.after(1000, actualizar_hora)

# Llamar a la función por primera vez
actualizar_hora()

# Iniciar el bucle principal de tkinter
ventana.mainloop()