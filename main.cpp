#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

const int NAMEPOKEMON = 12;

const int CANTIDADPOKEMONES = 10;

struct Pokemon
{
    char name[ NAMEPOKEMON ] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};
    short level = 0;
    float attactk = 0.0;
    float defense = 0.0;
};

//Función 1
Pokemon createPokemon( std::string name, int attack, int defense, short level );

//Función 2
void printPokemon( Pokemon pokemon );

//Función 3
void savePokemon( Pokemon pokemon );

//Función 4
Pokemon readPokemon( int pos );

//Función 5
int sizeOfFile();

//Función 6
int numberOfPokemons();

//Función 7
void readAllPokemons( Pokemon pokemones[ CANTIDADPOKEMONES ], int pokeSize );

//Función 8
void updatePokedex( int pos, Pokemon newPokemon );

//Función 9
Pokemon ingresarPokemon();

//Función 10
void uploadPokemons( Pokemon pokemones[ CANTIDADPOKEMONES ], int tam );

//Función 11
void printAllPokemons( Pokemon pokemones[ CANTIDADPOKEMONES ], int tam );

int main()
{
    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::setw(65) << "Taller 3 Punto 1" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

    bool menuCerrado = false;
    int menu;
    Pokemon listaPokemones[ CANTIDADPOKEMONES ];
    Pokemon nuevoPokemon;
    Pokemon reemplazoPokemon;
    Pokemon informacionPokemon;
    int numeroPokemones = 0;
    int numeroPokemon;
    int numeroPokemonesGuardar;
    int cantidadPokemones;
    std::string inicializacionArregloChar = " ";

    while( menuCerrado == false )
    {
        std::cout << std::endl << "Digite la opcion que quiere ejecutar: " << std::endl << std::endl;
        std::cout << "\t" << "(1) Guardar nuevo pokemon" << std::endl;
        std::cout << "\t" << "(2) Modificar datos de un pokemon" << std::endl;
        std::cout << "\t" << "(3) Buscar un pokemon" << std::endl;
        std::cout << "\t" << "(4) Leer todos los pokemones" << std::endl;
        std::cout << "\t" << "(5) Guardar arreglo de pokemones" << std::endl;
        std::cout << "\t" << "(6) Cantidad de pokemones" << std::endl;
        std::cout << "\t" << "(7) Salir" << std::endl << std::endl;
        std::cout << "Eleccion: ";
        std::cin >> menu;
        std::cout << std::endl;
        switch( menu )
        {
        case 1:
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            nuevoPokemon = ingresarPokemon();
            savePokemon( nuevoPokemon );
            numeroPokemones++;
            std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            break;
        case 2:
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            std::cout << "Digite el numero del pokemon del cual quiere modificar su informacion: ";
            std::cin >> numeroPokemon;
            numeroPokemon -= 1;
            std::cout << std::endl;
            reemplazoPokemon = ingresarPokemon();
            updatePokedex( numeroPokemon, reemplazoPokemon );
            std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            break;
        case 3:
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            std::cout << "Digite el numero del pokemon del cual quiere saber su informacion: ";
            std::cin >> numeroPokemon;
            numeroPokemon -= 1;
            informacionPokemon = readPokemon( numeroPokemon );
            printPokemon( informacionPokemon );
            std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            break;
        case 4:
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            readAllPokemons( listaPokemones, numeroPokemones );
            printAllPokemons( listaPokemones, numeroPokemones );
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            break;
        case 5:
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

            for( int i = 0; i < numeroPokemones; i++ )
            {
                strcpy( listaPokemones[ i ].name, inicializacionArregloChar.c_str() );
                listaPokemones[ i ].attactk = 0.0;
                listaPokemones[ i ].defense = 0.0;
                listaPokemones[ i ].level = 0;
            }

            numeroPokemones = 0;
            std::cout << "Digite la cantidad de pokemones que quiere guardar: ";
            std::cin >> numeroPokemonesGuardar;
            numeroPokemones = numeroPokemonesGuardar;

            std::cout << std::endl;
            for( int i = 0; i < numeroPokemonesGuardar; i++ )
            {
                std::cout << "Pokemon " << i + 1 << std::endl;
                listaPokemones[ i ] = ingresarPokemon();
                std::cout << std::endl;
            }

            uploadPokemons( listaPokemones, numeroPokemonesGuardar );

            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            break;
        case 6:
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            cantidadPokemones = numberOfPokemons();
            std::cout << "El numero de pokemones guardados en el archivo son: " << cantidadPokemones << std::endl;
            std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            break;
        case 7:
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            std::cout << "Gracias por su atencion, vuelva pronto" << std::endl;
            std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            return 0;
        default:
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            std::cout << "El numero ingresado no corresponde a ninguna de las opciones permitidas" << std::endl;
            std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            break;
        }
    }
}

//Función 1
Pokemon createPokemon( std::string name, int attack, int defense, short level )
{
    Pokemon pokemonDisenado;

    strcpy( pokemonDisenado.name, name.c_str() );
    pokemonDisenado.attactk = attack;
    pokemonDisenado.defense = defense;
    pokemonDisenado.level = level;

    return pokemonDisenado;
}

