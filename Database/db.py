import psycopg2
import datetime
###########
def insertreporte(data): #Inserta un nuevo reporte en la base de datos
    try:
        connection = psycopg2.connect(user = "leonvillapun",
                                      password = "00_lui_lv",
                                      host = "127.0.0.1",
                                      port = "5432",
                                      database = "debris")
        cursor = connection.cursor()
        cursor.execute("INSERT INTO reporte (date, peso_pet, peso_organic, peso_papel, peso_vidrio, cant_pet, cant_organic, cant_papel, cant_vidrio, debris_id) VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s)",
                        data)
        connection.commit()
    except (Exception, psycopg2.Error) as error :
        print ("Error while connecting to PostgreSQL", error)
    finally:
        #closing database connection.
            if(connection):
                cursor.close()
                connection.close()
                print("PostgreSQL connection is closed")
###########

###########
def insertdebris(data): #Inserta un nuevo reporte en la base de datos
    try:
        connection = psycopg2.connect(user = "leonvillapun",
                                      password = "00_lui_lv",
                                      host = "127.0.0.1",
                                      port = "5432",
                                      database = "debris")
        cursor = connection.cursor()
        cursor.execute("INSERT INTO debris (nombre, capacidad, codigo) VALUES (%s, %s, %s)",
                        data)
        connection.commit()
    except (Exception, psycopg2.Error) as error :
        print ("Error while connecting to PostgreSQL", error)
    finally:
        #closing database connection.
            if(connection):
                cursor.close()
                connection.close()
                print("PostgreSQL connection is closed")
###########



datos = (datetime.date.today(), 3.0, 4.5, 0.6, 0.8, 3, 4, 5, 2, 1)
insertreporte(datos)
