-- Created by Vertabelo (http://vertabelo.com)
-- Last modification date: 2019-04-16 02:51:24.174

-- tables
-- Table: Debris
CREATE TABLE Debris (
    id SERIAL NOT NULL,
    nombre varchar(50)  NOT NULL,
    capacidad decimal  NOT NULL,
    peso_pet decimal  NOT NULL,
    peso_organic decimal  NOT NULL,
    peso_papel decimal  NOT NULL,
    peso_vidrio decimal  NOT NULL,
    cant_pet int  NOT NULL,
    cant_organic int  NOT NULL,
    cant_papel int  NOT NULL,
    cant_vidrio int  NOT NULL,
    codigo varchar(16)  NOT NULL,
    CONSTRAINT Debris_pk PRIMARY KEY (id)
);

-- Table: Reporte
CREATE TABLE Reporte (
    id SERIAL NOT NULL,
    date date  NOT NULL,
    peso_pet decimal  NULL,
    peso_organic decimal  NULL,
    peso_papel decimal  NULL,
    peso_vidrio decimal  NULL,
    cant_pet int  NULL,
    cant_organic int  NULL,
    cant_papel int  NULL,
    cant_vidrio int  NULL,
    Debris_id int  NOT NULL,
    CONSTRAINT Reporte_pk PRIMARY KEY (id)
);

-- foreign keys
-- Reference: Reporte_Debris (table: Reporte)
ALTER TABLE Reporte ADD CONSTRAINT Reporte_Debris
    FOREIGN KEY (Debris_id)
    REFERENCES Debris (id)
    NOT DEFERRABLE
    INITIALLY IMMEDIATE
;

-- End of file.
