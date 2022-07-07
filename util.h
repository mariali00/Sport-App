#ifndef UTIL_H
#define UTIL_H

#include<iostream>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <fstream>
using namespace std;

class DB
{
public:
    bool DatabaseEmpty()
    {
        bool r=0;
        //creando una conexion a la base datos
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        //aqui se le dice la direccion de la base de datos a crear o cargar
        db.setDatabaseName("data.db");
        QSqlQuery query;
        if(db.open())
        {
            if(query.exec("select grupo.nombrecarrera from grupo"))
            {
                r = !query.next();
            }
            else
            {
                qDebug() << query.lastError();
            }

        }
        else
        {
            qDebug() << query.lastError();
        }
        db.close();
        return r;
    }

    bool createDB()
    {
        bool r=1;
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        //aqui se le dice la direccion de la base de datos a crear o cargar
        db.setDatabaseName("data.db");
        QSqlQuery query;
        if(db.open())
        {
            //creando tablas de la base de datos si no estan definidas
            if(!(query.exec("create table if not exists estudiante("
                            "idestudiante integer primary key autoincrement,"
                            "nombre text,"
                            "sexo text,"
                            "edad integer,"
                            "peso real,"
                            "altura real,"
                            "presion real,"
                            "cintura real"


                            ");") && query.exec("create table if not exists grupo("
                                                "idgrupo integer primary key autoincrement, "
                                                "nombregrupo text,"
                                                "idcarrera integer,"
                                                "curso text,"
                                                "asignatura text,"
                                                "anno text);")
                                    && query.exec("create table if not exists carrera("
                                                 "idcarrera integer primary key autoincrement,"
                                                  "nombre text"
                                                  ");")
                                     && query.exec("create table if not exists grupo_tiene_estudiante("
                                                   "idgrupo integer key,"
                                                   "idestudiante integer key"
                                                    ");")
                                     && query.exec("create table if not exists capacidad_fisica("
                                                   "idCF integer primary key autoincrement,"
                                                    "nombre text "
                                                    ");")
                                     && query.exec("create table if not exists estudiante_tiene_cf("
                                                   "idCF integer key,"
                                                    "idestudiante integer key, "
                                                    "valor real,"
                                                    "periodo text"
                                                    ");")
                 ))
            {
                //caso de que no se puedan crear las tablas se finaliza la ejecucion del programa
                qDebug() << query.lastError();
                r=0;
            }
        }
        else
        {
            qDebug() << query.lastError();
            r=0;
        }
        //insertar en tabla capacidad fisica
        if(!query.exec("insert into capacidad_fisica(nombre) values('flexibilidad');"))
        {
            qDebug()<<query.lastError();
        }
        if(!query.exec("insert into capacidad_fisica(nombre) values('plancha');"))
        {
            qDebug()<<query.lastError();
        }
        if(!query.exec("insert into capacidad_fisica(nombre) values('abdominales');"))
        {
            qDebug()<<query.lastError();
        }
        if(!query.exec("insert into capacidad_fisica(nombre) values('salto');"))
        {
            qDebug()<<query.lastError();
        }
        if(!query.exec("insert into capacidad_fisica(nombre) values('velocidad');"))
        {
            qDebug()<<query.lastError();
        }
        if(!query.exec("insert into capacidad_fisica(nombre) values('resistencia');"))
        {
            qDebug()<<query.lastError();
        }

        db.close();

        return r;


    }


    bool EmptyProfile()
    {
        ifstream fin("wet.txt");
        return fin ? 0 : 1;
    }

};

