#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <iostream>
#include <string>

class Pregunta {
private:
    int id;
    std::string enunciado;
    std::string tipo;
    std::string respuesta;
    std::string nivel;
    int tiempo;

public:
    Pregunta(int _id, std::string _enunciado, std::string _tipo, std::string _respuesta, std::string _nivel, int _tiempo)
        : id(_id), enunciado(_enunciado), tipo(_tipo), respuesta(_respuesta), nivel(_nivel), tiempo(_tiempo) {}

    int getId() const { return id; }
    std::string getNivel() const { return nivel; }
    int getTiempo() const { return tiempo; }

    void actualizar(std::string _enunciado, std::string _tipo, std::string _respuesta, std::string _nivel, int _tiempo) {
        enunciado = _enunciado;
        tipo = _tipo;
        respuesta = _respuesta;
        nivel = _nivel;
        tiempo = _tiempo;
    }

    void mostrar() const {
        std::cout << "\nID: " << id
                  << "\nEnunciado: " << enunciado
                  << "\nTipo: " << tipo
                  << "\nRespuesta esperada: " << respuesta
                  << "\nNivel taxonómico: " << nivel
                  << "\nTiempo estimado: " << tiempo << " minutos\n";
    }
};

#endif
