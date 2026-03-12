from dotenv import load_dotenv
import os 

class Env: 
    def __init__(self) -> None:
        load_dotenv() 

        self._DB_USER = os.getenv('DB_USER')
        self._DB_PASSWORD = os.getenv('DB_PASSWORD')
        self._DB_NAME = os.getenv('DB_NAME')
        self._DB_PORT = os.getenv('DB_PORT')
        self._DB_HOST = os.getenv('DB_HOST')

    def get_db_env(self) -> dict: 
        return {
            'host': self._DB_HOST,
            'port': self._DB_PORT, 
            'database': self._DB_NAME, 
            'user': self._DB_USER,
            'password': self._DB_PASSWORD
        }

