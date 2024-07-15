
// carga nombres del jugado/es
string cargarNombres(int jugador = 1);
// muestra los nombres
void mostrarNombres(string nameplayer);
// muestra las reflas del juego
void mostrarReglas();
// muestra la cantidad de rondas
void mostrarRondas(int cantRondas);
// separa con un |
void separador();
// salta una linea de codigo
void saltarLinea();
// hace una linea
void hacerLinea();
// muestra los puntos del jugador
void mostrarPuntos(int puntaje);
// muestra el maximo puntaje de la ronda
void maximoPuntaje(int MP);
// muestra el numero de lanzamiento
void mostrarTiro(int LAN);
// muestra el cartel
void mostrarCartel(string nombre1, int R, int L, int P, int vec[], int tam, int MX, int jugada, int puntajeTirada = 0);
// muestra cartel antes del turno
void entreTurnos(int R, string name, string name2, int puntosP1, int puntosP2, int turnoActual, int cantidadJugadores);

string cargarNombres(int jugador)
{
    string name;
    cout << "Ingresar nombre: ";
    if (jugador != 2)
    {
        cin.ignore();
    }
    getline(cin, name);

    return name;
}

void mostrarNombres(string nameplayer)
{
    cout << nameplayer;
    return;
}

void mostrarReglas()
{
    system("cls");
    cout << "REGLAMENTO DEL JUEGO" << endl;
    cout << "El objetivo del juego es obtener al menos 100 puntos en la menor cantidad posible de  rondas, o sacar una escalera en un lanzamiento." << endl;
    cout << "Una ronda esta compuesta por 3 lanzamientos. Un lanzamiento consiste en tirar seis dados y evaluar sus valores para determinar el puntaje." << endl;
    cout << endl;

    return;
}

void mostrarRondas(int cantRondas)
{
    cout << "RONDA NRO: " << cantRondas;
    return;
}

void separador()
{
    cout << "  |  ";
    return;
}

void saltarLinea()
{
    cout << endl;
}

void mostrarPuntos(int puntaje)
{
    cout << puntaje << endl;
}

void hacerLinea()
{
    cout << "______________________________________________________" << endl;
}

void maximoPuntaje(int MP)
{
    cout << "MAXIMO PUNTAJE DE LA RONDA: " << MP << endl;
}

void mostrarTiro(int LAN)
{
    cout << "LANZAMIENTO NUMERO: " << LAN << endl;
}

void mostrarCartel(string nombre1, int R, int L, int P, int vec[], int tam, int MX, int jugada, int puntajeTirada)
{
    system("cls");
    cout << "TURNO DE: ";
    mostrarNombres(nombre1);
    separador();
    mostrarRondas(R);
    separador();
    cout << "PUNTAJE TOTAL: ";
    mostrarPuntos(P);
    hacerLinea();
    saltarLinea();
    maximoPuntaje(MX);
    mostrarTiro(L);
    hacerLinea();
    saltarLinea();

    // funcion mostrar vector
    mostrarVector(vec, tam);
    saltarLinea();
    saltarLinea();

    // Cartel jugada
    switch (jugada)
    {
    // valores de jugada
    //  1 = SUMA DE DADOS
    //  2 = SEXTETO X
    //  3 = ESCALERA
    //  4 = SEXTETO 6
    case 1:
        // SUMA DE DADOS
        cout << "SUMA DE DADOS! " << puntajeTirada << " Puntos!" << endl;
        break;
    case 2:
        // SEXTETO X
        cout << "SEXTETO DE " << puntajeTirada / 10 << "! " << puntajeTirada << " Puntos!" << endl;
        break;
    case 3:
        // ESCALERA
        cout << "ESCALERA! GANASTE!" << endl;
        break;
    case 4:
        // SEXTETO 6 / RESET
        cout << "SEXTETO DE 6 TUS PUNTOS VOLVIERON A 0!" << endl;
        break;
    }
}

void entreTurnos(int R, string name, string name2, int puntosP1, int puntosP2, int turnoActual, int cantidadJugadores)
{

    string vNombres[2]{name, name2};

    int indiceProximoTurno;

    if (turnoActual == 1 && cantidadJugadores == 2)
        indiceProximoTurno = 1;
    else
        indiceProximoTurno = 0;

    system("cls");
    mostrarRondas(R);
    saltarLinea();
    cout << "PROXIMO TURNO: ";
    mostrarNombres(vNombres[indiceProximoTurno]);
    saltarLinea();
    hacerLinea();
    saltarLinea();
    cout << "PUNTAJE " << vNombres[0] << ": ";
    mostrarPuntos(puntosP1);

    if (cantidadJugadores == 2)
    {
        saltarLinea();
        cout << "PUNTAJE " << vNombres[1] << ": ";
        mostrarPuntos(puntosP2);
    }

    mostrarPausa();
}
