-- Created by Vertabelo (http://vertabelo.com)
-- Last modification date: 2019-02-27 04:03:47.127

-- tables
-- Table: Codigo
CREATE TABLE Codigo (
    codigo varchar(16) NOT NULL,
    activo bool NOT NULL,
    CONSTRAINT Codigo_pk PRIMARY KEY (codigo)
);

-- Table: Debris
CREATE TABLE Debris (
    id int NOT NULL,
    nombre varchar(50) NOT NULL,
    capacidad double NOT NULL,
    peso_pet double NOT NULL,
    peso_organic double NOT NULL,
    peso_papel double NOT NULL,
    peso_vidrio double NOT NULL,
    cant_pet int NOT NULL,
    cant_organic int NOT NULL,
    cant_papel int NOT NULL,
    cant_vidrio int NOT NULL,
    Codigo_codigo varchar(16) NOT NULL,
    CONSTRAINT Debris_pk PRIMARY KEY (id)
);

-- Table: Reporte
CREATE TABLE Reporte (
    id int NOT NULL,
    date date NOT NULL,
    peso_pet double NULL,
    peso_organic double NULL,
    peso_papel double NULL,
    peso_vidrio double NULL,
    cant_pet int NULL,
    cant_organic int NULL,
    cant_papel int NULL,
    cant_vidrio int NULL,
    Debris_id int NOT NULL,
    CONSTRAINT Reporte_pk PRIMARY KEY (id)
);

-- foreign keys
-- Reference: Debris_Codigo (table: Debris)
ALTER TABLE Debris ADD CONSTRAINT Debris_Codigo FOREIGN KEY Debris_Codigo (Codigo_codigo)
    REFERENCES Codigo (codigo);

-- Reference: Reporte_Debris (table: Reporte)
ALTER TABLE Reporte ADD CONSTRAINT Reporte_Debris FOREIGN KEY Reporte_Debris (Debris_id)
    REFERENCES Debris (id);

-- End of file.

