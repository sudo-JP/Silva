import struct
from typing import Optional 
import serial
import time
from db.timescale import TimescaleDB 

from dataclasses import dataclass
from fastcrc import crc16

@dataclass
class Payload:
    magic: int 
    temperature: int 
    humid: int 
    water_level: int 
    soil_moisture: int 
    checksum: int


"""// 12 Bytes 
struct __attribute__((packed)) Payload {
    uint16_t magic; 
    int16_t temperature; 
    int16_t humid; 
    int16_t water_level; 
    int16_t soil_moisture;
    uint16_t checksum; 
};"""

class ArduinoDecoder: 
    db: TimescaleDB
    ser: serial.Serial

    # SETUP 
    BAUDRATE = 115_200
    PORT= '/dev/ttyUSB0'
    FMT_STR = '<HhhhhH'
    STRUCT_SIZE = struct.calcsize(FMT_STR)

    MAGIC = 0xBEEF 

    def __init__(self, db: TimescaleDB) -> None:
        self.db = db  
        self.ser = serial.Serial(
            port=ArduinoDecoder.PORT,
            baudrate=ArduinoDecoder.BAUDRATE, 
            timeout=1
        )

    def read_data(self) -> Optional[Payload]:
        if self.ser.in_waiting >= ArduinoDecoder.STRUCT_SIZE: 
            raw = self.ser.read(ArduinoDecoder.STRUCT_SIZE)
            try: 
                data_tuple = struct.unpack(ArduinoDecoder.FMT_STR, raw)
                magic, temperature, humid, water, soil, checksum = data_tuple
                payload = Payload(magic, temperature, humid, water, soil, checksum)
                return self.validate_data(payload)
            except struct.error as e:
                print(f"Struct unpacking error: {e}")
                self.ser.reset_input_buffer()
        return None

    """
    Return the payload if data is correct, otherwise None
    """
    def validate_data(self, payload: Payload) -> Optional[Payload]: 
        pass

    def save_to_db(self, data: tuple) -> None: 
        pass

    """
    This function does not return 
    """
    def run(self) -> None: 
        try: 
            if self.ser.is_open: 
                print(f'Serial port {self.ser.port} opened successfully')
                while True: 
                    data = self.read_data() 

                    time.sleep(0.1)
        except Exception as e: 
            print(f"Arduino Error: {e}")
        finally: 
            if self.ser.is_open:
                self.ser.close()
                print('close')