//Función 2
void printPokemon( Pokemon pokemon )
{
    std::cout << "Pokemon" << std::endl;
    std::cout << "\t" << "Nombre: " << pokemon.name << std::endl;
    std::cout << "\t" << "Ataque: " << pokemon.attactk << std::endl;
    std::cout << "\t" << "Defensa: " << pokemon.defense << std::endl;
    std::cout << "\t" << "Nivel: " << pokemon.level << std::endl;
}

//Función 3
void savePokemon( Pokemon pokemon )
{
    std::ofstream file;

    file.open( "pokedex.bin", std::ios::binary | std::ios::app );

    if( file.is_open() )
    {
        file.write( ( char * ) &pokemon, sizeof( Pokemon ) );
    }
    else
    {
        std::cerr << "Error de apertura del archivo" << std::endl << std::endl;
    }

    file.close();
}

//Función 4
Pokemon readPokemon( int pos )
{
    Pokemon pokemon;
    std::ifstream file;

    file.open( "pokedex.bin", std::ios::binary );

    if( file.is_open() )
    {
        file.seekg( pos * sizeof( Pokemon ) );
        file.read( ( char * ) &pokemon, sizeof( Pokemon ) );
    }
    else
    {
        std::cerr << "Error de apertura del archivo" << std::endl << std::endl;
    }

    file.close();

    return pokemon;
}

//Función 5
int sizeOfFile()
{
    std::ifstream file;
    int tamanioFichero;

    file.open( "pokedex.bin", std::ios::binary );

    if( file.is_open() )
    {
        file.seekg( 0, std::ios::end );
        tamanioFichero = file.tellg();
    }
    else
    {
        std::cerr << "Error de apertura del archivo" << std::endl << std::endl;
    }

    file.close();

    return tamanioFichero;
}

//Función 6
int numberOfPokemons()
{
    int cantidadPokemones;
    int tamanioArchivo;

    tamanioArchivo = sizeOfFile();
    cantidadPokemones = tamanioArchivo / sizeof( Pokemon );

    return cantidadPokemones;
}

//Función 7
void readAllPokemons( Pokemon pokemones[ CANTIDADPOKEMONES ], int pokeSize )
{
    std::ifstream file;

    file.open( "pokedex.bin", std::ios::binary );

    if( file.is_open() )
    {
        for( int i = 0; i < pokeSize; i++ )
        {
            file.read( ( char * ) &pokemones[ i ], sizeof( Pokemon ) );
        }
    }
    else
    {
        std::cerr << "Error de apertura del archivo" << std::endl << std::endl;
    }

    file.close();
}

//Función 8
void updatePokedex( int pos, Pokemon newPokemon )
{
    std::fstream file;

    file.open( "pokedex.bin", std::ios::in | std::ios::out | std::ios::binary );

    if( file.is_open() )
    {
        file.seekp( pos * sizeof( Pokemon ) );
        file.write( ( char * ) &newPokemon, sizeof( Pokemon ) );
    }
    else
    {
        std::cerr << "Error de apertura del archivo" << std::endl << std::endl;
    }

    file.close();
}

//Función 9
Pokemon ingresarPokemon()
{
    std::string nombrePokemon;
    int ataquePokemon;
    int defensaPokemon;
    short nivelPokemon;
    Pokemon pokemonCreado;

    std::cout << "Digite el nombre del pokemon: ";
    std::cin.ignore();
    std::getline( std::cin, nombrePokemon );
    std::cout << "Digite la cantidad de ataque del pokemon " << nombrePokemon << ": ";
    std::cin >> ataquePokemon;
    std::cout << "Digite la cantidad de defensa del pokemon " << nombrePokemon << ": ";
    std::cin >> defensaPokemon;
    std::cout << "Digite el nivel del pokemon " << nombrePokemon << ": ";
    std::cin >> nivelPokemon;

    pokemonCreado = createPokemon( nombrePokemon, ataquePokemon, defensaPokemon, nivelPokemon );

    return pokemonCreado;
}

//Función 10
void uploadPokemons( Pokemon pokemones[ CANTIDADPOKEMONES ], int tam )
{
    std::ofstream file;

    file.open( "pokedex.bin", std::ios::binary | std::ios::out );

    if( file.is_open() )
    {
        for( int i = 0; i < tam; i++ )
        {
            file.write( ( char * ) &pokemones[ i ], sizeof( Pokemon ) );
        }
    }
    else
    {
        std::cerr << "Error de apertura del archivo" << std::endl << std::endl;
    }

    file.close();
}

//Función 11
void printAllPokemons( Pokemon pokemones[ CANTIDADPOKEMONES ], int tam )
{
    for( int i = 0; i < tam; i++ )
    {
        std::cout << "Pokemon " << i + 1 << std::endl;
        std::cout << "\t" << "Nombre: " << pokemones[ i ].name << std::endl;
        std::cout << "\t" << "Ataque: " << pokemones[ i ].attactk << std::endl;
        std::cout << "\t" << "Defensa: " << pokemones[ i ].defense << std::endl;
        std::cout << "\t" << "Nivel: " << pokemones[ i ].level << std::endl << std::endl;
    }
}