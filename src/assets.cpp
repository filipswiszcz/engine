#include <filesystem>

#include "assets.h"

namespace core {

asset_manager_status asset_manager::initialize(void) noexcept {
    return asset_manager_status::SUCCESS;
}

asset_manager_status asset_manager::index_assets(const char *dirpath) noexcept {
    if (dirpath == nullptr) {
        return asset_manager_status::INVALID_ARGUMENT;
    }

    std::error_code error_code;
    if (!std::filesystem::exists(dirpath, error_code)) {
        return asset_manager_status::FILE_NOT_FOUND;
    }

    for (const auto &entry : std::filesystem::recursive_directory_iterator(dirpath, error_code)) {
        if (!entry.is_regular_file(error_code)) {
            continue;
        }

        const char *filepath = entry.path().generic_string().c_str();

        // check file type etc

        //..
    }

    return asset_manager_status::SUCCESS;
}

// asset_manager_status asset_manager::_read_gltf_file(const char *filepath) noexcept {
//     return asset_manager_status::SUCCESS;
// }

}