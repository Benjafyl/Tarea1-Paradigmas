#ifndef BANCOPREGUNTAS_H
#define BANCOPREGUNTAS_H

#include <vector>
#include <algorithm>
#include "Pregunta.h"

class BancoPreguntas {
private:
    std::vector<Pregunta> preguntas;

public:
    void agregarPregunta(const Pregunta& p) {
        preguntas.push_back(p);
    }

    bool eliminarPregunta(int id) {
        auto it = std::remove_if(preguntas.begin(), preguntas.end(),
                                 [id](const Pregunta& p) { return p.getId() == id; });
        if (it != preguntas.end()) {
            preguntas.erase(it, preguntas.end());
            return true;
        }
        return false;
    }

    Pregunta* buscarPorId(int id) {
        for (auto& p : preguntas) {
            if (p.getId() == id) return &p;
        }
        return nullptr;
    }

    void mostrarPorNivel(const std::string& nivel) {
        for (const auto& p : preguntas) {
            if (p.getNivel() == nivel)
                p.mostrar();
        }
    }

    void mostrarTodas() const {
        for (const auto& p : preguntas) {
            p.mostrar();
        }
    }

    std::vector<Pregunta> obtenerPreguntasNivel(const std::string& nivel, int cantidad) {
        std::vector<Pregunta> seleccionadas;
        for (const auto& p : preguntas) {
            if (p.getNivel() == nivel) {
                seleccionadas.push_back(p);
                if (seleccionadas.size() == cantidad) break;
            }
        }
        return seleccionadas;
    }
};

#endif
