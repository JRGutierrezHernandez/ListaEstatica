#include <iostream>
#include <cstring>
#include <locale>

using namespace std;

const int TAM = 3;

class Empleado
{
private:
    int ClaveEmpleado;
    string Nombre;
    float Sueldo;
    string ReportaA;
    string Domicilio;

public:
    Empleado() : ClaveEmpleado(0), Nombre(""), Sueldo(0), ReportaA(""), Domicilio("") {}

    Empleado(int clave, const string &nombre, float sueldo, const string &reportaA, const string &domicilio)
        : ClaveEmpleado(clave), Nombre(nombre), Sueldo(sueldo), ReportaA(reportaA), Domicilio(domicilio) {}

    void operator=(const Empleado &x)
    {
        ClaveEmpleado = x.ClaveEmpleado;
        Nombre = x.Nombre;
        Domicilio = x.Domicilio;
        Sueldo = x.Sueldo;
        ReportaA = x.ReportaA;
    }

    bool operator==(const Empleado &x) const
    {
        return ClaveEmpleado == x.ClaveEmpleado;
    }

    friend ostream &operator<<(ostream &o, const Empleado &p)
    {
        o << "\t Clave empleado: " << p.ClaveEmpleado <<endl;
        o << "\t Nombre: " << p.Nombre <<endl;
        o << "\t Domicilio: "<< p.Domicilio <<endl;
        o << "\t Sueldo: " << p.Sueldo <<endl;
        o << "\t Reporta a: " << p.ReportaA <<endl;
        cout << "\t********************************" << endl;
        return o;
    }
};

class Lista
{
private:
    Empleado datos[TAM];
    int ult;

public:
    Lista() : ult(-1) {}

    bool vacia() const
    {
        if(ult==-1)
            return true;
        return false;

    }

    bool llena() const
    {
        if(ult==TAM-1)
            return true;
         return false;

    }

    int  inserta(const Empleado elem, int pos)
    {
        if (llena() || pos < 0 || pos > ult + 1)
        {
            cout << "\n\tError de insercion" << endl;
            return 0;
        }
        int i = ult + 1;
        while (i > pos)
        {
            datos[i] = datos[i - 1];
            i--;
        }
        datos[pos] = elem;
        ult++;
        return 1;
    }

    bool elimina(int pos)
    {
        if (vacia() || pos < 0 || pos > ult)
        {
            cout << "\n\tError de eliminación" << endl;
            return  false;
        }
        int i = pos;
        while (i < ult)
        {
            datos[i] = datos[i + 1];
            i++;
        }
        ult--;
        return true;
    }

    int ultimo() const
    {
        return ult;
    }

    int busca(const Empleado &elem) const
    {
        for (int i = 0; i <= ult; i++)
        {
            if (datos[i] == elem)
            {
                return i;
            }
        }
        return -1;
    }

    void muestra() const
    {
        if (vacia())
        {
            cout << "\n\tLa lista está vacía.\n" << endl;
        }
        else
        {
            for (int i = 0; i <= ult; i++)
            {
                cout << datos[i];
            }
        }
    }
};

int main()
{
    Lista MiLista;
    int opc;

    while(true)
    {
        setlocale(LC_ALL,"");
        cout << "\t********************[MENÚ EMPLEADO]******************\n" << endl;
        cout << "\t1. Agregar" << endl;
        cout << "\t2. Buscar" << endl;
        cout << "\t3. Eliminar" << endl;
        cout << "\t4. Insertar" << endl;
        cout << "\t5. Mostrar" << endl;
        cout << "\t6. Salir" << endl;
        cout << "\n\tElija una opción: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
        {
            int clave;
            string nombre;
            float sueldo;
            string reportaA;
            string domicilio;

            cout << "\n\tIngrese la clave del empleado: ";
            cin >> clave;

            cout << "\n\tIngrese el nombre del empleado: ";
            cin.ignore();
            getline(cin, nombre);

            cout << "\n\tIngrese el domicilio del empleado: ";
            cin.ignore();
            getline(cin, domicilio);

            cout << "\n\tIngrese el sueldo del empleado: ";
            cin >> sueldo;

            cout << "\n\tIngrese a quién reporta el empleado: ";
            cin.ignore();
            getline(cin, reportaA);

            Empleado nuevoEmpleado(clave, nombre, sueldo, reportaA, domicilio);
            if (MiLista.inserta(nuevoEmpleado, MiLista.ultimo() + 1))
            {
                cout << "\n\t¡Se agregó el empleado con éxito!.\n" << endl;
            }
            else
            {
                cout << "\n\tNo se pudo agregar el empleado porque la lista está llena." << endl;
            }
            break;
        }
        case 2:
        {
            int clave;
            cout << "\tIngrese la clave del empleado a buscar: ";
            cin >> clave;
            Empleado empleadoBuscado(clave, "", 0, "", "");
            int posicion = MiLista.busca(empleadoBuscado);
            if (posicion != -1)
            {
                cout << "\n\tEmpleado encontrado en la posición " << posicion << ".\n" << endl;
            }
            else
            {
                cout << "\n\tNo se encontró el empleado.\n" << endl;
            }
            break;
        }
        case 3:
        {
            int posicion;
            cout << "\tDame la posición del empleado a eliminar: ";
            cin >> posicion;

            if (MiLista.elimina(posicion))
            {
                cout << "\n\t¡Se eliminó el empleado con éxito!.\n" << endl;
            }
            else
            {
                cout << "\tNo se pudo eliminar el empleado porque la lista está vacía o la posición es inválida.\n" << endl;
            }
            break;
        }
        case 4:
        {
            Empleado nuevoEmpleado;
            int posicion;
            cout << "\tDame la posición donde insertar el empleado: ";
            cin >> posicion;
            if (MiLista.inserta(nuevoEmpleado, posicion))
            {
                cout << "\n\t¡Se insertó el empleado con éxito!." << endl;
            }
            else
            {
                cout << "\n\tNo se pudo insertar el empleado porque la lista está llena o la posición es inválida.\n" << endl;
            }
            break;
        }
        case 5:
        {
            cout << "\n\t***********[LISTA EMPLEADOS]*************"<<endl;
            MiLista.muestra();
            cout<<"\n\t------------------------------------------------"<<endl;
            break;
        }
        case 6:
        {
            cout << "\n\tSaliendo de la ejecución del programa.\n"<< endl;
            return 0;
            break;
        }
        default:
        {
            cout << "\n\tOpción no válida. Intentelo de nuevo.\n" << endl;
        }
        }
    }


}
