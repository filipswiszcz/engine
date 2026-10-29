#ifndef ARM_ASSETS_H
#define ARM_ASSETS_H

// #define CGLTF_IMPLEMENTATION
// #include <cgltf/cgltf.h>

#include "memory.h"

namespace core {

enum class asset_state : u8 {
    UNINITIALIZED = 0,
    INDEXED,
    LOADING,
    LOADED,
    FAILED
};

enum class asset_manager_status : u8 {
    SUCCESS = 0,
    FILE_NOT_FOUND,
    FILE_READ_ERROR,
    FILE_WRITE_ERROR,
    OUT_OF_MEMORY
};

class asset_manager {
public:
    [[nodiscard]] asset_manager_status initialize(void) noexcept;
private:
    // [[nodiscard]] asset_manager_status _read_gltf_file(const char *filepath) noexcept;
    // should i load all at once? streaming?
};

}

#endif // !ARM_ASSETS_H