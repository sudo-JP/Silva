CREATE TABLE IF NOT EXISTS microcontroller (
    mid SERIAL NOT NULL,
    name VARCHAR NOT NULL, 
    model VARCHAR NOT NULL, 

    PRIMARY KEY(mid)
);

CREATE TABLE IF NOT EXISTS collect_data (
    mid INT NOT NULL, 

    temperature FLOAT, 
    humidity FLOAT, 
    water_level INT, 
    soil_moisture INT,

    time TIMESTAMPTZ NOT NULL DEFAULT CURRENT_TIMESTAMP, 
    PRIMARY KEY(mid, time), 
    FOREIGN KEY(mid) REFERENCES microcontroller(mid),
);
