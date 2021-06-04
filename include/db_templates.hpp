#pragma once

namespace db_templates {
    enum type {
        user,
        _end, // Must be last one before _default
        _default = user // Must be last one
    };
}
