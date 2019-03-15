// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "fiddle/examples.h"
// HASH=b7b42965927788d853f449f08ddf46de
REG_FIDDLE(BlendMode_014, 256, 256, false, 0) {
void draw(SkCanvas* canvas) {
    SkColor colors[] = { SK_ColorRED, SK_ColorBLUE };
    SkPoint horz[] = { { 0, 0 }, { 256, 0 } };
    SkPaint paint;
    paint.setShader(SkGradientShader::MakeLinear(horz, colors, nullptr, SK_ARRAY_COUNT(colors),
            SkShader::kClamp_TileMode));
    canvas->drawPaint(paint);
    paint.setBlendMode(SkBlendMode::kDstATop);
    SkColor alphas[] = { SK_ColorBLACK, SK_ColorTRANSPARENT };
    SkPoint vert[] = { { 0, 0 }, { 0, 256 } };
    paint.setShader(SkGradientShader::MakeLinear(vert, alphas, nullptr, SK_ARRAY_COUNT(alphas),
            SkShader::kClamp_TileMode));
    canvas->drawPaint(paint);
    canvas->clipRect( { 30, 30, 226, 226 } );
    canvas->drawColor(SkColorSetA(SK_ColorGREEN, 128), SkBlendMode::kScreen);
}
}  // END FIDDLE
