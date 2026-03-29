
#include "Log.h"

namespace Violet {

    void Log::warning(Concern concern, std::string info) {
        std::string message = elaborate(concern);
        std::cerr << "\nWarning: " << message << '\n';
        if (info != "") std::cerr << "Info: " << info << '\n';
    }
    
    std::string Log::elaborate(Concern concern) {
        switch (concern) {
            case MESH_BEFORE_WINDOW: return "Mesh constructor called before OpenGL context has been established"; break;
        }
    }
}

