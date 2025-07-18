/*
 * Copyright (c) 2021, Idan Horowitz <idan.horowitz@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace JS {

class JS_API AsyncFunctionConstructor final : public NativeFunction {
    JS_OBJECT(AsyncFunctionConstructor, NativeFunction);
    GC_DECLARE_ALLOCATOR(AsyncFunctionConstructor);

public:
    virtual void initialize(Realm&) override;
    virtual ~AsyncFunctionConstructor() override = default;

    virtual ThrowCompletionOr<Value> call() override;
    virtual ThrowCompletionOr<GC::Ref<Object>> construct(FunctionObject& new_target) override;

private:
    explicit AsyncFunctionConstructor(Realm&);

    virtual bool has_constructor() const override { return true; }
};

}
