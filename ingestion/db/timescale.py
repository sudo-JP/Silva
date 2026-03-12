import psycopg2

from db.env import Env

class TimescaleDB:
    _instance = None 
    _initialized = False

    def __new__(cls, *args, **kwargs):
        if cls._instance is None:
            cls._instance = super(TimescaleDB, cls).__new__(cls)
        return cls._instance

    def __init__(self) -> None:
        if not self._initialized:
            self._initialized = True 
            try:
                environment = Env().get_db_env()
                self.conn = psycopg2.connect(**environment)
                print('Connected to TimescaleDB')

                self.cursor = self.conn.cursor()
            except (Exception, psycopg2.Error) as error: 
                print(f'Error connecting to DB {error}')
            finally: 
                if self.conn is not None:
                    self.conn.close()
                    print('Close connection to TimescaleDB')

        
    def save_to_db(self, a): 
        pass

    def close(self): 
        self.cursor.close()
        self.conn.close()
