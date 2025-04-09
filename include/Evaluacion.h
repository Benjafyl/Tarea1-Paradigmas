#ifndef EVALUACION_H
#define EVALUACION_H

#include <vector>
#include "Pregunta.h"

class Evaluacion {
private:
    std::vector<Pregunta> preguntas;

public:
    void agregarPregunta(const Pregunta& p) {
        preguntas.push_back(p);
    }

    int calcularTiempoTotal() const {
        int total = 0;
        for (const auto& p : preguntas) {
            total += p.getTiempo();
        }
        return total;
    }

    void mostrarEvaluacion() const {
        std::cout << "\n--- Evaluación Generada ---\n";
        for (const auto& p : preguntas) {
            p.mostrar();
        }
        std::cout << "\nTiempo total estimado: " << calcularTiempoTotal() << " minutos\n";
    }
};

#endif
