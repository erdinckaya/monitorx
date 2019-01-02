#include "Reflect.h"

namespace reflect {

//--------------------------------------------------------
// A type descriptor for int
//--------------------------------------------------------

    struct TypeDescriptor_Int : TypeDescriptor {
        TypeDescriptor_Int() : TypeDescriptor{"int", sizeof(int)} {
        }

        void dump(const void *obj, int /* unused */) const override {
            std::cout << "int{" << *(const int *) obj << "}";
        }

        std::string type(const void *obj) const override {
            return "int";
        }

        std::string value(const void *obj, size_t offset) const override {

            return std::to_string(*(const int *) ((char*)obj + offset));
        }
    };

    template<>
    TypeDescriptor *getPrimitiveDescriptor<int>() {
        static TypeDescriptor_Int typeDesc;
        return &typeDesc;
    }

//--------------------------------------------------------
// A type descriptor for std::string
//--------------------------------------------------------

    struct TypeDescriptor_StdString : TypeDescriptor {
        TypeDescriptor_StdString() : TypeDescriptor{"std::string", sizeof(std::string)} {
        }

        void dump(const void *obj, int /* unused */) const override {
            std::cout << "std::string{\"" << *(const std::string *) obj << "\"}";
        }

        std::string type(const void *obj) const override {
            return "string";
        }

        std::string value(const void *obj, size_t offset) const override {
            return *(const std::string *) obj;
        }
    };

    template<>
    TypeDescriptor *getPrimitiveDescriptor<std::string>() {
        static TypeDescriptor_StdString typeDesc;
        return &typeDesc;
    }

//--------------------------------------------------------
// A type descriptor for double
//--------------------------------------------------------

    struct TypeDescriptor_Double : TypeDescriptor {
        TypeDescriptor_Double() : TypeDescriptor{"double", sizeof(double)} {
        }

        void dump(const void *obj, int /* unused */) const override {
            std::cout << "double{" << *(const double *) obj << "}";
        }

        std::string type(const void *obj) const override {
            return "double";
        }

        std::string value(const void *obj, size_t offset) const override {
            return std::to_string(*(const double *) ((char*)obj + offset));
        }
    };

    template<>
    TypeDescriptor *getPrimitiveDescriptor<double>() {
        static TypeDescriptor_Double typeDesc;
        return &typeDesc;
    }


//--------------------------------------------------------
// A type descriptor for float
//--------------------------------------------------------

    struct TypeDescriptor_Float : TypeDescriptor {
        TypeDescriptor_Float() : TypeDescriptor{"float", sizeof(float)} {
        }

        void dump(const void *obj, int /* unused */) const override {
            std::cout << "float{" << *(const float *) obj << "}";
        }

        std::string type(const void *obj) const override {
            return "float";
        }

        std::string value(const void *obj, size_t offset) const override {
            return std::to_string(*(const float *) ((char*)obj + offset));
        }
    };

    template<>
    TypeDescriptor *getPrimitiveDescriptor<float>() {
        static TypeDescriptor_Float typeDesc;
        return &typeDesc;
    }

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

} // namespace reflect
