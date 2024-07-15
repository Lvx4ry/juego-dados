void dibujarRanking(string vNombres[], int vPuntos[]);

void dibujarRanking(string vNombres[], int vPuntos[])
{

    dibujarLinea();

    for (int i = 0; i <= 4; i++)
    {

        cout << "#" << i + 1 << " - " << vNombres[i] << " - " << vPuntos[i] << endl;
    }

    dibujarLinea();
    return;
}