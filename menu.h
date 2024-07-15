void menu();

void menu()
{
    int opcion;
    string jugador1, jugador2;
    string vNombres[5]{};
    int vPuntos[5]{};
    int nuevoPuntajeGanador;
    string nuevoNombreGanador;

    system("cls");

    while (true)
    {
        system("cls");

        dibujarLinea();
        cout << "1 - Modo 1 Jugador" << endl;
        cout << "2 - Modo 2 Jugadores" << endl;
        cout << "3 - Mostrar Ranking de Puntos" << endl;
        cout << "4 - Mostrar Reglas" << endl;
        dibujarLinea();
        cout << "5 - Modo manual" << endl;
        dibujarLinea();
        cout << "0 - Salir" << endl;
        dibujarLinea();
        cout << "Opcion: ";
        cin >> opcion;

        system("cls");

        switch (opcion)
        {
        case 1:
        {
            {
                string nombreP1 = cargarNombres();
                juego(1, nuevoPuntajeGanador, nuevoNombreGanador, nombreP1);
                cargarPuntaje(vNombres, vPuntos, nuevoPuntajeGanador, nuevoNombreGanador);

                mostrarPausa();
                break;
            }
        }
        case 2:
        {
            string nombreP1 = cargarNombres();

            cout << "Ahora el segundo jugador" << endl;
            string nombreP2 = cargarNombres(2);

            juego(2, nuevoPuntajeGanador, nuevoNombreGanador, nombreP1, nombreP2);
            cargarPuntaje(vNombres, vPuntos, nuevoPuntajeGanador, nuevoNombreGanador);

            mostrarPausa();
            break;
        }
        case 3:
            dibujarRanking(vNombres, vPuntos);
            mostrarPausa();
            break;
        case 4:
            mostrarReglas();
            mostrarPausa();
            break;
        case 5:
        {

            int cantidadJugadores;
            cout << "Indique la cantidad de jugadores (1 o 2):";
            cin >> cantidadJugadores;
            string nombreP1 = cargarNombres();
            string nombreP2;
            if (cantidadJugadores == 2)
            {
                cout << "Ahora el segundo jugador" << endl;
                nombreP2 = cargarNombres(2);
            }
            juego(cantidadJugadores, nuevoPuntajeGanador, nuevoNombreGanador, nombreP1, nombreP2, "test");
            cargarPuntaje(vNombres, vPuntos, nuevoPuntajeGanador, nuevoNombreGanador);

            mostrarPausa();
        }
        break;
        case 0:
            cout << "LA APLICACION HA FINALIZADO" << endl;
            mostrarPausa();
            return;
            break;
        default:
            cout << "La opcion ingresada no es valida, intente de nuevo" << endl;
            mostrarPausa();

            break;
        }
    }
}