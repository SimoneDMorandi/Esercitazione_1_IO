// Includo gli stream necessari per l'input/output e la formattazione dei numeri
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
// Creo la funzione per mappare i punti da un intervallo all'altro
double Map(double x, double a, double b, double c, double d)
{
    double y = ((x-a)*(d-c))/(b-a) + c;
    return y;
}

int main()
{
    // Apro i file di input e di output, controllando che non ci siano errori nell'esecuzione.
    std::ifstream input_file;
    std::string nameFile = "data.csv";
    std::ofstream output_file("result.csv");
    input_file.open(nameFile);

    if(input_file.fail())
    {
        std::cerr <<"Input File not found."<<std::endl;
        return 1;
    }
    if(output_file.fail())
    {
        std::cerr <<"Couldn't open/find Output file."<<std::endl;
        return 1;
    }
    // Inizializzo le variabili necessarie per la trasformazione dei numeri dall'intervallo [a,b] a [c,d]
    double val, mappedVal,mean;
    double a = 1;
    double b = 5;
    double c = -1;
    double d = 2;
    unsigned int numberValue = 0;
    double sumValues = 0.0;

    // Imposto l'header del file e imposto il formato esponenziale per i risultati
    output_file<< "# N Mean"<<"\n";
    output_file <<std::scientific;
    output_file <<std::setprecision(16);
    // Leggo i valori del file riga per riga ed eseguo i calcoli richiesti
    while(input_file>>val)
    {
        numberValue += 1;
        mappedVal = Map(val,a,b,c,d);
        sumValues += mappedVal;
        mean = sumValues/numberValue;
        // Aggiungo i risultati al file di output
        output_file<< numberValue<< " "<< mean<<"\n";
    }
    // Chiudo i file
    input_file.close();
    output_file.close();
    return 0;
}
