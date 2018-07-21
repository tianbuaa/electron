// Copyright (c) 2018 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "native_mate/dictionary.h"
// clang-format off
#include "atom/common/node_includes.h"  // NOLINT(build/include_alpha)
// clang-format on

namespace {

bool IsDesktopCapturerEnabled() {
#if defined(ENABLE_DESKTOP_CAPTURER)
  return true;
#else
  return false;
#endif
}

bool IsOffscreenRenderingEnabled() {
#if defined(ENABLE_OSR)
  return true;
#else
  return false;
#endif
}

bool IsPDFViewerEnabled() {
#if defined(ENABLE_PDF_VIEWER)
  return true;
#else
  return false;
#endif
}

void Initialize(v8::Local<v8::Object> exports,
                v8::Local<v8::Value> unused,
                v8::Local<v8::Context> context,
                void* priv) {
  mate::Dictionary dict(context->GetIsolate(), exports);
  dict.SetMethod("isDesktopCapturerEnabled", &IsDesktopCapturerEnabled);
  dict.SetMethod("isOffscreenRenderingEnabled", &IsOffscreenRenderingEnabled);
  dict.SetMethod("isPDFViewerEnabled", &IsPDFViewerEnabled);
}

}  // namespace

NODE_BUILTIN_MODULE_CONTEXT_AWARE(atom_common_features, Initialize)
