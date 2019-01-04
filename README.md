# monitorx
MonitorX is basic imgui editor for monitoring entityx. It uses SDL2, OpenGL2, EntityX,
imgui and Preshing's reflection.

# Prerequisites
* [SDL2](https://wiki.libsdl.org/Installation)
* [OpenGL](https://www.opengl.org/)
* [EntityX](https://github.com/alecthomas/entityx)

You can find [FindSDL2.cmake](https://github.com/erdinckaya/monitorx/blob/master/cmake/FindSDL2.cmake) and [FindOpenGL.cmake](https://github.com/erdinckaya/monitorx/blob/master/cmake/FindOpenGL.cmake) and [FindEntityx.cmake](https://github.com/erdinckaya/monitorx/blob/master/cmake/FindEntityx.cmake) in cmake folder.

# Build
[CMake](https://cmake.org/) is required. Quick start:
```
$ git clone https://github.com/erdinckaya/monitorx
$ cd monitorx
$ mkdir build
$ cd build
$ cmake ..
```

# Usage
You can just copy the files under src folder to your project that's it!

If your project is already integrated to imgui you dont need to copy imgui folder.

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

I added template struct feature to reflection. For instance :
```
template<typename C>
struct Vec2 {
    explicit Vec2(C x = 0, C y = 0) : x(x), y(y) {}

    C x;
    C y;

    REFLECT_TEMPLATE(Vec2, C)
                        REFLECT_STRUCT_MEMBER_TEMPLATE(x)
                        REFLECT_STRUCT_MEMBER_TEMPLATE(y)
    REFLECT_STRUCT_END()

};
REFLECT_STRUCT_INIT_TEMPLATE(Vec2)
```
There are some minor pitfalls in template struct reflection. You must
not define your template argument T, because in Preshing's reflection macro
uses T implicitly. Other than that just use reflect_template macros in header
file or inl file.


For now reflection supports basic types, however you can add your types easily.
If you want to find more information about reflection, you can look at this site. Thanks to Preshing.
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

