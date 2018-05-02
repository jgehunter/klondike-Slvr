#ifndef NODO_H
#define NODO_H

#include <vector>
#include <utility>
#include <map>
#include <list>

class Nodo
{
    public:
        Nodo();
        Nodo( std::pair<int,int> );
        virtual ~Nodo();

        std::pair<int,int> Getcoordenadas() { return coordenadas; }
        void Setcoordenadas(std::pair<int,int> val) { coordenadas = val; }
        Nodo* Getparent() { return parent; }
        void Setparent(Nodo* val) { parent = val; }
        std::vector<Nodo*>& Gethijos() { return hijos; }
        void Sethijos(Nodo* val) { hijos.push_back(val); }
        void Crearhijos( const std::list<Nodo> &val, const std::list<Nodo*> &abiertos, Nodo *nodoPadre, const std::map<std::pair<int,int>,int> &tablero  );
        int Comprobarmovimiento( const std::map<std::pair<int,int>,int> &val );
        bool operator==( Nodo &val );

    protected:

    private:
        std::pair<int,int> coordenadas;
        Nodo* parent;
        std::vector<Nodo*> hijos;
};

#endif // NODO_H
