import serial
import time 

"""
ser = serial.Serial(
    port='/dev/ttyUSB0',
    baudrate=115_200,
    timeout=1
)

try: 
    if ser.is_open: 
        print(f'Serial port {ser.port} opened successfully')
        while True: 
            line = ser.read()
            if line: 
                print(f'Received: {line}')
            
            time.sleep(0.1)
except Exception as _: 
    print("Error")
finally: 
    if ser.is_open:
        ser.close()
        print('close')"""
