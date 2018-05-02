#include <utility>
#include "nodo.h"

Nodo::Nodo()
{}

Nodo::Nodo( std::pair<int,int> val )
{
    Setcoordenadas(val);
}

Nodo::~Nodo()
{}

void Nodo::Crearhijos( const std::list<Nodo> &cerrados, const std::list<Nodo*> &abiertos, Nodo *nodoPadre, const std::map<std::pair<int,int>,int> &tablero )
{
        int flagMoveInvalid = 0;
        int flagAlreadyVisited = 0;
        Nodo nodoTemporal( this->Getcoordenadas() );

        for( int i = 0; i < this->Comprobarmovimiento(tablero); i++){
                nodoTemporal.Setcoordenadas(std::make_pair(nodoTemporal.Getcoordenadas().first, nodoTemporal.Getcoordenadas().second + 1));
                if( (i != this->Comprobarmovimiento(tablero) - 1) && (nodoTemporal.Comprobarmovimiento(tablero) <= 0) ){
                    flagMoveInvalid = 1;
                    break;
                }
            }
        for(auto it : cerrados) {
            if( it == nodoTemporal ) flagAlreadyVisited = 1;
        }
        /*for(auto it : abiertos) {
            if(*it == nodoTemporal) flagAlreadyVisited = 1;
        }*/
        if(!flagMoveInvalid && !flagAlreadyVisited){
            Nodo *nuevoNodoNorte = new Nodo;
            nuevoNodoNorte->Setcoordenadas( nodoTemporal.Getcoordenadas() );
            nuevoNodoNorte->Setparent( nodoPadre );
            this->Sethijos(nuevoNodoNorte);
        }

        flagMoveInvalid = 0;
        flagAlreadyVisited = 0;
        nodoTemporal.Setcoordenadas(this->Getcoordenadas());
        for( int i = 0; i < this->Comprobarmovimiento(tablero); i++){
                nodoTemporal.Setcoordenadas(std::make_pair(nodoTemporal.Getcoordenadas().first + 1, nodoTemporal.Getcoordenadas().second + 1));
                if( (i != this->Comprobarmovimiento(tablero) - 1) && (nodoTemporal.Comprobarmovimiento(tablero) <= 0) ){
                    flagMoveInvalid = 1;
                    break;
                }
            }
        for(auto it : cerrados) {
            if( it == nodoTemporal ) flagAlreadyVisited = 1;
        }
        /*for(auto it : abiertos) {
            if(*it == nodoTemporal) flagAlreadyVisited = 1;
        }*/
        if(!flagMoveInvalid && !flagAlreadyVisited){
            Nodo *nuevoNodoNoreste = new Nodo;
            nuevoNodoNoreste->Setcoordenadas( nodoTemporal.Getcoordenadas() );
            nuevoNodoNoreste->Setparent( nodoPadre );
            this->Sethijos(nuevoNodoNoreste);
        }

        flagMoveInvalid = 0;
        flagAlreadyVisited = 0;
        nodoTemporal.Setcoordenadas(this->Getcoordenadas());
        for( int i = 0; i < this->Comprobarmovimiento(tablero); i++){
                nodoTemporal.Setcoordenadas(std::make_pair(nodoTemporal.Getcoordenadas().first + 1, nodoTemporal.Getcoordenadas().second));
                if( (i != this->Comprobarmovimiento(tablero) - 1) && (nodoTemporal.Comprobarmovimiento(tablero) <= 0) ){
                    flagMoveInvalid = 1;
                    break;
                }
            }
        for(auto it : cerrados) {
            if( it == nodoTemporal ) flagAlreadyVisited = 1;
        }
        /*for(auto it : abiertos) {
            if(*it == nodoTemporal) flagAlreadyVisited = 1;
        }*/
        if(!flagMoveInvalid && !flagAlreadyVisited){
            Nodo *nuevoNodoEste = new Nodo;
            nuevoNodoEste->Setcoordenadas( nodoTemporal.Getcoordenadas() );
            nuevoNodoEste->Setparent( nodoPadre );
            this->Sethijos(nuevoNodoEste);
        }

        flagMoveInvalid = 0;
        flagAlreadyVisited = 0;
        nodoTemporal.Setcoordenadas(this->Getcoordenadas());
        for( int i = 0; i < this->Comprobarmovimiento(tablero); i++){
                nodoTemporal.Setcoordenadas(std::make_pair(nodoTemporal.Getcoordenadas().first + 1, nodoTemporal.Getcoordenadas().second - 1));
                if( (i != this->Comprobarmovimiento(tablero) - 1) && (nodoTemporal.Comprobarmovimiento(tablero) <= 0) ){
                    flagMoveInvalid = 1;
                    break;
                }
            }
        for(auto it : cerrados) {
            if( it == nodoTemporal ) flagAlreadyVisited = 1;
        }
        /*for(auto it : abiertos) {
            if(*it == nodoTemporal) flagAlreadyVisited = 1;
        }*/
        if(!flagMoveInvalid && !flagAlreadyVisited){
            Nodo *nuevoNodoSudeste = new Nodo;
            nuevoNodoSudeste->Setcoordenadas( nodoTemporal.Getcoordenadas() );
            nuevoNodoSudeste->Setparent( nodoPadre );
            this->Sethijos(nuevoNodoSudeste);
        }

        flagMoveInvalid = 0;
        flagAlreadyVisited = 0;
        nodoTemporal.Setcoordenadas(this->Getcoordenadas());
        for( int i = 0; i < this->Comprobarmovimiento(tablero); i++){
                nodoTemporal.Setcoordenadas(std::make_pair(nodoTemporal.Getcoordenadas().first, nodoTemporal.Getcoordenadas().second - 1));
                if( (i != this->Comprobarmovimiento(tablero) - 1) && (nodoTemporal.Comprobarmovimiento(tablero) <= 0) ){
                    flagMoveInvalid = 1;
                    break;
                }
            }
        for(auto it : cerrados) {
            if( it == nodoTemporal ) flagAlreadyVisited = 1;
        }
        /*for(auto it : abiertos) {
            if(*it == nodoTemporal) flagAlreadyVisited = 1;
        }*/
        if(!flagMoveInvalid && !flagAlreadyVisited){
            Nodo *nuevoNodoSur = new Nodo;
            nuevoNodoSur->Setcoordenadas( nodoTemporal.Getcoordenadas() );
            nuevoNodoSur->Setparent( nodoPadre );
            this->Sethijos(nuevoNodoSur);
        }

        flagMoveInvalid = 0;
        flagAlreadyVisited = 0;
        nodoTemporal.Setcoordenadas(this->Getcoordenadas());
        for( int i = 0; i < this->Comprobarmovimiento(tablero); i++){
                nodoTemporal.Setcoordenadas(std::make_pair(nodoTemporal.Getcoordenadas().first - 1, nodoTemporal.Getcoordenadas().second - 1));
                if( (i != this->Comprobarmovimiento(tablero) - 1) && (nodoTemporal.Comprobarmovimiento(tablero) <= 0) ){
                    flagMoveInvalid = 1;
                    break;
                }
            }
        for(auto it : cerrados) {
            if( it == nodoTemporal ) flagAlreadyVisited = 1;
        }
        /*for(auto it : abiertos) {
            if(*it == nodoTemporal) flagAlreadyVisited = 1;
        }*/
        if(!flagMoveInvalid && !flagAlreadyVisited){
            Nodo *nuevoNodoSuroeste = new Nodo;
            nuevoNodoSuroeste->Setcoordenadas( nodoTemporal.Getcoordenadas() );
            nuevoNodoSuroeste->Setparent( nodoPadre );
            this->Sethijos(nuevoNodoSuroeste);
        }

        flagMoveInvalid = 0;
        flagAlreadyVisited = 0;
        nodoTemporal.Setcoordenadas(this->Getcoordenadas());
        for( int i = 0; i < this->Comprobarmovimiento(tablero); i++){
                nodoTemporal.Setcoordenadas(std::make_pair(nodoTemporal.Getcoordenadas().first - 1, nodoTemporal.Getcoordenadas().second));
                if( (i != this->Comprobarmovimiento(tablero) - 1) && (nodoTemporal.Comprobarmovimiento(tablero) <= 0) ){
                    flagMoveInvalid = 1;
                    break;
                }
            }
        for(auto it : cerrados) {
            if( it == nodoTemporal ) flagAlreadyVisited = 1;
        }
        /*for(auto it : abiertos) {
            if(*it == nodoTemporal) flagAlreadyVisited = 1;
        }*/
        if(!flagMoveInvalid && !flagAlreadyVisited){
            Nodo *nuevoNodoOeste = new Nodo;
            nuevoNodoOeste->Setcoordenadas( nodoTemporal.Getcoordenadas() );
            nuevoNodoOeste->Setparent( nodoPadre );
            this->Sethijos(nuevoNodoOeste);
        }

        flagMoveInvalid = 0;
        flagAlreadyVisited = 0;
        nodoTemporal.Setcoordenadas(this->Getcoordenadas());
        for( int i = 0; i < this->Comprobarmovimiento(tablero); i++){
                nodoTemporal.Setcoordenadas(std::make_pair(nodoTemporal.Getcoordenadas().first - 1, nodoTemporal.Getcoordenadas().second + 1));
                if( (i != this->Comprobarmovimiento(tablero) - 1) && (nodoTemporal.Comprobarmovimiento(tablero) <= 0) ){
                    flagMoveInvalid = 1;
                    break;
                }
            }
        for(auto it : cerrados) {
            if( it == nodoTemporal ) flagAlreadyVisited = 1;
        }
        /*for(auto it : abiertos) {
            if(*it == nodoTemporal) flagAlreadyVisited = 1;
        }*/
        if(!flagMoveInvalid && !flagAlreadyVisited){
            Nodo *nuevoNodoNoroeste = new Nodo;
            nuevoNodoNoroeste->Setcoordenadas( nodoTemporal.Getcoordenadas() );
            nuevoNodoNoroeste->Setparent( nodoPadre );
            this->Sethijos(nuevoNodoNoroeste);
        }




}

int Nodo::Comprobarmovimiento( const std::map<std::pair<int,int>, int> &val )
{
    auto it = val.find(coordenadas);

    if( it != val.end()){
        return it->second;
    }
    else {
        return -1;
    }
}

bool Nodo::operator==( Nodo &val)
{
    return ((coordenadas.first == val.Getcoordenadas().first) && (coordenadas.second == val.Getcoordenadas().second));
}


