int jugarRonda(string nombreJugador, int ronda, int puntajeActual, string mode = "default");

int jugarRonda(string nombreJugador, int ronda, int puntajeActual, string mode)
{
    const int PUNTAJE_MAX = 100;
    const int TAM = 6;
    const int VALOR_RESET = 60;
    const int CANTIDAD_LANZAMIENTOS = 3;

    int lanzamiento;
    int dados[6]{0};
    int suma = 0;
    int sexteto;
    int puntaje = 0;
    bool esEscalera = false;

    // valores de jugada
    //  1 = SUMA DE DADOS
    //  2 = SEXTETO X
    //  3 = ESCALERA
    //  4 = SEXTETO 6
    int jugada;

    int puntajeTirada;

    for (lanzamiento = 1; lanzamiento <= CANTIDAD_LANZAMIENTOS; lanzamiento++)
    {
        system("cls");

        // carga de dados
        if (mode == "test")
        {
            cargarVector(dados, TAM);
        }
        else
        {
            cargarAleatorio(dados, TAM, 6);
        }

        // ordenamiento

        ordenarVector(dados, TAM);

        // sistema de puntos
        sexteto = verificarSexteto(dados, TAM);
        esEscalera = verificarEscalera(dados, TAM);

        if (sexteto == VALOR_RESET)
        {
            puntaje = 0;
            jugada = 4;
        }
        else if (sexteto != 0)
        {
            puntaje = compararMayor(puntaje, sexteto);
            jugada = 2;
            puntajeTirada = sexteto;
        }
        else if (esEscalera)
        {
            puntaje = PUNTAJE_MAX;
            jugada = 3;
        }
        else
        {
            suma = sumarVector(dados, TAM);
            puntaje = compararMayor(puntaje, suma);
            jugada = 1;
            puntajeTirada = suma;
        }

        // llamado interfaz turno
        mostrarCartel(nombreJugador, ronda, lanzamiento, puntajeActual, dados, TAM, puntaje, jugada, puntajeTirada);
        mostrarPausa();

        if (puntaje >= PUNTAJE_MAX || puntaje == 0)
        {
            return puntaje;
        }
    }

    return puntaje;
}
