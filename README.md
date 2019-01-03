# monitorx
Monitorx is basic imgui ui for monitoring entityx. It uses SDL2, OpenGL2, EntityX,
imgui and Preshing's reflection.

# Usage
You can just copy the files under src folder to your project that's it!

You should create your component in this way

In Position.h file.

```

struct Position {
    explicit Position(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    float x, y;

    REFLECT()
};
```

In Position.cpp or you can create a cpp file to
complete macro reflection implementation.

```

REFLECT_STRUCT_BEGIN(Position)
                    REFLECT_STRUCT_MEMBER(x)
                    REFLECT_STRUCT_MEMBER(y)
REFLECT_STRUCT_END()
```

For now reflection supports basic types, however you can add your types easily.
If you find more information about reflection. You can look at this site. Thanks to Preshing.
https://preshing.com/20180116/a-primitive-reflection-system-in-cpp-part-1/

In Primitives.cpp just add the template like that.

```

//--------------------------------------------------------
// A type descriptor for long
//--------------------------------------------------------

struct TypeDescriptor_Long : TypeDescriptor {
    TypeDescriptor_Long() : TypeDescriptor{"long", sizeof(long)} {
    }

    void dump(const void *obj, int /* unused */) const override {
        std::cout << "long{" << *(const long *) obj << "}";
    }

    std::string type(const void *obj) const override {
        return "long";
    }

    std::string value(const void *obj, size_t offset) const override {
        return std::to_string(*(const long *) ((char*)obj + offset));
    }
};

template<>
TypeDescriptor *getPrimitiveDescriptor<long>() {
    static TypeDescriptor_Long typeDesc;
    return &typeDesc;
}
```

You can find a basic example in main.cpp and Test.h

Here is the basic integration

```
entityx::EntityX entityX;
monitorx::MonitorX monitorX(&entityX, window, &gl_context);
monitorX.Init();


// Main loop
bool done = false;
while (!done) {
    const Uint32 start_time_ms = SDL_GetTicks();
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        // Pass events to monitorX for ImGui
        monitorX.ProcessEvent(&event);
        if (event.type == SDL_QUIT)
            done = true;
        if (event.type == SDL_KEYDOWN) {
            TestKey(event.key.keysym.scancode, monitorX, entityX);
        }
    }

    // Assign the components that you want to monitor
    monitorX.Render<Position, Size, Visibility, end_of_list>();
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SwapWindow(window);
    glClear(GL_COLOR_BUFFER_BIT);

    const auto ms_per_frame = static_cast<const Uint32>(1000/*ms*/ / 60.0f);
    const Uint32 elapsed_time_ms = SDL_GetTicks() - start_time_ms;
    if (elapsed_time_ms < ms_per_frame) {
        SDL_Delay(ms_per_frame - elapsed_time_ms);
    }
}

// Cleanup
monitorX.Destroy();
```

In test example when you hit A on keyboard it shows the entity monitor.

