int juego(int cantJugadores, int &nuevoPuntajeGanador, string &nuevoNombreGanador, string nombreP1, string nombreP2, string mode = "default");

int juego(int cantJugadores, int &nuevoPuntajeGanador, string &nuevoNombreGanador, string nombreP1, string nombreP2 = "", string mode)
{
    int ronda = 0;
    int totalP1 = 0;
    int totalP2 = 0;
    int resultadoRondaP1;
    int resultadoRondaP2;
    bool jugando = true;

    while (jugando)
    {
        ronda++;

        for (int i = 1; i <= cantJugadores; i++)
        {

            if (i == 1)
            {

                resultadoRondaP1 = jugarRonda(nombreP1, ronda, totalP1, mode);
                if (resultadoRondaP1 == 0)
                {
                    totalP1 = 0;
                }
                else if (resultadoRondaP1 == 100)
                {
                    totalP1 = resultadoRondaP1;
                }
                else
                {
                    totalP1 += resultadoRondaP1;
                }
            }
            else
            {
                resultadoRondaP2 = jugarRonda(nombreP2, ronda, totalP2, mode);
                if (resultadoRondaP2 == 0)
                {
                    totalP2 = 0;
                }
                else if (resultadoRondaP2 == 100)
                {
                    totalP2 = resultadoRondaP2;
                }
                else
                {
                    totalP2 += resultadoRondaP2;
                }
            }

            if ((totalP1 < 100 && cantJugadores == 1) ||
                (cantJugadores == 2 && i == 1) ||
                (i == 2 && totalP1 < 100 && totalP2 < 100))
            {
                entreTurnos(ronda, nombreP1, nombreP2, totalP1, totalP2, i, cantJugadores);
            }
        }

        if (totalP1 >= 100 || totalP2 >= 100)
        {
            jugando = false;
            system("cls");

            if (totalP1 >= 100)
            {
                cargarGanador(nuevoPuntajeGanador, nuevoNombreGanador, totalP1, nombreP1);
                dibujarGanador(nombreP1, ronda);
            }
            else
            {
                cargarGanador(nuevoPuntajeGanador, nuevoNombreGanador, totalP2, nombreP2);
                dibujarGanador(nombreP2, ronda);
            }
        }
    }

    return 0;
}