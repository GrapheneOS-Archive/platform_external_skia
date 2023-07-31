/*
 * Copyright 2023 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/private/base/SkAssert.h"
#include "src/sksl/SkSLContext.h"
#include "src/sksl/SkSLErrorReporter.h"
#include "src/sksl/SkSLProgramSettings.h"
#include "src/sksl/ir/SkSLModifiersDeclaration.h"

#include <cstdint>

namespace SkSL {

enum class ProgramKind : int8_t;

std::unique_ptr<ModifiersDeclaration> ModifiersDeclaration::Convert(const Context& context,
                                                                    Position pos,
                                                                    const Layout& layout,
                                                                    ModifierFlags flags) {
    SkSL::ProgramKind kind = context.fConfig->fKind;
    if (!ProgramConfig::IsFragment(kind) &&
        !ProgramConfig::IsVertex(kind)) {
        context.fErrors->error(pos, "layout qualifiers are not allowed in this kind of program");
        return nullptr;
    }

    return ModifiersDeclaration::Make(context, pos, layout, flags);
}

std::unique_ptr<ModifiersDeclaration> ModifiersDeclaration::Make(const Context& context,
                                                                 Position pos,
                                                                 const Layout& layout,
                                                                 ModifierFlags flags) {
    [[maybe_unused]] SkSL::ProgramKind kind = context.fConfig->fKind;
    SkASSERT(ProgramConfig::IsFragment(kind) ||
             ProgramConfig::IsVertex(kind));

    return std::make_unique<ModifiersDeclaration>(pos, layout, flags);
}

}  // namespace SkSL