class Eval
{
public:
    pair<double,double> ValoresReferencia[9][9] = {
        {make_pair(6.7,7.3),make_pair(6.7,7.3),make_pair(7.5,8.2),make_pair(7.3,7.7),make_pair(8.2,8.7),make_pair(7.7,8.4),make_pair(8.7,9.2),make_pair(8.4,8.4),make_pair(9.2,9.2)},
        {make_pair(6.7,7.3),make_pair(6.7,7.3),make_pair(7.5,8.2),make_pair(7.3,7.7),make_pair(8.2,8.7),make_pair(7.7,8.4),make_pair(8.7,9.2),make_pair(8.4,8.4),make_pair(9.2,9.2)},
        {make_pair(6.7,7.3),make_pair(7.2,7.8),make_pair(8.4,9.2),make_pair(7.8,8.3),make_pair(9.2,9.7),make_pair(8.3,9.1),make_pair(9.7,10.3),make_pair(9.1,9.1),make_pair(10.3,10.3)},
        {make_pair(6.7,7.3),make_pair(7.9,8.6),make_pair(8.9,9.7),make_pair(8.6,9.1),make_pair(9.7,10.3),make_pair(9.1,9.9),make_pair(10.3,10.9),make_pair(9.9,9.9),make_pair(10.9,10.9)},
        {make_pair(6.7,7.3),make_pair(7.0,7.6),make_pair(7.8,8.5),make_pair(7.6,8.1),make_pair(8.5,9.0),make_pair(8.1,8.8),make_pair(9.0,9.6),make_pair(8.8,8.8),make_pair(9.6,9.6)},
        {make_pair(6.7,7.3),make_pair(7.5,8.8),make_pair(8.8,9.8),make_pair(8.8,10.1),make_pair(9.8,11.8),make_pair(10.1,10.6),make_pair(11.8,12.8),make_pair(10.6,10.6),make_pair(12.8,12.8)},
        {make_pair(6.7,7.3),make_pair(7.5,8.8),make_pair(8.8,9.9),make_pair(8.8,10.0),make_pair(9.9,12.3),make_pair(10.0,10.6),make_pair(12.3,13.8),make_pair(10.6,10.6),make_pair(13.8,13.8)},
        {make_pair(6.7,7.3),make_pair(7.5,8.8),make_pair(8.8,10.3),make_pair(8.8,10.0),make_pair(10.3,11.0),make_pair(10.0,11.0),make_pair(11.0,13.8),make_pair(11.0,11.0),make_pair(13.8,13.8)},
        {make_pair(6.7,7.3),make_pair(7.7,8.9),make_pair(8.9,10.8),make_pair(8.9,10.3),make_pair(10.8,12.7),make_pair(10.3,11.0),make_pair(12.7,13.9),make_pair(11.0,11.0),make_pair(13.9,13.9)}
    };

    int presionArterial[4][2] = {{120, 80},
                                 {140, 90},
                                 {160, 100},
                                 {180, 110}
                                };

    string presionArt(QString presion)
    {
        string a = presion.toStdString();
        string sistolica = a.substr(0, a.find('/'));
        string diastolica = a.substr(a.find('/') + 1, a.size()-1);

        int sistolicaInt = atoi( sistolica.c_str() );
        int diastolicaInt = atoi( diastolica.c_str() );

        int ret = 0;
        // Normal
        if(sistolicaInt < 120)
        {
            ret = 1;
        }
        else
        {
            // Prehipertension
            if(sistolicaInt >= 120 && sistolicaInt <=139)
            {
                ret = 2;
            }
            // Grado I
            if(sistolicaInt >= 140 && sistolicaInt <=159)
            {
                ret = 3;
            }
            // Grado II
            if(sistolicaInt >= 160 && sistolicaInt <=179)
            {
                ret = 4;
            }
            // Grado III
            if(sistolicaInt >= 180)
            {
                ret = 5;
            }
        }

        // Normal
        if(diastolicaInt < 80 && ret < 1)
        {
            ret = 1;
        }
        else
        {
            // Prehipertension
            if(diastolicaInt >= 80 && diastolicaInt <=89 && ret < 2)
            {
                ret = 2;
            }
            // Grado I
            if(diastolicaInt >= 90 && diastolicaInt <=99 && ret < 3)
            {
                 ret = 3;
            }
            // Grado II
            if(diastolicaInt >= 100 && diastolicaInt <=109 && ret < 4)
            {
                ret = 4;
            }
            // Grado III
            if(diastolicaInt >= 110 && ret < 5)
            {
                ret = 5;
            }
        }
        string stringRet = "";
        switch (ret) {
        case 1:
                stringRet = "normal";
            break;
        case 2:
                stringRet = "pre";
            break;
        case 3:
                stringRet = "I";
            break;
        case 4:
                stringRet = "II";
            break;
        case 5:
                stringRet = "III";
            break;
        default:
            break;
        }

        return stringRet;
    }

    double IMC(double peso, double altura)
    {
        return peso/(altura*altura);
    }

    string eval_IMC(double imc, string sexo, int edad)
    {
        if(edad==17)
        {
            if(sexo=="F" || sexo=="f")
            {
                if (imc<=17.8)
                {
                    return "Bajo Peso";
                }
                if (imc<=25.2 && imc>=17.8)
                {
                    return "Normal";
                }
                if (imc >29.6)
                    return "Sobrepeso";
                return "Obesidad";
            }

            if(sexo=="M" || sexo=="m")
            {
                if (imc <=18.3)
                {
                    return "Bajo Peso";
                }
                if (imc<=24.9 && imc>=18.3)
                {
                    return "Normal";
                }
                if (imc >28.2)
                    return "Sobrepeso";
                return "Obesidad";
            }
        }
        if(edad>=18)
        {
            if(sexo=="F" || sexo=="f")
            {
                if (imc<=18.2)
                {
                    return "Bajo Peso";
                }
                if (imc<=25.6 && imc>=18.2)
                {
                    return "Normal";
                }
                if (imc >30.3)
                    return "Sobrepeso";
                return "Obesidad";
            }

            if(sexo=="M" || sexo=="m")
            {
                if (imc<=18.9)
                {
                    return "Bajo Peso";
                }
                if (imc<=25.6 && imc>=18.9)
                {
                    return "Normal";
                }
                if (imc >29.0)
                    return "Sobrepeso";
                return "Obesidad";
            }
        }
        return "retorno de funcion no valido";
    }

