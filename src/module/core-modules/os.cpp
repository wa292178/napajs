#include "os.h"

// This is not a module extension, so define this macro to use V8 common macros.
#define NAPA_MODULE_EXTENSION
#include <napa-module.h>
#include <napa/module/platform.h>

using namespace napa;
using namespace napa::module;

void os::Init(v8::Local<v8::Object> exports) {
    auto isolate = v8::Isolate::GetCurrent();
    v8::HandleScope scope(isolate);

    auto context = isolate->GetCurrentContext();

    (void)exports->CreateDataProperty(context,
                                      v8_helpers::MakeV8String(isolate, "type"),
                                      v8_helpers::MakeV8String(isolate, platform::OS_TYPE));
}