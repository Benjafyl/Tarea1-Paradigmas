#include <iostream>
#include "../include/Pregunta.h"
#include "../include/BancoPreguntas.h"
#include "../include/Evaluacion.h"


int main() {
    BancoPreguntas banco;
    int opcion, id, tiempo, cantidad;
    std::string enunciado, tipo, respuesta, nivel;

    while (true) {
        std::cout << "\n===== MENÚ =====\n";
        std::cout << "1. Crear pregunta\n";
        std::cout << "2. Actualizar pregunta\n";
        std::cout << "3. Borrar pregunta\n";
        std::cout << "4. Consultar pregunta\n";
        std::cout << "5. Buscar por nivel\n";
        std::cout << "6. Generar evaluación\n";
        std::cout << "7. Mostrar todas\n";
        std::cout << "0. Salir\nOpción: ";
        std::cin >> opcion;

        if (opcion == 0) break;

        switch (opcion) {
            case 1:
                std::cout << "ID: "; std::cin >> id;
                std::cin.ignore();
                std::cout << "Enunciado: "; std::getline(std::cin, enunciado);
                std::cout << "Tipo (VF/OM): "; std::getline(std::cin, tipo);
                std::cout << "Respuesta esperada: "; std::getline(std::cin, respuesta);
                std::cout << "Nivel taxonómico: "; std::getline(std::cin, nivel);
                std::cout << "Tiempo estimado (min): "; std::cin >> tiempo;
                banco.agregarPregunta(Pregunta(id, enunciado, tipo, respuesta, nivel, tiempo));
                break;

            case 2:
                std::cout << "ID de pregunta a actualizar: "; std::cin >> id;
                if (auto* p = banco.buscarPorId(id)) {
                    std::cin.ignore();
                    std::cout << "Nuevo enunciado: "; std::getline(std::cin, enunciado);
                    std::cout << "Nuevo tipo: "; std::getline(std::cin, tipo);
                    std::cout << "Nueva respuesta: "; std::getline(std::cin, respuesta);
                    std::cout << "Nuevo nivel: "; std::getline(std::cin, nivel);
                    std::cout << "Nuevo tiempo: "; std::cin >> tiempo;
                    p->actualizar(enunciado, tipo, respuesta, nivel, tiempo);
                } else {
                    std::cout << "Pregunta no encontrada.\n";
                }
                break;

            case 3:
                std::cout << "ID a borrar: "; std::cin >> id;
                if (banco.eliminarPregunta(id)) std::cout << "Eliminada.\n";
                else std::cout << "No encontrada.\n";
                break;

            case 4:
                std::cout << "ID a consultar: "; std::cin >> id;
                if (auto* p = banco.buscarPorId(id)) p->mostrar();
                else std::cout << "No encontrada.\n";
                break;

            case 5:
                std::cin.ignore();
                std::cout << "Nivel taxonómico a buscar: "; std::getline(std::cin, nivel);
                banco.mostrarPorNivel(nivel);
                break;

            case 6: {
                std::cin.ignore();
                std::cout << "Nivel a incluir en evaluación: "; std::getline(std::cin, nivel);
                std::cout << "Cantidad de preguntas: "; std::cin >> cantidad;
                Evaluacion eval;
                auto seleccionadas = banco.obtenerPreguntasNivel(nivel, cantidad);
                for (const auto& p : seleccionadas) {
                    eval.agregarPregunta(p);
                }
                eval.mostrarEvaluacion();
                break;
            }

            case 7:
                banco.mostrarTodas();
                break;

            default:
                std::cout << "Opción inválida.\n";
        }
    }

    return 0;
}