    QString RCE(double perimetro_cintura, double estatura )
    {
        double r=perimetro_cintura/(estatura*100);

        if (r>=0.55)
        {
            return "Necesita mejorar";
        }
        return "Aceptable";
    }

    QString fuerza_piernas(double salto, string sexo)
    {
        if(sexo=="f" || sexo=="F")
        {
            if(salto<=142)
                return "Necesita mejorar";
            if (salto<=151)
                return "Aceptable";
            return "Destacado";
        }

           if(sexo=="m" || sexo=="M")
        {
            if(salto<=187)
                return "Necesita mejorar";
            if (salto<=196)
                return "Aceptable";
            return "Destacado";
        }
        return "retorno de funcion no valido";
    }


    string fuerza_abdominal(int ctdad_abdominales, string sexo)
    {
        if(sexo=="f" || sexo=="F")
        {
            if(ctdad_abdominales<=28)
                return "Necesita mejorar";
            if (ctdad_abdominales<=32)
                return "Aceptable";
            return "Destacado";
        }

           if(sexo=="m" || sexo=="M")
        {
            if(ctdad_abdominales<=34)
                return "Necesita mejorar";
            if (ctdad_abdominales<=38)
                return "Aceptable";
            return "Destacado";
        }
        return "retorno de funcion no valido";
    }


    string fuerza_brazo(int salto, string sexo)
    {
        if(sexo=="f" || sexo=="F")
        {
            if(salto<=16)
                return "Necesita mejorar";
            if (salto<=19)
                return "Aceptable";
            return "Destacado";
        }

           if(sexo=="m" || sexo=="M")
        {
            if(salto<=19)
                return "Necesita mejorar";
            if (salto<=23)
                return "Aceptable";
            return "Destacado";
        }
        return "retorno de funcion no valido";
    }

    int CategoriaVelocidad(QString e, QString s, QString v)
    {
        int edad = e.toInt();
        int sexo;
        (s == "f" || s == "F")? sexo = 0 : sexo = 1;
        double velocidad = v.toDouble();
        int ret;

        edad-=16;
        if(velocidad < ValoresReferencia[edad][1].first && sexo) return 1;
        if(!sexo && velocidad < ValoresReferencia[edad][2].first) return 1;
        if(velocidad > ValoresReferencia[edad][8].second && sexo) return 4;
        if(!sexo && velocidad > ValoresReferencia[edad][2].second) return 4;
        for(int i=1; i <=8; i++)
        {
            if(ValoresReferencia[edad][i].first <= velocidad && ValoresReferencia[edad][i].second > velocidad && i%2 == sexo)
            {
                ret = i;
                break;
            }
        }

        switch(ret)
        {
        case 1: ret = 1;
            break;
        case 2: ret = 1;
            break;
        case 3: ret = 2;
            break;
        case 4: ret = 2;
            break;
        case 5: ret = 3;
            break;
        case 6: ret = 3;
            break;
        case 7: ret = 4;
            break;
        case 8: ret = 4;
            break;
        }

        return ret;
    }

    QString resistencia(string sexo,double dist)
    {
        if(sexo=="f" || sexo=="F")
        {
            if(dist<=1630)
                return "Necesita mejorar";
            if(dist<=1849)
                return "Aceptable";
            return "Destacado";
        }
        if(sexo=="m" || sexo=="M")
            {
            if(dist<1610)
                return "Necesita mejorar";
            if(dist<=2008)
                return "Aceptable";
            return "Destacado";
        }
        return "retorno de funcion no valido";
    }


    QString flexibilidad(double salto, string sexo)
    {
        if(sexo=="f" || sexo=="F")
        {
            if(salto<=32)
                return "Necesita mejorar";
            if (salto<=35)
                return "Aceptable";
            return "Destacado";
        }

           if(sexo=="m" || sexo=="M")
        {
            if(salto<=37)
                return "Necesita mejorar";
            if (salto<=41)
                return "Aceptable";
            return "Destacado";
        }
           return "retorno de funcion no valido";
    }

};


#endif //UTIL_H
