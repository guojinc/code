import pymysql
class SQL:
    def __init__(self):
        self.create_db_and_table()

    def delete_db(self):
        connection = pymysql.connect(
            host='localhost',
            user='root',
            password='g1963307454',
            charset='utf8',
        )
        try:
            with connection.cursor() as cursor:
                cursor.execute('DROP DATABASE IF EXISTS INFO_SYS')
            connection.commit()
        finally:
            connection.close()

    def create_db_and_table(self):
        connection = pymysql.connect(
            host='localhost',
            user='root',
            password='g1963307454',
            charset='utf8',
        )
        try:
            with connection.cursor() as cursor:
                cursor.execute('CREATE DATABASE IF NOT EXISTS INFO_SYS')
                cursor.execute('USE INFO_SYS')
                cursor.execute('CREATE TABLE IF NOT EXISTS student(\
                    NUMBER INT PRIMARY KEY,\
                    ID INT,\
                    name VARCHAR(20),\
                    age INT,\
                    class VARCHAR(20),\
                    department VARCHAR(20)\
                )')
            connection.commit()
        finally:
            connection.close()

    def get_connection(self):
        return pymysql.connect(
            host='localhost',
            user='root',
            password='g1963307454',
            database='INFO_SYS',
            charset='utf8'
        )

    def create(self, mes : dict):
        operation = 'INSERT INTO student(ID, name, age, class, department) VALUES(%d, "%s", %d, "%s", "%s")'%(
            mes['ID'], mes['name'], mes['age'], mes['class'], mes['department']
        )
        connection = self.get_connection()
        try:
            with connection.cursor() as cursor:
                cursor.execute(operation)
            connection.commit()
        finally:
            connection.close()
    
    def read(self, ID : int):
        connection = self.get_connection()
        operation = 'SELECT * FROM student WHERE ID = %d'%ID
        try:
            with connection.cursor() as cursor:
                cursor.execute(operation)
                result = cursor.fetchone()
        finally:
            connection.close()
            return result
    
    def update(self, id : int, mes : dict):
        set_str = ''
        for key in mes:
            if isinstance(key, str):
                set_str += key + '="' + str(mes[key]) + '",'
                continue
            set_str += key + '=' + str(mes[key]) + ','
        
        operation = 'UPDATE student SET %s WHERE ID = %d'%(set_str[:-1], id)
        connection = self.get_connection()
        try:
            with connection.cursor() as cursor:
                cursor.execute(operation)
                connection.commit()
        finally:
            connection.close()

    def delete(self, id : int):
        operation = 'DELETE FROM student WHERE ID = %d'%id
        connection = self.get_connection()
        try:
            with connection.cursor() as cursor:
                cursor.execute(operation)
                connection.commit()
                return cursor.rowcount > 0
        finally:
            connection.close()

    def find_all(self):
        connection = self.get_connection()
        operation = 'SELECT * FROM student'
        try:
            with connection.cursor() as cursor:
                cursor.execute(operation)
                result = cursor.fetchall()
        finally:
            connection.close()
            return result