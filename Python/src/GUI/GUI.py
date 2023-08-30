import tkinter as tk
import serial

# Create the GUI
root = tk.Tk()

# Create the buttons
button_connect = tk.Button(root, text="Connect", command=connect)
button_send = tk.Button(root, text="Send", command=send)
button_disconnect = tk.Button(root, text="Disconnect", command=disconnect)

# Create the plot
canvas = tk.Canvas(root, width=500, height=200)
line = canvas.create_line(0, 0, 0, 200, fill="blue")

# Add the buttons and plot to the GUI
button_connect.pack()
button_send.pack()
button_disconnect.pack()
canvas.pack()

# Create a serial connection
ser = serial.Serial("COM3", 9600)

# Start the GUI
root.mainloop()

# Define the connect function
def connect():
    global ser
    ser.open()

# Define the send function
def send(data):
    ser.write(data.encode())

# Define the disconnect function
def disconnect():
    ser.close()

# Define the serial event handler
def serial_event(event):
    data = ser.readline().decode()
    canvas.coords(line, 0, 0, len(data), 200)

# Add the serial event handler
ser.add_event_listener(serial_event)