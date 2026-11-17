#ifndef ARM_ASSETS_H
#define ARM_ASSETS_H

// #define CGLTF_IMPLEMENTATION
// #include <cgltf/cgltf.h>

#include "memory.h"

namespace core {

typedef u16 asID;

constexpr asID INVALID_ASSET = 0; 

enum class asset_type : u8 {
    UNKNOWN = 0,
    MODEL,
    TEXTURE,
    AUDIO
};

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
    OUT_OF_MEMORY,
    CAPACITY_EXCEEDED,
    INVALID_ARGUMENT
};

struct asset_descriptor {
    asID id;
    asset_type type;
    asset_state state;
    char filepath[256];
    void *data;
    u32 ref_counter;
};

class asset_manager {
public:
    [[nodiscard]] asset_manager_status initialize(void) noexcept;
    [[nodiscard]] asset_manager_status index_assets(const char *dirpath) noexcept;
    
    [[nodiscard]] asID find_asset(const char *filepath) const noexcept;
    [[nodiscard]] asID load_asset(const char *filepath) noexcept;
    [[nodiscard]] asset_manager_status release_asset(const asID id) noexcept;
private:
    [[nodiscard]] asset_manager_status _read_gltf_file(const asset_descriptor *descriptor) noexcept;
};

}

#endif // !ARM_ASSETS_H