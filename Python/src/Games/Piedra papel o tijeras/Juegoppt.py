# Importar los módulos necesarios
import random
import sys

# Crear una lista de opciones
opciones = ["Piedra", "Papel", "Tijera"]

# Asignar una opción al ordenador
eleccion_ordenador = random.choice(opciones)


# Crear una función para tomar la entrada del usuario
def entrada_usuario():
  eleccion_usuario = input("Elige Piedra, Papel o Tijera: ")
  if eleccion_usuario in opciones:
    return eleccion_usuario
  else:
    print("Entrada no válida. Inténtalo de nuevo.")
    return entrada_usuario()

# Crear una función para determinar el ganador
def ganador(eleccion_usuario, eleccion_ordenador):
  if eleccion_usuario == eleccion_ordenador:
    return "Empate"
  elif (eleccion_usuario == "Piedra" and eleccion_ordenador == "Tijera") or (eleccion_usuario == "Papel" and eleccion_ordenador == "Piedra") or (eleccion_usuario == "Tijera" and eleccion_ordenador == "Papel"):
    return "Ganas tú"
  else:
    return "Gana el ordenador"

# Crear un bucle para repetir el juego hasta que el usuario quiera salir
while True:
  # Llamar a la función de entrada del usuario
  eleccion_usuario = entrada_usuario()
  
  # Llamar a la función de ganador y mostrar el resultado
  resultado = ganador(eleccion_usuario, eleccion_ordenador)
  print(f"Tú eliges {eleccion_usuario}, el ordenador elige {eleccion_ordenador}. {resultado}.")

  # Preguntar al usuario si quiere jugar otra vez o salir
  otra_vez = input("¿Quieres jugar otra vez? (s/n): ")
  if otra_vez.lower() == "n":
    print("Gracias por jugar. Adiós.")
    sys.exit()