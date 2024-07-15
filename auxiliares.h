
// prototipo funciones
void dibujarLinea();
int verificarSexteto(int v[], int tam);
void ordenarRanking(string vNombres[], int vPuntos[]);
void mostrarPausa();
void cargarPuntaje(string vNombres[], int vPuntos[], int nuevoPuntaje, string nuevoNombre);
void cargarGanador(int &puntajeGanador, string &nombreGanador, int valorPuntaje, string valorNombre);
void dibujarGanador(string nombre, int cantidadRondas);

// cuerpo funciones
void dibujarLinea()
{
    cout << "-----------------------------" << endl;
    return;
}

int verificarSexteto(int v[], int tam)
{

    for (int i = 1; i <= 6; i++)
    {

        int cant = contarNumerosRepetidos(v, i, tam);
        if (cant == tam)
            return (i * 10);
    }

    return 0;
}

bool verificarEscalera(int v[], int tam)
{

    for (int i = 0; i < tam - 1; i++)
    {
        if (v[i + 1] != v[i] + 1)
        {
            return false;
        }
    }

    return true;
}

int compararMayor(int n1, int n2)
{
    int mayor;

    if (n1 > n2)
        mayor = n1;
    else
        mayor = n2;
    return mayor;
}

void ordenarRanking(string vNombres[], int vPuntos[])
{

    int puntosActual;
    string nombreActual;

    for (int i = 1; i < 5; i++)
    {

        for (int j = 0; j < 4; j++)
        {

            if (vPuntos[j] < vPuntos[j + 1])
            {
                puntosActual = vPuntos[j];
                nombreActual = vNombres[j];
                vPuntos[j] = vPuntos[j + 1];
                vNombres[j] = vNombres[j + 1];
                vPuntos[j + 1] = puntosActual;
                vNombres[j + 1] = nombreActual;
            }
        }
    }

    return;
}

void mostrarPausa()
{
    cout << endl
         << "Presione cualquier tecla para continuar";
    system("pause>null");
    return;
}

void cargarPuntaje(string vNombres[], int vPuntos[], int nuevoPuntaje, string nuevoNombre)
{
    if (nuevoPuntaje > vPuntos[4])
    {
        vPuntos[4] = nuevoPuntaje;
        vNombres[4] = nuevoNombre;
    }

    ordenarRanking(vNombres, vPuntos);

    return;
}

void cargarGanador(int &puntajeGanador, string &nombreGanador, int valorPuntaje, string valorNombre)
{
    puntajeGanador = valorPuntaje;
    nombreGanador = valorNombre;

    return;
}

void dibujarGanador(string nombre, int cantidadRondas)
{
    cout << "--------------------FELICITACIONES-------------------------" << endl;
    cout << "                  EL GANADOR ES: " << nombre << endl;
    cout << "                  En " << cantidadRondas << " Ronda/s jugadas!" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "                  GRACIAS POR JUGAR!" << endl;
    cout << "-----------------------------------------------------------" << endl;
}